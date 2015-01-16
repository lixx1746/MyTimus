#include <iostream>
#include <set>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 987654321;
double dp[1001][1001];
int N, M, K;
set<pair<int, int> > s;

int main(void) {
  cin >> N >> M >> K;
  int x, y;
  for(int i = 0; i < K; i++) {
    cin >> x >> y;
    s.insert(make_pair(x, y));
  }
  for(int i = 0; i <= N; i++)
    for(int j = 0; j <= M; j++)
      dp[i][j] = INF;
  dp[0][0] = 0.0;
  for(int i = 1; i <= M; i++) dp[0][i] = dp[0][i - 1] + 100;
  for(int i = 1; i <= N; i++) dp[i][0] = dp[i - 1][0] + 100;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      pair<int, int> q = make_pair(i, j);
      int flag = 0;
      if(s.count(q)) flag = 1;
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 100;
      if(flag) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]) + sqrt(2) * 100;
    }
  }
  int ans = round(dp[N][M]);
  cout << ans << endl;
  return 0;
}
