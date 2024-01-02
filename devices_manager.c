/*
 * devices_manager.c
 *
 *  Created on: Dec 27, 2023
 *      Author: root
 */

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
#include  "Wifi_common.h"


// ------------ Variabili ------------
uint8_t gatt_db_value_table[HRS_IDX_NB];
uint8_t *spiderman_db_value_table[HRS_IDX_NB][TOTAL_SIZE];

// Variabili Eeeprom
nvs_handle_t MotorFlash;
nvs_handle MotorFlash2;
nvs_handle_t WifiDataFlash;


// ------------ Fuznioni --------------
void show_bonded_devices(void)
{
    int dev_num = esp_ble_get_bond_device_num();

    esp_ble_bond_dev_t *dev_list = (esp_ble_bond_dev_t *)malloc(sizeof(esp_ble_bond_dev_t) * dev_num);
    if (!dev_list) {
        ESP_LOGE(EXAMPLE_TAG, "malloc failed, return\n");
        return;
    }
    esp_ble_get_bond_device_list(&dev_num, dev_list);
    EXAMPLE_DEBUG(EXAMPLE_TAG, "Bonded devices number : %d\n", dev_num);

    EXAMPLE_DEBUG(EXAMPLE_TAG, "Bonded devices list : %d\n", dev_num);
    for (int i = 0; i < dev_num; i++) {
        #if DEBUG_ON
        esp_log_buffer_hex(EXAMPLE_TAG, (void *)dev_list[i].bd_addr, sizeof(esp_bd_addr_t));
        #endif
    }

    free(dev_list);
}

void __attribute__((unused)) remove_all_bonded_devices(void)
{
    int dev_num = esp_ble_get_bond_device_num();

    esp_ble_bond_dev_t *dev_list = (esp_ble_bond_dev_t *)malloc(sizeof(esp_ble_bond_dev_t) * dev_num);
    if (!dev_list) {
        ESP_LOGE(EXAMPLE_TAG, "malloc failed, return\n");
        return;
    }
    esp_ble_get_bond_device_list(&dev_num, dev_list);
    for (int i = 0; i < dev_num; i++) {
        esp_ble_remove_bond_device(dev_list[i].bd_addr);
    }

    free(dev_list);
}

void gatt_db_value_table_manager(gatt_value_operation gatt_value_operation_act)
{
	uint8_t err;
	char buffer[64];
	if (gatt_value_operation_act == READ_FROM_FLASH)
	{

	}
	else if (gatt_value_operation_act == INIT_FROM_BLE_STACK)
	{
//		for (int var = 0; var < HRS_IDX_NB; ++var) {
//			esp_ble_gatts_get_attr_value(gatt_db_handle_table[var],&length,gatt_db_value_table[var]);
//		}

	}
	else if (gatt_value_operation_act == UPDATE_FROM_WRITE)
	{
		MotorDefault.power = *spiderman_db_value_table[IDX_CHAR_VAL_A][VALUE];

		memcpy(wifi_config.sta.ssid,WifiSSIDList[*spiderman_db_value_table[IDX_CHAR_VAL_WIFI_SEL][VALUE]],sizeof(WifiSSIDList[*spiderman_db_value_table[IDX_CHAR_VAL_WIFI_SEL][VALUE]]));

		// rimuovo la virgola --> vediamo se c'è un metodo più elòegante
		for (int var = 0; var < 64; ++var) {
			if (wifi_config.sta.ssid[var] == ',')
			{
				wifi_config.sta.ssid[var] = '\0';
				break;
			}
		}

		// Copio password wifi
		memcpy(wifi_config.sta.password,spiderman_db_value_table[IDX_CHAR_VAL_WIFI_PSW][VALUE],sizeof(wifi_config.sta.password));
		memcpy(Wifidataram[0],wifi_config.sta.ssid,sizeof(wifi_config.sta.ssid));
		memcpy(Wifidataram[1],wifi_config.sta.password,sizeof(wifi_config.sta.password));


		err = nvs_commit(MotorFlash);
		if(err != ESP_OK)
		{
			asm("nop");
		}
		err = nvs_commit(WifiDataFlash);
				if(err != ESP_OK)
				{
					asm("nop");
				}

//		nvs_close(MotorFlash);
		// debug ()

	}

	return;
}
