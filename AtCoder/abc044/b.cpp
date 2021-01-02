#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  string w;
  string ans = "Yes";

  cin >> w;
  int n = w.length();
  for(int i = 'a'; i <= 'z'; i++) {
    int cnt = 0;
    for(int j = 0; j < n; j++) {
      if(i == w[j])
        cnt++;
    }
    if(cnt % 2 == 1) {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
}
