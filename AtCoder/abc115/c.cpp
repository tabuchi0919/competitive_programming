#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

vector<int64> arr;

void rec(string s, int a, int b, int c) {
  if(s.size() > 10)
    return;
  rec(s + "3", true, b, c);
  rec(s + "5", a, true, c);
  rec(s + "7", a, b, true);
  if(s.size() && a && b && c)
    arr.push_back(stoll(s));
}

int main() {
  int N;
  cin >> N;
  int ret = 0;
  rec("", false, false, false);
  for(auto &p : arr) {
    ret += p <= N;
  }
  cout << ret << endl;
}
