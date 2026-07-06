typedef enum {CMD_TAKE, CMD_HALT, CMD_INFO, CMD_UPLOAD} COMMAND;

// Shutter trigger request
typedef struct {
	uint16_t command;
	TaskHandle_t taskHandle;
} CMD_t;
