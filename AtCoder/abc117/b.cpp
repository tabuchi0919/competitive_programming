#include <algorithm>
#include <iostream>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  string ans = "No";
  for(int i = 0; i < N; i++) {
    cin >> L[i];
  }
  sort(L.begin(), L.end());
  if(accumulate(L.begin(), L.end(), 0) > 2 * L[N - 1])
    ans = "Yes";
  cout << ans << endl;
}
