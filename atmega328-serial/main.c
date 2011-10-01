/*
 * ATMega88/168/328P Hello World (with serial output)
 * (C) 2011 Akafugu Corporation
 *
 * This program is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 */

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "uart.h"

#define LED_BIT PB5
#define LED_HIGH PORTB |= _BV(LED_BIT)
#define LED_LOW PORTB &= ~(_BV(LED_BIT))

void main(void) __attribute__ ((noreturn));

void main(void) {
	uint8_t led_state = 1;

	uartInit();
	uartSetBaudRate(115200);

	DDRB |= (1 << LED_BIT);
   
	while (1) {
		if (led_state) {
			uartSendBuffer("LED goes on\n", 12);
			LED_HIGH;
		}
		else {
			uartSendBuffer("LED goes off\n", 13);
			LED_LOW;
		}

		led_state = !led_state;
		_delay_ms(1000);
	}
}

