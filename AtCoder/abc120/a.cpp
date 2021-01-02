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
  int A, B, C;
  cin >> A >> B >> C;
  cout << min(C, B / A) << endl;
}
