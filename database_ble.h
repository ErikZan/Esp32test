/*
 * database_ble.h
 *
 *  Created on: Dec 29, 2023
 *      Author: root
 */

#ifndef MAIN_DATABASE_BLE_H_
#define MAIN_DATABASE_BLE_H_
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_bt.h"
#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_main.h"
#include "ble_compatibility_test.h"
#include "esp_gatt_common_api.h"
#include "esp_gatt_defs.h"
#include "UserCostumData.h"

/* Service */
//extern /*static*/ const uint16_t GATTS_SERVICE_UUID_TEST      = 0x00FF;
//extern /*static*/ const uint16_t CHAR_1_SHORT_WR              = 0xFF01;
//extern /*static*/ const uint16_t CHAR_2_LONG_WR               = 0xFF02;
//extern /*static*/ const uint16_t CHAR_3_SHORT_NOTIFY          = 0xFF03;
//       /*      */
//extern /*static*/ const uint16_t primary_service_uuid         = ESP_GATT_UUID_PRI_SERVICE;
//extern /*static*/ const uint16_t character_declaration_uuid   = ESP_GATT_UUID_CHAR_DECLARE;
//extern /*static*/ const uint16_t character_client_config_uuid = ESP_GATT_UUID_CHAR_CLIENT_CONFIG;
//extern /*static*/ const uint16_t character_user_description   = ESP_GATT_UUID_CHAR_DESCRIPTION;
//extern /*static*/ const uint8_t char_prop_notify              = ESP_GATT_CHAR_PROP_BIT_NOTIFY;
//extern /*static*/ const uint8_t char_prop_read_write          = ESP_GATT_CHAR_PROP_BIT_WRITE | ESP_GATT_CHAR_PROP_BIT_READ;
//extern /*static*/ const uint8_t char1_name[]  = "Char_1_Short_WR";
//extern /*static*/ const uint8_t char2_name[]  = "Char_2_Long_WR";
//extern /*static*/ const uint8_t char3_name[]  = "Char_3_Short_Notify";
//extern /*static*/ const uint8_t char_ccc[2]   = {0x00, 0x00};
//extern /*static*/ const uint8_t char_value[4] = {0x11, 0x22, 0x33, 0x44};

/* Full Database Description - Used to add attributes into the database */
extern /*static*/ const esp_gatts_attr_db_t gatt_db[HRS_IDX_NB] ;



#endif /* MAIN_DATABASE_BLE_H_ */
