/*
 * devices_manager.c
 *
 *  Created on: Dec 27, 2023
 *      Author: root
 */

#include "General_def.h"
#include "devices_manager.h"

//void show_bonded_devices(void)
//{
//    int dev_num = esp_ble_get_bond_device_num();
//
//    esp_ble_bond_dev_t *dev_list = (esp_ble_bond_dev_t *)malloc(sizeof(esp_ble_bond_dev_t) * dev_num);
//    if (!dev_list) {
//        ESP_LOGE(EXAMPLE_TAG, "malloc failed, return\n");
//        return;
//    }
//    esp_ble_get_bond_device_list(&dev_num, dev_list);
//    EXAMPLE_DEBUG(EXAMPLE_TAG, "Bonded devices number : %d\n", dev_num);
//
//    EXAMPLE_DEBUG(EXAMPLE_TAG, "Bonded devices list : %d\n", dev_num);
//    for (int i = 0; i < dev_num; i++) {
//        #if DEBUG_ON
//        esp_log_buffer_hex(EXAMPLE_TAG, (void *)dev_list[i].bd_addr, sizeof(esp_bd_addr_t));
//        #endif
//    }
//
//    free(dev_list);
//}
//
//void __attribute__((unused)) remove_all_bonded_devices(void)
//{
//    int dev_num = esp_ble_get_bond_device_num();
//
//    esp_ble_bond_dev_t *dev_list = (esp_ble_bond_dev_t *)malloc(sizeof(esp_ble_bond_dev_t) * dev_num);
//    if (!dev_list) {
//        ESP_LOGE(EXAMPLE_TAG, "malloc failed, return\n");
//        return;
//    }
//    esp_ble_get_bond_device_list(&dev_num, dev_list);
//    for (int i = 0; i < dev_num; i++) {
//        esp_ble_remove_bond_device(dev_list[i].bd_addr);
//    }
//
//    free(dev_list);
//}
