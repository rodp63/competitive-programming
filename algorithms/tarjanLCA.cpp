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
int n, q, root;
vector<int> edges[ms], ans;
vector<pair<int,int> > queries[ms];
bool vis[ms];
int parent[ms];

int Find(int u){ return u == parent[u] ? u : parent[u] = Find(parent[u]); }

void dfs(int u){
  vis[u] = true;
  parent[u] = u;
  for(int e : edges[u]){
    dfs(e);
    parent[e] = u;
  }
  for(pair<int,int> x : queries[u]){
    if(vis[x.first]){
      ans[x.second] = Find(x.first) + 1;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n;
  FORN(i,0,n){
    int x; cin>>x; // x is the parent of i-th node
    if(x != -1) edges[--x].push_back(i);
    else root = i;
  }
  cin>>q;
  FORN(i,0,q){
    int a, b;
    cin>>a>>b;
    a--, b--;
    queries[a].emplace_back(b,i);
    queries[b].emplace_back(a,i);
  }
  memset(vis, 0, sizeof(vis));
  ans = vector<int> (q);
  dfs(root);
  PRINTVEC(ans);
}
