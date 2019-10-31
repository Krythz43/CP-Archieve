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

int gcd(int a, int b)
{
   if (a == b)
      return a;
   if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

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
    int count=0;

    std::sort(a.begin(),a.begin()+n);
    int z=gcd(a[0],a[1]);
    
    rep(i,n,0)
    {
      if(a[i]%z==0)
      count++;
      else
      break;
    }

    if(z==1)
    cout<<"0"<<endl;
    else if(count==n)
    cout<<"-1"<<endl;
    else
    cout<<"0"<<endl;

  }
}
