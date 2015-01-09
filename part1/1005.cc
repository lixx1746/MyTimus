#include <cstdio>
using namespace std;
int data[21];

inline int abs(int a) { return a < 0 ? -a : a; }
inline int min(int a, int b) { return a < b ? a : b; }

int main(void) {
  int N, total = 0;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", data + i);
    total += data[i];
  }
  int ans = 10000000;
  for(int i = 0; i <= (1 << N) - 1; i++) {
    int sum = 0;
    for(int j = 0; j < 21; j++) if(i & (1 << j)) sum += data[j];
    ans = min(ans, abs(total - sum - sum));
  }
  printf("%d\n", ans);
  return 0;
}
