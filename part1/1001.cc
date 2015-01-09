#include <vector>
#include <cstdio>
//#include <cmath>
using namespace std;

//const double eps = 0.000001;

inline double abs(double a) { return a <= 0 ? -a : a; }

double sqrt(long long a) {
  double l = 0;
  double r = a / 2 + 1;
  for(int i = 0; i < 200; i++) {
    double mid = (l + r) / 2;
    double ans = mid * mid;
    if(ans > a) r = mid;
    else l = mid;
  }
  return l;
}

int main(void) {
  double d;
  vector<double> data;
  while(scanf("%lf",&d) != EOF)  data.push_back(d);
  for(int i = data.size() - 1; i >= 0; i--) printf("%.4lf\n",sqrt(data[i]));;
  return 0;
}
