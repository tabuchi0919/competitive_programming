#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for(int i = 0; i < N; ++i)
    cin >> A[i];

  long long res = 0;
  for(int d = 60; d >= -1; --d) { // d = -1 は X = K の場合
    if(d != -1 && !(K & (1LL << d)))
      continue;

    long long tmp = 0;
    for(int e = 60; e >= 0; --e) {
      long long mask = 1LL << e;
      int num = 0;
      for(int i = 0; i < N; ++i)
        if(A[i] & mask)
          ++num;

      if(e > d) {
        if(K & mask)
          tmp += mask * (N - num);
        else
          tmp += mask * num;
      } else if(e == d) {
        tmp += mask * num;
      } else {
        tmp += mask * max(num, N - num);
      }
    }
    res = max(res, tmp);
  }
  cout << res << endl;
}
