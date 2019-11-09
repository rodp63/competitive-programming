#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <string>
using namespace std;
#define PRINT(x) cout<<x<<endl;
#define FORN(i,m,n) for(int i=m; i<n; i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl

typedef long long ll;
typedef vector< vector<ll> > matrix;
const ll mod = 1000000007;
ll n;

matrix mult(matrix a, matrix b){
  matrix res(2,vector<ll>(2));
  FORN(i,0,2){
    FORN(j,0,2){
      ll temp = 0;
      FORN(h,0,2){
        temp += (a[i][h]*b[h][j]) % mod;
      }
      res[i][j] = (temp % mod);
    }
  }
  return res;
}

matrix solve(matrix m, ll n){
  if(n==1)
    return m;
  if(n%2)
    return mult(m,solve(m,n-1));
  matrix temp = solve(m,n/2);
  return mult(temp,temp);
}

int main(){

  cin>>n;
  matrix mat(2, vector<ll>(2));
  mat[0][0]=2; mat[0][1]=3;
  mat[1][0]=1; mat[1][1]=0;
  matrix ans = solve(mat,n);
  PRINT(ans[1][1]);
  
}
