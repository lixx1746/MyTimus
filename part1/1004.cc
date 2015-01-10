#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M, len;
int l, r, up;
const int MAX_N = 105, INF = 300000000;
int G[MAX_N][MAX_N], dist[MAX_N][MAX_N], pre[MAX_N][MAX_N];
int path[MAX_N];

int main(void) {
  while(1) {
    scanf("%d", &N);
    if(N == -1) break;
    scanf("%d", &M);
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        G[i][j] = dist[i][j] = INF;
        pre[i][j] = i;
      }
    }
    len = 0;
    int from, to;
    for(int i = 0; i < M; i++) {
      scanf("%d %d %d", &from, &to, &len);
      if(G[from][to] > len)
        G[from][to] = G[to][from] = dist[from][to] = dist[to][from] = len;
    }

    int ans = INF;
    for(int k = 1;  k <= N; k++) {
      for(int i = 1; i < k; i++) {
        for(int j = i + 1; j < k; j++) {
          if(ans > dist[i][j] + G[i][k] + G[k][j]) {
            ans = dist[i][j] + G[i][k] + G[k][j];
            len = 0;
            int p = j;
            while(p != i) {
              path[len++] = p;
              p = pre[i][p];
            }
            path[len++] = i;
            path[len++] = k;
          }
        }
      }

      for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
          if(dist[i][j] > dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
            pre[i][j] = pre[k][j];
          }
        }
      }
    }

    if(ans == INF) printf("No solution.\n");
    else {
      for(int i = 0; i < len; i++) {
        if(i != 0) printf(" ");
        printf("%d", path[i]);
      }
      printf("\n");
    }
  }


  return 0;
}
