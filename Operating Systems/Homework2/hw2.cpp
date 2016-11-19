#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


using namespace std;

enum DIRECTION {WEST, SOUTH, EAST, NORTH};//Directions of the crossroad

#include "writeOutput.h"//Outputs of the simulation

vector <vector <int> > intersectionBusy;
vector <vector <pthread_cond_t> > cvList;
vector <vector <pthread_mutex_t> > mutexList;
vector <pthread_mutex_t> nightModeMutex;
vector <vector <int> > nightModeIntersectionBusy; // WS - WE - WN * SW - SE - SN * EW - ES - EN * NW - NS - NE *
int carCount=0;
pthread_mutex_t carCountMutex;

class CrossRoad//Class for the crossroad
{
	private:
		int N;// It is the number of intersections.
		int *lightState;// Its value is the direction of the green light on the intersection, -1 in the night mode. Its size is N.
	public:
		CrossRoad(int _N,int _mode);//Constructor
		void Enter(int vehicleCode, int intersectionCode, DIRECTION From,DIRECTION To, pthread_cond_t carCond);//Vehicles call this function for entering the intersection
		void Exit(int vehicleCode, int intersectionCode, DIRECTION From,DIRECTION To);//Vehicles call this function for exiting the intersection
		void SetGreenLight(int intersectionCode);//Call this function for turning green traffic lights on in the given intersection
};

typedef struct {
	int carID;
	int arriveDuration;
	int passingDuration;
	vector < vector <string> > turns;
	pthread_cond_t myCV;
	CrossRoad* cr;
} carStruct;

typedef struct//Struct for the intersections in the day mode
{
	int intersectionCode;//Id of the intersection
	int duration;//Duration of the green light in the day mode
	CrossRoad *crossroad;//CrossRoad class object of the intersection
} intersectionData;

typedef struct//Struct for the intersections in the day mode
{
	int carID;
	DIRECTION from;
	DIRECTION to;
	pthread_cond_t cond;
} waitingCar;

vector <vector <waitingCar*> > nightModeQueue;

void *trafficLight(void *data)//Traffic light thread
{
	intersectionData *iData=(intersectionData *)data;//Getting intersection data

	while(true)
	{
		usleep(iData->duration*1000);//Waiting until the green light on the next direction turns on
		(iData->crossroad)->SetGreenLight(iData->intersectionCode);//Turning next green light on the next direction on
	}
}

CrossRoad::CrossRoad(int _N,int _mode) {
	N = _N;
	if(_mode == 1) {
		lightState = new int[N];
		for(int i=0; i<N; i++) {
			lightState[i]=-1;
		}
	}
	else {
		lightState = new int[N];
		for(int i=0; i<N; i++) {
			lightState[i]=0;
		}
	}
}

