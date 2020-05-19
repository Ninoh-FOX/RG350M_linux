/****************************************************************************
*
*    Copyright (C) 2005 - 2012 by Vivante Corp.
*
*    This program is free software; you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation; either version 2 of the license, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not write to the Free Software
*    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*
*****************************************************************************/

#ifndef __gc_hal_kernel_hardware_h_
#define __gc_hal_kernel_hardware_h_

/* gckHARDWARE object. */
struct _gckHARDWARE
{
    /* Object. */
    gcsOBJECT                   object;

    /* Pointer to gctKERNEL object. */
    gckKERNEL                   kernel;

    /* Pointer to gctOS object. */
    gckOS                       os;

    /* Core */
    gceCORE                     core;

    /* Chip characteristics. */
    gcsHAL_QUERY_CHIP_IDENTITY  identity;
    int                         allowFastClear;
    int                         allowCompression;
    u32                         powerBaseAddress;
    int                         extraEventStates;

    /* Big endian */
    int                         bigEndian;

    /* Chip status */
    void *                      powerMutex;
    u32                         powerProcess;
    u32                         powerThread;
    gceCHIPPOWERSTATE           chipPowerState;
    u32                         lastWaitLink;
    int                         clockState;
    int                         powerState;
    void *                      globalSemaphore;

    gctISRMANAGERFUNC           startIsr;
    gctISRMANAGERFUNC           stopIsr;
    void *                      isrContext;

    u32                         mmuVersion;

    /* Type */
    gceHARDWARE_TYPE            type;

#if gcdPOWEROFF_TIMEOUT
    u32                         powerOffTime;
    u32                         powerOffTimeout;
    void *                      powerOffTimer;
#endif

    void *                      pageTableDirty;
};

gceSTATUS
gckHARDWARE_GetBaseAddress(
    IN gckHARDWARE Hardware,
    OUT u32 *BaseAddress
    );

gceSTATUS
gckHARDWARE_NeedBaseAddress(
    IN gckHARDWARE Hardware,
    IN u32 State,
    OUT int *NeedBase
    );

gceSTATUS
gckHARDWARE_GetFrameInfo(
    IN gckHARDWARE Hardware,
    OUT gcsHAL_FRAME_INFO * FrameInfo
    );

#endif /* __gc_hal_kernel_hardware_h_ */
