#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

#define ID_MASK               (7<<0)    // 00 00 01 11 (used to configure ID, max 7)  
#define IS_CONNECTED_MASK     (1<<3)    // 00 00 10 00
#define HAS_ERROR_MASK        (1<<4)    // 00 01 00 00
#define IS_BUSY_MASK          (1<<5)    // 00 10 00 00
#define RESERVED_MASK         (3<<6)    // 11 00 00 00 (max 3)

#define SET_STATUS_ON 1
#define SET_STATUS_OFF 0

void initConfig(uint8_t *device);
int setDeviceIDConfig(uint8_t *device, int valueID);
int isConnectConfig(uint8_t *device, int value);
int hasErrorConfig(uint8_t *device, int value);
int isBusyConfig(uint8_t *device, int value);
int reservedConfig(uint8_t *device, int value);
void printConfigDevice(uint8_t *device);

#endif