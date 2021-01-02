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
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  cout << H * W - h * W - w * H + h * w << endl;
}
