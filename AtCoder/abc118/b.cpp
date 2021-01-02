#include <algorithm>
#include <iostream>
#include <limits>
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
  int A[N][M];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      A[i][j] = 0;
    }
  }
  for(int i = 0; i < N; i++) {
    int K;
    cin >> K;
    for(int j = 0; j < K; j++) {
      int tmp;
      cin >> tmp;
      A[i][tmp - 1] = 1;
    }
  }
  int ans = 0;
  for(int i = 0; i < M; i++) {
    int tmp2 = 1;
    for(int j = 0; j < N; j++) {
      tmp2 *= A[j][i];
    }
    if(tmp2 == 1)
      ans++;
  }
  cout << ans << endl;
}
