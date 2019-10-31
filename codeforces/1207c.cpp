#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'


lli n,a,b;
string s;
const int S=2e5+9;

lli dp[S][2];

lli solve(int id,int sta){
    lli &ans=dp[id][sta];
    if(ans!=-1)return ans;

    ans=b+b*sta;
    if(id==0){
        if(sta==0)return ans=ans+a;
        else return ans=ans+2*a;
    }

    if(s[id]=='1'){
        return ans=ans+a+solve(id-1,sta);
    }

    if(s[id-1]=='1'){
        if(sta){
            return ans=ans+a+solve(id-1,sta);
        }
        else{
            return ans=ans+2*a+solve(id-1,1);
        }
    }

    if(sta){
        return ans=ans+min(a+solve(id-1,1),2*a+solve(id-1,0));
    }
    else{
        return ans=ans+min(a+solve(id-1,0),2*a+solve(id-1,1));
    }
}


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        cin>>s;
        memset(dp,-1,sizeof dp);
        cout<<solve(n-1,0)+b<<endl;
    }
}