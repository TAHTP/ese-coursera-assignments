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

/* Size of the Data Set */
#define SIZE (40)

void main() {
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114,  88,  45,  76, 123,  87,  25,  23,
                              200, 122, 150,  90,  92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250,  230, 99,   3, 100,  90};

  printf("===== ORIGINAL DATA ARRAY =====\n");
  print_array(test, SIZE);
  
  printf("\n===== STATISTICAL REPORT =====\n");
  print_statistics(test, SIZE);

  printf("\n===== SORTED ARRAY (LARGEST TO SMALLEST) =====\n");
  sort_array(test, SIZE);
  print_array(test, SIZE);
}

/* --- FUNCTION IMPLEMENTATIONS --- */

void print_statistics(unsigned char *ptr, unsigned int size) {
  printf("Maximum Value: %d\n", find_maximum(ptr, size));
  printf("Minimum Value: %d\n", find_minimum(ptr, size));
  printf("Mean Value: %d\n", find_mean(ptr, size));
  printf("Median Value: %d\n", find_median(ptr, size));
}

void print_array(unsigned char *ptr, unsigned int size) {
  for (int i = 0; i < size; i++) {
    printf("%3d ", *(ptr + i));
    if ((i + 1) % 8 == 0) {
      printf("\n");
    }
  }
}

unsigned char find_median(unsigned char *ptr, unsigned int size) {
  sort_array(ptr, size);
  unsigned int mid1 = (size / 2) - 1;
  unsigned int mid2 = size / 2;
  return (*(ptr + mid1) + *(ptr + mid2)) / 2;
}

unsigned char find_mean(unsigned char *ptr, unsigned int size) {
  unsigned int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += *(ptr + i);
  }
  return (unsigned char)(sum / size);
}

unsigned char find_maximum(unsigned char *ptr, unsigned int size) {
  unsigned char max = *ptr;
  for (int i = 1; i < size; i++) {
    if (*(ptr + i) > max) {
      max = *(ptr + i);
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char *ptr, unsigned int size) {
  unsigned char min = *ptr;
  for (int i = 1; i < size; i++) {
    if (*(ptr + i) < min) {
      min = *(ptr + i);
    }
  }
  return min;
}

void sort_array(unsigned char *ptr, unsigned int size) {
  unsigned char temp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (*(ptr + j) > *(ptr + i)) {
        temp = *(ptr + i);
        *(ptr + i) = *(ptr + j);
        *(ptr + j) = temp;
      }
    }
  }
}
