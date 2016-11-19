#include <iostream>
#include <limits.h>
using namespace std;
#define V 4

int minKey(int key[],bool mstKey[]){
	int min = INT_MAX;
	int min_index;
	for(int i=0;i<V;i++){
		if(mstKey[i] == false && key[i] < min){
			min = key[i];
			min_index = i;
		} 		
	}
	return min_index;
}

void printMST(int parent[], int key[]){
	for(int i=1;i<V;i++){
		cout<< parent[i] <<"   " << i << "   " << key[i] << endl;
	}
}

void prim(int graph[V][V]){
	int key[V];
	int parent[V];
	bool mstKey[V];

	for(int i=0;i<V;i++){
		key[i] = INT_MAX;
		mstKey[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;
	
	for(int i=0;i<V-1;i++){
		int u = minKey(key,mstKey);
		mstKey[u] = true;
	
		for(int j=0;j<V;j++){
			if(graph[u][j] && mstKey[j] == false && graph[u][j] < key[j] ){
				key[j] = graph[u][j];
				parent[j] = u; 
			}
		}		
	}

	printMST(parent,key);
}

int main(){
	int graph[V][V]={{0,2,7,0},
			 {2,0,4,0},
			 {7,4,0,5},
			 {0,0,5,0}};
	prim(graph);
}
