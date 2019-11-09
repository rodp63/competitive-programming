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
#define FORN(i,m,n) for(int i=m; i<int(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
#define p_b(x) push_back(x)
#define m_p(a,b) make_pair(a,b)
typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string s; cin>>s;
  int n = s.size(), ms = 1 << 20;
  vector<int> dp(ms, 0);
  FORN(i,0,n){
    vector<bool> vis(20,false);
    int mask = 0, ind = i;
    while(ind < n && !vis[s[ind] - 'a']){
      vis[s[ind] - 'a'] = true;
      mask |= (1 << (s[ind++] - 'a'));
      dp[mask] = __builtin_popcount(mask);
    }
  }
  FORN(i,0,ms){
    FORN(j,0,20){
      if((i >> j) & 1){
	dp[i] = max(dp[i], dp[i ^ (1 << j)]);
      }
    }
  }
  int ans = 0;
  FORN(i,0,ms){
    int comp = ~i & (ms - 1);
    ans = max(ans, dp[i] + dp[comp]);
  }
  cout<<ans<<endl;
}
