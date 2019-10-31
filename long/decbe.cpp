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

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}


int n,c;

bool check(int v)
{
    if(v>=0)
    return false;
    else
    return true;
}
int main()
{
    fastio;
    int hash[200000];
    cin>>n>>c;
    int bal=1000;  // initiate balance
    int mid;
    int state=0;

    memset(hash,-1,sizeof hash);

    int hi=n,lo=0;  //setting the possible attainable values
    mid=hi+lo;
    mid>>=1;
    while(hi-lo>1)
    {
        mid=hi+lo;
        mid>>=1;  
        if(state)
        {
            if(check(bal-c))           //check if broken
            {
                cout<<3<<" "<<(hi+lo)/2+1<<endl;cout.flush();return 0;
            }
            else bal-=c;          //not broken so pay for it

            cout<<2<<endl;
            cout.flush();
        }

        if(check(bal-1))              // check for balance
        { 
            cout<<3<<" "<<(hi+lo)/2+1<<endl;cout.flush();return 0;
        }
        else bal-=1;

        cout<<1<<" "<<mid<<endl;
        cout.flush();
        cin>>state;
        hash[mid]=state;  //state=1 is broken, 0 is still working

        if(state)    //change accoriding to the statw of the letric board
        hi=mid;
        else
        lo=mid;
    }

    if(state)
    {
        if(check(bal-c))     // check again if broken
        {
            cout<<3<<" "<<(hi+lo)/2+1<<endl;cout.flush();return 0;
        }
        else bal-=c;

        cout<<2<<endl;
        cout.flush();
    }

    if(check(bal-1))          //pay to test the voltage 
    {
        cout<<3<<" "<<(hi+lo)/2+1<<endl;cout.flush();return 0;
    }
    else bal-=1;
    int hashed=0;

    if(hash[hi]==-1)
    {
        cout<<1<<" "<<hi<<endl;
        cout.flush();
        cin>>state;
    }
    else
    {
        state=hash[hi];
        hashed=1;
    }

    if(state==1)
    {
        if(!hashed)
        {
            if(check(bal-c))
            {
                cout<<3<<" "<<(hi+lo)/2+1<<endl;cout.flush();return 0;
            }
            else bal-=c;

            cout<<2<<endl;
            cout.flush();
        }
        cout<<3<<" "<<lo+1<<endl;
        cout.flush();
    }
    else
    {
        cout<<3<<" "<<hi+1<<endl;
        cout.flush();
    }

}