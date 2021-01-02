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
  int x, a, b;
  cin >> x >> a >> b;
  if(b <= a) {
    cout << "delicious" << endl;
  } else if(b <= a + x) {
    cout << "safe" << endl;
  } else {
    cout << "dangerous" << endl;
  }
}
