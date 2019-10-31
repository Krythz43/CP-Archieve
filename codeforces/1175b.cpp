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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    lli mx=(1LL<<32)-1LL;
    int n,x;
    cin>>n;
    string s;
    lli ans=0,tcal=0;
    vlli layerval(100000,0);
    vlli mul(100000,1);
    int clayer=0;
    while(n--)
    {
        cin>>s;
        if(s=="add")
        {
            layerval[clayer]++;
            if(mul[clayer]*layerval[clayer]>mx)
            {
                cout<<"OVERFLOW!!!"<<endl;
                return 0;
            }
        }
        else if(s=="for")
        {
            clayer++;
            cin>>x;
            mul[clayer]*=x;
            if(mul[clayer]*layerval[clayer]>mx)
            {
                cout<<"OVERFLOW!!!"<<endl;
                return 0;
            }
        }
        else if(s=="end")
        {
            if(mul[clayer]*layerval[clayer]>mx)
            {
                cout<<"OVERFLOW!!!"<<endl;
                return 0;
            }
            layerval[clayer-1]+=layerval[clayer]*mul[clayer];
            layerval[clayer]=0;
            mul[clayer]=1;
            clayer--;
        }
    }
    if(mul[0]*layerval[0]>mx)
    {
        cout<<"OVERFLOW!!!"<<endl;
        return 0;
    }
    cout<<layerval[0]*mul[0]<<endl;
}
