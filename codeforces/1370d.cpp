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
    cin>>n;
    string s;
    string t;
    cin>>s>>t;
    int c1,c2;
    c1 = c2 = 0;

    rep(i,n,0){
        if(s[i] == '1')c1++;
        if(s[i] == '0')c2++;
    }

    rep(i,n,0){
        if(t[i] == '1')c1--;
        if(t[i] == '0')c2--;
    }

    if(c1 !=0 || c2 != 0){
        cout<<-1<<endl;
        return 0;
    }

    vi mis;
    rep(i,n,0)if(s[i] != t[i])mis.pb(s[i] - '0');

    lli ans = 0;

    rep(i,mis.size(),1)if(mis[i]  == mis[i - 1])ans++;
    if(mis.size() > 1){
        if(mis.back() == mis[0])ans++;
    }

    if(mis.empty()){
        cout<<0<<endl;
        return 0;
    }

    cout<<min(n/2,(ans + 1)/2 + 1)<<endl;
}