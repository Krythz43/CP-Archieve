#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define F first
#define S second
#define pb emplace_back
#define mt make_tuple
#define gcd __gcd
#define PI 3.141592653589
// Input
#define in(a) scanf("%d",&a)
#define in2(a,b) scanf("%d%d",&a,&b)
#define in3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define llin(a) cin >> a
#define inl(a) scanf("%lld",&a)
#define read(v,i,n) for(i=0;i<n;i++)in(v[i])
#define twod(mat,i,j,n,m) rep(i,n){rep(j,m)in(mat[i][j]);}
#define sc(ch) scanf("%c",&ch)
#define sstr(str) scanf("%s",str)
// Output
#define pr(a) printf("%d ",a)
#define pr2(a,b) printf("%d %d\n",a,b)
#define pr3(a,b,c) printf("%d %d %d\n",a,b,c)
#define out(a) printf("%d\n",a)
#define outl(a) printf("%lld\n",a)
#define llpr(a) cout << a << " "
#define llout(a) cout << a << "\n"
#define yes printf("YES\n")
#define no printf("NO\n")
#define lin printf("\n")
// Iterator
#define lp(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define all(vec) vec.begin(),vec.end()
#define lower(v,k) lower_bound(v.begin(),v.end(),k)-v.begin()
#define upper(v,k) upper_bound(v.begin(),v.end(),k)-v.begin()
#define tf(mytuple) get<0>(mytuple)
#define ts(mytuple) get<1>(mytuple)
#define tt(mytuple) get<2>(mytuple)
// Debug
#define dbg(v,i,n) for(i=0;i<n;i++)pr(v[i]); lin
#define what(x) cerr << #x << " : " << x << "\n"
#define ck printf("continue\n")
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}
// Data Type
#define ll long long int
#define ii pair<int,int>
#define pli pair<ll,int>
#define triple tuple<int,int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vector<int> >
#define viii vector<pair<pair<int,int>,int> >
#define vvii vector<vector<pair<int,int> > >
#define M 1000000007
#define N 100005  //check the limits, man
const ll INF = 1e12;
vvi ad(N);
bool vis[N];
int main()
{
    int n,i,j,k,a,b,c,x,y,z;
    in(n);
    vector<triple> v(n-2);
    rep(i,n-2)
    {
        in3(a,b,c);
        v[i]=mt(a,b,c);
        ad[a].pb(i);
        ad[b].pb(i);
        ad[c].pb(i);
    }
    k=0;
    lp(i,1,n+1)
    {
        if(ad[i].size()==1)
        {
            k=i;
            break;
        }
    }
    vi ar(n);
    ar[0]=k;
    i=ad[k][0];
    tie(a,b,c)=v[i];
    if(ad[a].size()==2)
        x=a;
    else if(ad[b].size()==2)
        x=b;
    else
        x=c;
    ar[1]=x;
    vis[k]=1,vis[x]=1;
    lp(i,2,n)
    {
        x=ar[i-2],y=ar[i-1];
        z=ad[y].size();
        rep(j,z)
        {
            k=ad[y][j];
            tie(a,b,c)=v[k];
            k=vis[a]+vis[b]+vis[c];
            if(k==2)
            {
                if(a!=x && a!=y)
                    ar[i]=a;
                else if(b!=x && b!=y)
                    ar[i]=b;
                else
                    ar[i]=c;
            }
        }
        vis[ar[i]]=1;
    }
    dbg(ar,i,n);
}
 