#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long dp[51][51][2500];
long long n, a, x[50];
int main() {
  cin >> n >> a;
  for(int i = 0; i < n; i++)
    cin >> x[i];
  dp[0][0][0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < 2500; k++) {
        if(dp[i][j][k] == 0)
          continue;
        dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
        dp[i + 1][j][k] += dp[i][j][k];
      }
    }
  }
  long long sum = 0;
  for(int i = 1; i <= n; i++)
    sum += dp[n][i][a * i];
  cout << sum << endl;
}
