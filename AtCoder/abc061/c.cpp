#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

bool cmp(const pair<long long, long long> &a,
         const pair<long long, long long> &b) {
  return a.first < b.first;
}

int main() {
  long long N, K, a, b;
  cin >> N >> K;
  vector<pair<long long, long long>> p(N);
  for(int i = 0; i < N; i++) {
    cin >> a >> b;
    p[i] = make_pair(a, b);
  }
  sort(p.begin(), p.end(), cmp);
  long long cnt = 0;
  for(int i = 0; i < N; i++) {
    cnt += p[i].second;

    if(cnt >= K) {
      cout << p[i].first << endl;
      break;
    }
  }
}
