/*
2
3 8 55
3 6 42
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define priority_queue pq;
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}


int main()
{
	fastio;
  long long int x,y,z,a,d,n,l,r;
  int t;
  cin>>t;
  while(t--)
  {
    cin>>x>>y>>z;
    l=y-x;
    r=x+y;
    n=(2*z)/r;
    d=(l)/(n-5);
    a=x-2*d;
    cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
      cout<<a<<" ";
      a+=d;
    }
    cout<<endl;

  }
}
