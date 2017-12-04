#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fill(a) memset(a,0,sizeof(a))
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		double s;
		cout << setprecision(10) << fixed;
		cin >> n >> s;
		if(n==1 && s!=0){
			cout << -1 << endl;
			continue;
		}
		else if(n==1 && s==0){
			cout << 0 << endl;
			continue;
		}
		if(n%2==0){
			int p=n/2;
			while(p--){
				cout << s << " ";
			}
			p=n/2;
			while(p--){
				cout << -s << " ";
			}
		}
		else {
			cout << 0 << " ";
			int p=(n-1)/2;
			double b=n;
			double x=s*sqrt(b/(b-1));
			while(p--){
				cout << x <<" ";
			}
			p=(n-1)/2;
			while(p--){
				cout << -x <<" ";
			}
		}
		cout << endl;
	}	
}
