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

int n;
string s[2];
lli S=200005;




bool solve(int st){

    string s1[2]=s;
    
    rep(i,n,0){
        if(s1[0][i] == s1[1][i] && s1[0][i]=='0')st^=1;
        else if(s1[st][i]=='1')continue;
        else
        return false;
    }
    if(st)return true;
    return false;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s[0]>>s[1];
        rep(i,n,0)if( s[0][i] == '2' || s[0][i] == '1' ) s[0][i]='1'; else s[0][i]='0';
        rep(i,n,0)if( s[1][i] == '2' || s[1][i] == '1' ) s[1][i]='1'; else s[1][i]='0';

        lli ans=0;
        ans|=(solve(0));

        if(ans == 1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}