#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

typedef long long ll;
ll n, m;
string str, ans, ansbuf;

bool hantei(bool last, bool first) {
  bool left = last;
  bool now = first;
  bool right;
  ansbuf = "";

  for(ll i = 0; i < n; i++) {
    ansbuf += (now) ? "S" : "W";
    if(str[i] == 'o') {
      right = (now) ? left : !left;
    } else {
      right = (now) ? !left : left;
    }
    left = now;
    now = right;
  }
  return left == last && now == first;
}

int main() {
  cin >> n >> str;

  ans = "-1";
  ans = hantei(true, true) ? ansbuf : ans;
  ans = hantei(true, false) ? ansbuf : ans;
  ans = hantei(false, true) ? ansbuf : ans;
  ans = hantei(false, false) ? ansbuf : ans;

  cout << ans << endl;
  return 0;
}
