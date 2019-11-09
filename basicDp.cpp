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
 
ll dp[300005][3];
int n;
vector<pair<ll,ll> > fence(300005);
 
ll Solve(int pos, int prev){
  if(pos == n) return 0;
  if(dp[pos][prev] != -1) return dp[pos][prev];
  ll ans = 1e18;
  FORN(i,0,3){
    if(pos == 0 || fence[pos].first + i != fence[pos-1].first + prev){
      ans = min(ans, fence[pos].second * i + Solve(pos + 1, i));
    }
  }
  return dp[pos][prev] = ans;
}
 
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int q; cin>>q;
  while(q--){
    cin>>n;
    FORN(i,0,n) FORN(j,0,3) dp[i][j] = -1;
    FORN(i,0,n) cin>>fence[i].first>>fence[i].second;
    cout<<Solve(0,0)<<endl;
  }
}
