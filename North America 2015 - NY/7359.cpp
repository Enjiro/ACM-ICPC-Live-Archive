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

const int MN=20000+35;
ll s[MN][3];

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

	for(ll i=1; i<MN; i++)
	{
		s[i][0]=s[i-1][0]+(i%2==0)*i;
		s[i][1]=s[i-1][1]+(i%2==1)*i;
		s[i][2]=s[i-1][2]+i;
	}

	int tt;
	rd(tt);
	while(tt--)
	{
		int t, n;
		rd(t), rd(n);
		printf("%d %lld %lld %lld\n", t, s[n][2], s[2*n][1], s[2*n][0]);
	}
	return 0;
}