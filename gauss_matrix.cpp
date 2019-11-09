#include <iostream>
#include <vector>
using namespace std;

vector<float> gauss(vector< vector<float> > &v, int n){

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(j==i || v[i][i]==0) continue;
      float temp = -(v[j][i]/v[i][i]);
      for(int h=0; h<n+1; h++){
	v[j][h] += (temp*v[i][h]);
      }
      /*
      for(int x=0; x<n; x++){
	for(int y=0; y<n+1; y++)
	  cout<<v[x][y]<<" ";
	cout<<endl;
      }
      cout<<endl;
      */
    }
  }
  vector<float> res(n);
  for(int i=0; i<n; i++){
    if(v[i][i]==0) continue;
    float temp = 1/v[i][i];
    res[i] = temp * v[i][n];
  }
  return res;	 

}

int main(){

  int n;
  cin>>n;
  vector< vector<float> > v(n,vector<float> (n+1));
  for(int i=0; i<n; i++)
    for(int j=0; j<n+1; j++)
      cin>>v[i][j];
  vector<float> ans = gauss(v,n);
  for(int i=0; i<n; i++)
    cout<<ans[i]<<" ";
  cout<<endl;

  return 0; 
  
}
