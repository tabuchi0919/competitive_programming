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
  int A, B;
  cin >> A >> B;
  int ans = B - A;
  if(B % A == 0)
    ans = A + B;
  cout << ans << endl;
}
