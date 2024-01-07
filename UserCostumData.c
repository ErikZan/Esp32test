/*
 * UserCostumData.c
 *
 *  Created on: Dec 29, 2023
 *      Author: root
 */

#include "UserCostumData.h"
#include "General_def.h"

/* Initialization */
struct MotorDefault_struct MotorDefault;
struct MotorDefault_struct MotorDefault2;

struct MotorDefault_struct MotorDefaultEeprom = {
		.name = "Motor",
		.operating_hours = 5,
		.power = 50,
};


