#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,a,b) for(int i=a;i<b;i++)
int main()
{
	ll n,pos,fl=0,fptr,sptr,mid,one,scnd;
	string str;
	cin >> n >> pos >> str;
	ll f=0,l=str.size()-1;
	mid=n/2;
	while(f<l)
	{
		//cout << "frst" << " ";
		//	cout << f << " " << l << "\n";
		if(str[f]==str[l])
			f++,l--;
		else
		{
			fl=1;
			break; 
		}
	}
	if(!fl) cout << 0 << "\n";
	else
	{
		ll ans=0;
		mid=n/2;
		fptr=mid-1;
		if(n&1) sptr=mid+1;
		else sptr=mid;
		while(fptr>f and sptr<l)
		{
			//cout << "scnd" << " " << fptr << " " << sptr << "\n";
			if(str[fptr]==str[sptr])
				fptr--,sptr++;
			else
				break;
		}
		if(pos>mid)
			pos=n-pos+1;
		loop(i,0,mid)
		{
			//cout << (str[n-i-1]) << " " <<  str[i] << "\n";
			one=abs(str[n-i-1]-str[i]);
			scnd=26-(one);
			ans+=min(one,scnd);
		}//cout << ans << "\n";
		pos--;
		//cout << f << " " << fptr << " ";
		if(pos>=0 and pos<=f)
			ans+=(fptr-pos);
		else if(pos>f and pos<fptr)
			ans+=(min(2*fptr-pos-f,fptr+pos-2*f));
		else if(pos>=fptr and pos<=mid)
			ans+=(pos-f);
		cout << ans << "\n";
	}
	return 0;


}