void CrossRoad::Enter(int vehicleCode, int intersectionCode, DIRECTION From,DIRECTION To, pthread_cond_t carCond) {
	if(lightState[intersectionCode-1]!=-1) {
		pthread_mutex_lock(&mutexList[intersectionCode-1][0]);
		int busySum=0;
		//pthread_mutex_lock(&mutexList[intersectionCode-1][1]);
		for(int i=0; i<intersectionBusy[intersectionCode-1].size(); i++) {
			busySum += intersectionBusy[intersectionCode-1][i];
		}
		//pthread_mutex_unlock(&mutexList[intersectionCode-1][1]);

		if(From == WEST) {
			//pthread_mutex_lock(&mutexList[intersectionCode-1][1]);
			busySum-=intersectionBusy[intersectionCode-1][0];
			if(lightState[intersectionCode-1] != 0 || busySum != 0) {
				pthread_cond_wait(&cvList[intersectionCode-1][0], &mutexList[intersectionCode-1][0]);
			}
			intersectionBusy[intersectionCode-1][0]++;
			writeOutput(1, vehicleCode, intersectionCode, From, To);
			//pthread_mutex_unlock(&mutexList[intersectionCode-1][1]);
		}
		if(From == SOUTH) {
			//pthread_mutex_lock(&mutexList[intersectionCode-1][1]);f
			busySum-=intersectionBusy[intersectionCode-1][1];
			if(lightState[intersectionCode-1] != 1 || busySum != 0) {
				pthread_cond_wait(&cvList[intersectionCode-1][1], &mutexList[intersectionCode-1][0]);
			}
			intersectionBusy[intersectionCode-1][1]++;
			writeOutput(1, vehicleCode, intersectionCode, From, To);
			//pthread_mutex_unlock(&mutexList[intersectionCode-1][1]);
		}
		if(From == EAST) {
			//pthread_mutex_lock(&mutexList[intersectionCode-1][1]);
			busySum-=intersectionBusy[intersectionCode-1][2];
			if(lightState[intersectionCode-1] != 2 || busySum != 0) {
				pthread_cond_wait(&cvList[intersectionCode-1][2], &mutexList[intersectionCode-1][0]);
			}
			intersectionBusy[intersectionCode-1][2]++;
			writeOutput(1, vehicleCode, intersectionCode, From, To);
			//pthread_mutex_unlock(&mutexList[intersectionCode-1][1]);

		}
		if(From == NORTH) {
			//pthread_mutex_lock(&mutexList[intersectionCode-1][1]);
			busySum-=intersectionBusy[intersectionCode-1][3];
			if(lightState[intersectionCode-1] != 3 || busySum != 0) {
				pthread_cond_wait(&cvList[intersectionCode-1][3], &mutexList[intersectionCode-1][0]);
			}
			intersectionBusy[intersectionCode-1][3]++;
			writeOutput(1, vehicleCode, intersectionCode, From, To);
			//pthread_mutex_unlock(&mutexList[intersectionCode-1][1]);
		}
		pthread_mutex_unlock(&mutexList[intersectionCode-1][0]);
	}
	else { //night-mode
		pthread_mutex_lock(&nightModeMutex[intersectionCode-1]);
		if(From == WEST && To == SOUTH) {
			if(nightModeIntersectionBusy[intersectionCode-1][10] != 0 || nightModeIntersectionBusy[intersectionCode-1][7] != 0 || nightModeIntersectionBusy[intersectionCode-1][11] != 0) {
				waitingCar* wCar = new waitingCar; //struct olustur.
				wCar->carID=vehicleCode;
				wCar->from=From;
				wCar->to=To;
				wCar->cond=carCond;

				nightModeQueue[intersectionCode-1].push_back(wCar); //que'ya ekle.
				pthread_cond_wait(&wCar->cond, &nightModeMutex[intersectionCode-1]); //wait				
			}
			else {
				nightModeIntersectionBusy[intersectionCode-1][0]++; //nightmodeintersectionbusy WS yi bir arttır
			}
			writeOutput(1, vehicleCode, intersectionCode, From, To);
		}
		if(From == SOUTH && To == EAST) {
			if(nightModeIntersectionBusy[intersectionCode-1][11] != 0 || nightModeIntersectionBusy[intersectionCode-1][1] != 0 || nightModeIntersectionBusy[intersectionCode-1][2] != 0) {
				waitingCar* wCar = new waitingCar; //struct olustur.
				wCar->carID=vehicleCode;
				wCar->from=From;
				wCar->to=To;
				wCar->cond=carCond;

				nightModeQueue[intersectionCode-1].push_back(wCar); //que'ya ekle.
				pthread_cond_wait(&wCar->cond, &nightModeMutex[intersectionCode-1]); //wait				
			}
			else {
				nightModeIntersectionBusy[intersectionCode-1][4]++; //nightmodeintersectionbusy WS yi bir arttır
			}//que'dan cikart ya da exitte uyandirinca cikart
			writeOutput(1, vehicleCode, intersectionCode, From, To);
		}
		if(From == NORTH && To == WEST) {
			if(nightModeIntersectionBusy[intersectionCode-1][6] != 0 || nightModeIntersectionBusy[intersectionCode-1][3] != 0 || nightModeIntersectionBusy[intersectionCode-1][7] != 0) {
				waitingCar* wCar = new waitingCar; //struct olustur.
				wCar->carID=vehicleCode;
				wCar->from=From;
				wCar->to=To;
				wCar->cond=carCond;

				nightModeQueue[intersectionCode-1].push_back(wCar); //que'ya ekle.
				pthread_cond_wait(&wCar->cond, &nightModeMutex[intersectionCode-1]); //wait				
			}
			else {
				nightModeIntersectionBusy[intersectionCode-1][9]++; //nightmodeintersectionbusy WS yi bir arttır
			}//que'dan cikart ya da exitte uyandirinca cikart
			writeOutput(1, vehicleCode, intersectionCode, From, To);
		}
		if(From == EAST && To == NORTH) {
			if(nightModeIntersectionBusy[intersectionCode-1][5] != 0 || nightModeIntersectionBusy[intersectionCode-1][2] != 0 || nightModeIntersectionBusy[intersectionCode-1][3] != 0) {
				waitingCar* wCar = new waitingCar; //struct olustur.
				wCar->carID=vehicleCode;
				wCar->from=From;
				wCar->to=To;
				wCar->cond=carCond;

				nightModeQueue[intersectionCode-1].push_back(wCar); //que'ya ekle.
				pthread_cond_wait(&wCar->cond, &nightModeMutex[intersectionCode-1]); //wait				
			}
			else {
				nightModeIntersectionBusy[intersectionCode-1][8]++; //nightmodeintersectionbusy WS yi bir arttır
			}//que'dan cikart ya da exitte uyandirinca cikart
			writeOutput(1, vehicleCode, intersectionCode, From, To);
		}
		if(From == SOUTH && To == NORTH) {
			if(nightModeIntersectionBusy[intersectionCode-1][8] != 0 || nightModeIntersectionBusy[intersectionCode-1][6] != 0 || nightModeIntersectionBusy[intersectionCode-1][7] != 0
				|| nightModeIntersectionBusy[intersectionCode-1][11] != 0 || nightModeIntersectionBusy[intersectionCode-1][2] != 0 || nightModeIntersectionBusy[intersectionCode-1][1] != 0) {
				waitingCar* wCar = new waitingCar; //struct olustur.
				wCar->carID=vehicleCode;
				wCar->from=From;
				wCar->to=To;
				wCar->cond=carCond;

				nightModeQueue[intersectionCode-1].push_back(wCar); //que'ya ekle.
				pthread_cond_wait(&wCar->cond, &nightModeMutex[intersectionCode-1]); //wait				
			}
			else {
				nightModeIntersectionBusy[intersectionCode-1][5]++; //nightmodeintersectionbusy WS yi bir arttır
			}//que'dan cikart ya da exitte uyandirinca cikart
			writeOutput(1, vehicleCode, intersectionCode, From, To);
		}
		if(From == NORTH && To == SOUTH) {
			if(nightModeIntersectionBusy[intersectionCode-1][6] != 0 || nightModeIntersectionBusy[intersectionCode-1][1] != 0 || nightModeIntersectionBusy[intersectionCode-1][7] != 0
				|| nightModeIntersectionBusy[intersectionCode-1][0] != 0 || nightModeIntersectionBusy[intersectionCode-1][3] != 0 || nightModeIntersectionBusy[intersectionCode-1][2] != 0) {
				waitingCar* wCar = new waitingCar; //struct olustur.
				wCar->carID=vehicleCode;
				wCar->from=From;
				wCar->to=To;
				wCar->cond=carCond;

				nightModeQueue[intersectionCode-1].push_back(wCar); //que'ya ekle.
				pthread_cond_wait(&wCar->cond, &nightModeMutex[intersectionCode-1]); //wait				
			}
			else {
				nightModeIntersectionBusy[intersectionCode-1][10]++; //nightmodeintersectionbusy WS yi bir arttır
			}//que'dan cikart ya da exitte uyandirinca cikart
			writeOutput(1, vehicleCode, intersectionCode, From, To);
		}
		if(From == WEST && To == EAST) {
			if(nightModeIntersectionBusy[intersectionCode-1][10] != 0 || nightModeIntersectionBusy[intersectionCode-1][5] != 0 || nightModeIntersectionBusy[intersectionCode-1][4] != 0
				|| nightModeIntersectionBusy[intersectionCode-1][11] != 0 || nightModeIntersectionBusy[intersectionCode-1][3] != 0 || nightModeIntersectionBusy[intersectionCode-1][7] != 0) {
				waitingCar* wCar = new waitingCar; //struct olustur.
				wCar->carID=vehicleCode;
				wCar->from=From;
				wCar->to=To;
				wCar->cond=carCond;

				nightModeQueue[intersectionCode-1].push_back(wCar); //que'ya ekle.
				pthread_cond_wait(&wCar->cond, &nightModeMutex[intersectionCode-1]); //wait				
			}
			else {
				nightModeIntersectionBusy[intersectionCode-1][1]++; //nightmodeintersectionbusy WS yi bir arttır
			}//que'dan cikart ya da exitte uyandirinca cikart
			writeOutput(1, vehicleCode, intersectionCode, From, To);
		}
		if(From == EAST && To == WEST) {
			if(nightModeIntersectionBusy[intersectionCode-1][10] != 0 || nightModeIntersectionBusy[intersectionCode-1][5] != 0 || nightModeIntersectionBusy[intersectionCode-1][3] != 0
				|| nightModeIntersectionBusy[intersectionCode-1][9] != 0 || nightModeIntersectionBusy[intersectionCode-1][11] != 0 || nightModeIntersectionBusy[intersectionCode-1][2] != 0) {
				waitingCar* wCar = new waitingCar; //struct olustur.
				wCar->carID=vehicleCode;
				wCar->from=From;
				wCar->to=To;
				wCar->cond=carCond;

				nightModeQueue[intersectionCode-1].push_back(wCar); //que'ya ekle.
				pthread_cond_wait(&wCar->cond, &nightModeMutex[intersectionCode-1]); //wait				
			}
			else {
				nightModeIntersectionBusy[intersectionCode-1][6]++; //nightmodeintersectionbusy WS yi bir arttır
			}//que'dan cikart ya da exitte uyandirinca cikart
			writeOutput(1, vehicleCode, intersectionCode, From, To);
		}
		if(From == SOUTH && To == WEST) {
			if(nightModeIntersectionBusy[intersectionCode-1][2] != 0 || nightModeIntersectionBusy[intersectionCode-1][1] != 0 || nightModeIntersectionBusy[intersectionCode-1][9] != 0
				|| nightModeIntersectionBusy[intersectionCode-1][10] != 0 || nightModeIntersectionBusy[intersectionCode-1][11] != 0 || nightModeIntersectionBusy[intersectionCode-1][6] != 0 
				|| nightModeIntersectionBusy[intersectionCode-1][7] != 0) {
				waitingCar* wCar = new waitingCar; //struct olustur.
				wCar->carID=vehicleCode;
				wCar->from=From;
				wCar->to=To;
				wCar->cond=carCond;

				nightModeQueue[intersectionCode-1].push_back(wCar); //que'ya ekle.
				pthread_cond_wait(&wCar->cond, &nightModeMutex[intersectionCode-1]); //wait				
			}
			else {
				nightModeIntersectionBusy[intersectionCode-1][3]++; //nightmodeintersectionbusy WS yi bir arttır
			}//que'dan cikart ya da exitte uyandirinca cikart
			writeOutput(1, vehicleCode, intersectionCode, From, To);
		}
		if(From == WEST && To == NORTH) {
			if(nightModeIntersectionBusy[intersectionCode-1][3] != 0 || nightModeIntersectionBusy[intersectionCode-1][5] != 0
				|| nightModeIntersectionBusy[intersectionCode-1][10] != 0 || nightModeIntersectionBusy[intersectionCode-1][11] != 0 || nightModeIntersectionBusy[intersectionCode-1][6] != 0 
				|| nightModeIntersectionBusy[intersectionCode-1][7] != 0 || nightModeIntersectionBusy[intersectionCode-1][8] != 0) {
				waitingCar* wCar = new waitingCar; //struct olustur.
				wCar->carID=vehicleCode;
				wCar->from=From;
				wCar->to=To;
				wCar->cond=carCond;

				nightModeQueue[intersectionCode-1].push_back(wCar); //que'ya ekle.
				pthread_cond_wait(&wCar->cond, &nightModeMutex[intersectionCode-1]); //wait				
			}
			else {
				nightModeIntersectionBusy[intersectionCode-1][2]++; //nightmodeintersectionbusy WS yi bir arttır
			}//que'dan cikart ya da exitte uyandirinca cikart
			writeOutput(1, vehicleCode, intersectionCode, From, To);
		}
		if(From == NORTH && To == EAST) {
			if(nightModeIntersectionBusy[intersectionCode-1][1] != 0 || nightModeIntersectionBusy[intersectionCode-1][2] != 0
				|| nightModeIntersectionBusy[intersectionCode-1][3] != 0 || nightModeIntersectionBusy[intersectionCode-1][4] != 0 || nightModeIntersectionBusy[intersectionCode-1][5] != 0 
				|| nightModeIntersectionBusy[intersectionCode-1][6] != 0 || nightModeIntersectionBusy[intersectionCode-1][7] != 0) {
				waitingCar* wCar = new waitingCar; //struct olustur.
				wCar->carID=vehicleCode;
				wCar->from=From;
				wCar->to=To;
				wCar->cond=carCond;

				nightModeQueue[intersectionCode-1].push_back(wCar); //que'ya ekle.
				pthread_cond_wait(&wCar->cond, &nightModeMutex[intersectionCode-1]); //wait				
			}
			else {
				nightModeIntersectionBusy[intersectionCode-1][11]++; //nightmodeintersectionbusy WS yi bir arttır
			}//que'dan cikart ya da exitte uyandirinca cikart
			writeOutput(1, vehicleCode, intersectionCode, From, To);
		}
		if(From == EAST && To == SOUTH) {
			if(nightModeIntersectionBusy[intersectionCode-1][0] != 0 || nightModeIntersectionBusy[intersectionCode-1][1] != 0 || nightModeIntersectionBusy[intersectionCode-1][2] != 0
				|| nightModeIntersectionBusy[intersectionCode-1][3] != 0 || nightModeIntersectionBusy[intersectionCode-1][5] != 0
				|| nightModeIntersectionBusy[intersectionCode-1][10] != 0 || nightModeIntersectionBusy[intersectionCode-1][11] != 0) {
				waitingCar* wCar = new waitingCar; //struct olustur.
				wCar->carID=vehicleCode;
				wCar->from=From;
				wCar->to=To;
				wCar->cond=carCond;

				nightModeQueue[intersectionCode-1].push_back(wCar); //que'ya ekle.
				pthread_cond_wait(&wCar->cond, &nightModeMutex[intersectionCode-1]); //wait				
			}
			else {
				nightModeIntersectionBusy[intersectionCode-1][7]++; //nightmodeintersectionbusy WS yi bir arttır
			}//que'dan cikart ya da exitte uyandirinca cikart
			writeOutput(1, vehicleCode, intersectionCode, From, To);
		}
		pthread_mutex_unlock(&nightModeMutex[intersectionCode-1]);
	}
}

