#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <vector>

using namespace std;

int main() {
  long long int N;
  cin >> N;
  vector<long long int> t(N), a(N);
  for(int i = 0; i < N; i++) {
    cin >> t[i] >> a[i];
  }
  long long int anst = 1, ansa = 1;
  for(int i = 0; i < N; i++) {
    long long int tmp = max((anst - 1) / t[i] + 1, (ansa - 1) / a[i] + 1);
    anst = t[i] * tmp;
    ansa = a[i] * tmp;
  }

  cout << anst + ansa << endl;
}
