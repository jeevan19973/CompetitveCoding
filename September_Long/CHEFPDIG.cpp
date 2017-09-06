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
			string s;
			cin >> s;
			int cnt[10];
			memset(cnt,0,sizeof(cnt));
			rep(j,s.length()){
				cnt[s[j]-'0']++;
			}

			int isp[26];
			memset(isp,0,sizeof(isp));
			myrep(j,65,90){
				int h,l;
				l = j%10;
				h = j/10;
				if( h != l ){
					if( cnt[h] > 0 && cnt[l] > 0 ) isp[j-65] = 1;
				}
				else{
					if( cnt[h] >= 2 ) isp[j-65] = 1;
				}
			}

			string ans = "";
			rep(j,26){
				if( isp[j] == 1 ) ans += 'A' + j;
			}

			cout << ans << endl;
		}		
		return 0 ;
	}

