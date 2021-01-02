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
  int N;
  cin >> N;
  long long int state[101][64], ans = 0;
  for(int i = 0; i < 101; i++) {
    for(int j = 0; j < 64; j++) {
      state[i][j] = 0;
    }
  }
  for(int i = 0; i < 64; i++) {
    state[3][i] = 1LL;
  }
  state[3][16 * 0 + 4 * 2 + 1] = 0LL;
  state[3][16 * 0 + 4 * 1 + 2] = 0LL;
  state[3][16 * 2 + 4 * 0 + 1] = 0LL;
  for(int i = 3; i < 100; i++) {
    for(int j = 0; j < 64; j++) {
      for(int k = 0; k < 4; k++) {
        if((j * 4 + k) != 6 && (j * 4 + k) != 70 && (j * 4 + k) != 134 &&
           (j * 4 + k) != 198 && (j * 4 + k) != 9 && (j * 4 + k) != 73 &&
           (j * 4 + k) != 137 && (j * 4 + k) != 201 && (j * 4 + k) != 33 &&
           (j * 4 + k) != 97 && (j * 4 + k) != 161 && (j * 4 + k) != 225 &&
           (j * 4 + k) != 9 && (j * 4 + k) != 25 && (j * 4 + k) != 41 &&
           (j * 4 + k) != 57 && (j * 4 + k) != 33 && (j * 4 + k) != 37 &&
           (j * 4 + k) != 41 && (j * 4 + k) != 45 && (j * 4 + k) != 36 &&
           (j * 4 + k) != 37 && (j * 4 + k) != 38 && (j * 4 + k) != 39 &&
           (j * 4 + k) != 24 && (j * 4 + k) != 25 && (j * 4 + k) != 26 &&
           (j * 4 + k) != 27 && (j * 4 + k) != 132 && (j * 4 + k) != 133 &&
           (j * 4 + k) != 134 && (j * 4 + k) != 135) {
          state[i + 1][(j * 4 + k) % 64] += state[i][j] % 1000000007;
          state[i + 1][(j * 4 + k) % 64] %= 1000000007;
        }
      }
    }
  }
  for(int i = 0; i < 64; i++) {
    ans += state[N][i] %= 1000000007;
    ans %= 1000000007;
  }
  cout << ans << endl;
}
