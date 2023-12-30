/*
 * UserCostumData.c
 *
 *  Created on: Dec 29, 2023
 *      Author: root
 */



/* Initialization */
struct MotorDefault_struct MotorDefault ={
		.name = "MotorName",
		.power = 100,
		.operating_hours = 5,
};
nvs_handle_t MotorFlash;
size_t required_size = sizeof(MotorDefault);

