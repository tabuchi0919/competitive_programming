#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int W, a, b;
  cin >> W >> a >> b;
  cout << max(max(b - a - W, 0), max(a - b - W, 0)) << endl;
}
