#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int N;
string num;
map<string, int> dict;
string i_to_c[] = { "oqz", "ij", "abc", "def", "gh", "kl", "mn", "prs", "tuv", "wxy" };
char c_to_i[26];

vector<string> mydict;

int pos[105][105], dp[105][105], used[105][105];

void myprint(int i, int j, vector<string> &res) {
  if(i >= j) return;
  if(dp[i][j] == 1) {
    res.push_back(mydict[used[i][j]]);
    return;
  }
  myprint(i, pos[i][j], res);
  myprint(pos[i][j], j, res);
}

int main(void) {
  ifstream fin("data.in");
  string line;
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < (int) i_to_c[i].size(); j++) {
      char c = i_to_c[i][j];
      c_to_i[c - 'a'] = i + '0';
    }
  }
  while(1) {

    fin >> num;
    if(num == "-1") break;
    for(int i = 0; i < 105; i++)
      for(int j = 0; j < 105; j++)
        dp[i][j] = 1000;

    for(int i = 0; i < 105; i++)
      for(int j = 0; j < 105; j++)
        pos[i][j] = 0;

    dict.clear();
    mydict.clear();
    fin >> N;

    for(int i = 0; i < N; i++) {
      fin >> line;
      mydict.push_back(line);
      string temp = "";
      for(int j = 0; j < (int) line.size(); j++) temp.push_back(c_to_i[line[j] - 'a']);
      dict[temp] = i;
    }

    int len = num.size();
    for(int l = 1; l <= len; l++) {
      for(int from = 0; from + l <= len; from++) {
        int to = from + l;
        string query;
        for(int j = from; j < to; j++) query.push_back(num[j]);
        if(dict.count(query)) {
          dp[from][to] = 1;
          used[from][to] = dict[query];
        }
        else {
          for(int k = from; k < to; k++) {
            if(dp[from][to] > dp[from][k] + dp[k][to]) {
              dp[from][to] = dp[from][k] + dp[k][to];
              pos[from][to] = k;
            }
          }
        }
      }
    }

    vector<string> res;
    if(dp[0][len] >= 1000) cout << "No solution." << endl;
    else {
      myprint(0, len, res);
      for(int i = 0; i < (int) res.size(); i++) {
        if(i != 0) cout << " ";
        cout << res[i];
      }
      cout << endl;
    }
  }
  return 0;
}
