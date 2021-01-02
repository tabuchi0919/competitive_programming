#include <iostream>
#include <string>

using namespace std;

int main() {
  string O, E;
  cin >> O >> E;
  for(int i = 0; i < O.size() + E.size(); i++) {
    if(i % 2 == 0)
      cout << O[i / 2];
    else
      cout << E[i / 2];
  }
  cout << endl;
}
