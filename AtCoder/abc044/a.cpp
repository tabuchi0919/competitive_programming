#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  if(n <= k)
    cout << x * n << endl;
  else
    cout << x * k + y * (n - k) << endl;
}
