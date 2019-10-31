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

#define mod 1000000007
int main()
{
    int t;
    fastio;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>m>>n;
        vi a(m);
        vi b(m);

        lli suma=0,sumb=0;

        rep(i,m,0)
        {
            cin>>a[i];
            suma=(suma+a[i])%mod;
        }

        rep(i,m,0)
        {
            cin>>b[i];
            sumb=(sumb+b[i])%mod;
        }


         vi fib(n+1);
         fib[1]=(suma*m)%mod;
         fib[2]=(sumb*m)%mod;

         for(int i=3;i<=n;i++)
         fib[i]=(fib[i-1] + fib[i-2])%mod; 

         cout<<(fib[n])%mod<<endl;

    }
}

