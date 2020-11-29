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
#define FORN(i,m,n) for(ll i=(m); i<ll(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
#define PB(x) push_back(x)
#define MP(a,b) make_pair(a,b)
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, k, len = 1;
  cin>>n>>k; k--;
  vector<int> succ(n);
  FORN(i,0,n){
    cin>>succ[i];
    succ[i]--;
  }
  int a = succ[k], b = succ[a];
  while(a != b){
    a = succ[a];
    b = succ[succ[b]];
  }
  a = k;
  while(a != b){
    a = succ[a];
    b = succ[b];
  }
  b = succ[b];
  while(a != b){
    b = succ[b];
    len++;
  }
  cout<<++a<<" "<<len<<endl;
}
