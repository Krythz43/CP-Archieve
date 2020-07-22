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
        int n;
        cin>>n;
        cin>>s;
        int c = 1;
        vector<ipair> cou;
        rep(i,n,1){
            if(s[i] == s[i - 1])c++;
            else{
                cou.pb(mp(s[i - 1]-'0',c));
                c = 1;
            }
        }

        cou.pb(mp(s[n - 1]-'0',c));
        vi inc(cou.size(), - 1);

        if(cou.size() == 1){
            cout<<s<<endl;
            continue;
        }

        int mx1 = 0,mx2 = 0;

        if(cou.back().ff == 0){
            cout<<0;
            if(cou[0].ff == 0){
                rep(i,cou[0].ss,0)cout<<0;
            }
                nl;

            continue;
        }

        

        if(cou[0].ff == 1){
            cout<<0;
        }
        else{
            rep(i,cou[0].ss,0)cout<<0;
            for(int i = 2;i <cou.size() - 1;i += 2){cout<<0;break;}
        }
        
        rep(i,cou.back().ss,0)cout<<1;
        nl;
    }
}