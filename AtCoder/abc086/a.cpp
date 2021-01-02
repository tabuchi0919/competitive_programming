#include <iostream>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, p;
  cin >> a;
  cin >> b;

  p = a * b;
  if(p % 2 == 1) {
    cout << "Odd" << endl;
  } else {
    cout << "Even" << endl;
  }
}
