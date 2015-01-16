#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int id[101];
vector<int> G[101];
int dp[101];

void dfs(int i) {
  if(dp[i]) return;
  for(int j = 0; j < G[i].size(); j++) {
    int to = G[i][j];
    dfs(to);
    dp[i] = max(dp[i], dp[to] + 1);
  }
  dp[i]++;
}

bool cmp(int i, int j) { return dp[i] > dp[j]; }

int main(void) {
  cin >> N;
  int from, to;
  for(int i = 1; i <= N; i++) {
    id[i] = i;
    while(1) {
      cin >> to;
      if(to == 0) break;
      G[i].push_back(to);
    }
  }

  for(int i = 1; i <= N; i++) {
    dfs(i);
  }
  sort(id + 1, id + N + 1, cmp);
  for(int i = 1; i <= N; i++) {
    if(i != 1) cout << " ";
    cout << id[i];
  }
  cout << endl;

  return 0;
}