void CrossRoad::Exit(int vehicleCode, int intersectionCode, DIRECTION From,DIRECTION To) {
	if(lightState[intersectionCode-1]!=-1) {
		pthread_mutex_lock(&mutexList[intersectionCode-1][0]);
		writeOutput(2, vehicleCode, intersectionCode, From, To);
		if(From==WEST) {
			//pthread_mutex_lock(&mutexList[intersectionCode-1][2]);
			intersectionBusy[intersectionCode-1][0]--;
			//pthread_mutex_unlock(&mutexList[intersectionCode-1][2]);
			if(intersectionBusy[intersectionCode-1][0] == 0 && intersectionBusy[intersectionCode-1][1] == 0 && intersectionBusy[intersectionCode-1][2] == 0 && intersectionBusy[intersectionCode-1][3] == 0) {
				if(lightState[intersectionCode-1]==0) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][0]);
				}
				else if(lightState[intersectionCode-1]==1) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][1]);
				}
				else if(lightState[intersectionCode-1]==2) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][2]);
				}
				else if(lightState[intersectionCode-1]==3) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][3]);
				}
			}
		}
		else if(From==SOUTH) {
			//pthread_mutex_lock(&mutexList[intersectionCode-1][2]);
			intersectionBusy[intersectionCode-1][1]--;
			//pthread_mutex_unlock(&mutexList[intersectionCode-1][2]);
			if(intersectionBusy[intersectionCode-1][0] == 0 && intersectionBusy[intersectionCode-1][1] == 0 && intersectionBusy[intersectionCode-1][2] == 0 && intersectionBusy[intersectionCode-1][3] == 0) {
				if(lightState[intersectionCode-1]==0) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][0]);
				}
				else if(lightState[intersectionCode-1]==1) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][1]);
				}
				else if(lightState[intersectionCode-1]==2) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][2]);
				}
				else if(lightState[intersectionCode-1]==3) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][3]);
				}
			}
		}
		else if(From==EAST) {
			//pthread_mutex_lock(&mutexList[intersectionCode-1][2]);
			intersectionBusy[intersectionCode-1][2]--;
			//pthread_mutex_unlock(&mutexList[intersectionCode-1][2]);
			if(intersectionBusy[intersectionCode-1][0] == 0 && intersectionBusy[intersectionCode-1][1] == 0 && intersectionBusy[intersectionCode-1][2] == 0 && intersectionBusy[intersectionCode-1][3] == 0) {
				if(lightState[intersectionCode-1]==0) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][0]);
				}
				else if(lightState[intersectionCode-1]==1) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][1]);
				}
				else if(lightState[intersectionCode-1]==2) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][2]);
				}
				else if(lightState[intersectionCode-1]==3) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][3]);
				}
			}
		}
		else if(From==NORTH) {
			//pthread_mutex_lock(&mutexList[intersectionCode-1][2]);
			intersectionBusy[intersectionCode-1][3]--;
			//pthread_mutex_unlock(&mutexList[intersectionCode-1][2]);
			if(intersectionBusy[intersectionCode-1][0] == 0 && intersectionBusy[intersectionCode-1][1] == 0 && intersectionBusy[intersectionCode-1][2] == 0 && intersectionBusy[intersectionCode-1][3] == 0) {
				if(lightState[intersectionCode-1]==0) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][0]);
				}
				else if(lightState[intersectionCode-1]==1) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][1]);
				}
				else if(lightState[intersectionCode-1]==2) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][2]);
				}
				else if(lightState[intersectionCode-1]==3) {
					pthread_cond_broadcast(&cvList[intersectionCode-1][3]);
				}
			}
		}
		pthread_mutex_unlock(&mutexList[intersectionCode-1][0]);
	}
	else { //night-mode
		pthread_mutex_lock(&nightModeMutex[intersectionCode-1]);
		writeOutput(2, vehicleCode, intersectionCode, From, To);

		if(From==WEST && To==SOUTH) nightModeIntersectionBusy[intersectionCode-1][0]--;
		if(From==WEST && To==EAST) nightModeIntersectionBusy[intersectionCode-1][1]--;
		if(From==WEST && To==NORTH) nightModeIntersectionBusy[intersectionCode-1][2]--;

		if(From==SOUTH && To==WEST) nightModeIntersectionBusy[intersectionCode-1][3]--;
		if(From==SOUTH && To==EAST) nightModeIntersectionBusy[intersectionCode-1][4]--;
		if(From==SOUTH && To==NORTH) nightModeIntersectionBusy[intersectionCode-1][5]--;

		if(From==EAST && To==WEST) nightModeIntersectionBusy[intersectionCode-1][6]--;
		if(From==EAST && To==SOUTH) nightModeIntersectionBusy[intersectionCode-1][7]--;
		if(From==EAST && To==NORTH) nightModeIntersectionBusy[intersectionCode-1][8]--;

		if(From==NORTH && To==WEST) nightModeIntersectionBusy[intersectionCode-1][9]--;
		if(From==NORTH && To==SOUTH) nightModeIntersectionBusy[intersectionCode-1][10]--;
		if(From==NORTH && To==EAST) nightModeIntersectionBusy[intersectionCode-1][11]--;

		for(int i=0; i<nightModeQueue[intersectionCode-1].size(); i++) {
			DIRECTION queueFrom = nightModeQueue[intersectionCode-1][i]->from;
			DIRECTION queueTo = nightModeQueue[intersectionCode-1][i]->to;
			if(queueFrom == WEST && queueTo == SOUTH) {
				if(nightModeIntersectionBusy[intersectionCode-1][10] == 0 && nightModeIntersectionBusy[intersectionCode-1][7] == 0 && nightModeIntersectionBusy[intersectionCode-1][11] == 0) {
					nightModeIntersectionBusy[intersectionCode-1][0]++; //nightmodeintersectionbusy WS yi bir arttır
					pthread_cond_signal(&nightModeQueue[intersectionCode-1][i]->cond);//uyandir
					nightModeQueue[intersectionCode-1].erase(nightModeQueue[intersectionCode-1].begin()+i);//que'dan cikart
					i--;//kaydırma yap
					continue;
				}
			}
			if(queueFrom == SOUTH && queueTo == EAST) {
				if(nightModeIntersectionBusy[intersectionCode-1][11] == 0 && nightModeIntersectionBusy[intersectionCode-1][1] == 0 && nightModeIntersectionBusy[intersectionCode-1][2] == 0) {
					nightModeIntersectionBusy[intersectionCode-1][4]++; //nightmodeintersectionbusy WS yi bir arttır
					pthread_cond_signal(&nightModeQueue[intersectionCode-1][i]->cond);//uyandir
					nightModeQueue[intersectionCode-1].erase(nightModeQueue[intersectionCode-1].begin()+i);//que'dan cikart
					i--;//kaydırma yap
					continue;
				}
			}
			if(queueFrom == NORTH && queueTo == WEST) {
				if(nightModeIntersectionBusy[intersectionCode-1][6] == 0 && nightModeIntersectionBusy[intersectionCode-1][3] == 0 && nightModeIntersectionBusy[intersectionCode-1][7] == 0) {
					nightModeIntersectionBusy[intersectionCode-1][9]++; //nightmodeintersectionbusy WS yi bir arttır
					pthread_cond_signal(&nightModeQueue[intersectionCode-1][i]->cond);//uyandir
					nightModeQueue[intersectionCode-1].erase(nightModeQueue[intersectionCode-1].begin()+i);//que'dan cikart
					i--;//kaydırma yap
					continue;				
				}
			}
			if(queueFrom == EAST && queueTo == NORTH) {
				if(nightModeIntersectionBusy[intersectionCode-1][5] == 0 && nightModeIntersectionBusy[intersectionCode-1][2] == 0 && nightModeIntersectionBusy[intersectionCode-1][3] == 0) {
					nightModeIntersectionBusy[intersectionCode-1][8]++; //nightmodeintersectionbusy WS yi bir arttır
					pthread_cond_signal(&nightModeQueue[intersectionCode-1][i]->cond);//uyandir
					nightModeQueue[intersectionCode-1].erase(nightModeQueue[intersectionCode-1].begin()+i);//que'dan cikart
					i--;//kaydırma yap
					continue;
				}
			}
			if(queueFrom == SOUTH && queueTo == NORTH) {
				if(nightModeIntersectionBusy[intersectionCode-1][8] == 0 && nightModeIntersectionBusy[intersectionCode-1][6] == 0 && nightModeIntersectionBusy[intersectionCode-1][7] == 0
					&& nightModeIntersectionBusy[intersectionCode-1][11] == 0 && nightModeIntersectionBusy[intersectionCode-1][2] == 0 && nightModeIntersectionBusy[intersectionCode-1][1] == 0) {
					nightModeIntersectionBusy[intersectionCode-1][5]++; //nightmodeintersectionbusy WS yi bir arttır
					pthread_cond_signal(&nightModeQueue[intersectionCode-1][i]->cond);//uyandir
				}
				nightModeQueue[intersectionCode-1].erase(nightModeQueue[intersectionCode-1].begin()+i);//que'dan cikart
				i--;//kaydırma yap
				continue;
			}
			if(queueFrom == NORTH && queueTo == SOUTH) {
				if(nightModeIntersectionBusy[intersectionCode-1][6] == 0 && nightModeIntersectionBusy[intersectionCode-1][1] == 0 && nightModeIntersectionBusy[intersectionCode-1][7] == 0
					&& nightModeIntersectionBusy[intersectionCode-1][0] == 0 && nightModeIntersectionBusy[intersectionCode-1][3] == 0 && nightModeIntersectionBusy[intersectionCode-1][2] == 0) {
					nightModeIntersectionBusy[intersectionCode-1][10]++; //nightmodeintersectionbusy WS yi bir arttır
					pthread_cond_signal(&nightModeQueue[intersectionCode-1][i]->cond);//uyandir
					nightModeQueue[intersectionCode-1].erase(nightModeQueue[intersectionCode-1].begin()+i);//que'dan cikart
					i--;//kaydırma yap
					continue;
				}
			}
			if(queueFrom == WEST && queueTo == EAST) {
				if(nightModeIntersectionBusy[intersectionCode-1][10] == 0 && nightModeIntersectionBusy[intersectionCode-1][5] == 0 && nightModeIntersectionBusy[intersectionCode-1][4] == 0
					&& nightModeIntersectionBusy[intersectionCode-1][11] == 0 && nightModeIntersectionBusy[intersectionCode-1][3] == 0 && nightModeIntersectionBusy[intersectionCode-1][7] == 0) {
					nightModeIntersectionBusy[intersectionCode-1][1]++; //nightmodeintersectionbusy WS yi bir arttır
					pthread_cond_signal(&nightModeQueue[intersectionCode-1][i]->cond);//uyandir
					nightModeQueue[intersectionCode-1].erase(nightModeQueue[intersectionCode-1].begin()+i);//que'dan cikart
					i--;//kaydırma yap
					continue;
				}
			}
			if(queueFrom == EAST && queueTo == WEST) {
				if(nightModeIntersectionBusy[intersectionCode-1][10] == 0 && nightModeIntersectionBusy[intersectionCode-1][5] == 0 && nightModeIntersectionBusy[intersectionCode-1][3] == 0
					&& nightModeIntersectionBusy[intersectionCode-1][9] == 0 && nightModeIntersectionBusy[intersectionCode-1][11] == 0 && nightModeIntersectionBusy[intersectionCode-1][2] == 0) {
					nightModeIntersectionBusy[intersectionCode-1][6]++; //nightmodeintersectionbusy WS yi bir arttır
					pthread_cond_signal(&nightModeQueue[intersectionCode-1][i]->cond);//uyandir
					nightModeQueue[intersectionCode-1].erase(nightModeQueue[intersectionCode-1].begin()+i);//que'dan cikart
					i--;//kaydırma yap
					continue;
				}
			}
			if(queueFrom == SOUTH && queueTo == WEST) {
				if(nightModeIntersectionBusy[intersectionCode-1][2] == 0 && nightModeIntersectionBusy[intersectionCode-1][1] == 0 && nightModeIntersectionBusy[intersectionCode-1][9] == 0
					&& nightModeIntersectionBusy[intersectionCode-1][10] == 0 && nightModeIntersectionBusy[intersectionCode-1][11] == 0 && nightModeIntersectionBusy[intersectionCode-1][6] == 0 
					&& nightModeIntersectionBusy[intersectionCode-1][7] == 0) {
					nightModeIntersectionBusy[intersectionCode-1][3]++; //nightmodeintersectionbusy WS yi bir arttır
					pthread_cond_signal(&nightModeQueue[intersectionCode-1][i]->cond);//uyandir
					nightModeQueue[intersectionCode-1].erase(nightModeQueue[intersectionCode-1].begin()+i);//que'dan cikart
					i--;//kaydırma yap
					continue;
				}
			}
			if(queueFrom == WEST && queueTo == NORTH) {
				if(nightModeIntersectionBusy[intersectionCode-1][3] == 0 && nightModeIntersectionBusy[intersectionCode-1][5] == 0
					&& nightModeIntersectionBusy[intersectionCode-1][10] == 0 && nightModeIntersectionBusy[intersectionCode-1][11] == 0 && nightModeIntersectionBusy[intersectionCode-1][6] == 0 
					&& nightModeIntersectionBusy[intersectionCode-1][7] == 0 && nightModeIntersectionBusy[intersectionCode-1][8] == 0) {
					nightModeIntersectionBusy[intersectionCode-1][2]++; //nightmodeintersectionbusy WS yi bir arttır
					pthread_cond_signal(&nightModeQueue[intersectionCode-1][i]->cond);//uyandir
					nightModeQueue[intersectionCode-1].erase(nightModeQueue[intersectionCode-1].begin()+i);//que'dan cikart
					i--;//kaydırma yap
					continue;
				}
			}
			if(queueFrom == NORTH && queueTo == EAST) {
				if(nightModeIntersectionBusy[intersectionCode-1][1] == 0 && nightModeIntersectionBusy[intersectionCode-1][2] == 0
					&& nightModeIntersectionBusy[intersectionCode-1][3] == 0 && nightModeIntersectionBusy[intersectionCode-1][4] == 0 && nightModeIntersectionBusy[intersectionCode-1][5] == 0 
					&& nightModeIntersectionBusy[intersectionCode-1][6] == 0 && nightModeIntersectionBusy[intersectionCode-1][7] == 0) {
					nightModeIntersectionBusy[intersectionCode-1][11]++; //nightmodeintersectionbusy WS yi bir arttır
					pthread_cond_signal(&nightModeQueue[intersectionCode-1][i]->cond);//uyandir
					nightModeQueue[intersectionCode-1].erase(nightModeQueue[intersectionCode-1].begin()+i);//que'dan cikart
					i--;//kaydırma yap
					continue;
				}	
			}
			if(queueFrom == EAST && queueTo == SOUTH) {
				if(nightModeIntersectionBusy[intersectionCode-1][0] == 0 && nightModeIntersectionBusy[intersectionCode-1][1] == 0 && nightModeIntersectionBusy[intersectionCode-1][2] == 0
					&& nightModeIntersectionBusy[intersectionCode-1][3] == 0 && nightModeIntersectionBusy[intersectionCode-1][5] == 0 
					&& nightModeIntersectionBusy[intersectionCode-1][10] == 0 && nightModeIntersectionBusy[intersectionCode-1][11] == 0) {
					nightModeIntersectionBusy[intersectionCode-1][7]++; //nightmodeintersectionbusy WS yi bir arttır
					pthread_cond_signal(&nightModeQueue[intersectionCode-1][i]->cond);//uyandir
					nightModeQueue[intersectionCode-1].erase(nightModeQueue[intersectionCode-1].begin()+i);//que'dan cikart
					i--;//kaydırma yap
					continue;
				}
			}
		}
		pthread_mutex_unlock(&nightModeMutex[intersectionCode-1]);
	}
}

