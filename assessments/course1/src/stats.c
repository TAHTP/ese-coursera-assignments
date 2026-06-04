/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Implementation of array statistical analytics functions
 *
 * @author Ngo Tuan Anh
 * @date 05/20/2026
 */

#include <stdio.h>
#include "stats.h"
#include "platform.h"
/* Size of the Data Set */
// Sửa cái ruột hàm lại cho chuẩn kiểu dữ liệu mới
void print_array(uint8_t * array, size_t length) {
#ifdef VERBOSE
    // Sếp có thể copy ruột in mảng cũ vào đây, nhớ dùng PRINTF thay vì printf nhé!
    PRINTF("Array contents:\n");
    for (size_t i = 0; i < length; i++) {
        PRINTF("%d ", array[i]);
    }
    PRINTF("\n");
#endif
}