#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> crossSum(vector<int> &v, int low, int mid, int high){

  int leftsum, rightsum, maxl, maxr;
  leftsum = -INT_MAX; rightsum = -INT_MAX;
  int sum = 0;
  for(int i=mid; i>=low; i--){
    sum += v[i];
    if (sum>leftsum){
      leftsum = sum;
      maxl = i;
    }
  }
  sum = 0;
  for(int i=mid+1; i<=high; i++){
    sum += v[i];
    if(sum>rightsum){
      rightsum = sum;
      maxr = i;
    }
  }
  return {maxl, maxr, leftsum + rightsum};
  
}

vector<int> maxSub(vector<int> &v, int low, int high){

  vector<int> l,r,c;
  
  if (high == low){
    return {low, high, v[low]};
  }
  else{
    int mid = (low+high)/2;
    l = maxSub(v,low,mid);
    r = maxSub(v,mid+1,high);
    c = crossSum(v,low,mid,high);

    if(l[2] >= r[2] && l[2]>= c[2]) return l;
    else if (r[2] >= l[2] && r[2] >= c[2]) return r;
    else return c;
  }
  
}

int main(){

  vector<int> v = {1,-2,3,-4,5,-6,7};//{13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
  vector<int> ans;
  ans = maxSub(v,0,v.size()-1);
  cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
  
}
