#include "config.h"
#include "error_handler.h"
#include <stdint.h>
#include <stdio.h>


void initConfig(uint8_t *device) {
  *device = 0;
}
int setDeviceIDConfig(uint8_t *device, int valueID) {
  if (valueID > 0b111) {
    return E_INVALID_ID;
  }
  *device &= ~0x7;
  *device |= valueID;

  return E_SUCCESS;
}
int isConnectConfig(uint8_t *device, int value) {
  if (value == SET_STATUS_ON) {
    *device &= ~IS_CONNECTED_MASK;
    *device |= IS_CONNECTED_MASK;
  }
  else if (value == SET_STATUS_OFF) {
    *device &= ~IS_CONNECTED_MASK;
  }
  else {
    return E_INVALID_VALUE;
  }

  return E_SUCCESS;
}
int hasErrorConfig(uint8_t *device, int value) {
  if (value == SET_STATUS_ON) {
    *device &= ~HAS_ERROR_MASK;
    *device |= HAS_ERROR_MASK;
  }
  else if (value == SET_STATUS_OFF) {
    *device &= ~HAS_ERROR_MASK;
  }
  else {
    return E_INVALID_VALUE;
  }

  return E_SUCCESS;
}
int isBusyConfig(uint8_t *device, int value) {
  if (value == SET_STATUS_ON) {
    *device &= ~IS_BUSY_MASK;
    *device |= IS_BUSY_MASK;
  }
  else if (value == SET_STATUS_OFF) {
    *device &= ~IS_BUSY_MASK;
  }
  else {
    return E_INVALID_VALUE;
  }

  return E_SUCCESS;
}
int reservedConfig(uint8_t *device, int value) {
  if (value > 0b11) {
    return E_INVALID_VALUE;
  }
  *device &= ~RESERVED_MASK;
  *device |= (value << 6);

  return E_SUCCESS;
}
void printConfigDevice(uint8_t *device) {
  printf("\nID : %u\nisConnected? : %u\nhasError? : %u\nisBusy? : %u\nreservedBits : %u\n",
    *device & ID_MASK,
    (*device & IS_CONNECTED_MASK) ? 1 : 0,
    (*device & HAS_ERROR_MASK) ? 1 : 0,
    (*device & IS_BUSY_MASK) ? 1 : 0,
    (*device & RESERVED_MASK) >> 6
  );
}
