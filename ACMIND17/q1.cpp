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

int main()
	{
		ios_base::sync_with_stdio(false); cin.tie(0);
		int T;
		cin >> T;
		rep(i,T){
			int s[3][3];
			rep(j,3){
				rep(k,3){
				cin >> s[j][k];
			}

			}

			int fl = 0;

			rep(j,3){
				rep(k,3){
					rep(m,3){
						if( j == k || k == m || j == m ) continue;
						int ft = 0;
						rep(r,3){
							// cout << j << " " << k << " " << s[j][r] << " " << s[k][r] << " " << r << endl;
							if( s[j][r] > s[k][r] ){ ft = 1; continue; }
							if( s[j][r] < s[k][r] ){ ft=0; break;}
						}

						// cout << endl;
						if( ft == 0 ) break;
						ft = 0;
						rep(r,3){
							// cout << k << " " << m << " " << s[k][r] << " " << s[m][r] << " " << r << endl;
							if( s[k][r] > s[m][r] ){ ft=1; continue; }
							if( s[k][r] < s[m][r] ){ ft=0; break;}
						}

						if( ft == 0 ) continue;
						// cout << "ya" << endl;

						fl = 1; break;
					}
					if( fl == 0 ) continue;
					break;
				}
				if( fl == 0 ) continue;
				break;
			}

			if( fl ){ cout << "yes" << endl; }
			else cout << "no" << endl;
		}		
		return 0 ;
	}

