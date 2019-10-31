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

int n,k;
lli mod=1e9+7;

lli memo[2005][2005];

// lli solve(lli id,lli left)
// {
//     if(memo[id][left]!=-1) return memo[id][left];
//     memo[id][left]=0;

//     if(left==0)
//     return memo[id][left]=1;
    
//     for(int i=1;i<=sqrt(id);i++)
//     {
//         if(id%i==0)
//         {

//             if(id/i==i)
//             memo[id][left]=(memo[id][left]+solve(i,left-1));
//             else
//             memo[id][left]=(memo[id][left]+( solve(i,left-1)+solve(id/i,left-1)));

//             if(memo[id][left]>mod)
            
//             while(memo[id][left]>mod)
//             memo[id][left]-=mod;
//         }
//     }
//     return memo[id][left];
// }


int main()
{
    fastio;
    cin>>n>>k;
    // lli ans=0;
    memset(memo,0,sizeof memo);
    // rep(i,n,0)
    // {
    //     ans=(ans+solve(i+1,k-1));
    //     if(ans>mod)
    //     while(ans>mod)
    //     ans-=mod;
    // }
    // cout<<ans<<endl;

    for(int i=1;i<n;i++)
    {

    }
}