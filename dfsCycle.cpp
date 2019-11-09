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
#define FORN(i,m,n) for(int i=m; i<(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
#define p_b(x) push_back(x)
#define m_p(a,b) make_pair(a,b)
typedef long long ll;

int n, m, k = 1;
vector<vector<int> > edges;
map<pair<int,int>,int> ans;
vector<int> state;
vector<pair<int,int> > ord;

void dfs(int u){
  state[u] = 1;
  FORN(i,0,edges[u].size()){
    if(state[edges[u][i]] == 0) dfs(edges[u][i]);
    else if(state[edges[u][i]] == 1){
      ans[{u,edges[u][i]}] = 2;
      k = 2;
    }
  }
  state[u] = 2;
}
 
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n>>m;
  edges = vector<vector<int> > (n);
  state = vector<int> (n,0);
  FORN(i,0,m){
    int a, b; cin>>a>>b;
    a--, b--;
    edges[a].p_b(b);
    ans[{a,b}] = 1;
    ord.emplace_back(a,b);
  }
  FORN(i,0,n) if(state[i] == 0) dfs(i);
  cout<<k<<endl;
  FORN(i,0,m) cout<<ans[ord[i]]<<" "; cout<<endl;
}
