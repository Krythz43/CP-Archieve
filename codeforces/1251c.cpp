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
        vi odd,ev;
        rep(i,s.length(),0){
            int x = s[i] - '0';
            if(x%2)odd.pb(x);
            else ev.pb(x);
        }

        int p1 = 0, p2 = 0;

        while(p1<odd.size() || p2<ev.size()){
            if(p1 == odd.size()){
                cout<<ev[p2++];
                continue;
            }

            if(p2 == ev.size()){
                cout<<odd[p1++];
                continue;
            }

            if(odd[p1] < ev[p2]){
                cout<<odd[p1++];
            }
            else cout<<ev[p2++];
        }
        nl;
    }
}