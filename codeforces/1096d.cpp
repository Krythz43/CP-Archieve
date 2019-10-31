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
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf LLONG_MAX
#define endl '\n'

int main()
{
    fastio;
    int n;
    cin>>n;
    string s;
    cin>>s;
    vinput(a,n);
    lli dp[100005][4];
    memset(dp,-1,sizeof dp);
    map<char,int> M;
    M['h']=4;
    M['a']=3;
    M['r']=2;
    M['d']=1;
    int x=4;
    rep(i,n,0)if(M[s[i]]==x && x!=0)x--;

    function<lli(int,int)> solve=[&](int id,int let)->lli{
        if(let==4)return inf;
        if(id<0){
            return 0;
        }

        lli &ans=dp[id][let];

        if(ans!=-1)return ans;
        if(M[s[id]]-1 !=let){
            lli x=solve(id-1,let);
            // cout<<id<<" "<<let<<" returns1:"<<x<<endl;
            return ans=x;
        }
        lli x=min(a[id]+solve(id-1,let),solve(id-1,let+1));
        // cout<<id<<" "<<let<<" returns2:"<<x<<endl;
        return ans=x;
        //take the current letter and look for the lower letter
    };

    if(x==0)
    cout<<solve(n-1,0)<<endl;
    else
    cout<<0<<endl;

}