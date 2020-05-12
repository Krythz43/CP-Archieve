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
    rep(Q,t+1,1){
        lli n,h;
        cin>>n>>h;
        bitset<22> b,a(pow(2,n));
        lli ans=0;
        vector<ipair> hap(n);
        rep(i,n,0)cin>>hap[i].ff;
        rep(i,n,0)cin>>hap[i].ss;

        do{
            lli as=0,bs=0;
            rep(i,n,0){
                cout<<b[i]<<endl;
                if(b[i]==0)as+=hap[i].ff;
                else bs+=hap[i].ss;
            }
            if(as>=h && bs>=h){
                // cout<<"upating"<<" "<<b<<" "<<bs<<" "<<as<<endl;     
                ans++;
            }

            rep(i,n,0){
                if(b[i]==0){bs+=hap[i].ss;
                // else as+=hap[i].ff;

                if(as>=h && bs>=h){
                cout<<"upating"<<" "<<b<<" "<<bs<<" "<<as<<endl;   
                ans++;}
            }
            }

            b=b.to_ulong()+1;
            cout<<as<<" "<<bs<<" "<<b<<endl;
        }while(b!=a);

        cout<<"Case #"<<Q<<": "<<ans<<endl;
    }
}