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


#define R 0
#define D 1
#define L 2
#define U 3

int main()
{
    fastio;
    int n,m,k;
    cin>>n>>m>>k;
    
    vector<ipair> obs(n);
    rep(i,k,0)cin>>obs[i].ff>>obs[i].ss;
    vector<int>hor[n+5],ver[n+5];

    for(auto x: obs){
        hor[x.ff].pb(x.ss);
        ver[x.ss].pb(x.ff);
    }
    rep(i,n+1,1){
        SO(hor[i]);
        SO(ver[i]);
    }

    int p1=1,p2=n,v1=1,v2=n,cobs;
    int mex=1,mey=1;
    lli DIR=R;
    lli taz=0;
    while(1){
        if(DIR == R && p2 == mex)break;
        if(DIR == L && p1 == mex)break;
        if(DIR == U && v1 == mey)break;
        if(DIR == D && v2 == mey)break;

        if(DIR == R){
            cobs = upper_bound(all(hor[p1],v1))-hor[p1].begin();
            if(cobs != hor[p1].size()){
                cobs = hor[p1][cobs];
                if(cobs==v2)v2--;
                else if(cobs<v2)v2=hor[p1][cobs]-1;
            }            
            if(mex == v2)break;
            taz+=v2-mex;
            mex = v2;
        }
        else if(DIR == L){
            cobs = upper_bound(all(hor[p2],v1))-hor[p2].begin()-1;
            if(cobs<0)
            if(cobs != hor[p1].size()){
                cobs = hor[p1][cobs];
                if(cobs==v2)v2--;
                else if(cobs<v2)v2=hor[p1][cobs]-1;
            }            
            if(mex == v2)break;
            mex = v2;
        }


        DIR = (DIR+1)%4;
    }
}