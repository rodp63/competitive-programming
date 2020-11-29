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
using namespace std;
#define FORN(i,m,n) for(ll i=(m); i<ll(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
typedef long long ll;

const int inf = 1e9;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m, u;
  cin>>n>>m>>u; //n -> nodes, m -> edges, u -> head
  vector<tuple<int,int,int> > edges;
  FORN(i,0,m){
    int a, b, w; cin>>a>>b>>w;
    a--, b--;
    edges.emplace_back(a,b,w);
    edges.emplace_back(b,a,w);
  }
  vector<int> distance(n, inf);
  distance[--u] = 0;
  bool flag = true;
  while(flag){
    flag = false;
    for(auto e : edges){
      int a, b, w, cur;
      tie(a,b,w) = e;
      cur = distance[a] + w;
      if(cur < distance[b]){
	distance[b] = cur;
	flag = true;
      }
    }
  }
  PRINTVEC(distance);
  // max n - 1 rounds if no negative cycles.
}
