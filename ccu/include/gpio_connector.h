#pragma once

#include <gpio/gpio.h>
#include <bsp/bsp.h>
#include <rtl/countof.h>
#include <iostream>

#include <memory>

#define HW_MODULE_NAME  "gpio0"
#define HW_MODULE_CFG   "rpi4_bcm2711.default"
#define GPIO_HIGH_LEVEL 1
#define GPIO_LOW_LEVEL  0

class GPIOConnector
{
    public:
        GPIOConnector() = default;
        bool Init();
        bool Enable25();
        bool Disable25();
        bool Enable16();
        bool Disable16();
        bool Close();
    private:
        GpioHandle handle = GPIO_INVALID_HANDLE;
        Retcode rc = rcFail;
        Retcode rc25 = rcFail;
};

using GPIOConnectorPtr = std::shared_ptr<GPIOConnector>;
