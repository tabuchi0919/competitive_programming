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
  long long N, Q;
  string S;
  cin >> N >> Q;
  cin >> S;
  vector<int> cnt(N, 0);
  long long tmp = 0;
  for(int i = 1; i < N; i++) {
    if(S[i - 1] == 'A' && S[i] == 'C') {
      tmp += 1;
    }
    cnt[i] = tmp;
  }
  long long r, l;
  for(int i = 0; i < Q; i++) {
    cin >> l >> r;
    cout << cnt[r - 1] - cnt[l - 1] << endl;
  }
}
