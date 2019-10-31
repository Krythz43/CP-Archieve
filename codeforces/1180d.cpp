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
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    if(n==1 && m==1){
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    ipair ll={1,1},rr={n,m};
    int ic=1,dc=0;
    cout<<1<<" "<<1<<endl;
    cout<<n<<" "<<m<<endl;
    ipair prev=mp(n,m);

    int cc=2;
    map<ipair,int> M;
    while(cc!=n*m){

        // cout<<n<<" "<<m<<" "<<cc<<endl;
        if(cc%2==0){
            if(ic){
                if(ll.ss==m){
                    ll.ff++;
                    ic^=1;
                }
                else{
                    ll.ss++;
                }
            }
            else{
                if(ll.ss==1){
                    ll.ff++;
                    ic^=1;
                }else{
                    ll.ss--;
                }
            }
            cout<<ll.ff<<" "<<ll.ss<<endl;
            if(M.count(mp(ll.ff-prev.ff,ll.ss-prev.ss)))
            {
                cout<<"runtime error"<<endl;
                return 0;
            }
            else{
                M[mp(ll.ff-prev.ff,ll.ss-prev.ss)]++;
            }
            prev=ll;
        }
        else{
            if(dc){
                if(rr.ss==m){
                    rr.ff--;
                    dc^=1;
                }
                else{
                    rr.ss++;
                }
            }
            else{
                if(rr.ss==1){
                    rr.ff--;
                    dc^=1;
                }else{
                    rr.ss--;
                }
            }
            cout<<rr.ff<<" "<<rr.ss<<endl;
            if(M.count(mp(rr.ff-prev.ff,rr.ss-prev.ss)))
            {
                cout<<"runtime error"<<endl;
                return 0;
            }
            else{
                M[mp(rr.ff-prev.ff,rr.ss-prev.ss)]++;
            }
            prev=rr;
        }
        cc++;
    }
}