#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define mod	1000000007
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define myrep(i,a,b) for( int i = a; i <= b; i++ )

using namespace std ;

ll binPow(ll a ,ll b ,ll Mo){
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % Mo)
        if (b&1) ans = ans * a % Mo;
    return ans;
}

void generate( map<pair<int,int>,int> m, int n, int k, ll &ans, string s ){
	if( s.length() == n ){
		vector<int> v;
		rep(i,s.length()){
			if( s[i] == '1' ) v.pb(i);
		}
		ll ed = 0;
		rep(i,v.size()){
			myrep(j,i+1,v.size()-1){
				if( m[mp(v[i],v[j])] == 1 ){ ed++; }
			}
		}
		ed %= mod;
		ed = binPow(ed,k,mod);
		ans = (ans%mod+ed%mod)%mod;
		return;
	}
	else{
		generate( m, n, k, ans, s + '0' );
		generate( m, n, k, ans, s + '1' );
	}
	return;
}

int main()
	{
		ios_base::sync_with_stdio(false); cin.tie(0);
		int T;
		cin >> T;
		rep(i,T){
			int n,m,k;
			cin >> n >> m >> k;
			map<pair<int,int>, int> ma;
			rep(j,m){
				int a,b;
				cin >> a >> b;
				a--; b--;
				ma[mp(a,b)] = 1;
				ma[mp(b,a)] = 1;
			}


			ll ans = 0;
			if( k == 1 ){
				ans = binPow( 2, n - 2, mod );
				ans = (ans%mod * m%mod )%mod;
				ans %= mod;
				cout << ans << endl;
				continue;
			}
			generate( ma, n, k, ans, "" );
			ans %= mod;
			cout << ans << endl;
		}		
		return 0 ;
	}

