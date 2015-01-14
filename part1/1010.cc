#include <cstdio>
#include <climits>
#include <cmath>
using namespace std;

long long N;
double d[100005];

int main(void) {
  scanf("%lld", &N);
  for(int i = 1; i <= N; i++) scanf("%lf", d + i);
  long long ans_l = 1, ans_r = 2;
  double max_val = abs(d[2] - d[1]);
  for(int i = 3; i <= N; i++) {
    double t = abs(d[i] - d[i - 1]);
    if(t > max_val) {
      max_val = t;
      ans_l = i - 1;
      ans_r = i;
    }
  }
  printf("%lld %lld\n", ans_l, ans_r);
  return 0;
}
