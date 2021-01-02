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
  int N;
  cin >> N;
  vector<int> C(N), S(N), F(N);
  for(int i = 0; i < N - 1; i++) {
    cin >> C[i] >> S[i] >> F[i];
  }
  for(int i = 0; i < N - 1; i++) {
    int tmp = 0;
    for(int j = i; j < N - 1; j++) {
      if(tmp < S[j]) {
        tmp = S[j];
      } else {
        tmp = (tmp + F[j] - 1) / F[j] * F[j];
      }
      tmp += C[j];
    }
    cout << tmp << endl;
  }
  cout << 0 << endl;
}
