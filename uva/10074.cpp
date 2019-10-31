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


struct l
{
    int l,r;
};


int main()
{
    fastio;
    int n,m;
    while(1)
    {
        cin>>n>>m;

        if(n==0 && m==0)
        break;

        vector<vi > a(n,vi (m));
        vector<vector<l> > ans(n,vector<l> (m));

        rep(i,n,0)
        rep(j,m,0)
        {   
            cin>>a[i][j];
            ans[i][j].l=ans[i][j].r=0;
        }

        if(a[0][0]==0)
        ans[0][0].l=ans[0][0].r=1;

        rep(i,m,1)
        {
            if(a[0][i]==0)
            {ans[0][i].l=ans[0][i-1].l+1;
            ans[0][i].r=1;}
        }

        rep(i,n,1)
        {
            if(a[i][0]==0)
            {ans[i][0].r=ans[i-1][0].r+1;
            ans[i][0].l=1;}
        }
        

        rep(i,n,1)
        {
            rep(j,m,1)
            {
                if(a[i][j]==0)
                {
                    ans[i][j].l=ans[i][j-1].l+1;
                    ans[i][j].r=ans[i-1][j].r+1;
                }
            }
        }

        // cout<<n<<" "<<m<<endl;
        // ans[0][0].r=0;

        int maxe=-INT_MAX;
        rep(i,n,0)
        {
            rep(j,m,0)
            maxe=max(ans[i][j].l*ans[i][j].r,maxe);
        }
        cout<<maxe<<endl;
    }
}