void CrossRoad::SetGreenLight(int intersectionCode) {
	pthread_mutex_lock(&mutexList[intersectionCode-1][0]);
	DIRECTION direction;
	//pthread_mutex_lock(&mutexList[intersectionCode-1][0]);
	lightState[intersectionCode-1]=(lightState[intersectionCode-1]+1)%4;
	if(lightState[intersectionCode-1] == 0) {
		direction=WEST;
		if(intersectionBusy[intersectionCode-1][1]==0 && intersectionBusy[intersectionCode-1][2]==0 && intersectionBusy[intersectionCode-1][3]==0) {
			pthread_cond_broadcast(&cvList[intersectionCode-1][0]);
		}
	}
	else if(lightState[intersectionCode-1] == 1) {
		direction=SOUTH;
		if(intersectionBusy[intersectionCode-1][0]==0 && intersectionBusy[intersectionCode-1][2]==0 && intersectionBusy[intersectionCode-1][3]==0) {
			pthread_cond_broadcast(&cvList[intersectionCode-1][1]);
		}
	}
	else if(lightState[intersectionCode-1] == 2) {
		direction=EAST;
		if(intersectionBusy[intersectionCode-1][0]==0 && intersectionBusy[intersectionCode-1][1]==0 && intersectionBusy[intersectionCode-1][3]==0) {
			pthread_cond_broadcast(&cvList[intersectionCode-1][2]);
		}
	}
	else if(lightState[intersectionCode-1] == 3) {
		direction=NORTH;
		if(intersectionBusy[intersectionCode-1][0]==0 && intersectionBusy[intersectionCode-1][1]==0 && intersectionBusy[intersectionCode-1][2]==0) {
			pthread_cond_broadcast(&cvList[intersectionCode-1][3]);
		}
	}
	writeOutput(3, -1, intersectionCode, direction, EAST);
	//pthread_mutex_unlock(&mutexList[intersectionCode-1][0]);
	pthread_mutex_unlock(&mutexList[intersectionCode-1][0]);
}

