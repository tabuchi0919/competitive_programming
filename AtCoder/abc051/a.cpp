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
  cout << s.substr(0, 5) << " " << s.substr(6, 7) << " " << s.substr(14, 5)
       << endl;
}
