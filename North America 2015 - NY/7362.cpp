/// David Mateus Batista <david.batista3010@gmail.com>
/// Computer Science - Federal University of Itajuba - Brazil

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define DINF (double)1e+30
#define EPS (double)1e-9
#define PI (double)acos(-1.0)
#define RAD(x) (double)(x*PI)/180.0
#define PCT(x,y) (double)x*100.0/y

#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second

#define D(x) x&(-x)
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define SET(a,b) memset(a, b, sizeof(a))

#define gcd(x,y) __gcd(x, y)
#define lcm(x,y) (x/gcd(x,y))*y

#define bitcnt(x) __builtin_popcountll(x)
#define lbit(x) 63-__builtin_clzll(x)
#define zerosbitll(x) __builtin_ctzll(x)
#define zerosbit(x) __builtin_ctz(x)

enum {North, East, South, West};
//{0, 1, 2, 3}
//{Up, Right, Down, Left}

int mi[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int mj[] = {0, 1, 0, -1, 1, 1, -1, -1};

const int MN=10000+35;
ll dp[MN];

long long lp[MN+1];
vector<long long>pr;

void sieve()
{
	for(long long i=2; i<=MN; i++)
	{
		if(lp[i]==0)
		{
			lp[i]=i;
			pr.push_back(i);
		}
		for(long long j=0; j<pr.size() && pr[j]<=lp[i] && i*pr[j]<=MN; j++)
			lp[i*pr[j]]=pr[j];
	}
}

ll phi(ll x)
{
	ll ret=x;
	while(x>1)
	{
		ll y=lp[x];
		while(x%y==0)
			x/=y;
		ret-=ret/y;
	}
	if(x>1)
		ret-=ret/x;
	return ret;
}

template<class num>inline void rd(num &x)
{
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c))
		neg=(c=='-'), x=0;
	else
		x=c-'0';
	while(isdigit(c=getchar()))
		x=(x<<3)+(x<<1)+c-'0';
	if(neg)
		x=-x;
}

int main()
{
	#ifdef LOCAL_PROJECT
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#else
	#endif
	sieve();
	dp[1]=2;
	for(int i=2; i<MN; i++)
		dp[i]=dp[i-1]+phi((ll)i);

	int tt;
	rd(tt);
	while(tt--)
	{
		int t, x;
		rd(t), rd(x);
		printf("%d %lld\n", t, dp[x]);
	}
	return 0;
}