vector <string> parse(string str, char delimiter) {
	stringstream ss(str);
	vector <string> parsedLine;
	string tok;

	while(getline(ss, tok, delimiter)) {
		parsedLine.push_back(tok);
	}
	return parsedLine;
}

void *carThread(void* carS) {
	//cout << "EXECUTE" << endl;
	DIRECTION from;
	DIRECTION to;

	carStruct* car;
	car = (carStruct*) carS;	
	int plate = car -> carID;
	int arrvDur = car -> arriveDuration;
	int passDur = car -> passingDuration;
	vector <vector <string> > asd = car -> turns;
	pthread_cond_t cond;
	cond = car -> myCV;
	

	for(int i=0; i<asd.size(); i++) {
		if(asd[i][1] == "WEST") from = WEST;
		if(asd[i][1] == "SOUTH") from = SOUTH;
		if(asd[i][1] == "EAST") from = EAST;
		if(asd[i][1] == "NORTH") from = NORTH;

		if(asd[i][2] == "WEST") to = WEST;
		if(asd[i][2] == "SOUTH") to = SOUTH;
		if(asd[i][2] == "EAST") to = EAST;
		if(asd[i][2] == "NORTH") to = NORTH;

		usleep(arrvDur*1000);
		writeOutput(0,plate, atoi(asd[i][0].c_str()), from, to);
		car->cr->Enter(plate, atoi(asd[i][0].c_str()), from, to, cond);
		usleep(passDur*1000);
		car->cr->Exit(plate, atoi(asd[i][0].c_str()), from, to);
	}
	pthread_mutex_lock(&carCountMutex);
	carCount--;
	//cout << "araba cikti " << carCount << endl;
	pthread_mutex_unlock(&carCountMutex);
	pthread_exit(NULL);
	//cout << "plaka: " << plate << " arriveDuration: " << arrvDur << " passingDuration: " << passDur << endl;
	/*for(int i=0; i<asd.size(); i++) {
		for(int j=0; j<asd[i].size(); j++) {
			cout << "i: " << i << " j: " << j << " deger: " << asd[i][j] << endl;
		}
	}*/
}

