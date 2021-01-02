#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  vector<int> v(3);
  cin >> v[0] >> v[1] >> v[2];
  set<int> s(v.begin(), v.end());
  cout << s.size() << endl;
}
