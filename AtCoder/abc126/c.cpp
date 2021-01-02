#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <random>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  long long N, K, nowx;
  cin >> N >> K;
  long double ans = 0;
  for(int i = 0; (1 << i) < K; i++) {
    nowx = i + 1;
  }
  int maxx = nowx;
  for(int i = 1; i <= N; i++) {
    while(nowx > -1 && (1 << nowx) * i >= K) {
      nowx--;
    }
    ans += (1 << (maxx - nowx));
  }
  cout << setprecision(20);
  cout << ans / N / (1 << (maxx + 1)) << endl;
}
