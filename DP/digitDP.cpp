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
#include <fstream>
using namespace std;

#define FORN(i,m,n) for(int i=(m); i<int(n); i++)
#define PRINTARR(a,n) FORN(i,0,n) cout<<a[i]<<" "; cout<<endl
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
typedef long long ll;

const int ms = 5005;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
int dp[10][100][2], dig[10];

int get(int pos, int dif, int t){
  int dpdif = (dif < 0) ? 50 - dif : dif;
  if(pos == 10){
    int f = 0;
    FORN(i,0,14) if(primes[i] == dif) f = 1;
    return f;
  }
  if(dp[pos][dpdif][t] != -1) return dp[pos][dpdif][t];
  int ans = 0;
  int last = t ? dig[pos] : 9;
  for(int i = 0; i <= last; i++){
    int cur = (pos & 1 ? -1 : 1) * i;
    int nt = (dig[pos] == i) ? t : 0;
    ans += get(pos+1, dif+cur, nt);
  }
  return dp[pos][dpdif][t] = ans;
}

int solve(int x){
  FORN(i,0,10) dig[i] = 0;
  int ind = 9;
  while(x){
    dig[ind] = x % 10;
    x /= 10;
    ind--;
  }
  FORN(i,0,10) FORN(j,0,100) FORN(k,0,2) dp[i][j][k] = -1;
  return get(0, 0, 1);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin>>t;
  while(t--){
    int a, b;
    cin>>a>>b;
    if(b == 1e9) b--;
    cout<<solve(b)-solve(a-1)<<endl;
  }
}
