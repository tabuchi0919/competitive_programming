#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

const int MOD = 1000000007;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, ans = 0;
  cin >> N;
  vector<int> h(N);
  for(int i = 0; i < N; i++)
    cin >> h[i];

  while(true) {
    int tmp = 0;
    for(int i = 0; i < N - 1; i++) {
      if(h[i] != 0 && h[i + 1] == 0)
        tmp++;
    }
    if(h[N - 1] != 0)
      tmp++;
    if(tmp == 0)
      break;
    for(int i = 0; i < N; i++) {
      if(h[i] != 0)
        h[i]--;
    }
    ans += tmp;
  }
  cout << ans << endl;
}
