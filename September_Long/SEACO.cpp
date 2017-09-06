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

ll treeInit( int q, int l, int r, int pos, ll stree[] ){
	if( l > r ) return 0;
	if( q < l || q > r ) return 0;
	if( l == r ) { 
		stree[pos] = stree[pos] + 1;
		stree[pos] %= mod;
		return stree[pos];
		}
	int m = (l+r)/2;
	stree[pos] = treeInit( q, l, m, pos*2+1, stree )%mod + treeInit( q, m+1, r, pos*2+2, stree )%mod;
	stree[pos] %= mod;
	return stree[pos];
}

int query( int q, int l, int r, int pos, ll stree[], ll add[] ){
	if( q < l || q > r ) return 0;
	if( l == r ){ 
		ll a = (stree[pos]%mod+add[pos]%mod)%mod;
		return a;
		}
	int m = l + (r-l)/2;
	ll ans = add[pos]%mod + query( q, l, m, pos*2+1, stree, add )%mod + query( q, m+1, r, pos*2+2, stree, add )%mod;
	ans %= mod;
	return ans;
}


void update( int ql, int qr, int l, int r, int pos, ll stree[], ll add[], int cnt ){
	if( qr < l || ql > r ) return;
	if( l >= ql && r <= qr ){ add[pos] = (add[pos]%mod + cnt%mod)%mod; return; }
	int m = (l+r)/2;
	update( ql, qr, l, m, pos*2+1, stree, add, cnt );
	update( ql, qr, m+1, r, pos*2+2, stree, add, cnt );
}

int main()
	{
		ios_base::sync_with_stdio(false); cin.tie(0);
		int T;
		cin >> T;
		rep(i,T){
			int n,m;
			cin >> n >> m;
			ll stree[4*m];
			ll add[4*m];
			memset(stree,0,sizeof(stree));
			memset(add,0,sizeof(add));
			vector<int> tt;
			vector<pair<int,pair<int,int> > > q;
			rep(j,m){
				int t,l,r;
				cin >> t >> l >> r;
				l--; r--; 
				q.pb(mp(t,mp(l,r)));
				if( t == 2 ){ tt.pb(j); }
				treeInit( j, 0, m-1, 0, stree );
			}

			rrep(j,tt.size()){
				// rep(k,m){
				// 	cout << query( k, 0, m-1, 0, stree, add, 2*m-1) << " ";
				// }
				// cout << endl;
				ll cnt = query( tt[j], 0, m-1, 0, stree, add );
				//cout << cnt << " ct" << endl;
				int l,r;
				l = q[tt[j]].se.fi;
				r = q[tt[j]].se.se;
				update( l, r, 0, m-1, 0, stree, add, cnt );

			}

			ll qtime[m];
			memset(qtime,0,sizeof(qtime));
			rep(j,m){
				qtime[j] = query( j, 0, m-1, 0, stree, add );
			}

			// rep(j,m){
			// 	cout << qtime[j] << " ";
			// }
			// cout << endl;

			ll cum = 0;
			ll cchange[n+4];
			memset(cchange,0,sizeof(cchange));

			rep(j,m){
				if( q[j].fi == 2 ) continue;
				cchange[q[j].se.fi] += qtime[j];
				cchange[q[j].se.fi] %= mod;
				cchange[q[j].se.se+1] -= qtime[j];
				if( cchange[q[j].se.se+1] < 0 ){
					cchange[q[j].se.se+1] += mod;
				}
				cchange[q[j].se.se+1] %= mod;
			}

			rep(j,n){
				cum = (cum%mod + cchange[j]%mod)%mod;
				cout << cum << " ";
			}
			cout << endl;
		}		
		return 0 ;
	}

