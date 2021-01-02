#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <random>
#include <set>
#include <string.h>
#include <vector>

using namespace std;

const int MOD = 1000000007;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, ans;
  cin >> n;
  vector<int> v1(100001), v2(100001);
  for(int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if(i % 2 == 0) {
      v1[v]++;
    } else {
      v2[v]++;
    }
  }
  int v1max1 = 0, v1max2 = 0, v2max1 = 0, v2max2 = 0;
  int v1max1id, v1max2id, v2max1id, v2max2id;
  for(int i = 1; i < 100001; i++) {
    if(v1[i] > v1max1) {
      v1max2 = v1max1;
      v1max2id = v1max1id;
      v1max1 = v1[i];
      v1max1id = i;
    } else if(v1[i] > v1max2) {
      v1max2 = v1[i];
      v1max2id = i;
    }

    if(v2[i] > v2max1) {
      v2max2 = v2max1;
      v2max2id = v2max1id;
      v2max1 = v2[i];
      v2max1id = i;
    } else if(v2[i] > v2max2) {
      v2max2 = v2[i];
      v2max2id = i;
    }
  }
  if(v1max1id != v2max1id) {
    ans = n - v1max1 - v2max1;
  } else {
    ans = min(n - v1max1 - v2max2, n - v1max2 - v2max1);
  }

  cout << ans << endl;
}
