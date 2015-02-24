#include <stdio.h>
#include <stdlib.h>

#include "dsp/is_prime.hpp"

int main(int argc, char *argv[])
{
  if(argc != 2) {
	fprintf(stderr, "next_prime_below requires exactly one argument\n");
        exit(-1);
  }

  int start = atoi(argv[1]);

  for(int i=start; i>0; i--)
  {
    if(is_prime(i)) {
      printf("Next prime below %d is %d\n", start, i);
      break;
    }
  }
}
