#include "error_handler.h"
#include <stdio.h>

void printError(int errorCode) {
  switch (errorCode)
  {
  case E_INVALID_ID:
    printf("\nError occurred!\nInvalid ID entered!\n");
    break;
  case E_INVALID_VALUE:
    printf("\nError occurred!\nInvalid value entered!\n");
    break;
  default:
    break;
  }
}