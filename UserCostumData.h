/*
 * UserCostumData.h
 *
 *  Created on: Dec 29, 2023
 *      Author: root
 */

#ifndef MAIN_USERCOSTUMDATA_H_
#define MAIN_USERCOSTUMDATA_H_

#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
//Adding Motor structure

struct MotorDefault_struct{
	char name[20];
	uint8_t power;
	uint16_t operating_hours;

}  ;

extern struct MotorDefault_struct MotorDefault;
extern struct MotorDefault_struct MotorDefault2;




#endif /* MAIN_USERCOSTUMDATA_H_ */
