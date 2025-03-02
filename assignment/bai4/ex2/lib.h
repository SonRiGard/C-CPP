#ifndef LIB_H
#define LIB_H

#include <stdint.h>

typedef enum _statetype {
    CORRECT,
    CHAR_INVALID,
    LENGHT_INVALID
} status_enum_t;

typedef void (*func)(status_enum_t status);
static func callbackFunc = NULL;

void RegisterCallback(func func_add);
void Check_Account(char* ptr, uint8_t lenght);

#endif // LIB_H
