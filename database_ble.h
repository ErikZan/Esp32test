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
extern const uint16_t GATTS_SERVICE_UUID_TEST      ;
extern const uint16_t CHAR_1_SHORT_WR              ;
extern const uint16_t CHAR_2_LONG_WR               ;
extern const uint16_t CHAR_3_SHORT_NOTIFY          ;

extern const uint16_t primary_service_uuid          ;
extern const uint16_t character_declaration_uuid    ;
extern const uint16_t character_client_config_uuid  ;
extern const uint16_t character_user_description    ;
extern const uint8_t char_prop_notify               ;
extern const uint8_t char_prop_read_write          ;
extern const uint8_t char1_name[]   ;
extern const uint8_t char2_name[]   ;
extern const uint8_t char3_name[]   ;
extern const uint8_t char_ccc[2]    ;
extern const uint8_t char_value[4]  ;

/* Full Database Description - Used to add attributes into the database */
extern const esp_gatts_attr_db_t gatt_db[HRS_IDX_NB] ;



#endif /* MAIN_DATABASE_BLE_H_ */
