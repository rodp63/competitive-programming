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
typedef pair<pair<int,int>,string> node;
int d,s;
vector<vector<bool> > vis;

string bfs(){
  queue<node> q;
  q.push(make_pair(make_pair(0,0),""));
  vis[0][0]=true;
  while(!q.empty()){
    node temp = q.front();
    q.pop();
    if(temp.first.second>s) continue;
    if(temp.first.first==0 && temp.first.second==s){
      return temp.second;
    }
    FORN(i,0,10){
      int mod = ((temp.first.first*10)+i)%d;
      int sum = (i+temp.first.second);
      if(!vis[mod][sum]){
	vis[mod][sum]=true;
	q.push(make_pair(make_pair(mod,sum),temp.second+char(i+'0')));
      }
    }
  }
  return "-1";
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cin>>d>>s;
  vis = vector<vector<bool> >(506,vector<bool>(5006,false));
  string ans = bfs();
  PRINT(ans);
}
