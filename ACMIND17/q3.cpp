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

int main()
	{
		ios_base::sync_with_stdio(false); cin.tie(0);
		int T;
		cin >> T;
		rep(i,T){
			double long n,k;
			cin >> n >> k;
			cout << setprecision(10) << fixed;
			double long ans = 2;
			if( n == 1 ) { cout << ans << endl; continue; }
			double long sum = (n-1)*(k-1);
			sum /= k;
			sum += 1;
			ans *= sum;
			cout << ans << endl;
		}		
		return 0 ;
	}

