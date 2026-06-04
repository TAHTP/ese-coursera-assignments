/**
 * @file data.h
 * @author Ngo_Tuan_Anh (tuananhcaobangvn@gmail.com)
 * @brief   this file is using for data converter 
 * @version 0.1
 * @date 2026-06-03
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef  __DATA_H__ 
#define  __DATA_H__

#include <stdint.h> 
#include <stdio.h> 
#define BASE_16 (16)
#define BASE_10 (10)
/**
 * @brief 
 * 
 * @param data 
 * @param ptr 
 * @param base 
 * @return uint8_t 
 */


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) ;
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base); 



/**
 * @brief 
 * 
 * @param ptr 
 * @param digits 
 * @param base 
 * @return int32_t 
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) ; 




#endif   
