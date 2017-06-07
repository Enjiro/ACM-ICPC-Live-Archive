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

const int MN=1e+6+35;
int n;

bool vis[MN];
vector<int>g[MN];
int data[MN];

int lp[MN];
vector<ll>pr;

inline void addEdge(int u, int v)
{
	g[u].pb(v);
	g[v].pb(u);
}
inline void raddEdge(int u, int v)
{
	g[u].clear();
	g[v].clear();
	vis[u]=vis[v]=false;
}

inline void sieve(int N)
{
	for(ll i=2; i<=N; i++)
	{
		if(!lp[i])
		{
			lp[i]=i;
			pr.pb(i);
		}
		for(ll j=0; j<SZ(pr) && pr[j]<=lp[i] && i*pr[j]<=N; j++)
		{
			lp[i*pr[j]]=pr[j];
		}
	}
}

inline void dfs(int x)
{
	vis[x]=true;
	for(int y:g[x])
		if(!vis[y])
			dfs(y);
}

inline void solve()
{
	int ans=0;
	for(int i=0; i<n; i++)
	{
		if(data[i]==1)
		{
			ans++;
			continue;
		}
		if(!vis[ data[i] ])
		{
			ans++;
			dfs(data[i]);
		}
	}
	printf("%d\n", ans);
}

inline void process(int x)
{
	int y=x;
	addEdge(x, y);
	while(x>1)
	{
		addEdge(y, lp[x]);
		x/=lp[x];
	}
}

inline void rprocess(int x)
{
	int y=x;
	raddEdge(x, y);
	while(x>1)
	{
		raddEdge(y, lp[x]);
		x/=lp[x];
	}
}

inline void cleardata()
{
	for(int i=0; i<n; i++)
		rprocess(data[i]);
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

	sieve(1e+6);
	int tt;
	rd(tt);
	for(int t=1; t<=tt; t++)
	{
		rd(n);
		for(int i=0; i<n; i++)
		{
			rd(data[i]);
			process(data[i]);
		}
		printf("Case %d: ", t);
		solve();
		cleardata();
	}
	return 0;
}