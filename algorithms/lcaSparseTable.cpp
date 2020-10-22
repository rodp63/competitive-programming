#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <string>
#include <iomanip>
#include <locale>
#include <list>
#include <bitset>
#include <tuple>
#include <fstream>
using namespace std;
 
#define FORN(i,m,n) for(int i=(m); i<int(n); ++i)
#define PRINTARR(a,n) FORN(i,0,n) cout<<a[i]<<" "; cout<<endl
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
 
typedef long long ll;
const int ms = 1e5 + 5;
vector<int> edges[ms], v;
int n, cur, pos[ms];
int table[ms][25];

void dfs(int u, int p = -1){
  pos[u] = cur;
  int idx = v.size();
  v.push_back(u);
  table[cur][0] = idx;
  for(int e : edges[u]){
    if(e == p) continue;
    cur++;
    dfs(e, u);
    cur++;
    table[cur][0] = idx;
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n;
  FORN(i,1,n){
    int a, b;
    cin>>a>>b;
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  cur = 0;
  dfs(0);
  int m = ++cur;
  FORN(j,1,25){
    for(int i = 0; i + (1 << j) <= m; i++){
      table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
    }
  }
  int a, b, l;
  cin>>a>>b;
  a = pos[a-1];
  b = pos[b-1];
  if(a > b) swap(a, b);
  l = 31 - __builtin_clz(b - a + 1);
  int id = min(table[a][l], table[b-(1<<l)+1][l]);
  cout<<v[id]+1<<endl;
}
