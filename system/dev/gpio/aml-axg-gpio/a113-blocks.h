// Copyright 2018 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <soc/aml-a113/a113-gpio.h>

static aml_gpio_block_t a113_gpio_blocks[] = {
    // GPIO X Block
    {
        .start_pin = (A113_GPIOX_START + 0),
        .pin_block = A113_GPIOX_START,
        .pin_count = 8,
        .mux_offset = A113_PERIPHS_PIN_MUX_4,
        .oen_offset = A113_GPIO_REG2_EN_N,
        .input_offset = A113_GPIO_REG2_I,
        .output_offset = A113_GPIO_REG2_O,
        .output_shift = 0,
        .mmio_index = 0,
        .lock = MTX_INIT,
    },
    {
        .start_pin = (A113_GPIOX_START + 8),
        .pin_block = A113_GPIOX_START,
        .pin_count = 8,
        .mux_offset = A113_PERIPHS_PIN_MUX_5,
        .oen_offset = A113_GPIO_REG2_EN_N,
        .input_offset = A113_GPIO_REG2_I,
        .output_offset = A113_GPIO_REG2_O,
        .output_shift = 0,
        .mmio_index = 0,
        .lock = MTX_INIT,
    },
    {
        .start_pin = (A113_GPIOX_START + 16),
        .pin_block = A113_GPIOX_START,
        .pin_count = 7,
        .mux_offset = A113_PERIPHS_PIN_MUX_6,
        .oen_offset = A113_GPIO_REG2_EN_N,
        .input_offset = A113_GPIO_REG2_I,
        .output_offset = A113_GPIO_REG2_O,
        .output_shift = 0,
        .mmio_index = 0,
        .lock = MTX_INIT,
    },

    // GPIO A Block
    {
        .start_pin = (A113_GPIOA_START + 0),
        .pin_block = A113_GPIOA_START,
        .pin_count = 8,
        .mux_offset = A113_PERIPHS_PIN_MUX_B,
        .oen_offset = A113_GPIO_REG0_EN_N,
        .input_offset = A113_GPIO_REG0_I,
        .output_offset = A113_GPIO_REG0_O,
        .output_shift = 0,
        .mmio_index = 0,
        .lock = MTX_INIT,
    },
    {
        .start_pin = (A113_GPIOA_START + 8),
        .pin_block = A113_GPIOA_START,
        .pin_count = 8,
        .mux_offset = A113_PERIPHS_PIN_MUX_C,
        .oen_offset = A113_GPIO_REG0_EN_N,
        .input_offset = A113_GPIO_REG0_I,
        .output_offset = A113_GPIO_REG0_O,
        .output_shift = 0,
        .mmio_index = 0,
        .lock = MTX_INIT,
    },
    {
        .start_pin = (A113_GPIOA_START + 16),
        .pin_block = A113_GPIOA_START,
        .pin_count = 5,
        .mux_offset = A113_PERIPHS_PIN_MUX_D,
        .oen_offset = A113_GPIO_REG0_EN_N,
        .input_offset = A113_GPIO_REG0_I,
        .output_offset = A113_GPIO_REG0_O,
        .output_shift = 0,
        .mmio_index = 0,
        .lock = MTX_INIT,
    },

    // GPIO Boot Block
    {
        .start_pin = (A113_GPIOBOOT_START + 0),
        .pin_block = A113_GPIOBOOT_START,
        .pin_count = 8,
        .mux_offset = A113_PERIPHS_PIN_MUX_0,
        .oen_offset = A113_GPIO_REG4_EN_N,
        .input_offset = A113_GPIO_REG4_I,
        .output_offset = A113_GPIO_REG4_O,
        .output_shift = 0,
        .mmio_index = 0,
        .lock = MTX_INIT,
    },
    {
        .start_pin = (A113_GPIOBOOT_START + 8),
        .pin_block = A113_GPIOBOOT_START,
        .pin_count = 7,
        .mux_offset = A113_PERIPHS_PIN_MUX_1,
        .oen_offset = A113_GPIO_REG4_EN_N,
        .input_offset = A113_GPIO_REG4_I,
        .output_offset = A113_GPIO_REG4_O,
        .output_shift = 0,
        .mmio_index = 0,
        .lock = MTX_INIT,
    },

    // GPIO Y Block
    {
        .start_pin = (A113_GPIOY_START + 0),
        .pin_block = A113_GPIOY_START,
        .pin_count = 8,
        .mux_offset = A113_PERIPHS_PIN_MUX_8,
        .oen_offset = A113_GPIO_REG1_EN_N,
        .input_offset = A113_GPIO_REG1_I,
        .output_offset = A113_GPIO_REG1_O,
        .output_shift = 0,
        .mmio_index = 0,
        .lock = MTX_INIT,
    },
    {
        .start_pin = (A113_GPIOY_START + 8),
        .pin_block = A113_GPIOY_START,
        .pin_count = 8,
        .mux_offset = A113_PERIPHS_PIN_MUX_9,
        .oen_offset = A113_GPIO_REG1_EN_N,
        .input_offset = A113_GPIO_REG1_I,
        .output_offset = A113_GPIO_REG1_O,
        .output_shift = 0,
        .mmio_index = 0,
        .lock = MTX_INIT,
    },

    // GPIO Z Block
    {
        .start_pin = (A113_GPIOZ_START + 0),
        .pin_block = A113_GPIOZ_START,
        .pin_count = 8,
        .mux_offset = A113_PERIPHS_PIN_MUX_2,
        .oen_offset = A113_GPIO_REG3_EN_N,
        .input_offset = A113_GPIO_REG3_I,
        .output_offset = A113_GPIO_REG3_O,
        .output_shift = 0,
        .mmio_index = 0,
        .lock = MTX_INIT,
    },
    {
        .start_pin = (A113_GPIOZ_START + 8),
        .pin_block = A113_GPIOZ_START,
        .pin_count = 3,
        .mux_offset = A113_PERIPHS_PIN_MUX_3,
        .oen_offset = A113_GPIO_REG3_EN_N,
        .input_offset = A113_GPIO_REG3_I,
        .output_offset = A113_GPIO_REG3_O,
        .output_shift = 0,
        .mmio_index = 0,
        .lock = MTX_INIT,
    },

    // GPIO AO Block
    // NOTE: The GPIO AO block has a seperate control block than the other
    //       GPIO blocks.
    {
        .start_pin = (A113_GPIOAO_START + 0),
        .pin_block = A113_GPIOAO_START,
        .pin_count = 8,
        .mux_offset = A113_AO_RTI_PIN_MUX_REG0,
        .oen_offset = A113_AO_GPIO_O_EN,
        .input_offset = A113_AO_GPIO_I,
        .output_offset = A113_AO_GPIO_O_EN,
        .output_shift = 16,

        .mmio_index = 1,
        .lock = MTX_INIT,
    },
    {
        .start_pin = (A113_GPIOAO_START + 8),
        .pin_block = A113_GPIOAO_START,
        .pin_count = 6,
        .mux_offset = A113_AO_RTI_PIN_MUX_REG1,
        .oen_offset = A113_AO_GPIO_O_EN,
        .input_offset = A113_AO_GPIO_I,
        .output_offset = A113_AO_GPIO_O_EN,
        .output_shift = 16,
        .mmio_index = 1,
        .lock = MTX_INIT,
    },
};
