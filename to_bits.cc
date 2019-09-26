/*
 * to_bits.cc
 *
 * Created by Jason Hullinger on 9/01/2019
 */

#include "to_bits.h"

/*
 *
 * print_bits --
 * Prints integer values of each bit in the char buffer up to len
 * 
 * Returns:
 * None
 * 
 * Side effects:
 * None
 *
 */

void print_bits(char *bits, /* IN */
		size_t len) /* IN */
{
  int i;
  for(i = 0; i < len; i ++){
    printf("%i", bits[i]);
  }
  printf("\n");
}

/*
 *
 * reverse_inplace --
 * Reverses a char buffer in place up to size len
 *
 * Rerturns:
 * None
 * 
 * Side effects:
 * None
 *
 */

void reverse_inplace(char *ptr, /* IN */
		     size_t len) /* IN */
{
  char c;
  int half, i;

  half = len >> 1;
  for(i = 0; i < half; i ++){
    c = ptr[i];
    ptr[i] = ptr[len - i - 1];
    ptr[len - i - 1] = c;
  }
}

/*
 *
 * remove_leading_zeros --
 * Removes the leading zeros in the buffer so that 00001 becomes 1
 *
 * Returns:
 * None
 *
 * Side effects:
 * Reduces the length of the buffer size, but does not decrease the heap size of the ptr buffer
 *
 */

void remove_leading_zeros(char *ptr, /* IN */
			  size_t len, /* IN */
			  size_t *reslen) /* OUT */
{
  int counter;
  size_t i = 0;
  bool do_append = false;
  for(counter = 0; counter < len; counter ++){
    if(!do_append && ptr[counter] == 1){
      do_append = true;
      i = 0;
    }
    if(do_append){
      ptr[i] = ptr[counter];
      i++;
    }
  }

  //in the case of 0
  if(i == 0){
    i = 1;
    ptr[0] = 0;
  }
  *reslen = i;
}

/*
 *
 * to_bits --
 * Takes a void pointer and converts it a char buffer representing the bits
 * 
 * Returns:
 * The char buffer containing the bit representation of the input buffer
 *
 * Side effects:
 * None
 *
 */
char* to_bits(void *ptr, /* IN */
	      size_t len, /* IN */
	      size_t *reslen) /* OUT */
{
  unsigned char *bytes = (unsigned char*)ptr;
  *reslen = (BITS_LEN * len);
  char *bits = (char*)malloc(*reslen);

  int i, j;
  for(i = 0; i < len; i ++){
    unsigned char b = bytes[i];
    for(j = 0; j < BITS_LEN; j ++){
      int pos = i*8+j;
      bits[pos] = b & 1;
      b >>= 1;
    }
  }
  
  reverse_inplace(bits, *reslen);
  return bits;
}
