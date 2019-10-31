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
    int n,m;
    cin>>n>>m;
    vi na(n);
    vi ma(m);
    int i=0,j=0;

    rep(i,n,0)
    cin>>na[i];
    rep(i,m,0)
    cin>>ma[i];

    int ans=0;
    std::sort(na.begin(),na.begin()+n);
    std::sort(ma.begin(),ma.begin()+m);
    while(1)
    {
      if(na[i]<ma[j])
      i++;
      else
      j++;

      if(i==n)
      {
        ans=0;
        break;
      }

      if(j==m)
      {
        ans=1;
        break;
      }
    }

    if(ans)
    cout<<"Godzilla"<<endl;
    else
    cout<<"MechaGodzilla"<<endl;
  }
}
