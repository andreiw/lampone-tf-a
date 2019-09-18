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

#define RPI3_IO_BASE			ULL(0x3F000000)
#define RPI3_IO_SIZE			ULL(0x01000000)


/*
 * Local interrupt controller
 */
#define RPI3_INTC_BASE_ADDRESS			ULL(0x40000000)

#endif /* RPI_HW_H */
