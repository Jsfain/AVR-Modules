/*
 * File    : SD_SPI_CAR.H
 * Version : 0.0.0.1 
 * Author  : Joshua Fain
 * Target  : ATMega1280
 * License : MIT
 * Copyright (c) 2020-2021
 * 
 * Macro definitions for the SD Card Commands, Arguments, and Responses
 * available in SPI mode.
 */

#ifndef SD_SPI_CAR_H
#define SD_SPI_CAR_H

// Commands available to an SD Card operating in SPI mode
#define GO_IDLE_STATE               0       //CMD0
#define SEND_OP_COND                1       //CMD1
#define SWITCH_FUNC                 6       //CMD6
#define SEND_IF_COND                8       //CMD8
#define SEND_CSD                    9       //CMD9
#define SEND_CID                    10      //CMD10
#define STOP_TRANSMISSION           12      //CMD12
#define SEND_STATUS                 13      //CMD13
#define SET_BLOCKLEN                16      //CMD16
#define READ_SINGLE_BLOCK           17      //CMD17
#define READ_MULTIPLE_BLOCK         18      //CMD18
#define WRITE_BLOCK                 24      //CMD24
#define WRITE_MULTIPLE_BLOCK        25      //CMD25
#define PROGRAM_CSD                 27      //CMD27
#define SET_WRITE_PROT              28      //CMD28
#define CLR_WRITE_PROT              29      //CMD29
#define SEND_WRITE_PROT             30      //CMD30
#define ERASE_WR_BLK_START_ADDR     32      //CMD32
#define ERASE_WR_BLK_END_ADDR       33      //CMD33
#define ERASE                       38      //CMD38
#define LOCK_UNLOCK                 42      //CMD42
#define APP_CMD                     55      //CMD55
#define GEN_CMD                     56      //CMD56
#define READ_OCR                    58      //CMD58
#define CRC_ON_OFF                  59      //CMD59
// Application Specific Commands. To use, first call APP_CMD (CMD55).
#define SD_STATUS                   13      //ACMD13
#define SEND_NUM_WR_BLOCKS          22      //ACMD22
#define SET_WR_BLK_ERASE_COUNT      23      //ACMD23
#define SD_SEND_OP_COND             41      //ACMD41
#define SET_CLR_CARD_DETECT         42      //ACMD42
#define SEND_SCR                    51      //ACMD51

// some arguments

//
// SEND_IF_COND arguments
//
#define VOLT_RANGE_SUPPORTED     0x01 // 0x01 means supports 2.7 to 3.6V 
#define CHECK_PATTERN            0xAA // arb val. sent to, and retnd by SD card
#define SEND_IF_COND_ARG  (VOLT_RANGE_SUPPORTED << 8) | CHECK_PATTERN

//
// CRC_ON_OFF arguments
//
#define CRC_ON_ARG      1
#define CRC_OFF_ARG     0

//
// SD_SEND_OP_COND arguments
//
#if HOST_CAPACITY_SUPPORT == SDHC
#define ACMD41_HCS_ARG 0x40000000
#else
#define ACMD41_HCS_ARG 0
#endif

/* 
 * ----------------------------------------------------------------------------
 *                                                            R1 RESPONSE FLAGS
 * 
 * Description : Flags returned by sd_GetR1().
 * 
 * Notes       : 1) With the exception of R1_TIMEOUT, these flags correspond to
 *                  the first byte returned by the SD card in response to any 
 *                  command.
 *      
 *               2) R1_TIMEOUT will be set in the sd_GetR1() return value if 
 *                  the SD card does not send an R1 response after set amount
 *                  of time.
 * ----------------------------------------------------------------------------
 */
#define OUT_OF_IDLE             0x00
#define IN_IDLE_STATE           0x01
#define ERASE_RESET             0x02
#define ILLEGAL_COMMAND         0x04
#define COM_CRC_ERROR           0x08
#define ERASE_SEQUENCE_ERROR    0x10
#define ADDRESS_ERROR           0x20
#define PARAMETER_ERROR         0x40
#define R1_TIMEOUT              0x80


//
// R7 RESPONSE BYTES
// 
// Response to SEND_IF_COND is the R7 response. These are the order of the
// R7 response bytes returned by the SD card.
//
#define R7_R1_RESP           0
#define R7_CMD_VERS          1  
#define R7_RSRVD             2
#define R7_VOLT_ACCEPTED     3
#define R7_CHK_PTRN_ECHO     4

#endif //SD_SPI_CAR_H
