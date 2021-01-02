#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int X, i = 1, tmp = 0;
  cin >> X;
  while(tmp < X) {
    tmp += i;
    i++;
  }
  cout << i + 1 << endl;
}
