#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}

int main()
{
    fastio;
    int n;
    cin>>n;
    vector<bool> vis(n,false);
    vlli a(n);
    rep(i,n,0)
    cin>>a[i];
    int c=0;
    sort(a.begin(),a.end());
    rep(i,n,0)
    {
        lli t=1;
        int f=0;
        while(t<2e9)
        {
            t=t<<1;
            lli ch=t-a[i];

            if(ch<0)
            continue;

            if(ch==a[i])
            {
                if(i>0)
                {
                    if(a[i]==a[i-1])
                    {f=1;
                    // cout<<t<<"a"<<endl;
                    break;}
                }
                if(i<n-1)
                {
                    if(a[i]==a[i+1])
                    {f=1;
                    // cout<<t<<"b"<<endl;
                    break;}
                }
            }
            else
            {
                if(binary_search(a.begin(),a.end(),ch))
                {
                    f=1;
                    // cout<<t<<"c"<<binary_search(a.begin(),a.end(),ch)<<endl;
                    break;
                }
            }
        }

        if(f==0)
       {
           c++;
        //    cout<<"Deleting "<<a[i]<<endl;
       }
    }
    cout<<c;
}