#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 150005;
struct sc {
  int id, score;
} d[MAX_N];

bool mycomp(sc a, sc b) { return a.score > b.score; }
int main(void) {
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d %d", &d[i].id, &d[i].score);
  stable_sort(d, d + N, mycomp);
  for(int i = 0; i < N; i++) printf("%d %d\n", d[i].id, d[i].score);
}
