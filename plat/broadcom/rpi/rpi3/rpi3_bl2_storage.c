/*
 * Copyright (c) 2015-2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>

#include <platform_def.h>


#include <common/bl_common.h>
#include <common/debug.h>
#include <drivers/sdhost/rpi3_sdhost.h>

#include <rpi_private_common.h>

/* Data structure which holds the MMC info */
static struct mmc_device_info mmc_info;

void plat_rpi_sdmmc_start(void)
{
	struct rpi3_sdhost_params params;

	memset(&params, 0, sizeof(struct rpi3_sdhost_params));
	params.reg_base = RPI3_SDHOST_BASE;
	params.bus_width = MMC_BUS_WIDTH_1;
	params.clk_rate = 50000000;
	mmc_info.mmc_dev_type = MMC_IS_SD_HC;
	rpi3_sdhost_init(&params, &mmc_info);
}

void plat_rpi_sdmmc_stop()
{
	/* Shutting down the SDHost driver to let BL33 drives SDHost.*/
	rpi3_sdhost_stop();
}
