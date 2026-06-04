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
 * @file stats.h
 * @brief Declarations for array statistical analytics
 *
 * This file contains the function prototypes and documentation
 * for the maximum, minimum, mean, and median analytics assignment.
 *
 * @author Ngo Tuan Anh
 * @date 05/20/2026
 */

#ifndef __STATS_H__
#define __STATS_H__
#include <stdint.h>
#include <stddef.h>
/**
 * @brief Print the statistics of an array including max, min, mean, median
 * @param ptr Pointer to data array
 * @param size Size of array
 * @return None
 */
void print_statistics(unsigned char *ptr, unsigned int size);

/**
 * @brief Print the array to the screen
 * @param ptr Pointer to data array
 * @param size Size of array
 * @return None
 */
void print_array(uint8_t * array, size_t length) ; 

/**
 * @brief Find the median value of the array
 * @param ptr Pointer to data array
 * @param size Size of array
 * @return Median value
 */
unsigned char find_median(unsigned char *ptr, unsigned int size);

/**
 * @brief Find the mean value of the array
 * @param ptr Pointer to data array
 * @param size Size of array
 * @return Mean value
 */
unsigned char find_mean(unsigned char *ptr, unsigned int size);

/**
 * @brief Find the maximum value of the array
 * @param ptr Pointer to data array
 * @param size Size of array
 * @return Maximum value
 */
unsigned char find_maximum(unsigned char *ptr, unsigned int size);

/**
 * @brief Find the minimum value of the array
 * @param ptr Pointer to data array
 * @param size Size of array
 * @return Minimum value
 */
unsigned char find_minimum(unsigned char *ptr, unsigned int size);

/**
 * @brief Sort the array from largest to smallest
 * @param ptr Pointer to data array
 * @param size Size of array
 * @return None
 */

void sort_array(unsigned char *ptr, unsigned int size);

#endif /* __STATS_H__ */
