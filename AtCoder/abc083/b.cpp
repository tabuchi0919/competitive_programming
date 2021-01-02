#include <iostream>
using namespace std;

int main() {
  int n, a, b, cnt = 0;
  cin >> n;
  cin >> a;
  cin >> b;
  for(int i = 1; i < n + 1; i++) {
    int sum = i / 10000 + i / 1000 % 10 + i / 100 % 10 + i / 10 % 10 + i % 10;
    if(a <= sum && sum <= b) {
      cnt += i;
    }
  }
  cout << cnt << endl;
}
