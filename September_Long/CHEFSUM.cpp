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

int main()
	{
		ios_base::sync_with_stdio(false); cin.tie(0);
		int T;
		cin >> T;
		rep(i,T){
			int N;
			cin >> N;
			ll ar[N];
			ll psum[N],ssum[N];
			rep(j,N){
				cin >> ar[j];
			}

			rep(j,N){
				if( j ) psum[j] = ar[j] + psum[j-1];
				else psum[j] = ar[j];
			}

			rrep(j,N){
				if( j != N-1 ) ssum[j] = ssum[j+1] + ar[j];
				else ssum[j] = ar[j];
			}

			ll mini = 1e12;
			int mpos = N-1;
			rrep(j,N){
				if( psum[j] + ssum[j] <= mini ){
					mini = psum[j] + ssum[j];
					mpos = j;
				}
			}
		
			cout << mpos + 1 << endl;
		}
		return 0 ;
	}

