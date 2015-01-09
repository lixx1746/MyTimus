#include <cstdio>
#include <vector>
#include <utility>
#include <map>

using namespace std;
int N, Q, from, to;
char val[10];
map<int, int> pre;
map<int, bool> see;
map<int, bool> odd;

bool add(int from, int to, bool p) {
  if(!see.count(to)) {
    see[to] = true;
    pre[to] = from;
    odd[to] = p;
    return true;
  }
  int anc = pre[to];
  if(anc == from) return odd[to] == p;
  else if(anc < from) return add(anc, from - 1, p != odd[to]);
  else return add(from, anc - 1, p != odd[to]);
}

void init(void) {
  pre.clear(); see.clear(); odd.clear();
}
int main(void) {
  while(1) {
  scanf("%d", &N);
  if(N == -1) break;
  scanf("%d", &Q);
  init();
  int i = 0, ans = 0;
  for(; i < Q; i++) {
    scanf("%d %d %s", &from, &to, val);
    bool v = val[0] == 'o';
    if(!ans && !add(from, to, v)) ans = i;
  }
  if(!ans) printf("%d\n", Q);
  else printf("%d\n", ans);
  }
  return 0;
}
