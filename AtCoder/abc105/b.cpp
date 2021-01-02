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
  int N;
  cin >> N;
  string ans = "No";
  for(int i = 0; i * 4 <= N; i++) {
    for(int j = 0; j * 7 <= N; j++) {
      if(i * 4 + j * 7 == N)
        ans = "Yes";
    }
  }
  cout << ans << endl;
}
