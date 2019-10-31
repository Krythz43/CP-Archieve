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
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}

bool m(char a[])
{
    rep(i,strlen(a),0)
    {
        if(a[i]=='m')
        return true;
    }
    return false;
}
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int f=0;
        int n1,n2,n3;
        char x[10];
        cin>>x;
        if(!m(x))
        {
            n1=atoi(x);
        }
        else
        f=1;
        
        cin>>x;
        cin>>x;
        if(!m(x))
        {
            n2=atoi(x);
        }
        else
        f=2;

        cin>>x;
        cin>>x;
        if(!m(x))
        {
            n3=atoi(x);
        }
        else
        f=3;

        if(f==1)
        n1=n3-n2;
        else if(f==2)
        n2=n3-n1;
        else
        n3=n1+n2;

        cout<<n1<<" + "<<n2<<" = "<<n3<<endl;

    }
}