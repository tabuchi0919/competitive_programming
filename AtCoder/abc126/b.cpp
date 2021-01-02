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
  int n;
  cin >> n;
  int up = n / 100, down = n - n / 100 * 100;
  if(1 <= up && up <= 12 && 1 <= down && down <= 12) {
    cout << "AMBIGUOUS" << endl;
  } else if(1 <= up && up <= 12) {
    cout << "MMYY" << endl;
  } else if(1 <= down && down <= 12) {
    cout << "YYMM" << endl;
  } else {
    cout << "NA" << endl;
  }
}
