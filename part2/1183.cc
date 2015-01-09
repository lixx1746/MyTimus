#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int len[205][205];
string s;
string get_ans(int i, int j) {
  if(j - i == 1) return s[i] == ')' || s[i] == '(' ? "()" : "[]";
  if(j - i == len[i][j]) return s.substr(i, j - i);
  for(int k = i + 1; k < j; k++) {
    if(len[i][k] + len[k][j] == len[i][j]) {
      return get_ans(i, k) + get_ans(k, j);
    }
  }
  string ans;
  if(s[i] == '(') ans += "(" + get_ans(i + 1, j - 1) + ")";
  else ans += "[" + get_ans(i + 1, j - 1) + "]";
  return ans;
}

int main(void) {
  cin >> s;
  int n = s.size();
  for(int i = 0; i < n; i++) len[i][i + 1] = 2;
  for(int l = 2; l <= n; l++) {
    for(int from = 0; from + l <= n; from++) {
      int to = l + from;
      len[from][to] = 210;
      if((s[from] == '(' && s[to - 1] == ')') || (s[from] == '[' && s[to - 1] == ']'))
        len[from][to] = len[from + 1][to - 1] + 2;
      for(int k = from + 1; k < to; k++)
        len[from][to] = min(len[from][k] + len[k][to], len[from][to]);
    }
  }
  cout << get_ans(0, n) << endl;

  return 0;
}
