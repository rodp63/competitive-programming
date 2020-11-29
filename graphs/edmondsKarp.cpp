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
const int ms = 1001;
const ll inf = 1e18;

int n, m, parent[ms];
ll capacity[ms][ms];
vector<int> edges[ms];

ll bfs(int s, int t) {
  fill(parent, parent + n, -1);
  queue<pair<int, ll> > q;
  q.push({s, inf});
  while (!q.empty()) {
    int cur = q.front().first;
    ll flow = q.front().second;
    q.pop();
    for (int e : edges[cur]) {
      if(parent[e] == -1 && capacity[cur][e]) {
        parent[e] = cur;
        ll min_flow = min(flow, capacity[cur][e]);
        if(e == t) return min_flow;
        q.push({e, min_flow});
      }
    }
  }
  return 0;
}

ll maxflow(int s, int t) {
  ll ans = 0, new_flow;
  while ((new_flow = bfs(s, t))) {
    ans += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }
  return ans;
}


int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n>>m;
  FORN (i,0,m) {
    int a, b, c;
    cin>>a>>b>>c;
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
    capacity[a][b] += c;
  }
  ll ans = maxflow(0, n-1);
  cout<<ans<<endl;
}
