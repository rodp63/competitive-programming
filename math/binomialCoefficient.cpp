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

const int mod = 1e9 + 7;
 
ll fact(ll a){
  ll ans = 1;
  for(int i = 2; i <= a; i++) ans = (ans * i) % mod;  
  return ans;
}
 
ll exp(ll a, ll b){
  ll ans = 1;
  a %= mod;
  while(b){
    if ((b & 1) == 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
 
ll solve(ll k, ll n){
  ll x = max(n - k, k);
  ll ans = 1;
  for(ll i = x + 1; i <= n; i++) ans = (ans * i) % mod;
  ans = (ans * exp(fact(n - x), mod - 2)) % mod;
  return ans;
}
 
int main(){
  ll n, a, ans;
  cin>>n>>a;
  ans = solve(a, n);
  cout<<ans<<endl;
}
