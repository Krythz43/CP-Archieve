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
    int n,N;
    cin>>n;
    N = n;
    string s;
    cin>>s;
    vector<int> a;
    rep(i,n,0)a.pb(s[i]-97);
    vector<int> b;
    while(1){
        b.clear();
        if(n == 1)break;

        if(n>2)
        rep(i,n-1,1){
            if(a[i-1] == a[i]-1 || a[i+1]==a[i]-1)b.pb(a[i]);
        }

        if(a[0]-1 == a[1])b.pb(a[0]);
        if(a[n-1]-1 == a[n-2])b.pb(a[n-1]);
        if(b.empty())break;
        SO(b);
        int mx = b[b.size()-1];
        
        b.clear();
        rep(i,n,0){
            if(mx == a[i]){
                if(n>2){
                    if(a[i-1] != a[i]-1 && a[i+1]!=a[i]-1)b.pb(a[i]);
                }
                else{
                    if(i == 0 && a[0]-1 != a[1])b.pb(a[0]);
                    if(i == n-1 && a[n-1]-1 != a[n-2])b.pb(a[n-1]);   
                }
            }
            else b.pb(a[i]);
        }

        a = b;
        n = a.size();
        // printarray(a,n)
    }

    cout<<N - n<<endl;
}