#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

double a, b;
int main() {
  cin >> a >> b;
  if(a == b) {
    cout << "EQUAL" << endl;
    return 0;
  }
  cout << (a > b ? "GREATER" : "LESS") << endl;
}
