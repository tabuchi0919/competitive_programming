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

pair<int, int> operator+(const pair<int, int> &lhs, const pair<int, int> &rhs) {
  pair<int, int> p = {lhs.first + rhs.first, lhs.second + rhs.second};
  return p;
}

bool operator==(const pair<int, int> &lhs, const pair<int, int> &rhs) {
  return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int H, W, cnt = 0;
  cin >> H >> W;
  vector<string> S(H);
  vector<vector<int>> field(H, vector<int>(W, -1));
  queue<pair<int, int>> q;
  for(int i = 0; i < H; i++) {
    cin >> S[i];
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '#')
        cnt++;
    }
  }
  field[0][0] = 0;
  q.push(make_pair(0, 0));

  const pair<int, int> moves[] = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };

  while(!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for(auto &move : moves) {
      pair<int, int> next = cur + move;
      if(next.first < 0 || next.first >= H || next.second < 0 ||
         next.second >= W)
        continue;
      if(field[next.first][next.second] == -1 &&
         S[next.first][next.second] != '#') {
        field[next.first][next.second] = field[cur.first][cur.second] + 1;
        q.push(next);
      }
    }
  }
  if(field[H - 1][W - 1] == -1) {
    cout << -1 << endl;
  } else {
    cout << H * W - 1 - field[H - 1][W - 1] - cnt << endl;
  }
}
