#include <iostream>
#include <limits.h>
#define V 5
using namespace std;

int minKey(int key[],bool mstSet[]){
	int min=INT_MAX, min_index;	
	for(int i=0;i<V;i++){
		if(key[i]<min && mstSet[i]==false){
			min=key[i]; min_index=i;
		}
	}
	return min_index;
}
void printMST(int graph[V][V], int key[]){
	cout<<"EDGE"<<"    "<<"WEIGHT"<<endl;
	for(int i=1;i<V;i++){
		cout<< i << " "<<key[i]<<endl;
	}
}
int dijik(int graph[V][V]){
	int key[V];

	for(int i=0;i<V;i++){
		key[i] = INT_MAX;
	}

	key[0] = 0;

	for(int i=0;i<V-1;i++){
		for(int j=0;j<V;j++){
			for(int z=0;z<V;z++){

				if(graph[j][z]!=0 && (key[j]!=INT_MAX || key[z]!=INT_MAX) && key[z]>key[j]+graph[j][z]){
					key[z]=key[j]+graph[j][z];
				}
			}
				
		}
	}

	for(int j=0;j<V;j++){
			for(int z=0;z<V;z++){

				if(graph[j][z]!=0 && (key[j]!=INT_MAX || key[z]!=INT_MAX) && key[z]>key[j]+graph[j][z]){
					cout<<"sikik"<<endl<<j<<"  "<<z<<endl;
				}
			}
				
		}

	printMST(graph,key);
}
int main(){
	 int graph[V][V] = {{0, -1, 4, 0, 0},
                      {0, 0, 3, 2, 2},
                      {0, 0, 0, 0, 0},
                      {0, 1, 5, 0, 0},
                      {0, 0, 0, -4, 0},
                     };
	dijik(graph);
}