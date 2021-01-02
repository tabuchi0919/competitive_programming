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
  double ans = 0;
  for(int i = 0; i < N; i++) {
    double x;
    string u;
    cin >> x >> u;
    if(u == "JPY") {
      ans += x;
    } else {
      ans += 380000.0 * x;
    }
  }
  cout << ans << endl;
}
