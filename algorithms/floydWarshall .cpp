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
typedef long long ll;

const ll inf = 1e18;
const int ms = 500;
ll dis[ms][ms];
int n, m;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n>>m; // n -> nodes, m -> edges
  FORN(i,0,n) FORN(j,0,n) dis[i][j] = inf;
  FORN(i,0,n) dis[i][i] = 0;
  FORN(i,0,m){
    ll a, b, w;
    cin>>a>>b>>w;
    a--, b--;
    dis[a][b] = dis[b][a] = w;
  }
  FORN(k,0,n){
    FORN(i,0,n){
      FORN(j,0,n){
	dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  FORN(i,0,n) {FORN(j,0,n) cout<<dis[i][j]<<" "; cout<<endl;}
}
