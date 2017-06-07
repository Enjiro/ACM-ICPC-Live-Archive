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

const ll MOD=1e+9;
class matrix
{
	const static int N=2;
public:
	ll v[N][N];
	matrix(){};
	matrix(ll _v[])
	{
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				v[i][j]=(i+1==j);
		for(int i=0; i<N; i++)
			v[N-1][i]=_v[i];
	}
	matrix operator *(const matrix &foo)
	{
		matrix ret;
		SET(ret.v, 0);
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				for(int k=0; k<N; k++)
				{
					ret.v[i][j]+=(v[i][k]*foo.v[k][j]);
				}
				ret.v[i][j]%=MOD;
			}
		}
		return ret;
	}
	matrix pow(matrix b, ll m)
	{
		if(m==1)
			return b;
		if(m&1)
			return b*pow(b, m-1);
		matrix ret=pow(b, m>>1);
		return ret*ret;
	}
};

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

ll b[2]={1, 1};
ll fib(ll x)
{
	if(x<=2)
		return b[x-1];
	matrix aux=matrix().pow(matrix(b), x-1);
	ll ret=0;
	for(int i=0; i<2; i++)
		ret=(ret+(b[i]*aux.v[0][i])%MOD)%MOD;
	return ret;
}

int main()
{
	#ifdef LOCAL_PROJECT
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#else
	#endif

	int tt;
	rd(tt);
	while(tt--)
	{
		int t;
		ll x;
		rd(t), rd(x);
		printf("%d %lld\n", t, fib(x));
	}

	return 0;
}