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
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i];} cout<<endl

int main()
{
  int t;
  fastio;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vi a(n);
    rep(i,n,0)
    cin>>a[i];

    int f=0,j;
    int lc=a[n-2];
    for(int i=n-2;i>=0;i--)
    {
      if(a[i]<a[i+1])
      {
        f=1;
        for(j=i+1;j<n;j++)
        {
         if( a[j]<=a[i] )
         break;
        }
          iter_swap(a.begin()+i,a.begin()+j-1);
          std::sort(a.begin()+i+1,a.begin()+n);
          break;
      }
    }
    if(f){
    printarray(a,n);
  }
    else
    cout<<"-1"<<endl;
  }
}
