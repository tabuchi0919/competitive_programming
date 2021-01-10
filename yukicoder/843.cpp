#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

const int INF = (1 << 30) - 1;
const ll INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()

// vector<bool> IsPrime;

// void sieve(int max){
//   if(max+1 > IsPrime.size()){
//     IsPrime.resize(max+1,true);
//   }
//   IsPrime[0] = false;
//   IsPrime[1] = false;

//   sieve(N);
//   for(int i=2; i*i<=max; ++i){
//     if(IsPrime[i]){
//       for(int j=2; i*j<=max; ++j){
//         IsPrime[i*j] = false;
//       }
//     }
//   }
// }
//   for(int i=0;i<N;i++){
//     if(IsPrime[i])primes.push_back(i);
//   }
//   vector<int> ans;
//   for(auto r : primes){
//     if(r*r>2*N)break;
//     for(auto p : primes){
//       int q=r*r-p;
//       auto low = lower_bound(ALL(primes), q);
//       auto up = upper_bound(ALL(primes), q);
//       if(up-low>0)ans.push_back(max({p,q,r}));
//     }
//   }
//   for(int i=0;i<81;i++){
//     cout<<ans[i]<<endl;
//   }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> p = {
      2,      7,      7,      23,     23,     47,     47,     167,    167,
      359,    359,    839,    839,    1367,   1367,   1847,   1847,   2207,
      2207,   3719,   3719,   5039,   5039,   7919,   7919,   10607,  10607,
      11447,  11447,  16127,  16127,  17159,  17159,  19319,  19319,  29927,
      29927,  36479,  36479,  44519,  44519,  49727,  49727,  54287,  54287,
      57119,  57119,  66047,  66047,  85847,  85847,  97967,  97967,  113567,
      113567, 128879, 128879, 177239, 177239, 196247, 196247, 201599, 201599,
      218087, 218087, 241079, 241079, 273527, 273527, 292679, 292679, 323759,
      323759, 344567, 344567, 368447, 368447, 426407, 426407, 458327, 458327};
  int ans = 0;
  for(int i = 0; i < 81; i++) {
    if(p[i] <= N)
      ans++;
  }
  cout << ans << endl;
}
