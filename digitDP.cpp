#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <bitset>
using namespace std;
#define FORN(i,m,n) for(int i=m; i<(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
#define p_b(x) push_back(x)
#define m_p(a,b) make_pair(a,b)
typedef long long ll;
const int mod = 1e9+7;
ll dp[2000][2000][2];
vector<int> M;
int d,m;

ll Solve(int mm, int pos, bool tight, string &s){
  if(pos==s.size()-1) return mm==0;
  if(dp[mm][pos][tight]!=-1) return dp[mm][pos][tight];
  int top = tight ? s[pos+1]-'0'+1 : 10;
  ll cnt = 0;
  FORN(i,0,top){
    int tmp = (i*M[pos+1])+mm;
    tmp %= m;
    bool T = tight & (i==(s[pos+1]-'0'));
    if(pos&1){
      if(i!=d) cnt += Solve(tmp,pos+1,T,s);
    }
    else if(i==d) cnt += Solve(tmp,pos+1,T,s);
    cnt %= mod;
  }
  dp[mm][pos][tight] = cnt;
  return cnt;
}

void getMod(string &a){
  ll tmp = 1;
  M = vector<int> (a.size());
  for(int i=a.size()-1; i>=0; i--){
    M[i] = tmp;
    tmp*=10; tmp%=m;
  }
}

void Resta(string &s){
  int ind = s.size()-1;
  while(s[ind]=='0') s[ind--] = '9';
  s[ind]-=1;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>m>>d;
  string a,b;
  cin>>a>>b;
  getMod(a);
  Resta(a);
  
  ll ansA=0,ansB=0;
  memset(dp, -1, sizeof(dp)); 
  FORN(i,1,a[0]-'0'+1){
    int tmp = (i*M[0]) % m;
    if(i!=d) ansA += Solve(tmp,0,i==(a[0]-'0'),a);
    ansA %= mod;
  }
  memset(dp, -1, sizeof(dp)); 
  FORN(i,1,b[0]-'0'+1){
    int tmp = (i*M[0]) % m;
    if(i!=d) ansB += Solve(tmp,0,i==(b[0]-'0'),b);
    ansB %= mod;
  }
  ll ans = (ansB-ansA+mod)%mod;
  cout<<ans<<endl;
}
