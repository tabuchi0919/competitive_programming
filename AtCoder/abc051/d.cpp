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
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m), c(m);
  vector<vector<int>> dist = vector<vector<int>>(n, vector<int>(n, 0));

  for(int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i != j)
        dist[i][j] = 100000000;
    }
  }

  for(int i = 0; i < m; i++) {
    dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
    dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
  }

  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int ans = m;
  for(int i = 0; i < m; i++) {
    bool flag = false;
    for(int j = 0; j < n; j++) {
      if(dist[j][a[i]] + c[i] == dist[j][b[i]])
        flag = true;
    }
    if(flag)
      ans--;
  }

  cout << ans << endl;
}
