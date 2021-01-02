#include <iostream>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string ans;
  if(a + b == c + d)
    ans = "Balanced";
  if(a + b < c + d)
    ans = "Left";
  if(a + b > c + d)
    ans = "Right";
  cout << ans << endl;
}
