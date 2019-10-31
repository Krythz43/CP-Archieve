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

int n,m;

bool r(int a,int b)
{
    return a>b;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a[n][m],t[m][n];

        rep(i,n,0)
        {
            rep(j,m,0)
            a[i][j]=0;
        }
        string s;
        int l;
        rep(i,n,0)
        {
            cin>>s;
            l=s.length();
            rep(j,l,0)
            {
                if(s[j]=='1')
                {
                    a[i][j]++;
                }
            }
        }

        cin>>s;
        l=s.length();

        rep(i,l,0)
        {
            if(s[i] =='R')
            {
                // cout<<"executing right";
                for (int i = 0 ; i < n; i++)
                sort(a[i], a[i] + m);
            }
            else if(s[i]=='D')
            {
                // cout<<"executing down";
                        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) 
                    {
                        t[j][i]=a[i][j];
                    }
                for (int i = 0 ; i < m; i++)
                    sort(t[i], t[i] + n);
                for (int i = 0; i < n; i++)
                for (int j =0; j < m; j++) 
                    {
                        a[i][j]=t[j][i];
                    }
            }
            else if(s[i]=='U')
            {
                // cout<<"executing ip";
                for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) 
                    {
                        t[j][i]=a[i][j];
                    }
                for (int i = 0 ; i < m; i++)
                    sort(t[i], t[i] + n,r);
                for (int i = 0; i < n; i++)
                for (int j =0; j < m; j++) 
                    {
                        a[i][j]=t[j][i];
                    }
            }
            else 
            {
                // cout<<"executing left";
                for (int i = 0 ; i < n; i++)
                sort(a[i], a[i] + m,r);
            }
        }

        rep(i,n,0)
        {
            rep(j,m,0)
            cout<<a[i][j];
            nl;
        }
    }
}