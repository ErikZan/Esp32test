/*
 * database_ble.c
 *
 *  Created on: Dec 29, 2023
 *      Author: root
 */
#include <inttypes.h>
#include "ble_compatibility_test.h"
#include "esp_gatt_defs.h"

#include "General_def.h"
#include "UserCostumData.h"
#include "database_ble.h"


const uint16_t GATTS_SERVICE_UUID_TEST      = 0x00FF;
const uint16_t CHAR_1_SHORT_WR              = 0xFF01;
const uint16_t CHAR_2_LONG_WR               = 0xFF02;
const uint16_t CHAR_3_SHORT_NOTIFY          = 0xFF03;

const uint16_t primary_service_uuid         = ESP_GATT_UUID_PRI_SERVICE;
const uint16_t character_declaration_uuid   = ESP_GATT_UUID_CHAR_DECLARE;
const uint16_t character_client_config_uuid = ESP_GATT_UUID_CHAR_CLIENT_CONFIG;
const uint16_t character_user_description   = ESP_GATT_UUID_CHAR_DESCRIPTION;
const uint8_t char_prop_notify              = ESP_GATT_CHAR_PROP_BIT_NOTIFY;
const uint8_t char_prop_read_write          = ESP_GATT_CHAR_PROP_BIT_WRITE | ESP_GATT_CHAR_PROP_BIT_READ;
const uint8_t char1_name[]  = "Char_1_Short_WR";
const uint8_t char2_name[]  = "Char_2_Long_WR";
const uint8_t char3_name[]  = "Char_3_Short_Notify";
const uint8_t char_ccc[2]   = {0x00, 0x00};
const uint8_t char_value[4] = {0x11, 0x22, 0x33, 0x44};


/* Full Database Description - Used to add attributes into the database */

const esp_gatts_attr_db_t gatt_db[HRS_IDX_NB] =
{
    // Service Declaration
    [IDX_SVC]        =
    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&primary_service_uuid, ESP_GATT_PERM_READ,
      sizeof(uint16_t), sizeof(GATTS_SERVICE_UUID_TEST), (uint8_t *)&GATTS_SERVICE_UUID_TEST}},

    /* Characteristic Declaration */
    [IDX_CHAR_A]     =
    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_declaration_uuid, ESP_GATT_PERM_READ,
      CHAR_DECLARATION_SIZE, CHAR_DECLARATION_SIZE, (uint8_t *)&char_prop_read_write}},

    /* Characteristic Value */
    [IDX_CHAR_VAL_A] =
    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&CHAR_1_SHORT_WR, ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE | ESP_GATT_PERM_READ_ENC_MITM,
    	sizeof(((struct MotorDefault_struct*)0)->power),sizeof(((struct MotorDefault_struct*)0)->power),(uint8_t *)&(MotorDefault.power)}},

    /* Characteristic User Descriptor */
	[IDX_CHAR_CFG_A]  =
	{{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_user_description, ESP_GATT_PERM_READ,
	  sizeof(MotorDefault.name), sizeof(MotorDefault.name), (uint8_t *)MotorDefault.name}},


	  // WIFI SSID to show -->

	  /* Characteristic Declaration */
//	 [IDX_CHAR_WIFI_LIST]     =
//	 {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_declaration_uuid, ESP_GATT_PERM_READ,
//	   CHAR_DECLARATION_SIZE, CHAR_DECLARATION_SIZE, (uint8_t *)&char_prop_read_write}},
//
//	  /* Characteristic Value */
//	  [IDX_CHAR_VAL_WIFI_LIST] =
//	  {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&CHAR_2_LONG_WR, ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE | ESP_GATT_PERM_READ_ENC_MITM,
//		sizeof(),sizeof(),(uint8_t *)}},
//
//	  /* Characteristic User Descriptor */
//     [IDX_CHAR_CFG_WIFI_LIST]  =
//	 {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_user_description, ESP_GATT_PERM_READ,
//	  sizeof(), sizeof(), (uint8_t *)}},

	  // WIFI SSID to show -->

    /* Characteristic Declaration */
    [IDX_CHAR_B]      =
    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_declaration_uuid, ESP_GATT_PERM_READ,
      CHAR_DECLARATION_SIZE, CHAR_DECLARATION_SIZE, (uint8_t *)&char_prop_read_write}},

    /* Characteristic Value */
    [IDX_CHAR_VAL_B]  =
    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&CHAR_2_LONG_WR, ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE,
      LONG_CHAR_VAL_LEN, sizeof(char_value), (uint8_t *)char_value}},

       /* Characteristic User Descriptor */
    [IDX_CHAR_CFG_B]  =
    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_user_description, ESP_GATT_PERM_READ,
      sizeof(char2_name), sizeof(char2_name), (uint8_t *)char2_name}},

   /* Characteristic Declaration */
    [IDX_CHAR_C]      =
    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_declaration_uuid, ESP_GATT_PERM_READ,
      CHAR_DECLARATION_SIZE, CHAR_DECLARATION_SIZE, (uint8_t *)&char_prop_notify}},

    /* Characteristic Value */
    [IDX_CHAR_VAL_C]  =
    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&CHAR_3_SHORT_NOTIFY, 0,
      LONG_CHAR_VAL_LEN, sizeof(char_value), (uint8_t *)char_value}},

    /* Characteristic User Descriptor */
    [IDX_CHAR_CFG_C]  =
    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_user_description, ESP_GATT_PERM_READ,
      sizeof(char3_name), sizeof(char3_name), (uint8_t *)char3_name}},

    /* Characteristic Client Configuration Descriptor */
    [IDX_CHAR_CFG_C_2]  =
    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_client_config_uuid, ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE,
      sizeof(uint16_t), sizeof(char_ccc), (uint8_t *)char_ccc}},

};
