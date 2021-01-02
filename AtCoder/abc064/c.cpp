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
  int N, ans;
  cin >> N;
  vector<int> color(9);
  for(int i = 0; i < 9; i++) {
    color[i] = 0;
  }
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    int tmp = a / 400;
    if(tmp > 8)
      tmp = 8;
    color[tmp]++;
  }
  int min = 0;
  for(int i = 0; i < 8; i++) {
    if(color[i] > 0)
      min++;
  }
  int max = min + color[8];
  if(min == 0)
    min++;

  cout << min << " " << max << endl;
}
