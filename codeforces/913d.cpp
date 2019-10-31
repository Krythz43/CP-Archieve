#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
 
using namespace std;
 
#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair
 
typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;
 
const int N = 200005;
int P[N], T[N];
vi v;
vector<pii > v1;
int n;
 
bool f(int x, int t) {
  v.clear();
  rep(i,0,n) if(P[i] >= x) {
    v.pb(T[i]);
  }
  if(v.size() < x) return false;
  sort(all(v));
  rep(i,0,x) t -= v[i];
  return t >= 0;
}
 
 
int main() {
  int t;
  S2(n,t);
  rep(i,0,n) {
    S2(P[i],T[i]);
  }
  int ans = 0;
  int lo = 0, hi = n;
  while(lo <= hi) {
    int mi = (lo + hi) >> 1;
    if(f(mi, t)) {
      ans = mi;
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
  P(ans);
  P(ans);
  rep(i,0,n) if(P[i] >= ans) {
    v1.pb(mp(T[i],i+1));
  }
  sort(all(v1));
  rep(i,0,ans) printf("%d ",v1[i].SS); printf("\n");
  return 0;
}