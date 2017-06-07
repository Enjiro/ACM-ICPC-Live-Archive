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

const int MN=100+7;
//p, l, r, dif
int n;
ll dp[MN][MN][MN][2];
bool memo[MN][MN][MN][2];
ll ans[MN];

ll solve(int i, int l, int r, int k)
{
	if(i>n)
		return 0;
	int b=l+r;
	int s=n-2*b;
	if(i==n)
		return (l==r && b>=s);
	if(memo[i][l][r][k])
		return dp[i][l][r][k];
	ll &ret=dp[i][l][r][k]=0;

	if(k)
	{
		ret+=solve(i+1, l, r, k^1);
		ret+=solve(i+2, l+1, r, k^1);
	}
	else
	{
		ret+=solve(i+1, l, r, k^1);
		ret+=solve(i+2, l, r+1, k^1);
	}
	memo[i][l][r][k]=true;
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
	for(int i=2; i<=100; i++)
	{
		n=i;
		SET(memo, false);
		ans[i]=solve(0, 0, 0, 1);
	}

	int tt;
	rd(tt);
	while(tt--)
	{
		int t, x;
		rd(t), rd(x);
		printf("%d %lld\n", t, ans[x]);
	}

	return 0;
}