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

struct tr
{
    int day;
    int lec;
    int sad;
};

bool comp(tr tr1,tr tr2)
{
    return tr1.day<tr2.day;
}

class pcomp
{
    public:
    int operator()(tr tr1,tr tr2)
    {
    return tr1.sad<tr2.sad;
    }
};


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int n,days;
        lli total=0,sum=0;
        cin>>n>>days;
        tr a[n];

        rep(i,n,0)
        {
            cin>>a[i].day>>a[i].lec>>a[i].sad;
            total+=a[i].lec*(lli)a[i].sad;
        }

        sort(a,a+n,comp);

        priority_queue <tr, vector<tr>, pcomp > p;

        int i=0,k=0;

        tr x;

        for(k=1;k<=days;k++)
        {
            while( k==a[i].day  &&  i<n )
            {
                p.push(a[i]);
                i++;
            }

            if(p.size()==0)
            {
                continue;
            };

	        sum+=p.top().sad;
	        tr a=p.top();
	        p.pop();
	        a.lec-=1;

	        if(a.lec>0)
	        p.push(a);
	    }

	   cout<<total-sum<<endl;
    }
}