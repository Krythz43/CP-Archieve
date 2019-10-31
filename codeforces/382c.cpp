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

int main()
{
    fastio;
    int n;
    cin>>n;
    vinput(a,n);
    SO(a);
    if(n==1){cout<<-1;return 0;}
    vi x;
    rep(i,n,1)
    {
        if(binary_search(x.begin(),x.end(),a[i]-a[i-1]))
        {

        }
        else
        {
            x.pb((a[i]-a[i-1]));
        }
    }

    if(x.size()>2)cout<<-1;
    else if(x.size()==1){
        if(x[0]%2)
        cout<<"2\n"<<a[0]-x[0]<<" "<<a[n-1]+x[0];
        else
        {
            cout<<a
        }
    }
    else
    {
        int d1=0,d2=0;
        rep(i,n,1)
        {
            rep(j,n,1)
            if(a[j]-a[j-1]==x[0])
            d1++;
            else
            d2++;

            if(d1==d2)
            {
                if(d1!=1)
                cout<<-1;
                else
                {
                    vi ans;
                    if(x[0]%2==0)
                    {
                        rep(i,n,1)
                        {
                            if(a[i]-a[i-1]==x[0])
                            ans.pb(a[i]-x[0]/2);
                        }
                        return 0;
                    }

                    if(x[1]%2==0)
                    {
                        rep(i,n,1)
                        {
                            if(a[i]-a[i-1]==x[1])
                            ans.pb(a[i]-x[1]/2);
                        }
                        return 0;
                    }

                    if(ans.size())
                    {
                        cout<<ans.size()<<endl;
                        rep(i,ans.size(),0)
                        cout<<ans[i]<<" ";
                    }
                    cout<<-1;
                }
            }
            else if(d1>1 && d2>1)
            cout<<-1;
            else
            {
                // rep(i,x.size(),0)
                // cout<<x[i]<<" ";
                // nl;
                // cout<<d1<<" "<<d2<<endl;
                if(d1==1)
                {
                    if(x[0]%2==0)
                    {
                        cout<<"1\n";
                        rep(i,n,1)
                        {
                            if(a[i]-a[i-1]==x[0])
                            cout<<a[i]-x[0]/2<<" ";
                        }
                        return 0;
                    }
                }
                else
                {
                    if(x[1]%2==0)
                    {
                        cout<<"1\n";
                        rep(i,n,1)
                        {
                            if(a[i]-a[i-1]==x[1])
                            cout<<a[i]-x[1]/2<<" ";
                        }
                        return 0;
                    }
                }
                cout<<-1;
            }         
        }
    }
}