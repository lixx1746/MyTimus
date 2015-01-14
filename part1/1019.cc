#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 5005;
int a[MAX_N], b[MAX_N], d[MAX_N << 1];
bool col[MAX_N << 1], op[MAX_N];
int N;

int main(void) {
  cin >> N;
  char c;
  int l = 0;
  d[l++] = 0; d[l++] = 1e9;
  for(int i = 0; i < N; i++) {
    cin >> a[i] >> b[i] >> c;
    d[l++] = a[i];
    d[l++] = b[i];
    op[i] = c == 'b';
  }
  sort(d, d + l);
  l = unique(d, d + l) - d;
  for(int i = 0; i < N; i++) {
    int ll = lower_bound(d, d + l, a[i]) - d;
    int rr = lower_bound(d, d + l, b[i]) - d;
    for(int j = ll; j < rr; j++) col[j] = op[i];
  }
  col[l  - 1] = true;
  int max_len = 0, ans_l, ans_r;
  for(int i = 0; i < l; i++) {
    if(!col[i]) {
      int l = d[i];
      while(!col[i]) i++;
      int r = d[i];
      if(max_len < r - l + 1) {
        max_len  = r -l + 1;
        ans_l = l;
        ans_r = r;
      }
    }
  }
  cout << ans_l << " " << ans_r << endl;
  return 0;
}
