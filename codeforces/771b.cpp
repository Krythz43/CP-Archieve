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
    int n,k;
    cin>>n>>k;
    vector<string> names;
    string s;
    rep(i,52,0)
    {
        if(i>=26)
        {
            s=names[i-26];
            s+=(char)(i+97-26);
            names.pb(s);
        }
        else
        {
            s="";
            s+=(char)(i+65);
            names.pb(s);
        }
    }

    // rep(i,names.size(),0)
    // cout<<names[i]<<" ";
    vector<string> out;
    rep(i,k-1,0){cout<<names[i]<<" ";out.pb(names[i]);}
    string s1;
    int p1=k;
    rep(i,n-k+1,0){
        cin>>s1;
        if(s1=="YES"){cout<<names[i+k]<<" ";out.pb(names[i+k]);}
        else
        {cout<<out[out.size()-k+1]<<" ";out.pb(out[out.size()-k+1]);}
    }
    nl;
}