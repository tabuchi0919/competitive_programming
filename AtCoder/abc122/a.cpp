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
  string b;
  cin >> b;
  int N = b.length();
  for(int i = 0; i < N; i++) {
    if(b[i] == 'A')
      cout << 'T';
    if(b[i] == 'T')
      cout << 'A';
    if(b[i] == 'C')
      cout << 'G';
    if(b[i] == 'G')
      cout << 'C';
  }
  cout << endl;
}
