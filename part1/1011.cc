#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 0.0000001;
double lower, upper;

bool check(int a) {
  int r = floor(a * upper);
  if(abs(1.0 * r - (double) (a) * upper) < eps) r--;
  int l = ceil(a * lower);
  if(abs(1.0 * l - (double) (a) * lower) < eps) l++;
  if(r >= l) return 1;
  else return 0;
}

int main(void) {
  scanf("%lf %lf", &lower, &upper);
  int ans = 1;
  lower /= 100.00;
  upper /= 100.00;
  while(1) {
    if(check(ans)) break;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
