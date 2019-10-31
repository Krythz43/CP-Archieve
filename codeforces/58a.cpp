#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false)
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
#define priority_queue pq;
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}

#define mod 1000003


int main()
{
	fastio;
    char a[101];
    cin>>a;
    int i=0;

    rep(j,strlen(a),0)
    {
        if(i==0)
        {
            if(a[j]=='h')
            i++;
        }
        else if(i==1)
        {
            if(a[j]=='e')
            i++;
        }
        else if(i==2 || i==3)
        {
            if(a[j]=='l')
            i++;
        }
        else if(i==4)
        {
            if(a[j]=='o')
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}