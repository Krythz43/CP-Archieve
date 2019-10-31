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

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

int m,c;
int memo[205][25]; //money*
int price[25][25];

int shop(int money,int id)
{
    if(money<0)
    return -inf;
    if(c==id)
    return m-money;
    if(memo[money][id]!=-1)
    return memo[money][id];
    int ans=-1;

    rep(i,price[id][0]+1,1)
    {
        ans=max(ans,shop(money-price[id][i],id+1));
    }
    // cout<<"updating "<<money<<","<<id<<": "<<ans<<endl;
    return memo[money][id]=ans;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        memset(memo,-1,sizeof memo);
        cin>>m>>c;
        rep(i,c,0)
        {
            cin>>price[i][0];
            rep(j,price[i][0]+1,1)
            {
                cin>>price[i][j];
            }
        }
        shop(m,0);
        if(memo[m][0]<0)
        cout<<"no solution"<<endl;
        else
        cout<<memo[m][0]<<endl;
    }
}