/*
 * Eeprom.c
 *
 *  Created on: Jan 7, 2024
 *      Author: root
 */

#include "Eeprom.h"



void start_non_volatile_storage(void)
{
	esp_err_t ret;
	size_t required_size;


	// ---------------------------------------------------------->
	// Start ---------------------------------------------------->
	// ---------------------------------------------------------->

	/* Initialize NVS. */
	ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES) {
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK( ret );


	// ---------------------------------------------------------->
	// Motor ---------------------------------------------------->
	// ---------------------------------------------------------->

	ret = nvs_open("storage", NVS_READWRITE, &MotorFlash);

	/*Non serve volendo*/
	if (ret != ESP_OK) {
		printf("Error (%s) opening NVS handle!\n", esp_err_to_name(ret));
	} else {
		printf("Done\n");
	} /*Non serve volendo*/

	required_size = sizeof(MotorDefault);
	ret = nvs_get_blob(MotorFlash, "nvs_struct", /*(void *)*/&MotorDefault, &required_size);
	//
	switch (ret) {
	case ESP_OK:
		printf("Done\n\n");
		asm("nop");
		break;
	case ESP_ERR_NVS_NOT_FOUND:
//		printf("The value is not initialized yet!\n");
//		required_size = sizeof(MotorDefault);
//		memset(MotorDefault.name, 0, sizeof(MotorDefault.name));
//		strcpy(MotorDefault.name,"Motor");
//		MotorDefault.operating_hours = 14;
//		MotorDefault.power = 130;
		memcpy(&MotorDefault,&MotorDefaultEeprom,sizeof(MotorDefault));
		break;
	case ESP_ERR_NVS_KEY_TOO_LONG:
		ret = nvs_set_blob(MotorFlash, "nvs_struct", &MotorDefault, sizeof (MotorDefault) );
		ret = nvs_get_blob(MotorFlash, "nvs_struct", NULL, &required_size );
		ret = nvs_get_blob(MotorFlash, "nvs_struct", /*(void *)*/&MotorDefault, &required_size);

		if (ret != ESP_OK) {
			printf("Error (%s) opening NVS handle!\n", esp_err_to_name(ret));
		} else {
			printf("Done\n");
		}
		break;
	default :
		printf("Error (%s) reading!\n", esp_err_to_name(ret));

	}

	// ---------------------------------------------------------->
	// WIFI ----------------------------------------------------->
	// ---------------------------------------------------------->
	ret = nvs_open("storage2", NVS_READWRITE, &WifiDataFlash);
	required_size = sizeof(Wifidataram);
	ret = nvs_get_blob(WifiDataFlash, "wifi_flash", /*(void *)*/&Wifidataram, &required_size);
	//
	switch (ret) {
	case ESP_OK:
		printf("Done\n\n");

		asm("nop");
		break;
	case ESP_ERR_NVS_NOT_FOUND:
		printf("The value is not initialized yet!\n");

		break;
	case ESP_ERR_NVS_KEY_TOO_LONG:
		ret = nvs_set_blob(WifiDataFlash, "wifi_flash", &Wifidataram, sizeof (Wifidataram) );
		ret = nvs_get_blob(WifiDataFlash, "wifi_flash", /*(void *)*/NULL, &required_size);;
		ret = nvs_get_blob(WifiDataFlash, "wifi_flash", /*(void *)*/&Wifidataram, &required_size);;

		if (ret != ESP_OK) {
			printf("Error (%s) opening NVS handle!\n", esp_err_to_name(ret));
		} else {
			printf("Done\n");
		}
		break;
	default :
		printf("Error (%s) reading!\n", esp_err_to_name(ret));

	}

	return;
}
