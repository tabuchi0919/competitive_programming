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
  int H, W;
  cin >> H >> W;
  for(int i = 0; i < W + 2; i++) {
    cout << '#';
  }
  cout << endl;
  for(int i = 0; i < H; i++) {
    string t;
    cin >> t;
    cout << '#' << t << '#' << endl;
  }
  for(int i = 0; i < W + 2; i++) {
    cout << '#';
  }
  cout << endl;
}
