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

int dfs( int visit[], int pt[], int good[], vector<pair<int,int> > v[], int n, int s, int p, int x ){
	// cout << s + 1 << " " << x << endl;
	visit[s] = 1;
	pt[s] = p;
	good[s] = x;
	rep(j,v[s].size()){
		int neigh = v[s][j].fi;
		if( visit[neigh] == 0 ){
			int b = dfs( visit, pt, good, v, n, neigh, s, x^v[s][j].se);
			if( b == -1 ) return -1;
		}
		else if( visit[neigh] == 1 ){
			// cout << "enter " << s + 1 << " " << neigh+1 << endl;
			int ans = x^v[s][j].se^good[neigh];
			// cout << ans << endl;
			if( ans == 1 ){ return -1; }
		}
	}

	visit[s] = 2;
	return 0;
}


int main()
	{
		ios_base::sync_with_stdio(false); cin.tie(0);
		int T;
		cin >> T;
		rep(i,T){
			int N,Q;
			cin >> N >> Q;
			map<pair<int,int>, int > m,fl;
			int flag = 0;
			rep(j,Q){
				int a,b,val;
				cin >> a >> b >> val;
				a--;
				b--;
				if( fl[mp(a,b)] == 1 ){
					if( val != m[mp(a,b)]) { flag = 1; }
				}
				fl[mp(a,b)] = 1;
				m[mp(a,b)] = val;
				if( a == b && val == 1 ) flag = 1;
			}

			if( flag ){ cout << "no" << endl; continue; }

			vector<pair<int,int> > v[N];

			for( map<pair<int,int>,int>::iterator it = m.begin(); it != m.end(); it++ ){
				pair<int,int> p = it->fi;
				pair<int,int> q = mp(p.se,p.fi);
				if( p.fi == p.se ) continue;
				if( fl[q] == 1 ){
					if( m[p] != m[q] ){
						flag = 1;
						break;
					}
				}
				else{
					fl[q] = 1;
					m[q] = it->second;
				}
			}

			for( map<pair<int,int>,int>::iterator it = m.begin(); it != m.end(); it++ ){
				pair<int,int> p = it->fi;
				v[p.fi].pb(mp(p.se,it->se));
			}

			int pt[N],visit[N],good[N];
			memset(pt,-1,sizeof(pt));
			memset(visit,0,sizeof(visit));
			memset(good,0,sizeof(good));

			rep(j,N){
				if( visit[j] == 0 ){
					int k = dfs( visit, pt, good, v, N, j, -1, 0 );
					if( k == -1 ){ flag = 1; 
									break;
								}
				}
			}

			if( flag ){ cout << "no" << endl; }
			else cout << "yes" << endl;

		}		
		return 0 ;
	}

