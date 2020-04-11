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

const int ms = 1e5 + 5;
int n, q;
int tree[ms<<1];

void build(){
  for(int i = n - 1; ~i; --i) tree[i] = max(tree[i<<1], tree[i<<1|1]);
}

void update(int p, int value){
  for(tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = max(tree[p], tree[p^1]);
}

int query(int l, int r){
  int res = -1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, tree[l++]);
    if (r&1) res = max(res, tree[--r]);
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n>>q;
  FORN(i,0,n) cin>>tree[n+i];
  build();
  FORN(i,0,q){
    int a, b;
    cin>>a>>b;
    a--;
    cout<<query(a,b)<<endl; //query: [a,b)
  }
}
