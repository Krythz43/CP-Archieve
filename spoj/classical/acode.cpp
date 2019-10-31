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
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";} cout<<endl

int main()
{
  while(1)
  {
    string s;
    cin>>s;
    if(s[0]=='0')
    break;
    else
    {
      int l=s.length();
      vi a(l+1);
      a[0]=1;
      a[1]=1;

      rep(i,l,1)
      {
        if(s[i]-'0'>6)
        a[i+1]=a[i];
        else
        {
          if(s-'0'>2)
          a[i+1]=a[i];
          else
          a[i+1]=a[i-1]+a[i];
        }
      }
      //printarray(a,l+1);
      cout<<a[l]<<endl;
    }
  }
}
