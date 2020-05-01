#include <emmintrin.h>
#include <stdio.h>
#include <stdint.h>
#include <x86intrin.h>

uint8_t array[256*4096];
int temp;
char secret = 94;

#define CACHE_HIT_THRESHOLD (130)
#define DELTA 1024

void flushSideChannel() {
  int i;
  for (in = 0; i < 256; i++) array[i*4096 + DELTA] = 1;
}