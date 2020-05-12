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

map<string,int> M;


void solve(string s)
{
    int n =  s.length();
    string s1;
    vi facts;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i == 0){
            facts.pb(i);
            if(n/i != i)facts.pb(n/i);
        }
    }

    SO(facts);

    for(auto l: facts){
        if(n%l == 0){
            s1 = s.substr(0,l);
            int f = 1;
            for(int i = l;i<n;i+=l){
                if(s1 != s.substr(i,l)){
                    f = 0;
                    break;
                }
            }
            if(f)M[s1]++;
        }
    }
}

int main()
{
    fastio;
    string s1,s2;
    cin>>s1>>s2;
    solve(s1);
    solve(s2);
    int ans = 0;
    for(auto  x: M)if(x.ss>1)ans++;
    cout<<ans<<endl;
}