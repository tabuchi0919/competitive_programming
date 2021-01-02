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
  long long X, Y;
  cin >> X >> Y;
  if(-1 <= X - Y && X - Y <= 1)
    cout << "Brown" << endl;
  else
    cout << "Alice" << endl;
}
