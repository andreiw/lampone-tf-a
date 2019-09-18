#
# Copyright (c) 2013-2019, ARM Limited and Contributors. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

include plat/broadcom/rpi/common/platform_common.mk

BL1_SOURCES		+=	lib/cpus/aarch64/cortex_a72.S

BL31_SOURCES		+=	lib/cpus/aarch64/cortex_a72.S

# Tune compiler for Cortex-A72
ifeq ($(notdir $(CC)),armclang)
    TF_CFLAGS_aarch64	+=	-mcpu=cortex-a72
else ifneq ($(findstring clang,$(notdir $(CC))),)
    TF_CFLAGS_aarch64	+=	-mcpu=cortex-a72
else
    TF_CFLAGS_aarch64	+=	-mtune=cortex-a72
endif

# Build config flags
# ------------------

# Enable all errata workarounds for Cortex-A72
ERRATA_A72_859971		:= 1
