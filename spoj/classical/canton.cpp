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

int num,den,m;
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        num=den=m=1;
        int itr=1;

        for(;;)
        {
            if(n==m)break;
            den++;m++;
            if(n==m)break;
            itr++;
            rep(i,itr-1,0)
            {
                num++;
                den--;
                m++;
                if(n==m)break;
            }

            if(n==m)break;
            num++;m++;
            if(n==m)break;

            itr++;

            rep(i,itr-1,0)
            {
                num--;
                den++;
                m++;
                if(n==m)break;
            }
            if(n==m)break;

        }    
        cout<<"TERM "<<n<<" IS "<<num<<"/"<<den<<endl;
    }
}