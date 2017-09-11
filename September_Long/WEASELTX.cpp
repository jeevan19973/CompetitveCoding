#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define mod 1000000007
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
        ll n,Q;
        scanf("%lld%lld",&n,&Q);
        vector<int> v[n];
        for(int i=0;i<n-1;i++){
                ll t1,t2;
                scanf("%lld%lld",&t1,&t2);
                v[t1].pb(t2);
                v[t2].pb(t1);
        }
        ll a[n];
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        queue< pair<ll,ll> > q,q2;
        q.push(mp(0,1));
        bool b[n];
        memset(b,false,sizeof(b));
        b[0]=true;
        ll m=0;
        while(!q.empty()){
                pair<ll,ll> p=q.front();
                q.pop();
                q2.push(p);
                m=max(m,p.second);
                for(int i=0;i<v[p.first].size();i++){
                        if(!b[v[p.first][i]]){
                                b[v[p.first][i]]=true;
                                q.push(mp(v[p.first][i],p.second+1));
                        }
                }
        }
        ll x[m+1];
        ll rx[m+1];
        memset(x,0,sizeof(x));
        while(!q2.empty()){
                pair<ll,ll> p=q2.front();
                q2.pop();
                x[p.second]^=a[p.first];
                // cout << p.second << " " << p.first << endl;
        }

        rep(i,m+1){
            if(!i) continue;
            rx[i] = x[m+1-i];
        }


        int mday = 0;
        while(pow(2,mday) < m ){
            mday++;
        }

        ll arsiz = pow(2,mday);

        ll quer[Q];
        int qmax = 0;
        rep(i,Q){
            ll d;
            scanf("%lld",&d);
            // cout << d << " here " << endl;
            d %= arsiz;
            if( d > qmax ) qmax = d;
            quer[i] = d;
        }

        ll dp[2][qmax+1];
        rep(i,2){
            rep(j,qmax+1){
                dp[i][j] = 0;
            }
        }

        int cur = 1;
        rep(i,qmax+1){
                    dp[cur%2][i] = rx[cur];
                }
        cur++;
        int common = 2;
        int po = 1;     
        while( cur <= m ){
                // cout << cur << endl;
                int p = cur%2;
                int cm = common;
                if( cur == pow(2,po-1) + 1 ){ cm /= 2; }
                rep(i,common+1){
                    if( i == 0 ) dp[p][0] = rx[cur];
                    else{       
                        dp[p][i] = dp[p][i-1];
                        int parent = i % cm;
                        dp[p][i] ^= dp[p^1][parent];
                    }
                    // cout << dp[cur%2][i] << " ";
                }
                // cout << endl;
            
            if( pow(2,po) == cur ){ common *= 2; 
                                    po++;
                                    }
            cur++;
        }

        cur = m;
        cur %= 2;

        rep(i,Q){
        ll d = quer[i];
        cout << dp[cur][d] << endl;
       }


        return 0 ;
    }

