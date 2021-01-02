#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int A, B;
  char op;
  cin >> A >> op >> B;
  if(op == '+')
    cout << A + B << endl;
  else
    cout << A - B << endl;
}
