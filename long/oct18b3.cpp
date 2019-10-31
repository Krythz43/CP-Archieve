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

class bal
{ 
    lli x,y;

public: 
   bal(lli _x, lli _y) 
   { 
      x = _x; 
      y = _y; 
   } 
   lli getX() const { return x; } 
   lli getY() const { return y; } 
}; 
  
// To compare two bals 
class myComparator 
{ 
public: 
    lli operator() (const bal& p1, const bal& p2) 
    { 
        return p1.getX() < p2.getX(); 
    } 
}; 


int main()
{
    fastio;
    lli n;
    lli m;
    cin>>n>>m;
    vlli a(n),b(n);

    pq <bal, vector<bal>, myComparator > p; 
    ainput(a,n);
    ainput(b,n);

    rep(i,n,0)
    {
        p.push(bal(a[i]*b[i],b[i]));
    }

    lli x,y;
    
    while(m)
    {
        bal top=p.top();
        // cout<<top.getX()<<" "<<top.getY()<<endl;
        x=top.getX(),y=top.getY();
        
        if(x)
        {
            p.pop();
            bal top1=p.top();   
            lli x1=top1.getX();
            lli diff=ceil((double)x-x1)/y;
            
            if(diff==0)
            diff++;

            diff=m>diff?diff:m;
            x-=diff*y;
            m-=diff;
            p.push(bal(x,y));
        }
        else
        break;
    }

    bal z=p.top();
    cout<<z.getX()<<endl;

    // while(n--)
    // {
    //     bal top=p.top();
    //     cout<<top.getX()<<" "<<top.getY()<<endl;
    //     p.pop();
    // }
}