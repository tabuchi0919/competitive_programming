#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(a * b, c * d) << endl;
}
