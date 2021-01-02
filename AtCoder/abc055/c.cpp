#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  long long int N, M, ans, z = 0;
  cin >> N >> M;
  cout << min(N, M / 2) + max(z, (M - 2 * N) / 4) << endl;
}
