#ifndef INPUT_H_
#define INPUT_H_
#include <iostream>
#include <cstdint>
// #define DEBUG
#define MAX_UINT8 255
#define MIN_UINT8 0
#define MAX_INT16 32767
#define MIN_INT16 -32768
#define MAX_UINT16 65535
#define MIN_UINT16 0

uint8_t getUint8();
int16_t getInt16();
uint16_t getUint16();

#endif