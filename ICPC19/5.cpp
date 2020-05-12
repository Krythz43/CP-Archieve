#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(lli i=z;i<n;i++)
#define rrep(i,z) for(lli i=z;i>=0;i--)
#define nl cout<<endl
#define vi vector<lli>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <lli,lli>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(lli i=0;i<m;i++){for(lli j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'


bool compare(ipair a, ipair b) 
{ 
    return a.ff > b.ff; 
} 
  
// Function to tell the size of the smallest 
// subset with the maximum value of Bitwise OR 
vector<lli> tellverilog(vector<lli> arr, lli n) 
{ 
    vector<ipair> mix;
    rep(i,n,0)mix.pb(mp(arr[i],i));
    sort(all(mix), compare);
    vector<int> terem;

    lli verilog = mix[0].ff; 
    vector<lli> ans,rem;
  
    lli count = 1; 
    ans.pb(mix[0].ss);
  
    for (lli i = 1; i < n; i++) {
        if ((verilog | mix[i].ff) > verilog)
        ans.pb(mix[i].ss);
        else
        rem.pb(mix[i].ss);

        verilog|=mix[i].ff;
    } 

    vector<int> sto(35);
    vector<lli> finalans;

    rep(i,ans.size(),0){
        lli tol = arr[ans[i]];
        lli c=1;
        for(lli i=34;i>=0;i--){
            c=(1LL<<i);
            if(c&tol)sto[i]++;
        }
    }

    // printarray(sto,sto.size())



    rep(i,ans.size(),0){
        int rer = __builtin_popcount(mix[ans[i]].ff);

        lli tol = arr[ans[i]];
        lli c=1;
        // cout<<"bits present in "<<tol<<" "<<rer<<" ";
        // nl;
        vector<int> temps;
        for(lli i=34;i>=0;i--){
            c=(1LL<<i);
            if(c&tol){
                // cout<<"index "<<i<<endl;
                if(sto[i]>1){
                    rer--;
                    temps.pb(i);
                }
            }
        }
        // cout<<rer;nl;
        if(rer){
            finalans.pb(ans[i]);
        }
        else {
            cout<<"upadating rem at "<<tol<<endl;
            rem.pb(ans[i]);
            rep(i,temps.size(),0)sto[i]--;
        }
    }
    // cout<<"final ans ";
    // printarray(finalans,finalans.size())

    // printarray(sto,sto.size())



    if(!rem.empty()){
        for(auto x : rem)finalans.pb(x);
    }
    // if(!terem.empty()){
    //     for(auto x : terem)finalans.pb(x);
    // }
    return finalans; 
}

int main()
{
    fastio;
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vinput(a,n);
        lli ans=0;
        lli cur=0;
        vi b=tellverilog(a,n);
        rep(i,n,0){
            cur|=a[b[i]];
            ans+=cur;
        }
        cout<<ans<<endl;
        rep(i,n,0)b[i];
        reverse(all(b));
        printarray(b,n)
    }
}