#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
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
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}

int main()
{
    fastio;
    int n,k,t;
    cin>>n>>k;
     vector<int> a(n*k+1,0);
     rep(i,k+1,1)
     {
         cin>>t;
         a[t]=i;
     }

     int r=1;
     t=0;

     rep(i,n*k+1,1)
     {
         if(t==n-1)
         {
             r++;
             t=0;
         }
         if(a[i]==0)
         {
            a[i]=r;
            t++;
         }
     }

     rep(i,k+1,1)
     {
         rep(j,n*k+1,1)
         {
             if(a[j]==i)
             cout<<j<<" ";
         }
         nl;
     }

}