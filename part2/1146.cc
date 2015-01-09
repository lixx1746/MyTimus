#include <iostream>
#include <cstdint>
using namespace std;

int dp[101][101];
int d[101][101];

int main(void) {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> d[i][j];
  int ans = d[0];


  cout << ans << endl;
  return 0;
}
