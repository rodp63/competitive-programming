#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <string>
#include <iomanip>
using namespace std;
#define PRINT(x) cout<<x<<endl;
#define FORN(i,m,n) for(int i=m; i<n; i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}

typedef long long ll;
typedef vector< vector<int> > matrix;

void MakeLcp(vector<int> &v, string s){
  v[0]=0; int j=0, i=1;
  while(i<s.size()){
    if(s[i]==s[j]){
      v[i++]=++j;
    }
    else{
      if(j==0){
	v[i++]=0;
      }
      else{
	j=v[j-1];
      }
    }}
}

void KMP(string t, string s, vector<int> &v){
  int i=0, j=0;
  while(i<t.size()){
    if(s[j]==t[i]){
      i++; j++;
    }
    else{
       if(j!=0){
	j=v[j-1];
      }
      else{
	i++;
      }
    }
    if(j==s.size()){
      cout<<"PAtt! "<<i-j<<endl;
      j=v[j-1];
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  string text = "abababa";
  string patt = "aba";
  vector<int> lcp(patt.size());
  
  MakeLcp(lcp,patt);
  PRINTVEC(lcp);
  KMP(text,patt,lcp);
}
