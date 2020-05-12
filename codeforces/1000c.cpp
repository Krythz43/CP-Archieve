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
    map<lli,lli> M,rev;
    int count = 1;
    int n;
    cin>>n;

    vector<llipair> points(n);
    rep(i,n,0){
        cin>>points[i].ff>>points[i].ss;
        if(!M.count(points[i].ff)){
            M[points[i].ff] = count;
            rev[count] = points[i].ff;
            count++;
        }

        if(!M.count(points[i].ss)){
            M[points[i].ss] = count;
            rev[count] = points[i].ss;
            count++;
        }

        points[i].ff = M[points[i].ff];
        points[i].ss = M[points[i].ss];
    }

    vi cover(count+5,0);
    vi ans(n + 1);
    lli add;
    rep(i,n,0){
        add = rev[points[i].ss]
        cover[points[i].ff] += rev[points[i].ff];
        cover[points[i].ss+1] -= rev[points[i].ss];
    }

    int roll = 0;
    for(int i = 0; i < cover.size();i++){
        roll += cover[i];
        ans[roll]++;
        assert(roll <= n);
    }

    rep(i,n+1,1)cout<<ans[i]<<' ';
    nl;
}