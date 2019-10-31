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
lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

lli multi(lli x,lli n,lli mod)
{
    if(n==0)
    return 1;
    if(n==1)
    return x%mod;
    if(n%2==0)
    return (multi((x*x)%mod,n/2,mod))%mod;
    return ((x%mod)*(multi((x*x)%mod,(n-1)/2,mod)))%mod;
}
int main()
{
    fastio;
    string s;
    cin>>s;
    lli a,b,pr=0,sf=0;
    cin>>a>>b;

    int l=s.length();
    pr=s[0]-'0';

    rep(i,l,1)
    sf=(sf*10+(s[i]-'0'))%b;
    rep(i,l,1)
    {
        // cout<<i<< " th iter: "<<pr<<endl;
        if(pr%a==0)
        {
            int j=i;
            while(s[j]=='0' && j!=l)
            j++;
            int z=j;
            if(j!=l)
            {
                if(sf%b==0)
                {
                    cout<<"YES"<<endl;
                    rep(n,z,0)
                    cout<<s[n];
                    nl;
                    rep(n,l,z)
                    cout<<s[n];
                    return 0;
                }
            }


        }
        else
        {
            // cout<<pr<<" "<<sf<<endl;
            pr=(pr*10+s[i]-'0')%a;
            sf=(sf-(((s[i]-'0')*multi(10,l-i-1,b))%b)+b)%b;
        }
    }

    cout<<"NO";
}