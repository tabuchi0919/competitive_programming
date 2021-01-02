#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>

using namespace std;

int main() {
  int N, K;
  string S;
  vector<int> v;
  cin >> N >> K >> S;
  char now = '1';
  int cnt = 0;
  for(int i = 0; i < N; i++) {
    if(now == S[i]) {
      cnt++;
    } else {
      v.push_back(cnt);
      cnt = 1;
      now = S[i];
    }
  }
  if(cnt != 0)
    v.push_back(cnt);
  if(now == '0')
    v.push_back(0);

  int ans = 0;
  if(2 * K + 1 >= v.size()) {
    ans = N;
  } else {
    vector<int> sum(v.size());
    sum[0] = v[0];
    for(int i = 1; i < v.size(); i++) {
      sum[i] = sum[i - 1] + v[i];
    }
    for(int i = 0; 2 * K + i < v.size(); i += 2) {
      if(i == 0) {
        ans = max(ans, sum[2 * K + i]);
      } else {
        ans = max(ans, sum[2 * K + i] - sum[i - 1]);
      }
    }
  }
  cout << ans << endl;
}
