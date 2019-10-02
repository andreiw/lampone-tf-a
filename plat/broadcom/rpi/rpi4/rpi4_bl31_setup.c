/*
 * Copyright (c) 2015-2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>

#include <platform_def.h>

#include <common/bl_common.h>
#include <plat/common/platform.h>

#include <rpi_private_common.h>

#include <drivers/arm/gic_common.h>
#include <drivers/arm/gicv2.h>

#define ARM_IRQ_SEC_PHY_TIMER 29

static const interrupt_prop_t g0_interrupt_props[] = {
	INTR_PROP_DESC(ARM_IRQ_SEC_PHY_TIMER, GIC_HIGHEST_SEC_PRIORITY,	\
		       GICV2_INTR_GROUP0, GIC_INTR_CFG_LEVEL),          \
};

gicv2_driver_data_t gic_data = {
	.gicd_base = RPI4_GICD_BASE,
	.gicc_base = RPI4_GICC_BASE,
	.interrupt_props = g0_interrupt_props,
	.interrupt_props_num = ARRAY_SIZE(g0_interrupt_props),
};


void bl31_platform_setup(void)
{
	gicv2_driver_init(&gic_data);
	gicv2_distif_init();
	gicv2_pcpu_distif_init();
	gicv2_cpuif_enable();

	bl31_platform_setup_common();
}
