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
  long long N, M, a, b, ans = 0;
  cin >> N >> M;
  vector<pair<long long, long long>> p(N);
  for(int i = 0; i < N; i++) {
    cin >> a >> b;
    p[i] = make_pair(a, b);
  }
  sort(p.begin(), p.end());
  long long sum = 0;
  for(int i = 0; i < N; i++) {
    if(p[i].second + sum >= M) {
      ans += (M - sum) * p[i].first;
      break;
    } else {
      ans += p[i].first * p[i].second;
      sum += p[i].second;
    }
  }
  cout << ans << endl;
}
