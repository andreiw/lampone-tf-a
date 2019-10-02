/*
 * Copyright (c) 2016-2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RPI_HW_H
#define RPI_HW_H

#include <lib/utils_def.h>
#include <rpi_hw_common.h>

/*
 * Peripherals
 */
#define RPI3_IO_BASE			ULL(0xFE000000)
#define RPI3_IO_SIZE			ULL(0x02000000)

/*
 * Local interrupt controller
 */
#define RPI3_INTC_BASE_ADDRESS		ULL(0xFF800000)
#define RPI4_GICD_BASE			ULL(0xff841000)
#define RPI4_GICC_BASE			ULL(0xff842000)

#endif /* RPI_HW_H */
