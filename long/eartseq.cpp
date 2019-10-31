#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'


vector <int> nprime;
void SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          nprime.pb(p);
} 

int main()
{
    fastio;
    int t;
    cin>>t;
    SieveOfEratosthenes((int)sqrt(1e9));
    // cout<<nprime.size()<<endl;
    // cout<<nprime[0]<<" "<<nprime[3400]<<endl;

    vi a;
    int x=0,y=1;
    int si=0;
    int dir=0;
    int c=0;
    while(1)
    {
        if(c==50000)
        break;
        if(dir==0)
        {
            a.pb(nprime[x]*nprime[y]);
            if(a[a.size()-1]==6)
            cout<<x<<" "<<y<<endl;
            x++;
            y++;
            if(y==2400)
            {
                x-=2;
                y--;
                dir=dir^1;
            }
        }
        else
        {
            a.pb(nprime[x]*nprime[y]);
            if(a[a.size()-1]==6)
            cout<<x<<" "<<y<<endl;
            x--;
            y--;
            if(x==-1)
            {
                x++;
                y+=2;
                dir=dir^1;
            }
        }
        c++;
    }

    for(int n=3;n<=50000;n++)
    {
        vi cans;
        
        rep(i,n-1,0)
        cans.pb(a[i]);
        cans.pb(a[n-1]*2);

        bool ok =true;


        rep(i,n,0)
        {
            int r=__gcd(cans[(i)],cans[(i+1)%n]);
            if(r!=1  && __gcd(r,cans[  (i+2)%n   ]    )==1 )
            ok=true;
            else
            {
                ok=false;
                cout<<cans[i]<<" "<<cans[(i+1)%n]<<" "<<r<<" "<<i<<endl;
                 break;
            }
        }

        if(ok)
       {
            // cout<<"passed at n="<<n;
        }
        else{
            cout<<"fails at n="<<n<<endl;
            return 0;
        }
    }
}