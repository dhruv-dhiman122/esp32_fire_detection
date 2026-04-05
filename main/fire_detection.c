#include <stdio.h>
#include <stdlib.h>
#include "driver/adc_types_legacy.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "soc/adc_channel.h"
#include "hal/adc_types.h"

//space for macro used for coding

#define EXT_SUCCESS 0
#define EXT_FAILURE 1

// space for defining the pins

#define MQ5_SENSOR GPIO_NUM_32
#define MQ5_CHANNEL ADC1_CHANNEL_4
// space for configing the pins

gpio_config_t MQ5_PIN_CONFIG = {
    .pin_bit_mask = (1ULL << MQ5_SENSOR),
    .mode = GPIO_MODE_INPUT,
    .pull_up_en = GPIO_PULLUP_DISABLE,
    .pull_down_en = GPIO_PULLDOWN_DISABLE,
    .intr_type = GPIO_INTR_DISABLE
};

void mq5_channel_init(void) {
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(MQ5_CHANNEL, ADC_ATTEN_DB_11);
}

void app_main(void)
{
    gpio_config(&MQ5_PIN_CONFIG);

    mq5_channel_init();

    int mq5_pin_input_enable = gpio_input_enable(MQ5_SENSOR);
    //setting the code for seeing if the gpio takes input or not
    if(mq5_pin_input_enable == 0) {
        printf("The input is enabled for the pin of MQ5 sensor\n");
    }
    else {
        fprintf(stderr,"The input is not enabled for the pin of MQ5 sensor\n");
        exit(EXT_FAILURE);
    }

    //taking input using gpio pin of MQ5
    float Gas_level = adc1_get_raw(MQ5_CHANNEL); // getting input for the MQ5 SENSOR pin for digital I/O
    if(Gas_level > 400 && Gas_level < 600) {
        printf("Warning!!!\n");
    }
    else if(Gas_level > 670) {
        //TODO -> add the buzzer warning
    }
    else {
        printf("All fine!!\n");
    }
}
