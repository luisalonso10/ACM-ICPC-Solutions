#include <bits/stdc++.h>
#define MAX 20000000
using namespace std;

typedef long long ll;

ll s;
vector< pair<ll,ll> > v;
bitset<MAX + 1> bs;

void sieve(){
	
	bs.set();
	bs[0] = bs[1] = 0, bs[2] = 1;
	
	for(ll i = 4; i <= MAX; i+=2) bs[i] = 0;
	
	for(ll i = 3; i <= MAX; i+=2){
		
		if(bs[i]){
			
			for(ll j = i*i; j<= MAX; j+=i){
				bs[j] = 0;
			}

			if(bs[i+2] && ((i + 2) <= MAX)){
				pair<ll,ll> p;
				p.first = i, p.second = i + 2;
				v.push_back(p);
			}	
		}
	}
}

int main(){
	sieve();
	while(cin>>s){
		pair<ll,ll> ans = v[s-1];
		cout<<"("<<ans.first<<", "<<ans.second<<")"<<endl;
	}
}