#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  string sa, sb, sc, ans, next = "a";
  cin >> sa >> sb >> sc;
  while(true) {
    if(next == "a") {
      if(sa == "") {
        ans = "A";
        break;
      }
      next = sa[0];
      sa.erase(sa.begin());
    }
    if(next == "b") {
      if(sb == "") {
        ans = "B";
        break;
      }
      next = sb[0];
      sb.erase(sb.begin());
    }
    if(next == "c") {
      if(sc == "") {
        ans = "C";
        break;
      }
      next = sc[0];
      sc.erase(sc.begin());
    }
  }
  cout << ans << endl;
}
