#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

struct po{
    int x1,y1,x2,y2;
};

bool completeCover(po x, po y){
    return x.x2<=y.x2 && x.y2<=y.y2 && x.x1>=y.x1 && x.y1>=y.y1;
}

bool pointCover(int x,int y,po p){
    return x<=p.x2 && y<=p.y2 && x>=p.x1 && y>=p.y1;
}

int main()
{
    fastio;
    vector <po> a(3);

    rep(i,3,0){
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
    }

    if(
        completeCover(a[0],a[1]) ||
        completeCover(a[0],a[2])
    ){
        cout<<"NO"<<endl;
    }
    else if(
        ( !pointCover(a[0].x1,a[0].y1,a[1]) && !pointCover(a[0].x1,a[0].y1,a[2]) )||
        ( !pointCover(a[0].x1,a[0].y2,a[1]) && !pointCover(a[0].x1,a[0].y2,a[2]) )||
        ( !pointCover(a[0].x2,a[0].y1,a[1]) && !pointCover(a[0].x2,a[0].y1,a[2]) )||
        ( !pointCover(a[0].x2,a[0].y2,a[1]) && !pointCover(a[0].x2,a[0].y2,a[2]) )  
    ){
        cout<<"YES"<<endl;
    }
    else{
        if(a[1].x1>a[2].x1)swap(a[1],a[2]);
        if(a[2].x1>a[1].x2){
            cout<<"YES"<<endl;
            return 0;
        }

        if(a[1].y1>a[2].y1)swap(a[1],a[2]);
        if(a[2].y1>a[1].y2){
            cout<<"YES"<<endl;
            return 0;
        }

        cout<<"NO"<<endl;
    }
}