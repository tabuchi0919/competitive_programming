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
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<long long> a(X + 1), b(Y + 1), c(Z + 1);
  for(int i = 0; i < X; i++)
    cin >> a[i];
  for(int i = 0; i < Y; i++)
    cin >> b[i];
  for(int i = 0; i < Z; i++)
    cin >> c[i];
  a[X] = -10000000000;
  b[Y] = -10000000000;
  c[Z] = -10000000000;
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());

  long long max = a[0] + b[0] + c[0];
  cout << max << endl;
  vector<vector<int>> comb;
  vector<int> tmp(4, 0);
  comb.push_back(tmp);

  for(int i = 0; i < K - 1; i++) {
    vector<int> next(4, 0);
    long long sum = 0;
    for(auto &e : comb) {
      int x = e[0], y = e[1], z = e[2], tmp = e[3];
      if(tmp == 7)
        continue;
      if(tmp % 2 == 0) {
        if(sum < a[x + 1] + b[y] + c[z]) {
          sum = a[x + 1] + b[y] + c[z];
          next[0] = x + 1;
          next[1] = y;
          next[2] = z;
        }
      }
      if(tmp % 4 <= 1) {
        if(sum < a[x] + b[y + 1] + c[z]) {
          sum = a[x] + b[y + 1] + c[z];
          next[0] = x;
          next[1] = y + 1;
          next[2] = z;
        }
      }
      if(tmp <= 3) {
        if(sum < a[x] + b[y] + c[z + 1]) {
          sum = a[x] + b[y] + c[z + 1];
          next[0] = x;
          next[1] = y;
          next[2] = z + 1;
        }
      }
    }
    comb.push_back(next);
    for(auto &e : comb) {
      int x = e[0], y = e[1], z = e[2];
      if(next[0] - 1 == x && next[1] == y && next[2] == z) {
        if(e[3] % 2 == 0)
          e[3] += 1;
      }
      if(next[0] == x && next[1] - 1 == y && next[2] == z) {
        if(e[3] % 4 <= 1)
          e[3] += 2;
      }
      if(next[0] == x && next[1] == y && next[2] - 1 == z) {
        if(e[3] <= 3)
          e[3] += 4;
      }
    }
    cout << sum << endl;
  }
}
