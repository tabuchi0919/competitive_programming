#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

const int INF = (1 << 30) - 1;
const ll INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  int max = (N - 1) * (N - 2) / 2;
  if(K > max) {
    cout << -1 << endl;
  } else {
    cout << N - 1 + (max - K) << endl;
    for(int i = 0; i < N - 1; i++) {
      cout << i + 1 << " " << N << endl;
    }
    bool flag = false;
    int cnt = 0;
    for(int i = 0; i < N - 1; i++) {
      for(int j = 0; j < i; j++) {
        if(cnt >= max - K)
          flag = true;
        if(flag)
          break;
        cout << i + 1 << " " << j + 1 << endl;
        cnt++;
      }
      if(flag)
        break;
    }
  }
}
