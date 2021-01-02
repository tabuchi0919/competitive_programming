#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  string ans;
  int A, B;
  cin >> A >> B;
  if(A == 1)
    A = 14;
  if(B == 1)
    B = 14;
  if(A > B)
    ans = "Alice";
  if(A == B)
    ans = "Draw";
  if(A < B)
    ans = "Bob";
  cout << ans << endl;
}
