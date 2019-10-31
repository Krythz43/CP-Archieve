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

void solve(string s){
    if(s[0]>=97){
        cout<<(char)toupper(s[0]);
    }
    else
    cout<<s[0];

    rep(i,s.length(),1)if(isupper(s[i]))cout<<(char)tolower(s[i]);else cout<<s[i];
}
int main()
{
    fastio;
    string s;
    cin>>s;
    int n=s.length();
    int f1=1,f2=1;
    rep(i,n,0){
        f1=f1&(bool)isupper(s[i]);
        if(i)
        f2=f2&(bool)isupper(s[i]);
        // cout<<i<<" "<<f1<<" "<<f2<<" "<<isupper(s[i])<<endl;
    }

    // cout<<f1<<" "<<f2<<endl;

    if((f2 && islower(s[0])))solve(s);
    else if(f1){
        rep(i,n,0)cout<<(char)tolower(s[i]);
    }
    else cout<<s;
    nl;   
}