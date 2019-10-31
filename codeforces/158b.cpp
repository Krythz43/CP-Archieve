#include <bits/stdc++.h>
#include <string.h>
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

#define mod 1000003


int main()
{
    fastio;
    int a[5]={0};
    int n;
    cin>>n;
    int t;
    rep(i,n,0)
    {
        cin>>t;
        a[t]++;
    }
    int ans=a[4],mine;
    mine=min(a[1],a[3]);
    ans+=mine;
    a[1]-=mine;
    a[3]-=mine;
    ans+=a[3];
    ans+=a[2]/2;
    a[2]%=2;
    if(a[2]>0)
    {
        ans++;
        if(a[1]<3)
            a[1]=0;
        else
            a[1]-=2;
    }

    ans+=ceil(a[1]/(4.0));
    cout<<ans;
}