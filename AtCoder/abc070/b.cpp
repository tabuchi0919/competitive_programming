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
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  cout << max(0, min(B, D) - max(A, C)) << endl;
}
