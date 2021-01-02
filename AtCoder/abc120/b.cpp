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
  int A, B, K, cnt = 0;
  cin >> A >> B >> K;
  for(int i = 100; i > 0; i--) {
    if(A % i == 0 && B % i == 0)
      cnt++;
    if(cnt == K) {
      cout << i << endl;
      break;
    }
  }
}
