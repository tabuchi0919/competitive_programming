#include <algorithm>
#include <iostream>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int s;
  cin >> s;
  for(int i = 0; i < 1000000; i++) {
    if(s == 4 || s == 2 || s == 1) {
      cout << i + 4 << endl;
      break;
    }
    if(s % 2 == 0) {
      s /= 2;
    } else {
      s *= 3;
      s += 1;
    }
  }
}
