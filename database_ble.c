/*
 * database_ble.c
 *
 *  Created on: Dec 29, 2023
 *      Author: root
 */
#include <inttypes.h>
//#include "freertos/FreeRTOS.h"
//#include "freertos/task.h"
//#include "freertos/event_groups.h"
//#include "esp_system.h"
//#include "esp_log.h"
//#include "nvs_flash.h"
//#include "esp_bt.h"
//#include "esp_gap_ble_api.h"
//#include "esp_gatts_api.h"
//#include "esp_bt_main.h"
#include "ble_compatibility_test.h"
//#include "esp_gatt_common_api.h"
#include "esp_gatt_defs.h"
#include "General_def.h"
#include "database_ble.h"
#include "UserCostumData.h"


/* Full Database Description - Used to add attributes into the database */
///*static*/const esp_gatts_attr_db_t gatt_db[HRS_IDX_NB] =
//{
//    // Service Declaration
//    [IDX_SVC]        =
//    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&primary_service_uuid, ESP_GATT_PERM_READ,
//      sizeof(uint16_t), sizeof(GATTS_SERVICE_UUID_TEST), (uint8_t *)&GATTS_SERVICE_UUID_TEST}},
//
//    /* Characteristic Declaration */
//    [IDX_CHAR_A]     =
//    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_declaration_uuid, ESP_GATT_PERM_READ,
//      CHAR_DECLARATION_SIZE, CHAR_DECLARATION_SIZE, (uint8_t *)&char_prop_read_write}},
//
//    /* Characteristic Value */
//    [IDX_CHAR_VAL_A] =
////    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&CHAR_1_SHORT_WR, ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE | ESP_GATT_PERM_READ_ENC_MITM,
////      SHORT_CHAR_VAL_LEN, sizeof(char_value), (uint8_t *)char_value}},
//    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&CHAR_1_SHORT_WR, ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE | ESP_GATT_PERM_READ_ENC_MITM,
//    		sizeof(((struct MotorDefault_struct*)0)->power),sizeof(((struct MotorDefault_struct*)0)->power),
//    					(uint8_t *)&(MotorDefault.power)}},
//
//    /* Characteristic User Descriptor */
//    [IDX_CHAR_CFG_A]  =
//    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_user_description, ESP_GATT_PERM_READ,
//      sizeof(char1_name), sizeof(char1_name), (uint8_t *)char1_name}},
//
//    /* Characteristic Declaration */
//    [IDX_CHAR_B]      =
//    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_declaration_uuid, ESP_GATT_PERM_READ,
//      CHAR_DECLARATION_SIZE, CHAR_DECLARATION_SIZE, (uint8_t *)&char_prop_read_write}},
//
//    /* Characteristic Value */
//    [IDX_CHAR_VAL_B]  =
//    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&CHAR_2_LONG_WR, ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE,
//      LONG_CHAR_VAL_LEN, sizeof(char_value), (uint8_t *)char_value}},
//
//       /* Characteristic User Descriptor */
//    [IDX_CHAR_CFG_B]  =
//    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_user_description, ESP_GATT_PERM_READ,
//      sizeof(char2_name), sizeof(char2_name), (uint8_t *)char2_name}},
//
//   /* Characteristic Declaration */
//    [IDX_CHAR_C]      =
//    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_declaration_uuid, ESP_GATT_PERM_READ,
//      CHAR_DECLARATION_SIZE, CHAR_DECLARATION_SIZE, (uint8_t *)&char_prop_notify}},
//
//    /* Characteristic Value */
//    [IDX_CHAR_VAL_C]  =
//    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&CHAR_3_SHORT_NOTIFY, 0,
//      LONG_CHAR_VAL_LEN, sizeof(char_value), (uint8_t *)char_value}},
//
//    /* Characteristic User Descriptor */
//    [IDX_CHAR_CFG_C]  =
//    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_user_description, ESP_GATT_PERM_READ,
//      sizeof(char3_name), sizeof(char3_name), (uint8_t *)char3_name}},
//
//    /* Characteristic Client Configuration Descriptor */
//    [IDX_CHAR_CFG_C_2]  =
//    {{ESP_GATT_AUTO_RSP}, {ESP_UUID_LEN_16, (uint8_t *)&character_client_config_uuid, ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE,
//      sizeof(uint16_t), sizeof(char_ccc), (uint8_t *)char_ccc}},
//
//};
