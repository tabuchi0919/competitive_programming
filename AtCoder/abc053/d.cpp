#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> A;
  for(int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    A.insert(tmp);
  }
  cout << A.size() - (A.size() + 1) % 2 << endl;
}