int main(int argc, char ** argv) {
	int numberOfIntersection = atoi(argv[1]);
	int mode = atoi(argv[2]);
	int duration = atoi(argv[3]);

	CrossRoad *crossRoad = new CrossRoad(numberOfIntersection, mode); //CROSSROAD OLUSTUR

	pthread_mutex_init(&carCountMutex,0);

	if(mode == 0) {
		/*INTERSECTIONLARI OLUSTURUP ISIK YAKMA THREADINI CALISTIR*/
		for(int i=0; i<numberOfIntersection; i++) {
			intersectionData* interData = new intersectionData;
			interData -> intersectionCode = i+1;
			interData -> duration = duration;
			interData -> crossroad = crossRoad;

			vector <int> temp;
			for(int j=0; j<4; j++) {
				temp.push_back(0);
			}
			intersectionBusy.push_back(temp);

			vector <pthread_cond_t> temp1;
			for(int k=0; k<4; k++) {
				pthread_cond_t cv;
				pthread_cond_init(&cv,0);
				temp1.push_back(cv);
			}
			cvList.push_back(temp1);

			vector <pthread_mutex_t> temp2;
			pthread_mutex_t mtx;
			pthread_mutex_init(&mtx,0);
			temp2.push_back(mtx);

			pthread_mutex_t mtx2;
			pthread_mutex_init(&mtx2,0);
			temp2.push_back(mtx2);

			pthread_mutex_t mtx3;
			pthread_mutex_init(&mtx3,0);
			temp2.push_back(mtx3);

			mutexList.push_back(temp2);
			
			pthread_t traffLight;
			pthread_attr_t det2;
			pthread_attr_init(&det2);
			pthread_attr_setdetachstate(&det2,PTHREAD_CREATE_DETACHED);
			pthread_create(&traffLight, &det2, trafficLight,(void*) interData);
			pthread_detach(traffLight);
		}
	}
	else if(mode==1) {
		for(int i=0; i<numberOfIntersection; i++) {
			pthread_mutex_t mtx;
			pthread_mutex_init(&mtx,0);
			nightModeMutex.push_back(mtx);

			vector <int> nightTemp;

			for(int j=0; j<12; j++) {
				nightTemp.push_back(0);
			}
			nightModeIntersectionBusy.push_back(nightTemp);

			vector <waitingCar*> waitTemp;
			nightModeQueue.push_back(waitTemp);
		}
	}
	/***********************************************/

	/*INPUT ALMA*/
	string line;
	vector <vector <string> > lines;
	vector <string> carInfo;

	getline(cin, line);
	carInfo = parse(line, ' ');

	while(getline(cin, line)) {
		if(line != "NR") {
			lines.push_back(parse(line, ' '));
		}
		else{
			pthread_mutex_lock(&carCountMutex);
			carCount++;
			//cout << "araba girdi " << carCount << endl;
			pthread_mutex_unlock(&carCountMutex);			carStruct* car = new carStruct;
			car->carID=atoi(carInfo[0].c_str());
			car->arriveDuration=atoi(carInfo[1].c_str());
			car->passingDuration=atoi(carInfo[2].c_str());
			car->turns=lines;
			car->cr = crossRoad;
			pthread_cond_t cond;
			pthread_cond_init(&cond, 0);
			car->myCV = cond;
			//EXECUTE CAR THREAD
			pthread_t carTr;
			pthread_attr_t det;
			pthread_attr_init(&det);
			pthread_attr_setdetachstate(&det,PTHREAD_CREATE_DETACHED);
			pthread_create(&carTr, &det, carThread,(void*) car);
			pthread_detach(carTr);
			/********************/

			lines.clear();
			if(getline(cin, line)) {
				carInfo = parse(line, ' ');	
				continue;
			}
			else {
				break;
			}
		}
	}
	/***********************/
	//pthread_exit(NULL);
	while(carCount);
	pthread_mutex_lock(&mutexWrite);
	return 1;
}
