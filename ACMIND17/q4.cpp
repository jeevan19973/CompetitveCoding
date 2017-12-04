/* TEAM-MasterMinds */
#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
#define fi first
#define se second
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define fill(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
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

bool mysort( pair<ll,ll> a, pair<ll,ll> b ){
	return a.fi < b.fi;
}

int main()
	{
		ios_base::sync_with_stdio(false); cin.tie(0);
		int T;
		cin >> T;
		rep(i,T){
			ll N;
			cin >> N;
			vl a,b;
			
			rep(j,N){
				ll ax;
				cin >> ax;
				a.pb(ax);
			}
			ll mini = mod;

			rep(j,N){
				ll bx;
				cin >> bx;
				b.pb(bx);
				if( bx < mini ) mini = bx;
			}

			ll ans = 0;
			vector<pair<ll,ll> > rem;
			rep(j,N){
				ll md = a[j] % b[j];
				if( md >= mini ){ ans += b[j] - md; md = 0; }
				rem.pb(mp(md,b[j]));
			}

			sort(rem.begin(),rem.end(),mysort);
			map<ll,ll> s;
			map<ll,ll> lcnt;
			rep(j,N){
				s[rem[j].fi]++;
				if( rem[j].fi == 0 ){ lcnt[rem[j].fi] += 0; }
				else{
					lcnt[rem[j].fi] += rem[j].se - rem[j].fi;
				}
			}

			vector<pair<ll,ll> > M;
			for( map<ll,ll>::iterator it = s.begin(); it != s.end(); it++ ){
				M.pb(mp(it->first,it->second));
			}

			ll fcm[M.size()];
			ll ccnt[M.size()];
			ll rcm[M.size()];
			memset(rcm,0,sizeof(rcm));
			memset(fcm,0,sizeof(fcm));
			memset(ccnt,0,sizeof(ccnt));

			rep(j,M.size()){
				ccnt[j] = M[j].se;
				if( !j ){ continue; }
				ccnt[j] += ccnt[j-1];
				fcm[j] = fcm[j-1] + ccnt[j-1] * (M[j].fi - M[j-1].fi); 
			}

			rrep(j,M.size()){
				rcm[j] = lcnt[M[j].fi];
				if( j != M.size()-1 ) rcm[j] += rcm[j+1];
			}

			ll mans;
			rep(j,M.size()){
				ll cans = ans;
				if( j != M.size()-1){ cans += rcm[j+1]; }
				ll remct = ccnt[M.size()-1] - ccnt[j];
				cans += remct * M[j].fi;
				cans += fcm[j];
				if( j == 0 ) mans = cans;
				else { if( cans < mans ) mans = cans; }				
			}

			cout << mans << endl;


		}		
		return 0 ;
	}

