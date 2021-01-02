#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <vector>

using namespace std;

const int MOD = 1000000007;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<ll> Ax(N), Ay(N), Bx(N), By(N);
  for(int i = 0; i < N; i++) {
    cin >> Ax[i] >> Ay[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> Bx[i] >> By[i];
  }

  long double aveax = accumulate(Ax.begin(), Ax.end(), 0ll) / (long double)N;
  long double aveay = accumulate(Ay.begin(), Ay.end(), 0ll) / (long double)N;

  long double avebx = accumulate(Bx.begin(), Bx.end(), 0ll) / (long double)N;
  long double aveby = accumulate(By.begin(), By.end(), 0ll) / (long double)N;

  long double alength = 0;
  for(int i = 0; i < N; i++) {
    alength = max(alength, (aveax - Ax[i]) * (aveax - Ax[i]) +
                               (aveay - Ay[i]) * (aveay - Ay[i]));
  }

  long double blength = 0;
  for(int i = 0; i < N; i++) {
    blength = max(blength, (avebx - Bx[i]) * (avebx - Bx[i]) +
                               (aveby - By[i]) * (aveby - By[i]));
  }

  cout << setprecision(12) << pow((blength / alength), 0.5) << endl;
}
