#include <cstdio>
#include <cstring>
using namespace std;
int N;
char d[1005];
int acc[1005];

int main(void) {
  scanf("%d", &N);
  while((scanf("%s", d + 1) != EOF)) {
    memset(acc, 0, sizeof acc);
    int l = strlen(d + 1);
    // printf("%s %d\n", d + 1, l);
    int sum = 0;
    if(l == N) {
      for(int i = 1; i <= l; i++) {
        if(d[i] == '1') sum += i;
      }
      if((sum % (N + 1)) != 0) {
        for(int j = 1; j <= N; j++) {
          if(d[j] == '1' && ((sum - j) % (N + 1)) == 0) { d[j] = '0'; break; }
        }
      }
      printf("%s\n", d + 1);
    }
    else if(l < N) {
      int cnt = 0;
      for(int i = 1; i <= l; i++) {
        acc[i] = acc[i - 1];
        if(d[i] == '1') { cnt++; sum += i; acc[i]++; }
      }
      if(sum % (N + 1) != 0) {
        for(int j = 1; j <= N; j++) {
          int t1 = sum + cnt - acc[j - 1], t2 = sum + cnt - acc[j - 1] + j;
          if(t1 % (N + 1) == 0) {
            memmove(d + j + 1, d + j, l - j + 1);
            d[j] = '0';
            break;
          }
          else if(t2 % (N + 1) == 0) {
            memmove(d + j + 1, d + j, l - j + 1);
            d[j] = '1';
            break;
          }
        }
      }
      else { d[l + 1] = '0'; d[l + 2] = 0; }
      printf("%s\n", d + 1);
    }
    else {
      int cnt = 0;
      for(int i = 1; i <= l; i++) {
        acc[i] = acc[i - 1];
        if(d[i] == '1') { cnt++; sum += i; acc[i]++; }
      }
      for(int i = 1; i <= l; i++) {
        if(d[i] == '0') {
          int t = sum - (cnt - acc[i]);
          if(t % (N + 1) == 0) {
            memmove(d + i, d + i + 1, l - i);
            d[N + 1] = 0;
            break;
          }
        }
        else {
          int t = sum - i - (cnt - acc[i]);
          if(t % (N + 1) == 0) {
            memmove(d + i, d + i + 1, l - i);
            d[N + 1] = 0;
            break;
          }
        }
      }
      printf("%s\n", d + 1);
    }
  }
  return 0;
}
