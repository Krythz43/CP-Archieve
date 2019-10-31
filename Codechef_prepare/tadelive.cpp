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


bool comp(ipair a, ipair b)
{
    return abs(a.ff-a.ss)>abs(b.ff-b.ss);
}

int main()
{
    fastio;
    int n,x,y;
    cin>>n>>x>>y;

    vector<ipair > a(n);
    rep(i,n,0)
    cin>>a[i].ff;
    rep(i,n,0)
    cin>>a[i].ss;

    sort(a.begin(),a.end(),comp);
    int ans=0;

    rep(i,n,0)
    {
        if(x>0 && y>0)
        {
            if(a[i].ff>a[i].ss)
            {
                ans+=a[i].ff;
                x--;
            }
            else
            {
                ans+=a[i].ss;
                y--;
            }
        }
        else if(x>0)
        {
            ans+=a[i].ff;
        }
        else
        ans+=a[i].ss;
    }
    cout<<ans;
}