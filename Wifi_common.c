/*
 * Wifi_common.c
 *
 *  Created on: Dec 31, 2023
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
#include "Wifi_common.h"



//void wifi_scan() {
//    wifi_scan_config_t scan_config = {
//        .ssid = 0,
//        .bssid = 0,
//        .channel = 0,
//        .show_hidden = true
//    };
//
//    ESP_ERROR_CHECK(esp_wifi_scan_start(&scan_config, true));
//    printf("Scanning...\n");
//
//    uint16_t ap_num = 0;
//    wifi_ap_record_t *ap_records;
//
//    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_num));
//    ap_records = (wifi_ap_record_t *)malloc(sizeof(wifi_ap_record_t) * ap_num);
//    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&ap_num, ap_records));
//
//    printf("Found %d networks\n", ap_num);
//    for (int i = 0; i < ap_num; i++) {
//        printf("SSID: %s, RSSI: %d\n", ap_records[i].ssid, ap_records[i].rssi);
//        // Salva gli SSID in un array o fa qualsiasi altra elaborazione
//    }
//
//    free(ap_records);
//}
//
//static esp_err_t event_handler(void *ctx, system_event_t *event) {
//    return ESP_OK;
//}
//
//void wifi_init_sta() {
//    tcpip_adapter_init();
//    ESP_ERROR_CHECK(esp_event_loop_init(event_handler, NULL));
//
//    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
//    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
//    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
//
//    wifi_config_t wifi_config = {
//        .sta = {
//            .ssid = "YOUR_SSID",
//            .password = "YOUR_PASSWORD",
//        },
//    };
//
//    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
//    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));
//    ESP_ERROR_CHECK(esp_wifi_start());
//}


//static void event_handler(void* arg, esp_event_base_t event_base,
//                                int32_t event_id, void* event_data)
//{
//    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
//        esp_wifi_connect();
//    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
//        esp_wifi_connect();
//    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
//        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
//        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
//    }
//}
//
//
///* Initialize Wi-Fi as sta and set scan method */
//static void fast_scan(void)
//{
//    ESP_ERROR_CHECK(esp_netif_init());
//    ESP_ERROR_CHECK(esp_event_loop_create_default());
//
//    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
//    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
//
//    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL, NULL));
//    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL, NULL));
//
//    // Initialize default station as network interface instance (esp-netif)
//    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
//    assert(sta_netif);
//
//    // Initialize and start WiFi
//    wifi_config_t wifi_config = {
//        .sta = {
//            .ssid = DEFAULT_SSID,
//            .password = DEFAULT_PWD,
//            .scan_method = DEFAULT_SCAN_METHOD,
//            .sort_method = DEFAULT_SORT_METHOD,
//            .threshold.rssi = DEFAULT_RSSI,
//            .threshold.authmode = DEFAULT_AUTHMODE,
//        },
//    };
//    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
//    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
//    ESP_ERROR_CHECK(esp_wifi_start());
//}

/* Initialize Wi-Fi as sta and set scan method */
void wifi_scan(void)
{
	const char *TAG = "scan";
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    uint16_t number = DEFAULT_SCAN_LIST_SIZE;
    wifi_ap_record_t ap_info[DEFAULT_SCAN_LIST_SIZE];
    uint16_t ap_count = 0;
    memset(ap_info, 0, sizeof(ap_info));

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());
    esp_wifi_scan_start(NULL, true);
    ESP_LOGI(TAG, "Max AP number ap_info can hold = %u", number);
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&number, ap_info));
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_count));
    ESP_LOGI(TAG, "Total APs scanned = %u, actual AP number ap_info holds = %u", ap_count, number);
    for (int i = 0; i < number; i++) {
        ESP_LOGI(TAG, "SSID \t\t%s", ap_info[i].ssid);
        ESP_LOGI(TAG, "RSSI \t\t%d", ap_info[i].rssi);
//        print_auth_mode(ap_info[i].authmode); // stampa roba che al momento non mi serve
//        if (ap_info[i].authmode != WIFI_AUTH_WEP) {
//            print_cipher_type(ap_info[i].pairwise_cipher, ap_info[i].group_cipher);
//        }
        ESP_LOGI(TAG, "Channel \t\t%d", ap_info[i].primary);
    }

}
