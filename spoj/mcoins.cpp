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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'



int main()
{
    fastio;
    int a,b,t;
    cin>>a>>b>>t;
    vector<int> ans(1000005,0);
    ans[1]=ans[a]=ans[b]=1;

    rep(i,ans.size(),2)
    {
        if(ans[i])
        continue;

        if(i-a>0 && i-b>0)
        {
            if(ans[i-1]==0 || ans[i-a]==0 || ans[i-b]==0)
            ans[i]=1;
        }
        else if(i-a>0)
        {
            if(ans[i-1]==0 || ans[i-a]==0)
            ans[i]=1;
        }
        else if(i-b>0)
        {
            if(ans[i-1]==0 || ans[i-b]==0)
            ans[i]=1;
        }
        else
        ans[i]=(ans[i-1]^1);
    }

    while(t--)
    {
        int n;
        cin>>n;
        if(ans[n])
        cout<<"A";
        else
        cout<<"B";
    }
    nl;
}
