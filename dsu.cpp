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
vector<vector<ll> > parent, rnk;

int Find(int a, int c){
  return parent[c][a] == a ? a : parent[c][a] = Find(parent[c][a], c);
}

void Union(int a, int b, int c){
  a = Find(a,c);
  b = Find(b,c);
  if(rnk[c][a] > rnk[c][b]) swap(a,b);
  parent[c][a] = b;
  rnk[c][b] += rnk[c][a];
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n;
  parent = rnk = vector<vector<ll> > (2, vector<ll> (n));
  FORN(i,0,n) {
    parent[0][i] = parent[1][i] = i;
    rnk[0][i] = rnk[1][i] = 1;
  }
  FORN(i,1,n){
    int a,b,c;
    cin>>a>>b>>c;
    a--; b--;
    Union(a,b,c);
  }
  ll ans = 0;
  FORN(i,0,n){
    if(parent[0][i] == i) ans += ((rnk[0][i] - 1) * rnk[0][i]);
    if(parent[1][i] == i) ans += ((rnk[1][i] - 1) * rnk[1][i]);
    ans += ((rnk[0][Find(i,0)] - 1) * (rnk[1][Find(i,1)] - 1));
  }
  cout<<ans<<endl;
}
