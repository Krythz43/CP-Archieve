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

int memo[4005][3005][4];

int solve(int h, int a,int t)
{
    int &ans=memo[h][a][t];

    if(ans!=-1)
    return ans;
    ans=0;
    if(h<=0 || a<=0)
    return 0;

    if(t!=1)
    {
        ans=max(ans,1+solve(h+3,a+2,1));
    }

    if(t!=2)
    {
        if(h-5>0 && a-10>0)
        ans=max(ans,1+solve(h-5,a-10,2));
    }

    if(t!=3)
    {
        if(h-20>0)
        ans=max(ans,1+solve(h-20,a+5,3));
    }
    return ans;
}
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        memset(memo,-1,sizeof memo);
        int h,a;
        cin>>h>>a;
        cout<<solve(h,a,0)<<endl;
    }
}