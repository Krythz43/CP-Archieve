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
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    string s1,s2;
    cin>>s1>>s2;
    int m=0,ans=0;
    rep(i,s2.length(),0)if(s1[i]!=s2[i])m++;
    int n=s1.length();
    vector<int> ch(n-1,0);
    rep(i,n-1,0)if(s1[i]!=s1[i+1])ch[i]++;
    int che=0;
    rep(i,s2.length(),0)che++;
    if(m%2==0)ans++;
    int id=0;
    while(id+s2.length()<s1.length()){
        che-=ch[id];
        che+=ch[id-1+s2.length()];
        if(che%2==m%2){ans++;m=2;}
        else m=1;
        id++;
    }
    cout<<ans<<endl;
}