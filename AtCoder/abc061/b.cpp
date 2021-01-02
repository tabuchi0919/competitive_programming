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
  int N, M, a, b;
  cin >> N >> M;
  vector<int> ans(N);
  for(int i = 0; i < M; i++) {
    cin >> a >> b;
    ans[a - 1]++;
    ans[b - 1]++;
  }
  for(int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }
}
