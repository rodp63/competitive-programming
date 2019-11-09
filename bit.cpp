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
using namespace std;
#define FORN(i,m,n) for(int i=m; i<(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
#define p_b(x) push_back(x)
#define m_p(a,b) make_pair(a,b)
typedef long long ll;

int n;
vector<ll> v, parent, ans, bit;

int Find(int u){return parent[u]==u ? u : parent[u] = Find(parent[u]);}

void update(int u, int dif){
  for(int i = u; i < bit.size(); i = i | (i + 1)) bit[i] += dif; 
}

ll query(int u){
  ll res = 0;
  for(int i = u; i >= 0; i = (i & (i + 1)) - 1) res += bit[i];
  return res;
}

int get(ll val){
  ll l = 0, r = n - 1, mid, res;
  while(r >= l){
    mid = (l + r)/2;
    res = query(mid);
    if(res < val) l = mid + 1;
    else r = mid - 1;
  }
  return Find(l) + 1;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n;
  v = parent = ans = bit = vector<ll> (n);
  FORN(i,0,n) cin>>v[i];
  FORN(i,0,n){
    parent[i] = i;
    update(i, i);
  }
  for(int i = n - 1; i >= 0; i--){
    int pos = get(v[i]);
    ans[i] = pos;
    if(pos < n) update(pos, -pos);
    parent[pos - 1] = pos;
  }
  PRINTVEC(ans);
}
