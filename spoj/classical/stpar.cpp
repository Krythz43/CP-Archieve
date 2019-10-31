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

int main()
{
    fastio;
    for(;;)
        {
        int n;
        cin>>n;

        if(n==0)
        break;

        vi a(n);
        rep(i,n,0)
        cin>>a[i];

        int f=0,k=0;

        stack <int> s;

        for(;;)
        {
            if(k==n)
            break;

            if(a[k]==f+1)
            {
                k++;
                f++;
            }
            else if(s.empty()==false)
            {
                if(s.top()==f+1)
                {f++;
                s.pop();}
                else
                {
                s.push(a[k]);
                k++;
                }
            }
            else
            {
                s.push(a[k]);
                k++;
            }
        }

        while(s.empty()==false)
        {
            if(s.top()==f+1)
            {
                f++;
                s.pop();
            }
            else
            {
                break;
            }
        }

        if(f==n)
        cout<<"yes";
        else
        cout<<"no"; 
        nl; 
    }
}   