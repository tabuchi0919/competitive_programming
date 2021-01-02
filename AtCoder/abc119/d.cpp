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
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<long long> s(A), t(B);
  for(int i = 0; i < A; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < B; i++) {
    cin >> t[i];
  }
  for(int i = 0; i < Q; i++) {
    long long x, slow, shigh, tlow, thigh, ans = 100000000000;
    cin >> x;
    decltype(s)::iterator its = lower_bound(s.begin(), s.end(), x);
    decltype(t)::iterator itt = lower_bound(t.begin(), t.end(), x);
    if(its == s.end()) {
      shigh = 100000000000;
    } else {
      shigh = *its;
    }
    if(itt == t.end()) {
      thigh = 100000000000;
    } else {
      thigh = *itt;
    }
    if(its == s.begin()) {
      slow = -100000000000;
    } else {
      its--;
      slow = *its;
    }
    if(itt == t.begin()) {
      tlow = -100000000000;
    } else {
      itt--;
      tlow = *itt;
    }
    // low->low
    ans = min(ans, x - min(slow, tlow));
    // high->high
    ans = min(ans, max(shigh, thigh) - x);
    // slow->thigh
    ans = min(ans, thigh + x - 2 * slow);
    ans = min(ans, shigh + x - 2 * tlow);
    // shigh->thigh
    ans = min(ans, 2 * shigh - x - tlow);
    ans = min(ans, 2 * thigh - x - slow);
    cout << ans << endl;
  }
}
