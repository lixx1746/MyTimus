#include <iostream>

using namespace std;

const int N = 505;

long long dp[N][N];

int main(void) {
  int n;
  cin >> n;
  for(int i = 3; i <= n; i++) {
    for(int j = 2; j < i; j++)
      for(int m = 1; m < j && m + j <= i; m++) {
        if(m + j == i) dp[i][j]++;
        else dp[i][j] += dp[i - j][m];
      }
  }

  long long sum = 0;
  for(int i = 1; i < n; i++) sum += dp[n][i];
  cout << sum << endl;
  return 0;
}
