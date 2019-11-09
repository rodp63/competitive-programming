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

int table[100005][25];
 
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, q; cin>>n;
  FORN(i,0,n) cin>>table[i][0];
  FORN(j,1,25){
    for(int i = 0; i + (1 << j) <= n; i++){
      table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
    }
  }
  cin>>q;
  while(q--){
    int a, b, j; cin>>a>>b;
    j = log2(b - a + 1);
    cout<<min(table[a][j], table[b-(1<<j)+1][j])<<endl;
    /*
    ll sum = 0;
    for (int j = 25; j >= 0; j--) {
      if ((1 << j) <= R - L + 1) {
        sum += st[L][j];
        L += 1 << j;
      }
    }
    */
  }
}
