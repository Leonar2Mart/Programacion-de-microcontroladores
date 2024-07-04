#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED 2
#define BT 17

void app_main()

{
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);

    gpio_set_direction(BT, GPIO_MODE_INPUT);

    gpio_set_direction(LED, GPIO_PULLDOWN_ONLY);

    while (1)

    {

        int state_bt = gpio_get_level (BT);
        if (!state_bt){

            gpio_set_level (LED, 1);

        }
        else {
            gpio_set_level(LED, 0);
        }

        g
        vTaskDelay(200/portTIck_RATE_MS);


    }


    

}