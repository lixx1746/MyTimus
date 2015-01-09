#include <iostream>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  long long blue = 0;
  long long nonblue = 2;
  for(int i = 1; i < N; i++) {
    long long temp = nonblue;
    nonblue = blue + nonblue;
    blue = i < N - 1 ? temp : 0;
  }
  cout << nonblue + blue << endl;
  return 0;
}
