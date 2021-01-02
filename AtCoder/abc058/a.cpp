#include <iostream>
#include <string>
int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::string ans = "NO";
  if(a - b == b - c)
    ans = "YES";
  std::cout << ans << std::endl;
}
