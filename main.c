
// TITLE          :       SIMPLE STATUS FLAG MANAGER
// AUTHOR         :       ichimaru001       
// DATE                   11/06/25
// -
// DESCRIPTION    :       SIMULATES A SYSTEM WITH 5 DEVICES, EACH WITH
//                        A STATUS REGISTER
//                                  
// -
// TIME TAKEN     :       (started at 4HR 30MIN, 
// TO COMPLETE            paused at 5HR 13MIN)
//                        

#include <stdio.h>
#include <stdint.h>

#define ID_MASK               (7<<0)    // 00 00 01 11 (used to configure ID, max 7)  
#define IS_CONNECTED_MASK     (1<<3)    // 00 00 10 00
#define HAS_ERROR_MASK        (1<<4)    // 00 01 00 00
#define IS_BUSY_MASK          (1<<5)    // 00 10 00 00
#define RESERVED_MASK         (3<<6)    // 11 00 00 00 (max 3)

#define SET_STATUS_ON 1
#define SET_STATUS_OFF 0

#define NUM_DEVICES 5

void initConfig(uint8_t *device) {
  *device = 0;
}
void setDeviceIDConfig(uint8_t *device, int valueID) {
  if (valueID > 0x7) {
    printf("Invalid ID value!\n");
  }
  *device &= ~0x7;
  *device |= valueID;
}
void isConnectConfig(uint8_t *device, int value) {
  if (value == SET_STATUS_ON) {
    *device &= ~IS_CONNECTED_MASK;
    *device |= IS_CONNECTED_MASK;
  }
  else if (value == SET_STATUS_OFF) {
    *device &= ~IS_CONNECTED_MASK;
  }
  else {
    printf("Invalid isConnect value!\n");
  }
}
void hasErrorConfig(uint8_t *device, int value) {
  if (value == SET_STATUS_ON) {
    *device &= ~HAS_ERROR_MASK;
    *device |= HAS_ERROR_MASK;
  }
  else if (value == SET_STATUS_OFF) {
    *device &= ~HAS_ERROR_MASK;
  }
  else {
    printf("Invalid hasError value!\n");
  }
}
void isBusyConfig(uint8_t *device, int value) {
  if (value == SET_STATUS_ON) {
    *device &= ~IS_BUSY_MASK;
    *device |= IS_BUSY_MASK;
  }
  else if (value == SET_STATUS_OFF) {
    *device &= ~IS_BUSY_MASK;
  }
  else {
    printf("Invalid isBusy value!\n");
  }
}
void reservedConfig(uint8_t *device, int value) {
  if (value > 0b11000000) {
    printf("Invalid reserved value!\n");
  }
  *device &= ~RESERVED_MASK;
  *device |= RESERVED_MASK;
}

void printConfigDevice(uint8_t *device) {
  printf("\nID : %u\nisConnected? : %u\nhasError? : %u\nisBusy? : %u\nreservedBits : %u\n",
    *device & ID_MASK,
    (*device & IS_CONNECTED_MASK) ? 1 : 0,
    (*device & HAS_ERROR_MASK) ? 1 : 0,
    (*device & IS_BUSY_MASK) ? 1 : 0,
    *device & RESERVED_MASK
  );
}

int main() {
  uint8_t statusRegisters[] = { 0 };

  initConfig(&statusRegisters[0]);
  setDeviceIDConfig(&statusRegisters[0], 3);
  isConnectConfig(&statusRegisters[0], 0);
  hasErrorConfig(&statusRegisters[0], 1);
  isBusyConfig(&statusRegisters[0], 1);
  reservedConfig(&statusRegisters[0], 0b11000000);
  printConfigDevice(&statusRegisters[0]);


  return 0;
}