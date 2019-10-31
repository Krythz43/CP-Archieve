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
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vlli a(n);

        rep(i,n,0)
        cin>>a[i];

        lli ans=0;

        rep(i,n,0)
        {
            ans^=(2*a[i]);
        }

        cout<<ans<<endl;
    }
}