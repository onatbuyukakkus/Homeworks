#include<iostream>
#include <list>
#define V 6

using namespace std;
void DFSvisit(int v, int graph[V][V], int visited[], int traverse[])
{
	static int counter=0;
	visited[v] = 2;

	for (int j=0; j<V; j++)
	{
		if(graph[v][j] && visited[j]==0)
			{
			DFSvisit(j,graph,visited,traverse);
			}	
	}

	traverse[counter++]=v;
	visited[v] = 2;
}


void DFS(int bas, int graph[V][V])
{
	int traverse[V];
	int visited[V];

	for(int i=0; i<V; i++)
	{
		visited[i] = 0;
		traverse[i] = -1;	
	}

	for(int k=bas; ; k++)
	{
		k = k % V;
		if(visited[k] == 0)
			DFSvisit(k,graph,visited,traverse);
		if (k == bas-1)
			break;
	}

	for(int i=0;i<V;i++)
	{
		cout<<traverse[i]<<endl;
	}
}

int main()
{
	int graph[V][V]={{0,0,7,0,0,0},
		 { 2,0,0,0,0,0},
		 {0,0,0,5,4,0},
		 {0,0,0,0,0,0},
		{0,0,0,0,0,5},
		{0,0,0,0,0,0}};

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    DFS(4,graph);

    return 0;
}

