#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef unsigned long long ll;
ll p=1;
vector<ll> multi;

void multiplicar(int n){
    multi.push_back(1);
    for(int i=1; i<=n; i++){
        p=(p*31);
        multi.push_back(p);
    }
}

void hasH(string s, vector<ll> &v){
    v[0]=s[0];
    for(int i=1; i<s.length(); i++){
        v[i]=v[i-1]+(s[i]*multi[i]);
        //cout<<v[i]<<endl;
    }
}

bool buscar(int a, int b, int c, int d, vector<ll> &v, vector<ll> &v1){

    ll temp1,temp2;
    int n=v.size();
    if(a==0) temp1=v[b];
    else temp1=v[b]-v[a-1];
    if(c==0) temp2=v1[d];
    else temp2=v1[d]-v1[c-1];

    temp1=temp1*multi[n-a];
    temp2=temp2*multi[n-c];

    if(temp1==temp2) return true;
    else return false;
}

int main()
{
    string s;
    cin>>s;
    multiplicar(s.length());
    vector<ll> v1(s.length());
    vector<ll> v2(s.length());
    hasH(s,v1);
    reverse(s.begin(),s.end());
    hasH(s,v2);
    vector<int> res(s.length(),0);

    for(int i=0; i<s.length()-1; i++){
        int d;
        d=s.length()-i-1;
        for(int j=i+1; j<s.length(); j++){
            int c=s.length()-j-1;
            if(buscar(i,j,c,d,v1,v2)==true) {
                bool temp=true;
                int cont=0;
                int a=i;
                int b=j;
                while(temp==true){
                    if(a==b){res[cont]++; break;}
                    else{
                        b=(a+b-1)/2;
                        temp=buscar(a,b,s.length()-b-1,s.length()-a-1,v1,v2);
                        res[cont]++;
                    }
                    cont++;
                }
            } //cout<<i<<" "<<j<<endl;}
        }
    }
    res[0]+=s.length();
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
}
