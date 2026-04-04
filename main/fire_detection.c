#include <stdio.h>
#include "driver/gpio.h"

// space for defining the pins

#define MQ5_SENSOR GPIO32

// space for configing the pins

gpio_config_t MQ5_PIN_CONFIG = {
    .pin_bit_mask = (1ULL << 32),
    .mode = GPIO_MODE_INPUT,
    .pull_up_en = GPIO_PULLUP_DISABLE,
    .pull_down_en = GPIO_PULLDOWN_DISABLE,
    .intr_type = GPIO_INTR_DISABLE
};

void app_main(void)
{
    gpio_config(&MQ5_PIN_CONFIG);
}
