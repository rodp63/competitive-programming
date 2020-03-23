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
#include <string>
#include <iomanip>
#include <locale>
#include <list>
#include <bitset>
#include <tuple>
using namespace std;
#define FORN(i,m,n) for(int i=(m); i<int(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
typedef long long ll;
 
const ll mod = 1e9 + 7, ms = (1ll << 31) - 1;
 
void Hash(string &s, vector<ll> &v, vector<ll> &m){
  v[0] = s[0];
  FORN(i,1,s.size()) v[i] = (v[i-1] + ((s[i] * m[i]) % mod)) % mod;
}
 
bool match(int a, int b, int c, int d, vector<ll> &h1, vector<ll> &m){
  ll x, y;
  int n = h1.size();
  x = h1[b];
  if(a) x = (x - h1[a-1] + mod) % mod;
  y = h1[d];
  if(c) y = (y - h1[c-1] + mod) % mod;
  x = (x * m[n-a]) % mod;
  y = (y * m[n-c]) % mod;
  return x == y;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string s; cin>>s;
  int a, b, c, d;
  cin>>a>>b>>c>>d;
  int n = s.size();
  vector<ll> m(n+1), h1(n);
  m[0] = 1;
  FORN(i,1,n+1) m[i] = (m[i-1] * ms) % mod;
  Hash(s, h1, m);
  cout<<(match(a,b,c,d,h1,m) ? "YES" : "NO")<<endl;
}
