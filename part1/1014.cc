#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int ans[200];

int main(void) {
  int n, cnt = 0;
  scanf("%d", &n);
  if(n == 0) printf("10\n");
  else if(n == 1) printf("1\n");
  else {
    while(n != 1) {
      int i = 9;
      for(; i >= 2; i--) {
        if(n % i == 0) {
          ans[cnt++] = i;
          n /= i;
          break;
        }
      }
      if(i < 2) {
        printf("-1\n");
        return 0;
      }
    }
  }
  sort(ans, ans + cnt);
  for(int i = 0; i < cnt; i++) printf("%d", ans[i]);
  printf("\n");
  return 0;
}
