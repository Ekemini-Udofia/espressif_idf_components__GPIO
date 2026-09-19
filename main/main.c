#include <stdio.h>

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "iot_button.h"
#include "button_gpio.h"

#define button_pin GPIO_NUM_7
#define BUTTON_ACTIVE_LEVEL 0

static const char *TAG = "Button_example";

static void button_single_click_callback(void *arg, void *usr_data) {
	ESP_LOGI(TAG, "Button single click");
}

static void button_double_click_callback(void *arg, void *usr_data) {
	ESP_LOGI(TAG, "Button double click");
}

static void button_long_press_callback(void *arg, void *usr_data) {
	ESP_LOGI(TAG, "Button long press");
}

void app_main(void) {
	const button_config_t btn_cfg = {0};
	const button_gpio_config_t btn_gpio_cfg = {
		.gpio_num = button_pin,
		.active_level = BUTTON_ACTIVE_LEVEL,
	};

	button_handle_t gpio_btn = NULL;
	esp_err_t ret = iot_button_new_gpio_device(&btn_cfg, &btn_gpio_cfg, &gpio_btn);
	if (ret != ESP_OK) {
		ESP_LOGE(TAG, "Button create failed");
		return;
	}

	// Register single click event
	iot_button_register_cb(gpio_btn, BUTTON_SINGLE_CLICK, NULL, button_single_click_callback, NULL);
	
	// Register double click event
	iot_button_register_cb(gpio_btn, BUTTON_DOUBLE_CLICK, NULL, button_double_click_callback, NULL);

	// Register long press event
	iot_button_register_cb(gpio_btn, BUTTON_LONG_PRESS_HOLD, NULL, button_long_press_callback, NULL);

	while (1) {
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}