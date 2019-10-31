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
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;

int main()
{
    fastio;
    int n,m,l;
    cin>>m>>n;
    l=m+n;

    if(m>n+1)
    cout<<-1;
    else
    {
        if(m>=n)
        {
            rep(i,n+m,0)
            {
                if(i%2==0)
                cout<<"0";
                else
                cout<<"1";
            }
        }
        else if (m==n-1)
        {
            rep(i,n+m,0)
            {
                if(i%2)
                cout<<"0";
                else
                cout<<"1";
            }
        }
        else
        {
            if(n>2*m+2)
            cout<<"-1";
            else
            {
                int t=0;

                while(n!=m)
                {
                    if(t%2==0)
                    {
                        if(n-m>1)
                        {
                            cout<<"11";
                            n-=2;
                            if(n==m)
                            {t++;
                            break;}
                        }
                        else
                        {
                            cout<<"1";
                            n--;
                        }
                    }
                    else
                    {
                        cout<<"0";
                        m--;
                    }   
                    t++;
                }

                while(n+m)
                {
                    if(t%2){
                        cout<<"0";
                        m--;
                    }
                    else
                    {
                        cout<<"1";
                        n--;
                    }
                    t++;
                }
            }
        }
    }
}