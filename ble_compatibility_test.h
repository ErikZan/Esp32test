/*
 * ble_compatibility_test.h
 *
 *  Created on: Dec 27, 2023
 *      Author: root
 */

#ifndef MAIN_BLE_COMPATIBILITY_TEST_H_
#define MAIN_BLE_COMPATIBILITY_TEST_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Attributes State Machine */
enum
{
//    IDX_SVC,
//    IDX_CHAR_A,
//    IDX_CHAR_VAL_A,
//    IDX_CHAR_CFG_A,
//
//    IDX_CHAR_B,
//    IDX_CHAR_VAL_B,
//    IDX_CHAR_CFG_B,
//
//    IDX_CHAR_C,
//    IDX_CHAR_VAL_C,
//    IDX_CHAR_CFG_C,
//    IDX_CHAR_CFG_C_2,
//
//    HRS_IDX_NB,
	PER_EVIATRE_ERRORI_DA_RIMOVERE,
	Esatto,
};

enum
{
	IDX_SVC, // non so ancora bene a cosa serve
	MOTOR_MODEL_DECL,
	MOTOR_MODEL_VAL,
	MOTOR_MODEL_CFG,
	IDX_CHAR_CFG_C_2, // NON SO ancora bene a cosa serve
//	MAX_VOLTAGE,
//	OPERATING_HOURS,
//	NUMBER_DEVICES,
//
//	WIFI_SSID,
//	WIFI_PSW,

	DATABASE_END,
};




#endif /* MAIN_BLE_COMPATIBILITY_TEST_H_ */
