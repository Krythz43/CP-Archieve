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

int main()
{
    fastio;
    int n;
    cin>>n;
    vinput(a,n);

    int q;
    cin>>q;
    vector<pair<lli,llipair> > query(q);
    rep(i,q,0){
        cin>>query[i].ff;
        if(query[i].ff == 1)cin>>query[i].ss.ff>>query[i].ss.ss;
        else cin>>query[i].ss.ff;
    }

    vlli payoff(q,0);

    if(query[q-1].ff == 2)payoff.back() = query[q-1].ss.ff;
    for(int i = q-2; i >= 0;i--){
        payoff[i] = payoff[i+1];
        if(query[i].ff == 2)payoff[i] = max(payoff[i],query[i].ss.ff);
    }

    vlli ans(n,-1);

    map<int,int> M;
    for(int i = q-1; i >=0 ; i--){
        if(query[i].ff == 2)continue;
        if(M.count(query[i].ss.ff))continue;
        ans[query[i].ss.ff - 1] = max(payoff[i],query[i].ss.ss);
        M[query[i].ss.ff]++;
    } 

    // printarray(payoff,q)

    rep(i,n+1,1)if(!M.count(i))ans[i - 1] = max(payoff[0],a[i - 1]);

    printarray(ans,n)
}