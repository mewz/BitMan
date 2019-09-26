#include "to_bits.h"

/*
 * Created by: Jason Hullinger
 * Date: 9/2/2019
 * Purpose: Bit manipulation library -
 * Mainly educational, but wanted an easy to represent binary from any void pointer
 */

int main(int argc, char **argv){
  unsigned short i;
  unsigned short max = 1024;
  for(i = max-10; i < max; i ++){
    size_t reslen;
    char *bits = to_bits(&i, sizeof(i), &reslen);
    remove_leading_zeros(bits, reslen, &reslen);
    print_bits(bits, reslen);
    free(bits);
  }

  char str[] = "Hello, World!";
  size_t reslen;
  char *bits = to_bits(str, sizeof(str), &reslen);
  remove_leading_zeros(bits, reslen, &reslen);
  print_bits(bits, reslen);
  free(bits);
  
  return 0;
}
