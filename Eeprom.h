/*
 * Eeprom.h
 *
 *  Created on: Jan 7, 2024
 *      Author: root
 */

#ifndef MAIN_EEPROM_H_
#define MAIN_EEPROM_H_

#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"

// costum header files
#include "database_ble.h"
#include "General_def.h"
#include "UserCostumData.h"
#include "devices_manager.h"
#include "Wifi_common.h"



extern void start_non_volatile_storage(void);
#endif /* MAIN_EEPROM_H_ */
