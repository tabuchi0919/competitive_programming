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
  int N, ans = 0;
  cin >> N;
  vector<int> p(N);
  for(int i = 0; i < N; i++)
    cin >> p[i];
  sort(p.begin(), p.end());
  for(int i = 0; i < N; i++) {
    if(i != N - 1) {
      ans += p[i];
    } else {
      ans += p[i] / 2;
    }
  }
  cout << ans << endl;
}
