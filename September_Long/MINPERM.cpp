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

void even( int ar[], int j ){
	while( j > 0 ){
		ar[j] = j-1;
		ar[j-1] = j;
		j -= 2;
	}

	return;
}


int main()
	{
		ios_base::sync_with_stdio(false); cin.tie(0);
		int T;
		cin >> T;
		rep(i,T){
			int N;
			cin >> N;
			int ar[N];
			memset(ar,0,sizeof(ar));
			int j = N-1;			
			if( N % 2 != 0 ){
				ar[j] = j-2;
				ar[j-1] = j;
				ar[j-2] = j-1;
				j -= 3;
			}

			even(ar,j);

			rep(k,N){
				cout << ar[k] + 1 << " ";
			}
			cout << endl;
		}		
		return 0 ;
	}

