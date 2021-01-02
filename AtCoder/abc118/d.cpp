#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int num[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[11000];

void chmax(string &a, string b) {
  if(a == "-")
    a = b;
  else if(a.size() < b.size())
    a = b;
  else if(a.size() == b.size()) {
    if(a < b)
      a = b;
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M);

  for(int i = 0; i < M; i++)
    cin >> A[i];
  for(int i = 0; i < 11000; ++i)
    dp[i] = "-";
  dp[0] = "";

  for(int i = 0; i <= N; i++) {
    if(dp[i] == "-")
      continue;
    for(auto a : A) {
      string b = dp[i] + char('0' + a);
      chmax(dp[i + num[a - 1]], b);
    }
  }
  cout << dp[N] << endl;
}
