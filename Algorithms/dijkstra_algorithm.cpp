#include <iostream>
#include <limits.h>
#define V 4
using namespace std;

int minKey(int key[],bool mstSet[]){
	int min=INT_MAX, min_index;	
	for(int i=0;i<V;i++){
		if(key[i]<min && mstSet[i]==false){
			min=key[i]; 
			min_index=i;
		}
	}
	return min_index;
}
void printMST(int parent[],int graph[V][V], int key[]){
	cout<<"EDGE"<<"    "<<"WEIGHT"<<endl;
	for(int i=1;i<V;i++){
		cout<<"0" << " " << i << " "<<key[i]<<endl;
	}
}
void dijik(int graph[V][V]){
	int key[V];
	int parent[V];
	bool mstSet[V];

	for(int i=0;i<V;i++){
		key[i] = INT_MAX;
		mstSet[i] = false;
	}

	parent[0] = -1;
	key[0] = 0;

	for(int i=0;i<V-1;i++){
		int u = minKey(key,mstSet);
		mstSet[u] = true;
		
		for(int j=0;j<V;j++)
			if(graph[u][j] && mstSet[j] != true && key[j] > graph[u][j] + key[u]){
				parent[j]=u;
				key[j]=graph[u][j]+ key[u];
			}
	}
	printMST(parent,graph,key);
}
int main(){
	int graph[V][V]={{0,2,7,0},
			 {2,0,4,0},
			 {7,4,0,5},
			 {0,0,5,0}};
	dijik(graph);
}
