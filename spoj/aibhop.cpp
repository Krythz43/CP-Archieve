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

string s1,s2;
int dp[6105][6105];


int solve(int n,int m)
{
    if(n==-1 || m==-1)
    return 0;

    int &ans= dp[n][m];

    if(ans!=-1)
    return ans;

    if(s1[n]==s2[m])
    ans=1+max(solve(n-1,m-1),solve(n-1,m-1));
    else
    ans=max(solve(n-1,m),solve(n,m-1));

    return ans;
}
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        cin>>s1;
        s2=s1;
        reverse(s2.begin(),s2.end());
        cout<<s1.length()-solve(s1.length()-1,s2.length()-1)<<endl;

        // displaymatrix(dp,s1.length(),s2.length())
    }
}