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
using namespace std;
#define FORN(i,m,n) for(ll i=m; i<ll(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
#define p_b(x) push_back(x)
#define m_p(a,b) make_pair(a,b)
typedef long long ll;
typedef long double ld;

int n = -1;
double dist[20][20], dp[1 << 16];

double solve(int cur){
  if(dp[cur] > -1) return dp[cur];
  if(cur == (1 << 2 * n) - 1) return dp[cur] = 0;
  double ans = 1e9;
  FORN(i,0,n<<1){
    if(!(cur & (1 << i))){
      FORN(j,i+1,n<<1){
	if(!(cur & (1 << j)))
	  ans = min(ans, dist[i][j] + solve(cur | (1 << i) | (1 << j)));
      }
    }
  }
  return dp[cur] = ans;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int c = 1;
  while(cin>>n){
    if(!n) return 0;
    vector<pair<int,int> > v(n);
    FORN(i,0,n<<1){
      string a;
      int x,y;
      cin>>a>>v[i].first>>v[i].second;
    }
    FORN(i,0,n<<1){
      FORN(j,0,n<<1){
	double x = v[i].first - v[j].first;
	double y = v[i].second - v[j].second;
	dist[i][j] = sqrt((x * x) + (y * y));
      }
    }
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<c++<<": "<<fixed<<setprecision(2)<<solve(0)<<endl;
  }
}
