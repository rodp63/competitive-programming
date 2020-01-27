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
#define PB(x) push_back(x)
#define MP(a,b) make_pair(a,b)
typedef long long ll;

const int ms = 1e5 + 5;
int n, m, ans = 0;
vector<tuple<int,int,int> > edges;
int parent[ms], rnk[ms];

int Find(int u){ return u == parent[u] ? u : parent[u] = Find(parent[u]); }

void Union(int a, int b){
  if(rnk[a] < rnk[b]) swap(a,b);
  rnk[a] += rnk[b];
  parent[b] = parent[a];
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n>>m;
  FORN(i,0,n) parent[i] = i, rnk[i] = 1;
  FORN(i,0,m){
    int a, b, w;
    cin>>a>>b>>w;
    edges.emplace_back(w,a,b);
  }
  sort(edges.begin(), edges.end());
  FORN(i,0,m){
    int a, b, w;
    tie(w,a,b) = edges[i];
    a = Find(a);
    b = Find(b);
    if(a != b){
      Union(a,b);
      ans += w;
    }
  }
  cout<<ans<<endl;
}
