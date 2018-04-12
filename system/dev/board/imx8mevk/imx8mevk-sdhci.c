// Copyright 2018 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <ddk/debug.h>
#include <ddk/device.h>
#include <ddk/protocol/platform-bus.h>
#include <ddk/protocol/platform-defs.h>

#include <soc/imx8m/imx8m.h>
#include <soc/imx8m/imx8m-hw.h>
#include <soc/imx8m/imx8m-iomux.h>
#include <soc/imx8m/imx8m-gpio.h>
#include <limits.h>

#include "imx8mevk.h"

static const pbus_mmio_t sdhci_mmios[] = {
    {
        // eMMC Interface
        .base = IMX8M_AIPS_USDHC1_BASE,
        .length = IMX8M_AIPS_LENGTH,
    },
    {
        // uSD Interface
        .base = IMX8M_AIPS_USDHC2_BASE,
        .length = IMX8M_AIPS_LENGTH,
    },
};

static const pbus_irq_t sdhci_irqs[] = {
    {
        .irq = IMX8M_A53_INTR_USDHC1,
    },
    {
        .irq = IMX8M_A53_INTR_USDHC2,
    },
};

static const pbus_bti_t sdhci_btis[] = {
    {
        .iommu_index = 0,
        .bti_id = BTI_SDHCI,
    },
};

static pbus_dev_t sdhci_dev = {
    .name = "sdhci",
    .vid = PDEV_VID_NXP,
    .pid = PDEV_PID_IMX8MEVK,
    .did = PDEV_DID_IMX_SDHCI,
    .mmios = sdhci_mmios,
    .mmio_count = countof(sdhci_mmios),
    .irqs = sdhci_irqs,
    .irq_count = countof(sdhci_irqs),
    .btis = sdhci_btis,
    .bti_count = countof(sdhci_btis),
};


zx_status_t imx8m_sdhci_init(imx8mevk_bus_t* bus) {
    zx_status_t status = pbus_device_add(&bus->pbus, &sdhci_dev, 0);
    if (status != ZX_OK) {
        zxlogf(ERROR, "%s: pbus_device_add failed %d\n", __FUNCTION__, status);
        return status;
    }

    return ZX_OK;
}