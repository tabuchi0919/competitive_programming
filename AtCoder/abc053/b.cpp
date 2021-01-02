#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  cout << s.rfind("Z") - s.find("A") + 1 << endl;
}
