#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "dht.h"

#define GPIO_DHT 17

int16_t temp, hum;

void app_main(){


    while(1){

    

        if (dht_red_data (DHT_TYPE DH11, GPID_DHT, &hum, &temp)== ESP_OK)

        print ("Temp: %d and HUM: %d\n", temp/10, hum/10);

        else 
        print ("Eroo with sensor, pls check the circuit\n");

    }
}


