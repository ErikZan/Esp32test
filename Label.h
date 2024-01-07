/*
 * Label.h
 *
 *  Created on: Jan 6, 2024
 *      Author: root
 */

#ifndef MAIN_LABEL_H_
#define MAIN_LABEL_H_

#include <stdint.h>

typedef enum
{
	SPIA_CANCELLO_APERTO_, // Spia cancello aperto
	LUCE_CORTESIA_,// Luce cortesia
	LUCE_ZONA_,// Luce zona
	LAMPEGGIANTE,// Lampeggiante
	PRELAMPEGGIO_IN_APERTURA_,// Prelampeggio in apertura
	PRELAMPEGGIO_IN_CHIUSURA_,// Prelampeggio in chiusura
	STAND_BY_,// Stand-by


	TABLE_NUM
} Database_cancello;

extern const uint8_t Label_table[TABLE_NUM][30];


#endif /* MAIN_LABEL_H_ */
