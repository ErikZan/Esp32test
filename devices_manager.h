/*
 * devices_manager.h
 *
 *  Created on: Dec 27, 2023
 *      Author: root
 */

#ifndef MAIN_DEVICES_MANAGER_H_
#define MAIN_DEVICES_MANAGER_H_

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
#include "esp_gatt_common_api.h"


extern uint8_t gatt_db_value_table[HRS_IDX_NB];
extern uint8_t *spiderman_db_value_table[HRS_IDX_NB][TOTAL_SIZE];

extern nvs_handle_t MotorFlash;
extern nvs_handle MotorFlash2;
extern nvs_handle_t WifiDataFlash;


extern void show_bonded_devices(void);
extern void __attribute__((unused)) remove_all_bonded_devices(void);
extern void gatt_db_value_table_manager(gatt_value_operation gatt_value_operation_act);




#endif /* MAIN_DEVICES_MANAGER_H_ */
