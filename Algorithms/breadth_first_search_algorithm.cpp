#include<iostream>
#include <list>
#include <queue>
#define V 7
using namespace std;

void BFST(int bas, int graph[V][V])
{
	static int counter=0;
	int visited[V];
	int traverse[V];

	for(int i=0; i<V; i++)
	{
		visited[i] = 0;
		traverse[i] = -1;
	}

	queue<int> q;
	q.push(bas);
	visited[bas] = 2;
	
	while(!q.empty()){

		int i = q.front();	
		traverse[counter++] = q.front();
		q.pop();

		for(int j = 0; j<V; j++){
			if(graph[i][j] && visited[j] == 0)
			{	
				q.push(j);
				visited[j] = 2;
			}
		}

	}

	for(int i=0; i<V; i++)
	{	
		cout<<traverse[i]<<endl;
	}
}


int main(){
	int graph[V][V]={{0,0},
			{1,0}};
					


    BFST(0,graph);

    return 0;
}
