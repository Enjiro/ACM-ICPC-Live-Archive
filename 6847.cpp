#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll x, y;
	while(scanf("%llu %llu", &x, &y))
	{
		if(x==0 && y==0)
			break;
		ll ans = y/5 - x/5 +1;
		printf("%llu\n", ans);
	}
	return 0;
}