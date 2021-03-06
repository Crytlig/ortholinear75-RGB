/*
             LUFA Library
     Copyright (C) Dean Camera, 2014.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2014  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *  \brief Command constants for the Atmel AT45DB321C Dataflash.
 *  \copydetails Group_AT45DB321C
 */

/** \ingroup Group_MiscDrivers
 *  \defgroup Group_AT45DB321C Atmel AT45DB321C Dataflash Commands - LUFA/Drivers/Misc/AT45DB321C.h
 *  \brief Command constants for the Atmel AT45DB321C Dataflash.
 *
 *  Dataflash command constants for the Atmel AT45DB321C Dataflash IC.
 *
 *  @{
 */

#ifndef __AT45DB321C_CMDS_H__
#define __AT45DB321C_CMDS_H__

	/* Public Interface - May be used in end-application: */
		/* Macros: */
			/** \name Dataflash Status Values */
			//@{
			#define DF_STATUS_READY                         (1 << 7)
			#define DF_STATUS_COMPMISMATCH                  (1 << 6)
			#define DF_STATUS_SECTORPROTECTION_ON           (1 << 1)
			//@}

			/** \name Dataflash Commands */
			//@{
			#define DF_CMD_GETSTATUS                        0xD7

			#define DF_CMD_MAINMEMTOBUFF1                   0x53
			#define DF_CMD_MAINMEMTOBUFF2                   0x55
			#define DF_CMD_MAINMEMTOBUFF1COMP               0x60
			#define DF_CMD_MAINMEMTOBUFF2COMP               0x61
			#define DF_CMD_AUTOREWRITEBUFF1                 0x58
			#define DF_CMD_AUTOREWRITEBUFF2                 0x59

			#define DF_CMD_MAINMEMPAGEREAD                  0xD2
			#define DF_CMD_CONTARRAYREAD_LF                 0xE8
			#define DF_CMD_BUFF1READ_LF                     0xD4
			#define DF_CMD_BUFF2READ_LF                     0xD6

			#define DF_CMD_BUFF1WRITE                       0x84
			#define DF_CMD_BUFF2WRITE                       0x87
			#define DF_CMD_BUFF1TOMAINMEMWITHERASE          0x83
			#define DF_CMD_BUFF2TOMAINMEMWITHERASE          0x86
			#define DF_CMD_BUFF1TOMAINMEM                   0x88
			#define DF_CMD_BUFF2TOMAINMEM                   0x89
			#define DF_CMD_MAINMEMPAGETHROUGHBUFF1          0x82
			#define DF_CMD_MAINMEMPAGETHROUGHBUFF2          0x85

			#define DF_CMD_PAGEERASE                        0x81
			#define DF_CMD_BLOCKERASE                       0x50

			#define DF_CMD_SECTORPROTECTIONOFF              ((char[]){0x3D, 0x2A, 0x7F, 0xCF})
			#define DF_CMD_SECTORPROTECTIONOFF_BYTE1        0x3D
			#define DF_CMD_SECTORPROTECTIONOFF_BYTE2        0x2A
			#define DF_CMD_SECTORPROTECTIONOFF_BYTE3        0x7F
			#define DF_CMD_SECTORPROTECTIONOFF_BYTE4        0xCF

			#define DF_CMD_READMANUFACTURERDEVICEINFO       0x9F
			//@}

			/** Manufacturer code for Atmel Corporation, returned by Atmel Dataflash ICs in response to the \c DF_CMD_READMANUFACTURERDEVICEINFO command. */
			#define DF_MANUFACTURER_ATMEL                   0x1F

#endif

/** @} */

