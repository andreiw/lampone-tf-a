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

void bl31_platform_setup(void)
{
	bl31_platform_setup_common();
}
