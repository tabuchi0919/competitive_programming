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
  int a, b;
  cin >> a >> b;
  if(a >= 13) {
    cout << b << endl;
  } else if(a >= 6) {
    cout << b / 2 << endl;
  } else {
    cout << 0 << endl;
  }
}
