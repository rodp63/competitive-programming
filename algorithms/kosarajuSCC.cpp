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
#define FORN(i,m,n) for(ll i=(m); i<ll(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
typedef long long ll;

const int ms = 1e5 + 5;
int n, m;
vector<int> edges[ms], rev[ms], tmp;
bool vis[ms];
vector<vector<int> > SCC;
stack<int> s;

void dfs(int u, bool key){
  vis[u] = true;
  for(int e : (key ? edges[u] : rev[u])) if(!vis[e]) dfs(e, key);
  key ? s.push(u) : tmp.push_back(u);
}

void kosaraju(){
  memset(vis, 0, sizeof(vis));
  FORN(i,0,n) if(!vis[i]) dfs(i, 1);
  memset(vis, 0, sizeof(vis));
  while(!s.empty()){
    int cur = s.top();
    s.pop();
    if(!vis[cur]){
      tmp.clear();
      dfs(cur, 0);
      SCC.push_back(tmp);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n>>m;
  FORN(i,0,m){
    int a, b;
    cin>>a>>b;
    a--, b--;
    edges[a].push_back(b);
    rev[b].push_back(a);
  }
  kosaraju();
  cout<<SCC.size()<<endl;
  PRINTMAT(SCC);
}
