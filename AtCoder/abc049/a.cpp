#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  char s;
  cin >> s;
  string ans = "consonant";
  if(s == 'a' || s == 'i' || s == 'u' || s == 'e' || s == 'o')
    ans = "vowel";
  cout << ans << endl;
}
