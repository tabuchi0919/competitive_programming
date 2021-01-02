#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  long long int a, b, x;
  cin >> a >> b >> x;
  if(a != 0)
    cout << b / x - (a - 1) / x << endl;
  if(a == 0)
    cout << b / x + 1 << endl;
}
