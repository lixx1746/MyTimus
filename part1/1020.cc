#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void) {
  int N;
  double ans = 0, R;
  double first_x, first_y, cur_x, cur_y, pre_x, pre_y;
  cin >> N >> R;
  cin >> first_x >> first_y;
  pre_x = first_x; pre_y = first_y;
  for(int i = 1; i < N; i++) {
    cin >> cur_x >> cur_y;
    double t = (cur_x - pre_x) * (cur_x - pre_x) +  (cur_y - pre_y) * (cur_y - pre_y);
    ans += sqrt(t);
    pre_x = cur_x; pre_y = cur_y;
  }
  ans +=  sqrt((first_x - pre_x) * (first_x - pre_x) + (first_y - pre_y) * (first_y - pre_y)) + 2 * 3.1415926 * R;
  printf("%.2lf\n", ans);
  return 0;
}
