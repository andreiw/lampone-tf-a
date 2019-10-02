/*
 * Copyright (c) 2015-2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>

#include <platform_def.h>

#include <arch_helpers.h>
#include <common/debug.h>
#include <drivers/console.h>
#include <lib/mmio.h>
#include <lib/psci/psci.h>
#include <plat/common/platform.h>
#include <rpi_hw.h>

/*******************************************************************************
 * Platform handlers for system reset and system off.
 ******************************************************************************/

/* 10 ticks (Watchdog timer = Timer clock / 16) */
#define RESET_TIMEOUT	U(10)

void __dead2 rpi3_watchdog_reset(void)
{
	uint32_t rstc;

	console_flush();

	dsbsy();
	isb();

	mmio_write_32(RPI3_PM_BASE + RPI3_PM_WDOG_OFFSET,
		      RPI3_PM_PASSWORD | RESET_TIMEOUT);

	rstc = mmio_read_32(RPI3_PM_BASE + RPI3_PM_RSTC_OFFSET);
	rstc &= ~RPI3_PM_RSTC_WRCFG_MASK;
	rstc |= RPI3_PM_PASSWORD | RPI3_PM_RSTC_WRCFG_FULL_RESET;
	mmio_write_32(RPI3_PM_BASE + RPI3_PM_RSTC_OFFSET, rstc);

	for (;;) {
		wfi();
	}
}

void __dead2 rpi3_system_reset(void)
{
	INFO("rpi3: PSCI_SYSTEM_RESET: Invoking watchdog reset\n");

	rpi3_watchdog_reset();
}

void __dead2 rpi3_system_off(void)
{
	uint32_t rsts;

	INFO("rpi3: PSCI_SYSTEM_OFF: Invoking watchdog reset\n");

	/*
	 * This function doesn't actually make the Raspberry Pi turn itself off,
	 * the hardware doesn't allow it. It simply reboots it and the RSTS
	 * value tells the bootcode.bin firmware not to continue the regular
	 * bootflow and to stay in a low power mode.
	 */

	rsts = mmio_read_32(RPI3_PM_BASE + RPI3_PM_RSTS_OFFSET);
	rsts |= RPI3_PM_PASSWORD | RPI3_PM_RSTS_WRCFG_HALT;
	mmio_write_32(RPI3_PM_BASE + RPI3_PM_RSTS_OFFSET, rsts);

	rpi3_watchdog_reset();
}
