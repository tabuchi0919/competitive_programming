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
  int N, M, C, cnt = 0;
  cin >> N >> M >> C;
  vector<int> B(M);
  for(int i = 0; i < M; i++) {
    cin >> B[i];
  }
  for(int i = 0; i < N; i++) {
    int sum = 0;
    for(int j = 0; j < M; j++) {
      int tmp;
      cin >> tmp;
      sum += tmp * B[j];
    }
    if(sum + C > 0)
      cnt++;
  }
  cout << cnt << endl;
}
