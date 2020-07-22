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
vlli s;
lli x,a;
lli y,b;
lli k;

bool F(lli mid){
    lli tot = 0;
    int tk = 0;

    for(int i = mid-1;i >= 0; i--){
        int idx = (i + 1);
        if(tk == n)break;
        if(idx%a == 0 && idx%b == 0){
            tot += (x + y)*s[tk++];
        }
    }

    for(int i = mid-1;i >= 0; i--){
        int idx = (i + 1);
        if(tk == n)break;
        if(idx%a != 0 && idx%b == 0){
            tot += (y)*s[tk++];
        }
    }

    for(int i = mid-1;i >= 0; i--){
        int idx = (i + 1);
        if(tk == n)break;
        if(idx%a == 0 && idx%b != 0){
            tot += (x)*s[tk++];
        }
    }

    return tot >= k;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        s.resize(n);
        rep(i,n,0)cin>>s[i];
        cin>>x>>a>>y>>b>>k;
        
        int hi = n,lo = 1,mid;
        SO(s);
        reverse(all(s));
        rep(i,n,0)s[i] /= 100;

        if(x > y){
            swap(x,y);
            swap(a,b);
        }
        while(hi - lo > 1){
            mid = (hi + lo)/2;
            if(F(mid))hi = mid;
            else lo = mid;
        }

        if(F(lo))cout<<lo<<endl;
        else if(F(hi))cout<<hi<<endl;
        else cout<<-1<<endl;
    }
}