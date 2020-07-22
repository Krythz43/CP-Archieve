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
    lli n;
    cin>>n;
    vector<pair<lli,lli>> a;
    lli x,y;

    map<lli,lli> X;
    rep(i,n,0){
        cin>>x>>y;
        a.pb(mp(x,y));
        X[x]++;
    }

    SO(a);

    if(n < 3)return cout<<0<<endl,0;

    lli ans = (n*(n - 1)*(n - 2))/6;

    for(auto x: X){
        ans -= (x.ss*(x.ss - 1)*(x.ss - 2))/6;
    }

    map<llipair,lli> M;

    lli x1,x2,x3,y1,y2,y3;
    lli gcd;
    rep(i,n - 1,1){
        M.clear();
        x2 = a[i].ff;
        y2 = a[i].ss;

        rep(j,i,0){
            x1 = a[j].ff;
            y1 = a[j].ss;

            if(x1 == x2)break;
            gcd = __gcd(abs(y2 - y1),x2 - x1);
            M[mp((y2 - y1)/gcd,(x2 - x1)/gcd)]++;
        }

        rep(j,n,i + 1){
            x3 = a[j].ff;
            y3 = a[j].ss;#include <bits/stdc++.h>
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
 
 
const int S=5005;
int dp[S][S];
 
int main()
{
    fastio;
    int n;
    cin>>n;
    vector<int> a;
    int x;
    cin>>x;
    a.pb(x);
    rep(i,n,1){
        cin>>x;
        if(x!=a[a.size()-1])a.pb(x);
    }
    n=a.size();
    vi b=a;
    reverse(b.begin(),b.end())
 
    rep(i,n+1,0)rep(j,n+1,0)dp[i][j]=0;
 
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j<=n; j++) {
			if (a[i-1] == b[j-1]) {dp[i][j] = dp[i-1][j-1] + 1;}
			else {dp[i][j] = max(dp[i-1][j], dp[i][j-1]);}
		}
	}
 
    cout<<n-(dp[n][n]+1)/2<<endl;
}
            if(x3 == x2)continue;
            gcd = __gcd(abs(y3 - y2),x3 - x2);            
            ans -= M[mp((y3 - y2)/gcd,(x3 - x2)/gcd)];
        }
    }

    cout<<ans<<endl;
}

