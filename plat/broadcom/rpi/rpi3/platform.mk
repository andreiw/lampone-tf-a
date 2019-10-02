#
# Copyright (c) 2013-2019, ARM Limited and Contributors. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

include plat/broadcom/rpi/common/platform_common.mk

BL1_SOURCES		+=	lib/cpus/aarch64/cortex_a53.S

BL2_SOURCES		+=	${PLAT_SOC}/drivers/sdhost/rpi3_sdhost.c

BL31_SOURCES		+=	lib/cpus/aarch64/cortex_a53.S \
				${PLAT_SOC}/rpi4_bl31_setup.c

# Tune compiler for Cortex-A53
ifeq ($(notdir $(CC)),armclang)
    TF_CFLAGS_aarch64	+=	-mcpu=cortex-a53
else ifneq ($(findstring clang,$(notdir $(CC))),)
    TF_CFLAGS_aarch64	+=	-mcpu=cortex-a53
else
    TF_CFLAGS_aarch64	+=	-mtune=cortex-a53
endif

# Build config flags
# ------------------

# Enable all errata workarounds for Cortex-A53
ERRATA_A53_826319		:= 1
ERRATA_A53_835769		:= 1
ERRATA_A53_836870		:= 1
ERRATA_A53_843419		:= 1
ERRATA_A53_855873		:= 1
