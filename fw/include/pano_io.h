/*
 *  pano_io.h
 *
 *  Copyright (C) 2019  Skip Hansen
 * 
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms and conditions of the GNU General Public License,
 *  version 2, as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 *  more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#ifndef _PANO_IO_H_
#define _PANO_IO_H_

#define SCREEN_X    80
#define SCREEN_Y    30

#define DLY_TAP_ADR        0x03000000
#define LEDS_ADR           0x03000004
#define SPI_CSN_ADR        0x0300000C
#define SPI_CLK_ADR        0x03000010
#define SPI_DO_ADR         0x03000014
#define SPI_DI_ADR         0x03000018

#define UART_ADR           0x03000100
#define VRAM_ADR           0x08000000
#define DDR_ADR            0x0C000000
#define DDR_TOTAL          0x2000000 // 32 MB


// For VRAM, only the lowest byte in each 32bit word is used
#define VRAM               ((volatile uint32_t *)VRAM_ADR)
#define DDR                ((volatile uint32_t *)DDR_ADR)
#define DLY_TAP           *((volatile uint32_t *)DLY_TAP_ADR)
#define LEDS              *((volatile uint32_t *)LEDS_ADR)

#define SPI_CSN            *((volatile uint32_t *)SPI_CSN_ADR)
#define SPI_CLK            *((volatile uint32_t *)SPI_CLK_ADR)
#define SPI_DO             *((volatile uint32_t *)SPI_DO_ADR)
#define SPI_DI             *((volatile uint32_t *)SPI_DI_ADR)
#define DEBUG_UART         *((volatile uint32_t *)UART_ADR)

#define LED_RED            0x1
#define LED_GREEN          0x2
#define LED_BLUE           0x4

#define uart              *((volatile uint32_t *)UART_ADR)

#endif // _PANO_IO_H_

