#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,d) for(int i=d;i<n;i++)
#define rrep(i,d) for(int i=d;i>=0;i--)
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

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

int n;
vi ans;
vi ext;

void xorcycle(int r)
{
    vi xox(r);
    rep(i,r,0)
    {
        xox[i]=(ext[i]^(ext[(i+1)%r]))^(ext[(i+2)%r]);
    }

    rep(i,r,0)
    ext[i]=xox[i];
}


void four()
{
    int a,b,c,d;
    d=n;
    c=n-1;
    b=n-2;
    a=n-3;

    int x1,x2,x3,x4,x5,x6;

    cout<<1<<" "<<a<<" "<<b<<" "<<c<<endl;
    cout<<flush;  
    cin>>x1;
    cout<<1<<" "<<b<<" "<<c<<" "<<d<<endl;
    cout<<flush;
    cin>>x2;
    cout<<1<<" "<<a<<" "<<c<<" "<<d<<endl;
    cout<<flush;
    cin>>x3;
    cout<<1<<" "<<a<<" "<<b<<" "<<d<<endl;
    cout<<flush;
    cin>>x4;

    x5=(x1^x2)^x3;  //gets c
    x6=(x1^x2)^x4;  //gets b
    ans.pb((x5^x6)^x2); //push d 
    ans.pb(x5);//push c 
    ans.pb(x6);//push b
    ans.pb((x5^x6)^x1);//push a
}



void five()
{
    int a,b,c,d,e;
    e=n;
    d=n-1;
    c=n-2;
    b=n-3;
    a=n-4;

    int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13;

    cout<<1<<" "<<a<<" "<<b<<" "<<c<<endl;
    cout<<flush;  
    cin>>x1;
    cout<<1<<" "<<b<<" "<<c<<" "<<d<<endl;
    cout<<flush;
    cin>>x2;
    cout<<1<<" "<<c<<" "<<d<<" "<<e<<endl;
    cout<<flush;
    cin>>x3;
    cout<<1<<" "<<a<<" "<<b<<" "<<e<<endl;
    cout<<flush;
    cin>>x4;
    cout<<1<<" "<<a<<" "<<d<<" "<<e<<endl;
    cout<<flush;
    cin>>x5;

    x6=(x1^x2)^x3; //a^c^e
    x7=(x4^x5); //d^b
    x8=(x7^x2); //gets the value of c
    x9=(x1^x8);  //a^b
    x10=(x9^x4);  //gets the value of e
    x11=(x3^(x8^x10));//gets the value of d
    x12=(x2^(x8^x11));//gets the value of b;
    x13=(x1^(x12^x8));//gets the value of a;

    ext.pb(x13);
    ext.pb(x12);
    ext.pb(x8);
    ext.pb(x11);
    ext.pb(x10);    
}

void seven()
{
    int a,b,c,d,e,f,g;
    g=n;
    f=n-1;
    e=n-2;
    d=n-3;
    c=n-4;
    b=n-5;
    a=n-6;

    int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11;

    cout<<1<<" "<<a<<" "<<b<<" "<<c<<endl;
    cout<<flush;  
    cin>>x1;
    cout<<1<<" "<<b<<" "<<c<<" "<<d<<endl;
    cout<<flush;
    cin>>x2;
    cout<<1<<" "<<c<<" "<<d<<" "<<e<<endl;
    cout<<flush;
    cin>>x3;
    cout<<1<<" "<<d<<" "<<e<<" "<<f<<endl;
    cout<<flush;
    cin>>x4;
    cout<<1<<" "<<e<<" "<<f<<" "<<g<<endl;
    cout<<flush;
    cin>>x5;
    cout<<1<<" "<<f<<" "<<g<<" "<<a<<endl;
    cout<<flush;
    cin>>x6;
    cout<<1<<" "<<g<<" "<<a<<" "<<b<<endl;
    cout<<flush;
    cin>>x7;

    ext.pb(x1);
    ext.pb(x2);
    ext.pb(x3);
    ext.pb(x4);
    ext.pb(x5);
    ext.pb(x6);
    ext.pb(x7);

    rep(i,6,0)
    xorcycle(7);
}





int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        ans.clear();
        ext.clear();


        cin>>n;
        switch(n%4)
        {
            case 1: five();n-=5;break;
            case 2: five();n-=5;five();n-=5;break;
            case 3: seven();n-=7;break;
            case 0: break;
        }

        

        while(n)
        {
            four();
            n-=4;
        }

        int q;

        cout<<2<<" ";
        cout<<flush;
        for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
        cout<<flush;
        rep(i,ext.size(),0)
        cout<<ext[i]<<" ";
        cout<<flush;
        nl;
        cout<<flush;

        cin>>q;
        if(q==-1)
        {
            return 0;
        }
    }
}