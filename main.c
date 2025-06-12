
// TITLE          :       SIMPLE STATUS FLAG MANAGER
// AUTHOR         :       ichimaru001       
// DATE                   11/06/25
// -
// DESCRIPTION    :       SIMULATES A SYSTEM WITH 5 DEVICES, EACH WITH
//                        A STATUS REGISTER
// -
// TIME TAKEN     :       1HR 56MIN
// TO COMPLETE            


#include <stdio.h>
#include <stdint.h>
#include <errno.h>

#include "config.h"
#include "error_handler.h"

#define NUM_DEVICES 5

int main() {
  uint8_t statusRegisters[NUM_DEVICES] = { 0 };

  int err = 0;

  initConfig(&statusRegisters[0]);
  setDeviceIDConfig(&statusRegisters[0], 7); // max 7
  isConnectConfig(&statusRegisters[0], 1); // 1 or 0
  hasErrorConfig(&statusRegisters[0], 1); // 1 or 0
  isBusyConfig(&statusRegisters[0], 1); // 1 or 0
  reservedConfig(&statusRegisters[0], 4); // max 3
  printConfigDevice(&statusRegisters[0]);

  printError(err);

  return 0;
}