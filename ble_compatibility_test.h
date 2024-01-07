/*
 * SPDX-FileCopyrightText: 2021 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAIN_BLE_COMPATIBILITY_H_
#define MAIN_BLE_COMPATIBILITY_H_

/* Attributes State Machine */
enum
{
    IDX_SVC,
    IDX_CHAR_A,
    IDX_CHAR_VAL_A,
    IDX_CHAR_CFG_A,

	IDX_CHAR_WIFI_LIST,
	IDX_CHAR_VAL_WIFI_LIST,
	IDX_CHAR_CFG_WIFI_LIST,

	IDX_CHAR_WIFI_SEL,
	IDX_CHAR_VAL_WIFI_SEL,
	IDX_CHAR_CFG_WIFI_SEL,

	IDX_CHAR_WIFI_PSW,
	IDX_CHAR_VAL_WIFI_PSW,
	IDX_CHAR_CFG_WIFI_PSW,

	IDX_CHAR_TABLE_1,
	IDX_CHAR_VAL_TABLE_1,
	IDX_CHAR_CFG_TABLE_1,

    IDX_CHAR_B,
    IDX_CHAR_VAL_B,
    IDX_CHAR_CFG_B,

    IDX_CHAR_C,
    IDX_CHAR_VAL_C,
    IDX_CHAR_CFG_C,
    IDX_CHAR_CFG_C_2,

    HRS_IDX_NB,
};

/* for */
typedef enum
{
	READ_FROM_FLASH,
	WRITE_TO_FLASH,
	INIT_FROM_BLE_STACK,
	UPDATE_FROM_WRITE,
} gatt_value_operation;

enum
{
	VALUE,
	SIZE,
	TOTAL_SIZE,
};
#endif /*MAIN_BLE_COMPATIBILITY_H_*/
