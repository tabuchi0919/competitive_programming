#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N;
  long long int T[N], sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> T[i];
    sum += T[i];
  }
  cin >> M;
  for(int i = 0; i < M; i++) {
    int p, x;
    cin >> p >> x;
    cout << sum + x - T[p - 1] << endl;
  }
}
