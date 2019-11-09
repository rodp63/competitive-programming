#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
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

vector<int> cost, tmp;
vector<vector<int> > A,B,SCC;
vector<bool> vis;
stack<int> S;
int n,m;
const ll mod = 1000000007;

void DFS(int u, vector<vector<int> > &V, bool fill){
  vis[u]=true;
  FORN(i,0,V[u].size()) if(!vis[V[u][i]]) DFS(V[u][i],V,fill);
  if(fill) tmp.p_b(cost[u]);
  else S.push(u);
}

void getSCC(){
  vis = vector<bool> (n+1,false);
  FORN(i,1,n+1) if(!vis[i]) DFS(i,A,false);
  vis = vector<bool> (n+1,false);
  while(!S.empty()){
    int u = S.top();
    S.pop();
    if(!vis[u]) {
      tmp.clear();
      DFS(u,B,true);
      SCC.p_b(tmp);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n;
  cost = vector<int> (n+1);
  FORN(i,1,n+1) cin>>cost[i];
  cin>>m;
  A = B = vector<vector<int> > (n+1);
  FORN(i,0,m){
    int a,b;
    cin>>a>>b;
    A[a].p_b(b);
    B[b].p_b(a);
  }
  getSCC();
  ll ans = 1, cnt = 0, tmp;
  FORN(i,0,SCC.size()){
    sort(SCC[i].begin(),SCC[i].end());
    cnt += SCC[i][0];
    tmp = 1; while(tmp<SCC[i].size() && SCC[i][tmp]==SCC[i][0]) tmp++;
    ans *= tmp; ans %= mod;
  }
  cout<<cnt<<" "<<ans<<endl;
}

