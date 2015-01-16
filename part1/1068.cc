#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  long long k = abs(N);
  long long ans = ((k + 1) * 1ll * k) / 2;
  cout <<  (N <= 0 ? -1ll * ans + 1ll : ans) << endl;
  return 0;
}
