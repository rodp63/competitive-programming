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
#include <fstream>
using namespace std;

#define FORN(i,m,n) for(int i=(m); i<int(n); i++)
#define PRINTARR(a,n) FORN(i,0,n) cout<<a[i]<<" "; cout<<endl
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
typedef long long ll;

const int ms = 3e5 + 5;
vector<int> edges[ms];
int ans, x;

void dfs(int u, int p = -1, int d = 0){
  for(int e : edges[u]){
    if(e == p) continue;
    dfs(e, u, d+1);
  }
  if(d > ans) ans = d, x = u;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n; cin>>n;
  FORN(i,1,n){
    int a, b;
    cin>>a>>b;
    a--, b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  ans = 0;
  dfs(0);
  ans = 0;
  dfs(x);
  cout<<ans<<endl;
}
