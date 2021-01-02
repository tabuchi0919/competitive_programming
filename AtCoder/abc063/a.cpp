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
  if(a + b >= 10) {
    cout << "error" << endl;
  } else {
    cout << a + b << endl;
  }
}
