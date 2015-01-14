#include <cstdio>
using namespace std;
const int MAX_N = 65536;
int hash[MAX_N];
int N;
int main(void) {
  scanf("%d", &N);
  int a, q;
  for(int i = 0; i < N; i++) {
    scanf("%d", &a);
    a += 32768;
    hash[a] = 1;
  }
  scanf("%d", &N);
  int flag = 0;
  for(int i = 0; !flag && i < N; i++) {
    scanf("%d", &a);
    q = 10000 + 32768 - a;
    if(q < 0 || q >= MAX_N) continue;
    if(hash[q]) flag = 1;
  }

  if(flag) printf("YES\n");
  else printf("NO\n");
  return 0;
}
