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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        map<char,int> M,N;
        int n = s.length();

        rep(i,n,0)M[s[i]] = 0;

        rep(i,n-1,0)if(s[i] != s[i+1])M[s[i]] = 1;
        else i++;

        if(n>1){
            if(!M[s[n-1]]){
                if(s[n-1] != s[n-2])M[s[n-1]]++;
            }
        } 

        SO(s);
        rep(i,n,0)N[s[i]]++;
        for(auto x: N)if(x.ss%2)M[x.ff]++;

        for(auto x: M){
            if(x.ss)cout<<x.ff;
        }
        nl;
    }
}