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
        int n,m;
        cin>>n;
        vinput(a,n);

        cin>>m;
        vector<llipair> b(m);
        rep(i,m,0)cin>>b[i].ff>>b[i].ss;

        vlli mx(n+1,0);
        rep(i,m,0){
            mx[b[i].ss]=max(mx[b[i].ss],b[i].ff);
        }

        for(int i=n-1;i>=0;i--)mx[i]=max(mx[i],mx[i+1]);
        // printarray(mx,n+1)

        int ans=0,f=0;
        for(int i=0;i<n;){
            lli dtf = 0,ldtf=0;
            // cout<<"New hero enters"<<endl;
            for(int j=0;i<n;j++){
                // cout<<"power "<<a[i]<<": ";
                if(mx[j+1] >= a[i] && mx[j+1]>=dtf){
                    // cout<<"defeated by power"<<mx[j+1]<<", dtf= "<<dtf<<endl;
                    dtf=max(dtf,a[i]);
                    i++;
                }
                else{
                    // cout<<"No standing opp"<<endl;
                    if(j==0)f=1;
                    break;
                }
            }
            if(f)break;
            else ans++;
        }

        if(f)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}