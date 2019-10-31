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

const int S=1e6+5;
int n;
string s;


lli dp[S][6];

// lli solve(int id,int x){
//     if(id==n)return 0;
//     lli &ans=dp[id][x];
//     if(ans!=-1 && x!=5)return ans;
//     if(x==5)return 1;

//     // cout<<id<<" "<<x<<endl;

    
//     if(x==2 && s[id]=='o')return ans=solve(id+1,x+1)+solve(id+1,x);
//     else if(s[id]=='v' && x!=2){
//         return ans=solve(id+1,x+1)+solve(id+1,x);
//     }
//     else
//     return ans=solve(id+1,x);
// }

int main()
{
    fastio;
    cin>>s;
    n=s.length();
    lli vc=0;

    string x="";
    lli cc=0;
    rep(i,n,0){
        if(s[i]=='o'){
            cc=0;
            x+='o';
        }else{
            if(cc==1){
                x+='w';
            }else{
                cc++;
            }
        }
    }

    n=x.length();
    rep(i,n,0)if(x[i]=='w')vc++;

    lli vtl=0;

    lli ans=0;
    rep(i,n,0){
        if(x[i]=='o'){
            lli rv=vc-vtl;
            ans+=rv*vtl;
            // cout<<rv<<" "<<vtl<<endl;
        }
        else
        vtl++;
    }
    cout<<ans<<endl;
}