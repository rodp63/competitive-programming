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

int n,m,k;
const ll inf = 1e18;
vector<vector<pair<ll,ll> > > edges;
vector<bool> vis;
vector<ll> ans;

void path(int u){
  vector<ll> dist(n,inf);
  vector<bool> reach(n,false);
  priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > q;
  q.push(m_p(0,u));
  while(!q.empty()){
    int cur = q.top().second;
    ll w = q.top().first;
    q.pop();
    if(!reach[cur]){
      reach[cur] = true;
      dist[cur] = w;
      if(w && !vis[cur]) ans.p_b(w);
      FORN(i,0,edges[cur].size()){
	int d = edges[cur][i].first;
	ll t = edges[cur][i].second;
	if(!reach[d]) q.push(m_p(t + w,d));
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n>>m>>k;
  vector<vector<ll> > v(m,vector<ll>(3));
  edges = vector<vector<pair<ll,ll> > > (n);
  FORN(i,0,m) {
    cin>>v[i][1]>>v[i][2]>>v[i][0];
    v[i][1]--;
    v[i][2]--;
  }
  sort(v.begin(),v.end());
  FORN(i,0,min(m,k)){
    int a = v[i][2];
    int b = v[i][1];
    edges[a].p_b(m_p(b,v[i][0]));
    edges[b].p_b(m_p(a,v[i][0]));
  }
  vis = vector<bool> (n,false);
  FORN(i,0,n) {
    if(edges[i].size()){
      vis[i] = true;
      path(i);
    }
  }
  sort(ans.begin(),ans.end());
  cout<<ans[k-1]<<endl;
}
