#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <locale>
#include <list>
using namespace std;
#define FORN(i,m,n) for(ll i=m; i<ll(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
#define p_b(x) push_back(x)
#define m_p(a,b) make_pair(a,b)
typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
vector<ll> f(1e6);

ll exp(ll a, ll b){
  ll ans = 1;
  a = a % mod;
  while (b > 0){
    if ((b & 1) == 1){
      ans *= a;
      ans = ans % mod;
    }
    a *= a;
    a = a % mod;
    b >>= 1;
  }
  return ans;
}

ll C(int k, int n){
  return f[n] * exp(f[k],mod-2) % mod * exp(f[n - k],mod-2) % mod;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  f[0] = 1;
  for (int i = 1; i <= 1e6; i++) {
    f[i] = f[i - 1] * i % mod;
  }
  int a, b; cin>>a>>b;
  cout<<C(a,b)<<endl;
}
