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
  int N, M;
  cin >> N >> M;
  int a[N], b[N], c[M], d[M];
  for(int i = 0; i < N; i++)
    cin >> a[i] >> b[i];
  for(int i = 0; i < M; i++)
    cin >> c[i] >> d[i];

  for(int i = 0; i < N; i++) {
    int min_dist = 1e18, min_idx = -1;
    for(int j = 0; j < M; j++) {
      int dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if(dist < min_dist) {
        min_dist = dist;
        min_idx = j + 1;
      }
    }
    cout << min_idx << endl;
  }
}
