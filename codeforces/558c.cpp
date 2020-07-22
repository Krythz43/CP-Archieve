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
// #define endl '\n'

int main()
{
    fastio;
    int n;
    cin>>n;
    vinput(a,n);
    int mx = *max_element(all(a));

    vlli ans(2*mx + 5);
    vlli occ(2*mx + 5);
    vlli vis(2*mx + 5, - 1);

    queue <ipair> Q;

    int idx,wei;

    rep(i,n,0){
        Q = queue<ipair>();
        Q.push(mp(a[i],0));

        while(!Q.empty()){
            auto X = Q.front();
            Q.pop();
            tie(idx,wei) = X;
            if(vis[idx] == i)continue;

            // cout<<i<<" "<<idx<<endl;
            vis[idx] = i;
            occ[idx]++;
            ans[idx] += wei;
            if(2*idx <= mx && vis[2*idx] != i)Q.push(mp(2*idx,wei + 1));
            if(vis[idx/2] != i)Q.push(mp(idx/2,wei + 1));
        }   
    }

    lli res = inf;
    rep(i,ans.size(),0){
        if(occ[i] == n)res = min(res,ans[i]);
    }

    cout<<res<<endl;
}