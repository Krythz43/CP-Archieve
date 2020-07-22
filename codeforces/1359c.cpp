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

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        lli h,c,t;
        cin>>h>>c>>t;
        // int co;
        // cin>>co;
        // int tu = 1;

        long double ht = 0, ct = 0;

        // rep(i,co,1){
        //     if(tu%2)ht +=h;
        //     else ct += c;
        //     tu ^= 1;
        //     cout<<i<<" "<<(ht + ct)/i<<endl;
        // }

        long double avg  = (h + c)/2.0;
        if(t <= avg){
            cout<<2<<endl;
            continue;
        }

        lli lo = 1, hi = 1e6 + 1,mid;

        while(hi - lo > 3){
            // cout<<hi<<" "<<lo<<endl;
            mid = (hi + lo)/2;
            if(mid%2 == 0)mid--;

            ht = (mid/2 + 1)*h;
            ct = (mid/2)*c;
            avg = (ht + ct)/mid;
            if(avg <= t)hi = mid;
            else lo = mid;
        }

        // cout<<lo<<" "<<hi<<endl;

        ht = (hi/2 + 1)*h;
        ht += (hi/2)*c;
        ht /= hi;

        ct = (lo/2 + 1)*h;
        ct += (lo/2)*c;
        ct /= lo;

        ht -= t; 
        ct -= t;

        if(ht < 0)ht *= -1;
        if(ct < 0)ct *= -1;

        if(ht < ct)cout<<hi<<endl;
        else cout<<lo<<endl;

    }
}