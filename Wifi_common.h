/*
 * Wifi_common.h
 *
 *  Created on: Dec 31, 2023
 *      Author: root
 */

#ifndef MAIN_WIFI_COMMON_H_
#define MAIN_WIFI_COMMON_H_

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
//#include "ble_compatibility_test.h"
#include "esp_gatt_common_api.h"

// wifi
#include "esp_wifi.h"
#include "esp_event.h"

// costum header files
#include "database_ble.h"
#include "General_def.h"
#include "UserCostumData.h"
#include "devices_manager.h"


// variabili
extern wifi_ap_record_t ap_info[DEFAULT_SCAN_LIST_SIZE_for_BLE_5_TRANS];
extern char WifiSSIDList[DEFAULT_SCAN_LIST_SIZE_for_BLE_5_TRANS][33+1];
extern uint8_t Wifi_select;
//extern char Wifi_password[64];
extern wifi_config_t wifi_config;


// funzioni
extern void wifi_check_task(void *pvParameters);
extern void wifi_scan(void);

#endif /* MAIN_WIFI_COMMON_H_ */
