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
typedef long double ld;

int n, m, s;
const int ms = 200005;
vector<vector<int> > edges;
int state[ms], parent[ms], cmp[ms];

int Find(int u){return cmp[u] == u ? u : cmp[u] = Find(cmp[u]);}

void DFS(int u, int p){
  if(state[u] == 2) return;
  if(state[u] == 1){
    int a = Find(p), b = Find(u);
    while(a != b){
      cmp[a] = b;
      a = parent[a];
      a = Find(a);
    }
    return;
  }
  parent[u] = p;
  state[u] = 1;
  FORN(i,0,edges[u].size()) if(edges[u][i] != p) DFS(edges[u][i], u);
  state[u] = 2;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n>>m;
  edges = vector<vector<int> > (n);
  FORN(i,0,n) state[i] = 0, cmp[i] = i;
  FORN(i,0,m){
    int a, b;
    cin>>a>>b;
    a--, b--;
    edges[a].p_b(b);
    edges[b].p_b(a);
  }
  cin>>s; s--;
  DFS(s,-1);
}
