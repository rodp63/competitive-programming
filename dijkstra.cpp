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
const int inf = 1e9;
vector<vector<pair<int,int> > > edges;
vector<bool> vis;
vector<int> ans;

void dijkstra(int u){
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
  ans[u] = 0;
  q.push({0,u});
  while(!q.empty()){
    int cur = q.top().second;
    q.pop();
    if(vis[cur]) continue;
    vis[cur] = true;
    for(auto e : edges[cur]){
      int b = e.first, w = e.second;
      if(ans[cur] + w < ans[b]){
	ans[b] = ans[cur] + w;
	q.push({ans[b], b});
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n>>m>>k;
  edges = vector<vector<pair<int,int> > > (n);
  vis = vector<bool> (n,false);
  ans = vector<int> (n,inf);
  FORN(i,0,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--, b--;
    edges[a].emplace_back(b,c);
  }
  dijkstra(--k);
  PRINTVEC(ans);
}
