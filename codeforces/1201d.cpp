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
    int n,m,k,q,x,y,hi,lo;
    cin>>n>>m>>k>>q;
    set<int> a[n+1];
    rep(i,k,0){
        cin>>x>>y;
        a[x].insert(y);
    }

    vinput(safe,q);
    SO(safe);

    int cr=1,cc=1;
    lli ans=0;

    while(1){

        // cout<<cr<<" "<<cc<<" "<<ans<<endl;
        if(cr==n){
            if(!a[n-1].empty()){
                x=*(a[cr].begin());
                y=*(a[cr].rbegin());
                x--,y--;
                if(x==y)ans+=abs(x-cc);
                else if(x<cc && y<cc)ans+=cc-min(x,y);
                else if(x>>cc && y>cc)ans+=max(x,y)-cc;
                else ans+=max(x,y)-min(x,y)+min(abs(x-cc),abs(y-cc));
            }
            cout<<ans<<endl;
            return 0;
        }

        if(a[cr-1].empty()){
            cr++;
            continue;
        }

        x=*(a[cr].begin());
        y=*(a[cr].rbegin());
        cr++;
        x--,y--;

        if(x==y){
            ans+=abs(x-cc);
            lo=lower_bound(all(safe),x)-safe.begin();
            hi=upper_bound(all(safe),x)-safe.begin();
            if(lo!=q &&  hi!=q){
                if(abs(lo-x)<abs(hi-x)){
                    ans+=abs(lo-x);
                    cc=lo;
                }
                else{
                    ans+=abs(hi-x);
                    cc=hi;
                }
            }
            else if(lo!=q){
                ans+=abs(lo-x);
                cc=lo;
            }
            else{
                ans+=abs(hi-x);
                cc=hi;
            }
        }
        else{
            if(x>y)swap(x,y);

            if(x<cc && y<cc){
                ans+=cc-x;
                lo=lower_bound(all(safe),x)-safe.begin();
                hi=upper_bound(all(safe),x)-safe.begin();
                if(lo!=q &&  hi!=q){
                    if(abs(lo-x)<abs(hi-x)){
                        ans+=abs(lo-x);
                        cc=lo;
                    }
                    else{
                        ans+=abs(hi-x);
                        cc=hi;
                    }
                }
                else if(lo!=q){
                    ans+=abs(lo-x);
                    cc=lo;
                }
                else{
                    ans+=abs(hi-x);
                    cc=hi;
                }
            }
            else if(x>>cc && y>cc){
                ans+=y-cc;
                lo=lower_bound(all(safe),y)-safe.begin();
                hi=upper_bound(all(safe),y)-safe.begin();
                if(lo!=q &&  hi!=q){
                    if(abs(lo-y)<abs(hi-y)){
                        ans+=abs(lo-y);
                        cc=lo;
                    }
                    else{
                        ans+=abs(hi-y);
                        cc=hi;
                    }
                }
                else if(lo!=q){
                    ans+=abs(lo-y);
                    cc=lo;
                }
                else{
                    ans+=abs(hi-y);
                    cc=hi;
                }
            }
            else{
                ans+=y-x;
                lli path1=0,path2=0;
                int c1,c2;

                //go to x first
                path1+=abs(cc-x);
                lo=lower_bound(all(safe),y)-safe.begin();
                hi=upper_bound(all(safe),y)-safe.begin();
                if(lo!=q &&  hi!=q){
                    if(abs(lo-y)<abs(hi-y)){
                        path1+=abs(lo-y);
                        c1=lo;
                    }
                    else{
                        path1+=abs(hi-y);
                        c1=hi;
                    }
                }
                else if(lo!=q){
                    path1+=abs(lo-y);
                    c1=lo;
                }
                else{
                    path1+=abs(hi-y);
                    c1=hi;
                }

                //go to y first

                path2+=abs(cc-y);
                lo=lower_bound(all(safe),x)-safe.begin();
                hi=upper_bound(all(safe),x)-safe.begin();
                if(lo!=q &&  hi!=q){
                    if(abs(lo-x)<abs(hi-x)){
                        path2+=abs(lo-x);
                        c2=lo;
                    }
                    else{
                        path2+=abs(hi-x);
                        c2=hi;
                    }
                }
                else if(lo!=q){
                    path2+=abs(lo-x);
                    c2=lo;
                }
                else{
                    path2+=abs(hi-x);
                    c2=hi;
                }

                if(path1<path2){
                    ans+=path1;
                    cc=c1;
                }
                else{
                    ans+=path2;
                    cc=c2;
                }
            }
            cc++;
        }
    }
}