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
using namespace std;
#define FORN(i,m,n) for(int i=(m); i<int(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
typedef long long ll;

vector<int> getz(string &s){
  int x = 0, y = 0;
  vector<int> z(s.size(), 0);
  FORN(i,1,s.size()){
    z[i] = max(0, min(z[i-x], y-i+1));
    while(i + z[i] < s.size() && s[z[i]] == s[i+z[i]]) z[i]++;
    if(i + z[i] - 1 > y){
      x = i;
      y = i + z[i] - 1;
    }
  }
  return z;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string s, pat, S;
  cin>>s>>pat;
  S = pat + '#' + s;
  vector<int> z = getz(S);
  int ans = 0;
  FORN(i, pat.size()+1, S.size()) ans += (z[i] == pat.size());
  cout<<ans<<endl;
}
