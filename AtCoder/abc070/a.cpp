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
  if(N / 100 == N % 10)
    ans = "Yes";
  cout << ans << endl;
}
