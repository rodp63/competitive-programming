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

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n,m,k;
 const ll inf = 1e18;
  cin>>n>>m>>k;
  vector<vector<ll> > v(m,vector<ll>(3));
  FORN(i,0,m) {
    cin>>v[i][1]>>v[i][2]>>v[i][0];
    v[i][1]--;
    v[i][2]--;
  }
  vector<int> idx(n,-1); int ind = 0;
  vector<vector<ll> > M(805, vector<ll> (805, inf));
  sort(v.begin(),v.end());
  FORN(i,0,min(m,k)){
    int a = v[i][1];
    int b = v[i][2];
    if(idx[a] < 0) idx[a] = ind++;
    if(idx[b] < 0) idx[b] = ind++;
    a = idx[a];
    b = idx[b];
    M[a][b] = M[b][a] = v[i][0];
  }
  FORN(i,0,ind) M[i][i] = 0;
  FORN(k,0,ind){
    FORN(i,0,ind){
      FORN(j,0,ind){
        M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
      }
    }
  }
  vector<ll> ans;
  FORN(i,0,ind){
    FORN(j,i+1,ind){
      ans.p_b(M[i][j]);
    }
  }
  sort(ans.begin(), ans.end());
  cout<<ans[k-1]<<endl;
}
