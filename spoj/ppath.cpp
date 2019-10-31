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

int fi,f=0;
bool vis[10005];
bool prime[10010]; 


void SieveOfEratosthenes(int n) 
{
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
} 

int solve(int in)
{
    queue <ipair> ol;
    ol.push({in,0});

    while(!ol.empty())
    {
        ipair x=ol.front();
        ol.pop();

        if(vis[x.ff]==true)
        continue;
        vis[x.ff]=true;

        if(prime[x.ff]==false)
        continue;

        // cout<<x.ff<<" "<<x.ss<<endl;

        if(x.ff==fi)
        {
            f=1;
            return x.ss;
        }

        int a,b,c,d;
        d=x.ff%10;
        x.ff/=10;
        c=x.ff%10;
        x.ff/=10;
        b=x.ff%10;  
        x.ff/=10;
        a=x.ff;

        int r=1000+b*100+c*10+d,lr;

        while(r<1e4)
        {
            // cout<<"here1"<<endl;
            if(vis[r])
            {r+=1000;continue;}
            ol.push({r,x.ss+1});
            r+=1000;
        }

        r=1000*a+c*10+d;
        lr=min(r+1000,(int)1e4);

        while(r<lr)
        {
            // cout<<"here2"<<endl;
            if(vis[r])
            {r+=100;continue;}
            ol.push({r,x.ss+1});
            r+=100;
        }

        r=1000*a+100*b+d;
        lr=min(r+100,(int)1e4);

        while(r<lr)
        {
            // cout<<"here3"<<endl;
            if(vis[r])
            {r+=10;continue;}
            ol.push({r,x.ss+1});
            r+=10;
        }

        r=1000*a+b*100+c*10;
        lr=min(r+10,(int)1e4);

        while(r<lr)
        {
            // cout<<"here4"<<endl;
            if(vis[r])
            {r+=1;continue;}
            ol.push({r,x.ss+1});
            r+=1;
        }
    }
    return -1;
}


int main()
{
    fastio;
    int init,t;
    cin>>t;
    SieveOfEratosthenes(10007); 
    while(t--)
    {
        cin>>init>>fi;
        memset(vis,false,sizeof vis);
        f=0;
        int ans=solve(init);

        if(f)
        cout<<ans<<endl;
        else
        cout<<"Impossible"<<endl;
    }
}