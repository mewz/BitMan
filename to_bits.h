/*
 * to_bits.cc
 *
 * Created by Jason Hullinger on 9/01/2019
 */

#ifndef __ToBytes__
#define __ToBytes__

#define BITS_LEN 8

#include <stdio.h>
#include <stdlib.h>

void print_bits(char*, size_t);
void reverse_inplace(char* ptr, size_t len);
void remove_leading_zeros(char *ptr, size_t len, size_t *reslen);
char* to_bits(void *ptr, size_t len, size_t *reslen);

#endif
