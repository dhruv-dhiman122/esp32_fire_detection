#include <stdio.h>
#include <stdlib.h>
#include "driver/gpio.h"

//space for macro used for coding

#define EXT_SUCCESS 0
#define EXT_FAILURE 1

// space for defining the pins

#define MQ5_SENSOR GPIO_NUM_32

// space for configing the pins

gpio_config_t MQ5_PIN_CONFIG = {
    .pin_bit_mask = (1ULL << MQ5_SENSOR),
    .mode = GPIO_MODE_INPUT,
    .pull_up_en = GPIO_PULLUP_DISABLE,
    .pull_down_en = GPIO_PULLDOWN_DISABLE,
    .intr_type = GPIO_INTR_DISABLE
};

void app_main(void)
{
    gpio_config(&MQ5_PIN_CONFIG);

    int mq5_pin_input_enable = gpio_input_enable(MQ5_SENSOR);
    if(mq5_pin_input_enable == 0) {
        printf("The input is enabled for the pin of MQ5 sensor\n");
    }
    else {
        fprintf("The input is not enabled for the pin of MQ5 sensor\n");
        exit(EXT_FAILURE);
    }

}
