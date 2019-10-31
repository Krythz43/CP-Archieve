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
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
lli llmax(lli a,lli b){if(a>b)return a; return b;}

int main()
{
    fastio;
    int n,m;
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0)
        break;

        vi d(n),a(m);
        rep(i,n,0)
        cin>>d[i];
        rep(i,m,0)
        cin>>a[i];

        sort(d.begin(),d.end());
        sort(a.begin(),a.end());
        int ans=0,dp=0,ap=0;
        while(1)
        {
            if(dp==n || ap==m)
            break;
            if(a[ap]>=d[dp])
            {
                ans+=a[ap];
                dp++;
            }
            ap++;
        }

        if(dp==n)
        cout<<ans<<endl;
        else
        cout<<"Loowater is doomed!"<<endl;
    }
}