#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  vector<string> s(N);
  for(int i = 0; i < N; i++) {
    cin >> s[i];
  }
  sort(s.begin(), s.end());

  for(int i = 0; i < N; i++) {
    cout << s[i];
  }
  cout << endl;
}
