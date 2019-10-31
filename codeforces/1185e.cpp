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
// #define endl '\n'

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>a(n);
        rep(i,n,0)
        cin>>a[i];
        map<char,int>Mx,My,my,mx;
        char mb='1',blo=0;
        pair<ipair,ipair> X;
        rep(i,n,0)
        rep(j,m,0){
            if(a[i][j]=='.')continue;
            if(!Mx.count(a[i][j])){
                Mx[a[i][j]]=My[a[i][j]]=0;
                mx[a[i][j]]=my[a[i][j]]=2005;
            }
            mb=max(mb,a[i][j]);
            blo=1;

            Mx[a[i][j]]=max(Mx[a[i][j]],i+1);
            My[a[i][j]]=max(My[a[i][j]],j+1);
            mx[a[i][j]]=min(mx[a[i][j]],i+1);
            my[a[i][j]]=min(my[a[i][j]],j+1);
            if(mb==a[i][j])
            X=mp(mp(i+1,j+1),mp(i+1,j+1));
            // cout<<"updating "<<a[i][j]<<" at "<<i+1<<","<<j+1<<" "<<mx[a[i][j]]<<" "<<my[a[i][j]]<<" "<<Mx[a[i][j]]<<" "<<My[a[i][j]]<<endl;
        }
        int ans=0,f=1;
        vector <pair<ipair,ipair>> q;

        // cout<<"X "<<X.ff.ff<<" "<<X.ff.ss<<" "<<X.ss.ff<<" "<<X.ss.ss<<endl;

        
        for(char ch='a';ch<=mb;ch++){
            if(Mx.count(ch)){
                ans++;
                f&=(Mx[ch]-mx[ch]==0 || My[ch]-my[ch]==0);
                q.pb(mp(mp(mx[ch],my[ch]),mp(Mx[ch],My[ch])));
            }else if(blo==0){
                f=0;
                break;
            }else{
                ans++;
                q.pb(X);
            }
        }

        string str;
        rep(i,m,0)
        str+=".";


        vector<string> check(n,str);

        if(f){
            rep(i,q.size(),0){
            int x1=q[i].ff.ff,y1=q[i].ff.ss,x2=q[i].ss.ff,y2=q[i].ss.ss;
            // cout<<(char)(i+97)<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
            rep(j,x2,x1-1)check[j][y1-1]=(char)(i+97);
            rep(j,y2,y1-1)check[x1-1][j]=(char)(i+97);
        }

        // nl;
        // rep(i,n,0)cout<<check[i]<<endl;


        rep(i,n,0)f&=(check[i]==a[i]);}

        if(f){
            cout<<"YES"<<endl;
            cout<<ans<<endl;
            rep(i,q.size(),0)
            cout<<q[i].ff.ff<<" "<<q[i].ff.ss<<" "<<q[i].ss.ff<<" "<<q[i].ss.ss<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
}