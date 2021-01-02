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
  int H, W;
  int ans = 0;
  cin >> H >> W;
  vector<string> s(H);
  for(int i = 0; i < H; i++) {
    cin >> s[i];
  }
  vector<vector<int>> up(H, vector<int>(W)), down(H, vector<int>(W)),
      right(H, vector<int>(W)), left(H, vector<int>(W));
  for(int i = 0; i < H; i++) {
    for(int j = 1; j < W; j++) {
      if(s[i][j] == '#') {
        left[i][j] = 0;
      } else {
        if(s[i][j - 1] == '.') {
          left[i][j] = left[i][j - 1] + 1;
        } else {
          left[i][j] = 0;
        }
      }
    }
  }
  for(int i = 0; i < H; i++) {
    for(int j = W - 2; j >= 0; j--) {
      if(s[i][j] == '#') {
        right[i][j] = 0;
      } else {
        if(s[i][j + 1] == '.') {
          right[i][j] = right[i][j + 1] + 1;
        } else {
          right[i][j] = 0;
        }
      }
    }
  }

  for(int i = 1; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(s[i][j] == '#') {
        up[i][j] = 0;
      } else {
        if(s[i - 1][j] == '.') {
          up[i][j] = up[i - 1][j] + 1;
        } else {
          up[i][j] = 0;
        }
      }
    }
  }

  for(int i = H - 2; i >= 0; i--) {
    for(int j = 0; j < W; j++) {
      if(s[i][j] == '#') {
        down[i][j] = 0;
      } else {
        if(s[i + 1][j] == '.') {
          down[i][j] = down[i + 1][j] + 1;
        } else {
          down[i][j] = 0;
        }
      }
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      ans = max(up[i][j] + right[i][j] + left[i][j] + down[i][j] + 1, ans);
    }
  }
  cout << ans << endl;
}
