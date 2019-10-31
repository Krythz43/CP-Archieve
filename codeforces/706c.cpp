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
#define inf (LLONG_MAX/2)
#define endl '\n'

int n;
vector<string> a;
vlli cost;

map <pair<int,string>,lli > M;

lli solve(int id,string s){
    if(id<0)return 0;
    if(M.count(mp(id,s)))return M[mp(id,s)];

    lli &ans=M[mp(id,s)];
    ans=inf;
    string s1=a[id];
    string s2=s1;
    reverse(s2.begin(),s2.end());
    if(s.compare(s1)>=0)ans=solve(id-1,s1);
    if(s.compare(s2)>=0)ans=min(ans,cost[id]+solve(id-1,s2));
    return ans;
}
int main()
{
    fastio;
    cin>>n;
    a.resize(n);
    cost.resize(n);

    rep(i,n,0)cin>>cost[i];
    rep(i,n,0)cin>>a[i];

    string a2=a[n-1];
    reverse(a2.begin(),a2.end());
    lli ans1=solve(n-2,a[n-1]);
    lli ans2=solve(n-2,a2);

    lli ans=min(ans1,cost[n-1]+ans2);
    if(ans1==inf && ans2==inf)cout<<-1<<endl;
    else cout<<ans<<endl;
}