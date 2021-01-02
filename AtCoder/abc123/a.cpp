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
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;
  if(e - a <= k) {
    cout << "Yay!" << endl;
  } else {
    cout << ":(" << endl;
  }
}
