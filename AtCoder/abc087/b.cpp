#include <iostream>
using namespace std;

int main() {
  int a, b, c, x, cnt = 0;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> x;

  for(int i = 0; i <= a; i++) {
    for(int j = 0; j <= b; j++) {
      for(int k = 0; k <= c; k++) {
        if(500 * i + 100 * j + 50 * k == x) {
          cnt += 1;
        }
      }
    }
  }
  cout << cnt << endl;
}
