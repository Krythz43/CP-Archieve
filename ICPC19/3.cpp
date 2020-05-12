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
        int n;
        cin>>n;
        lli l,r,v;
        map<lli,vector<llipair> > M;
        rep(i,n,0){
            cin>>l>>r>>v;
            M[v].pb(mp(l,r));
        }
        for(auto &x : M){
            SO(x.ss);
        }
        int f=1;
        queue<ipair> Q;
        int a,b,c;
        for(auto x: M){
            if(x.ss.size()<3)continue;
            rep(i,x.ss.size()-2,0){
                int ac=0,bc=0,cc=0;
                taken=0;
                rep(j,x.ss.size()-2,i){
                    if(j!=taken)continue;
                    if(Q.size() == 0){
                        Q.push(x.ss[taken]);
                        Q.push(x.ss[taken+1]);
                        Q.push(x.ss[taken+2]);
                        taken+=3;
                    }
                    else if(Q.size() == 1){
                        Q.push(x.ss[taken]);
                        Q.push(x.ss[taken+1]);
                    }
                    else if(Q.size() == 2) Q.push(x.ss[taken]);

                    ipair a[3];
                    int p=0;
                    for(auto X: Q){
                        a[p]=X;
                        p++;
                    }

                    if(!overlap(a[0],a[1]))Q.pop();
                    else
                }
            }
            if(!f)break;
        }

        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

















// if(!ac){
                    //     if(!bc){
                    //         if(!cc){
                    //             cc=x.ss[j+2];
                    //             bc=x.ss[j+1];
                    //             ac=x.ss[j];
                    //         }else{
                    //             bc=cc;
                    //         }

                    //     }else ac=bc;
                    // }
                    // else 