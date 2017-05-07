/*
 * Disjoint Paths problem sample solution by Andy Lutomirski
 *
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

void solve()
{
  static int caseno = 0;
  int N, M;
  {
    string line;
    getline(cin, line);
    istringstream ss(line);
    ss >> N >> M;
  }
  assert(!!cin);
  if (N == 0 && M == 0)
    exit(0);
  int V = M*2;
  VVI caps(V, VI(V, 0));
  VVI flow(caps);
  for(int i = 0; i < M; i++)
    {
      caps[2*i][2*i+1] = 1;
      string line;
      getline(cin, line);
      istringstream ss(line);
      while(true)
	{
	  int j;
	  ss >> j;
	  if (!ss)
	    break;
	  j--;
	  caps[2*i+1][2*j] = 1;
	}
    }

  cout << "Case " << ++caseno << ":\n";

  VI vis(V), dad(V), dist(V);
  for(int f = 0; f < N; f++)
    {
      fill(vis.begin(), vis.end(), 0);
      fill(dist.begin(), dist.end(), 100000);
      int i = 1;
      dad[i] = -1;
      dist[i] = 0;
      while(i != 2)
	{
	  int next = -1;
	  vis[i] = 1;
	  for(int j = 0; j < V; j++)
	    {
	      if (caps[i][j] > flow[i][j]) {
		if (dist[j] > dist[i] + 1) {
		  dist[j] = dist[i] + 1;
		  dad[j] = i;
		}
	      }
	      if (!vis[j] && dist[j] < 100000 && (next == -1 || dist[j] < dist[next]))
		next = j;
	    }
	  if (next == -1) {
	    cout << "Impossible\n\n";
	    return;
	  }
	  i = next;
	}

      while(dad[i] != -1)
	{
	  flow[dad[i]][i]++;
	  flow[i][dad[i]]--;
	  i = dad[i];
	}
    }

  for(int i = 0; i < V; i++) {
    if (flow[1][i] == 1) {
      cout << "1 " << i/2+1;
      int here = i;
      while(here != 2)
	{
	  for(int j = 0; j < V; j++)
	    if (flow[here][j] == 1) {
	      if (j % 2 == 0)
		cout << ' ' << j/2+1;
	      here = j;
	      break;
	    }
	}
      cout << endl;
    }
  }

  cout << endl;
}

int main()
{
  while(true)
    solve();
}
