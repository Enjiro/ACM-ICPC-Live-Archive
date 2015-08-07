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

#define MAXN 2550

int n, m;
vector<int>graph[MAXN];
vector<int>start;
bool vis[MAXN];
bool cycle;
char mat[55][55];

int convert(int i, int j)
{
	return (i*m)+j;
}
bool valid(int i, int j, int x, int y)
{
	return i+x>=0 && i+x<n && j+y>=0 && j+y<m;
}
int mx[]={0, 1, 0, -1};
int my[]={-1, 0, 1, 0};

int moves(string x)
{
	stringstream ss;
	int ans;
	ss << x;
	ss >> hex >> ans;
	return ans;
}

bool check()
{
	int t=convert(n-1,m);
	for(int i=0; i<t; i++)
		if(!vis[i])
			return false;
	return true;
}

void dfs(int x, int p)
{
	vis[x]=true;
	for(int i=0; i<graph[x].size(); i++)
	{
		int v=graph[x][i];
		if(!vis[v])
			dfs(v, x);
		else if(v!=p)
			cycle=true;
	}
}

void make_graph()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			char ch=mat[i][j];
			string st;
			st+=ch;
			bitset<4>pos(moves(st));
			for(int k=0; k<4; k++)
			{
				if(pos[k]==0)
				{
					int x=mx[k];
					int y=my[k];
					int v=convert(i,j);
					int u=convert(i+x, j+y);
					if( valid(i, j, x, y) )
					{
						graph[v].pb(u);
					}
					else
						start.pb(v);
				}
			}
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d %d", &n, &m) && n)
	{
		int t=convert(n-1,m);
		for(int i=0; i<t; i++)
			graph[i].clear();

		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf(" %c", &mat[i][j]);

		start.clear();
		make_graph();
		memset(vis, false, sizeof vis);
		cycle=false;
		dfs(start[0], start[0]);

		if(!vis[ start[1] ])
			printf("NO SOLUTION\n");
		else if( !check() )
			printf("UNREACHABLE CELL\n");
		else if(cycle)
			printf("MULTIPLE PATHS\n");
		else
			printf("MAZE OK\n");
	}
	return 0;
}