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

lli x,y,a,b,n,k,lcm;
vlli p;

bool F(int X){
    vlli Z;
    rep(i,X,0){
        Z.pb(p[i]);
    }
    SO(Z);
    lli sum=0;
    lli t=X/lcm;
    int poi=X-1;
    // rep(i,t,0){
    //     if(poi<0)break;
    //     ans+=(x+y)*Z[i];
    //     poi--;
    // }

    int p1=lcm,p2;
    while(p1<=X && poi>=0){
        sum+=(x+y)*Z[poi];
        poi--;
        p1+=lcm;
    }
    lli sum1,sum2;
    sum1=sum2=sum;

    // cout<<sum<<" "<<poi<<endl;
    //evaluavting with more a priority
    int tpoi=poi;
    p1=a;
    while(p1<=X && tpoi>=0){
        // cout<<"stuck1"<<endl;
        if(p1%b){
            sum1+=x*Z[tpoi];
            tpoi--;
        }
        p1+=a;
    }
    p1=b;
    while(p1<=X && tpoi>=0){
        // cout<<"stuck2"<<endl;
        if(p1%a){
            sum1+=y*Z[tpoi];
            tpoi--;
        }
        p1+=b;
    }
    int tpoi2 = poi;
    //evaluvating with more b priority

    p1=b;
    while(p1<=X && tpoi2>=0){
        // cout<<"stuck3"<<endl;
        if(p1%a){
            sum2+=y*Z[tpoi2];
            tpoi2--;
        }
        p1+=b;
    }
    p1=a;
    while(p1<=X && tpoi2>=0){
        // cout<<"stuck4"<<endl;
        if(p1%b){
            sum2+=x*Z[tpoi2];
            tpoi2--;
        }
        p1+=a;
    }

    if(sum1>sum2){
        poi=tpoi;
        sum=sum1;
    }
    else{
        poi=tpoi2;
        sum=sum2;
    }

    return k<=sum;
}


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        // nl;
        p.resize(n);
        ainput(p,n);
        rep(i,n,0)p[i]/=100;

        cin>>x>>a>>y>>b>>k;
        lcm=(a*b)/__gcd(a,b);

        if(!F(n)){
            cout<<-1<<endl;
            continue;
        }

        lli mid,lo=1,hi=n;
        while(hi-lo>1){
            // cout<<"mid ="<<mid<<" "<<lo<<" "<<hi<<endl;
            mid=(hi+lo)/2;
            if(F(mid))hi=mid;
            else lo=mid;
        }

        if(F(lo))cout<<lo<<endl;
        else cout<<hi<<endl;
    }
}