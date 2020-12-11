#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <string>
#include <iomanip>
#include <locale>
#include <list>
#include <bitset>
#include <tuple>
#include <fstream>
using namespace std;
 
#define FORN(i,m,n) for(int i=(m); i<int(n); ++i)
#define PRINTARR(a,n) FORN(i,0,n) cout<<a[i]<<" "; cout<<endl
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}

typedef long long ll;

const int ALPHA_SIZE = 27;

struct Trie {
  struct Node {
    Node* child[ALPHA_SIZE];
    bool is_word;
    Node() {
      for (int i = 0; i < ALPHA_SIZE; ++i) child[i] = nullptr;
      is_word = false;
    }
  };
  Node* root;
  Trie() : root(new Node) {} 
  void insert(string key) {
    Node *cur = root;
    for (int i = 0; i < key.size(); ++i) {
      int index = key[i] - 'a';
      if(!cur->child[index]) {
        cur->child[index] = new Node;
      }
      cur = cur->child[index];
    }
    cur->is_word = true;
  } 
  bool search(string key) {
    Node *cur = root;
    for (int i = 0; i < key.size(); ++i) {
      int index = key[i] - 'a';
      cur = cur->child[index];
      if(!cur) {
        return false;
      }
    }
    return cur->is_word;
  }
};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  Trie t;
  t.insert("carry");
  t.insert("car");
  t.insert("supp");
  cout<<t.search("car")<<endl;
  cout<<t.search("carr")<<endl;
}
