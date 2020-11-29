#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <string>
#include <iomanip>
#include <locale>
#include <list>
#include <bitset>
#include <tuple>
#include <fstream>
using namespace std;
 
#define FORN(i,m,n) for(int i=(m); i<int(n); ++i)
#define PRINTARR(a,n) FORN(i,0,n) cout<<a[i]<<" "; cout<<endl
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
 
typedef long long ll;
const int ms = 1e5 + 5;
int d1[ms], d2[ms], n;
string s;

void manacher(){
  int l = 0, r = -1;
  FORN(i,0,n){
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
    d1[i] = k--;
    if(i + k > r){
      l = i - k;
      r = i + k;
    }
  }
  l = 0, r = -1;
  FORN(i,0,n){
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) k++;
    d2[i] = k--;
    if(i + k > r){
      l = i - k - 1;
      r = i + k ;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  while(cin>>s){
    n = s.size();
    manacher();
    int ans = 1;
    FORN(i,0,n){
      if(i + d1[i] == n) ans = max(ans, 2 * d1[i] - 1);
      if(i + d2[i] == n) ans = max(ans, 2 * d2[i]);
    }
    cout<<s;
    for(int i = n - ans - 1; ~i; --i) cout<<s[i];
    cout<<endl;
  }
}
