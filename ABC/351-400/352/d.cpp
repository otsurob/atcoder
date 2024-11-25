#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
#define wow() cout<<"wow"<<endl;
#define coc(a) cout<<a<<endl;;
#define coc2(a, b) cout<<a<<" "<<b<<endl;
#define coc3(a, b, c) cout<<a<<" "<<b<<" "<<c<<endl;
#define coc4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define pll pair<ll, ll>
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

int main(){
	ll n, k;
	cin>>n>>k;
	vector<ll> p(n), q(n);
	cinv(p, n);
	rep(i, n){
		q[p[i]-1]=i;
	}
	// rep(i, n)cout<<q[i]<<" ";
	// cout<<endl;
	set<ll> st;
	rep(i, k) st.insert(q[i]);
	auto itr1=st.begin(), itr2=st.end();
	itr2--;
	ll mn=*itr2-*itr1;
	// coc3(mn, *itr1, *itr2)
	rep2(k, i, n){
		st.erase(q[i-k]);
		st.insert(q[i]);
		itr1=st.begin();
		itr2=st.end();
		itr2--;
		// itr1++, itr2++;
		mn=min(mn, *itr2-*itr1);
		// coc2(*itr1, *itr2)
		// for(auto x : st){
		// 	cout<<x<<" ";
		// }
		// cout<<endl;
	}
	cout<<mn<<endl;
}