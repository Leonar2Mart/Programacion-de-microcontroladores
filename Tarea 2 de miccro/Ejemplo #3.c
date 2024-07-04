#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

adc_channel_t adc_pot = ADC_CHANNEL_6;

void init_hw(void);

void app_main(){


    init_hw();

    while{

        int pot = adc1_get_raw (adc_pot);
        print("ADC: %d" \n", pot);

        vTaskDelay(300/ porTICK_PERIOD_MS);



    }

    void  init_hm(void)

    adc1_config_width(ADC_WIDTH_12BIT);
    adc1_config_channel_atten(adc_pot, ADC_ATTEN_DB11);
    
}

