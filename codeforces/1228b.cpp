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

const lli mod = 1e9+7;

lli multi(lli x,lli n){
    if(n==0)return 1;
    if(n==1) return x%mod;
    lli ans = multi(x*x%mod,n/2)%mod;
    if(n%2)ans=ans*x%mod;
    return ans;
}

int main()
{
    fastio;
    int h,w;
    cin>>h>>w;
    vinput(a,h);
    vinput(b,w);
    const int S=1005;
    int z[1005][1005];
    rep(i,S,0)rep(j,S,0)z[i][j]=-1;
    lli c=0;

    rep(i,h,0){
        rep(j,a[i]+1,0){
            if(j==a[i] && a[i]<w)z[i][j]=0;
            else z[i][j]=1;
        }
    }

    rep(i,w,0){
        rep(j,b[i]+1,0){
            if(j==b[i] && b[i]<h)z[j][i]=0;
            else z[j][i]=1;
        }
    }

    vlli e(h,0),d(w,0);
    

    rep(i,h,0){
        c=0;
        rep(j,w,0){
            if(z[i][j]==1)c++;
            else break;
        }   
        e[i]=c;
    }

    rep(i,w,0){
        c=0;
        rep(j,h,0){
            if(z[j][i]==1)c++;
            else break;
        }   
        d[i]=c;
    }


    // printarray(d,d.size());
    // printarray(e,e.size());

    // displaymatrix(z,h,w)

    rep(i,h,0){
        if(e[i]!=a[i]){
            cout<<0<<endl;
            return 0;
        }
    }


    rep(i,w,0){
        if(d[i]!=b[i]){
            cout<<0<<endl;
            return 0;
        }
    }


    c=0;
    rep(i,h,0)rep(j,w,0)if(z[i][j]==-1)c++;

    cout<<multi(2,c)%mod<<endl;
}