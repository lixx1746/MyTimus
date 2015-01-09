#include <stdio.h>

int main(void) {
  int N, K;
  scanf("%d  %d", &N, &K);
  int nonzero = K - 1, zero = 0;
  for(int i = 1; i < N; i++) {
    int temp = nonzero;
    nonzero = (nonzero + zero) * (K - 1);
    zero = temp;
  }
  printf("%d\n", zero + nonzero);
  return 0;
}
