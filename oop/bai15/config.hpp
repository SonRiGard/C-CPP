#pragma once


// Chỉ chọn một chế độ: AUTO_INPUT_MODE hoặc MANUAL_INPUT_MODE
//After swich mode AUTO <-> MANUAL, you must run "make clean" and rebuild the project 
#define AUTO_INPUT_MODE  // Hoặc có thể thay bằng #define MANUAL_INPUT_MODE
// #define MANUAL_INPUT_MODE

#ifdef AUTO_INPUT_MODE
    #define NUMBER_OF_STUDENTS 10  // so luong sv muon them
    #undef MANUAL_INPUT_MODE  // Nếu chế độ tự động bật, tắt chế độ nhập tay
#endif

#ifdef MANUAL_INPUT_MODE
    #undef AUTO_INPUT_MODE  // Nếu chế độ nhập tay bật, tắt chế độ tự động
#endif

