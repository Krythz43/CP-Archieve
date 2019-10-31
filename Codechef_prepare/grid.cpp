#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define umap unordered_map
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
    int n,m;
    cin>>n>>m;
    vector<vi > a(n,vector <int> (m));

    rep(i,n,0)
    {
        char y[m+10];
        cin>>y;
        rep(k,m,0)
        {
            a[i][k]=y[k]-'0';
        }
    }
    vector<vi > f(n,vector <int> (m));

    rep(i,m,0)
    {
        if(a[n-1][i]==1)
        f[n-1][i]=1;
        else
        f[n-1][i]=0;
    }

    for(int i=n-2;i>=0;i--)
    {
        rep(j,m,0)
        {
            f[i][j]=(a[i][j]==1)?f[i+1][j]+1:0;
        }
    }

    // vector<vi > ans(n,vector <int> (m,0));

    // rep(i,n,0)
    // {
    //     rep(j,m,1)
    //     {
    //         ans[i][j]=min(f[i][j],f[i][j-1]);
    //         ans[i][j]=max(ans[i][j],a[i][j]);
    //     }
    // }

    lli ovans=0;

    rep(i,n,0)
    {
        int last=0;
        rep(j,m,0)
        {
            ovans+=last=min(last+1,f[i][j]);
            // cout<<last<<" ";
        }
        // nl;
    }

    cout<<ovans;
}