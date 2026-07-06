/*
	Example using WEB Socket.
	This example code is in the Public Domain (or CC0 licensed, at your option.)
	Unless required by applicable law or agreed to in writing, this
	software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
	CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "freertos/message_buffer.h"
#include "esp_log.h"
#include "cJSON.h"

#include "cmd.h"

static const char *TAG = "web_client";

#include "websocket_server.h"

extern QueueHandle_t xQueueCmd;
extern MessageBufferHandle_t xMessageBufferToClient;

void client_task(void* pvParameters) {
	char jsonBuffer[512];
	char DEL = 0x04;
	char outBuffer[64];
	CMD_t cmdBuf;

	while (1) {
		size_t readBytes = xMessageBufferReceive(xMessageBufferToClient, jsonBuffer, sizeof(jsonBuffer), portMAX_DELAY );
		ESP_LOGI(TAG, "readBytes=%d", readBytes);
		ESP_LOGI(TAG, "jsonBuffer=[%.*s]", readBytes, jsonBuffer);
		cJSON *root = cJSON_Parse(jsonBuffer);
		if (cJSON_GetObjectItem(root, "id")) {
			char *id = cJSON_GetObjectItem(root,"id")->valuestring;
			ESP_LOGI(TAG, "id=[%s]",id);

			if ( strcmp (id, "init") == 0) {
				sprintf(outBuffer,"HEAD%cWebsocket Camera", DEL);
				ESP_LOGD(TAG, "outBuffer=[%s]", outBuffer);
				ws_server_send_text_all(outBuffer,strlen(outBuffer));
			} // init

			if ( strcmp (id, "take_picture") == 0) {
				cmdBuf.taskHandle = xTaskGetCurrentTaskHandle();
				cmdBuf.command = CMD_TAKE;
				if (xQueueSend(xQueueCmd, &cmdBuf, 10) != pdPASS) {
					ESP_LOGE(TAG, "xQueueSend fail");
				}
			} // take_picture

			if ( strcmp (id, "frame_size") == 0) {
				char *size = cJSON_GetObjectItem(root,"size")->valuestring;
				ESP_LOGI(TAG, "size=[%s]",size);
				sprintf(outBuffer,"TEXT%c%s", DEL, size);
				ESP_LOGD(TAG, "outBuffer=[%s]", outBuffer);
				ws_server_send_text_all(outBuffer,strlen(outBuffer));
			} // frame_size

			if ( strcmp (id, "got_picture") == 0) {
				sprintf(outBuffer,"PICTURE");
				ESP_LOGD(TAG, "outBuffer=[%s]", outBuffer);
				ws_server_send_text_all(outBuffer,strlen(outBuffer));
			} // got_picture

		} // end if

		// Delete a cJSON structure
		cJSON_Delete(root);

	} // end while

	// Never reach here
	vTaskDelete(NULL);
}
