#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  cout << int(k * pow((k - 1), n - 1)) << endl;
}
