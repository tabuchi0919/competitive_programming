#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, a;
  cin >> n >> a;
  string ans = "No";
  if(n % 500 <= a)
    ans = "Yes";
  cout << ans << endl;
}
