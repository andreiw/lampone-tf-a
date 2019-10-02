/*
 * Copyright (c) 2015-2019, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RPI_PRIVATE_COMMON_H
#define RPI_PRIVATE_COMMON_H

#include <stdint.h>

/*******************************************************************************
 * Function and variable prototypes
 ******************************************************************************/

/* Utility functions */
void rpi3_console_init(void);
void rpi3_setup_page_tables(uintptr_t total_base, size_t total_size,
			    uintptr_t code_start, uintptr_t code_limit,
			    uintptr_t rodata_start, uintptr_t rodata_limit
#if USE_COHERENT_MEM
			    , uintptr_t coh_start, uintptr_t coh_limit
#endif
			    );

/* Optional functions required in the Raspberry Pi 3 port */
unsigned int plat_rpi3_calc_core_pos(u_register_t mpidr);

/* BL2 utility functions */
uint32_t rpi3_get_spsr_for_bl32_entry(void);
uint32_t rpi3_get_spsr_for_bl33_entry(void);

/* SDMMC support */
void plat_rpi_sdmmc_start();
void plat_rpi_sdmmc_stop();

/* IO storage utility functions */
void plat_rpi3_io_setup(void);

/* Hardware RNG functions */
void rpi3_rng_read(void *buf, size_t len);

/* VideoCore firmware commands */
int rpi3_vc_hardware_get_board_revision(uint32_t *revision);

/* BL31 common setup */
void bl31_platform_setup_common(void);
void __dead2 rpi3_watchdog_reset(void);
void __dead2 rpi3_system_reset(void);
void __dead2 rpi3_system_off(void);

#endif /* RPI3_PRIVATE_COMMON_H */
