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
// #define endl '\n'

lli pow(lli x){
    return x*x;
}

lli solve(vlli & a, vlli & b, vlli & c){
    lli ans = LLONG_MAX;

    rep(i,b.size(),0){
        lli x = lower_bound(all(a),b[i]) - a.begin();
        lli y = upper_bound(all(c),b[i]) - c.begin();
        lli z = b[i];
        
        if(x == 0)x = a[0];
        else if(x == a.size())x = a[x-1];
        else if(z == a[x])x = z;
        else x = a[x-1];

        if(y == c.size())y = c[y-1];
        else if(y == 0)y = c[y];
        else if(c[y-1] == z)y = z;
        else y = c[y];

        ans = min(ans, pow(x-y) + pow(y-z) + pow(x-z));
    }

    return ans;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int an,bn,cn;
        cin>>an>>bn>>cn;
        vinput(a,an);
        vinput(b,bn);
        vinput(c,cn);
        SO(a);
        SO(b);
        SO(c);

        lli ans = LLONG_MAX;
        ans = min(ans,solve(b,a,c));
        ans = min(ans,solve(c,a,b));
        ans = min(ans,solve(a,b,c));
        ans = min(ans,solve(c,b,a));
        ans = min(ans,solve(a,c,b));
        ans = min(ans,solve(b,c,a));

        cout<<ans<<endl;


        // while(1){
        //     int x;
        //     cin>>x;
        //     cout<<"Upper "<<upper_bound(all(a),x) - a.begin()<<endl;
        //     cout<<"Lower "<<lower_bound(all(a),x) - a.begin()<<endl;
        // }
    }
}