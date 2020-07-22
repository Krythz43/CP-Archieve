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
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int pref[26][n + 1];
    rep(i,26,0)pref[i][0] = 0;

    rep(i,n,0){
        rep(j,26,0)pref[j][i + 1] = pref[j][i];
        pref[s[i] - 'a'][i + 1]++;
    }

    int l,r,k;
    while(q--){
        cin>>l>>r>>k;
        l--;
        vi x(26,0);
        rep(i,26,0)x[i] = pref[i][r] - pref[i][l];

        if(k){
            // cout<<"ascending"<<endl;
            int p1 = l;

            rep(i,26,0){
                rep(j,x[i],0)s[p1++] = (char)('a' + i);
            }
        }
        else{
            // cout<<"descending"<<endl;
            int p1 = l;
            for(int i = 25;i >= 0; i--){
                rep(j,x[i],0)s[p1++] = (char)('a' + i);
            }
        }
        cout<<s<<endl;
    }

    cout<<s<<endl;
}