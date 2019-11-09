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

const int N = 4e5; // MAX size
const int null = -1; // min, 0 for sum
int Tree[N];
vector<int> numbers;

int f(int a, int b){
  return max(a,b);
}

void build(int v, int l, int r){
  if(l == r) Tree[v] = numbers[l];
  else{
    int mid = (l + r) >> 1, next = (v << 1);
    build(next, l, mid);
    build(next+1, mid+1, r);
    Tree[v] = f(Tree[next],Tree[next+1]);
  }
}

int query(int v, int l, int r, int ql, int qr){
  if(ql > qr) return null;
  if(ql == l && qr == r) return Tree[v];
  int mid = (l + r) >> 1, next = (v << 1), A, B;
  A = query(next, l, mid, ql, min(qr, mid));
  B = query(next+1, mid+1, r, max(ql, mid+1), qr);
  return f(A, B);
}

void update(int v, int l, int r, int pos, int val){
  if(l == r) Tree[v] = val;
  else{
    int mid = (l + r) >> 1, next = (v << 1);
    if(pos <= mid) update(next, l, mid, pos, val);
    else update(next+1, mid+1, r, pos, val);
    Tree[v] = f(Tree[next], Tree[next+1]);
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m, ans = 0;
  cin>>n>>m;
  numbers = vector<int> (n);
  FORN(i,0,n) cin>>numbers[i];
  build(1,0,n-1);
  FORN(i,0,m){
    int a, b; cin>>a>>b;
    a--, b-=2;
    if(query(1,0,n-1,a,b) <= numbers[a]) ans++;
  }
  cout<<ans<<endl;
}
