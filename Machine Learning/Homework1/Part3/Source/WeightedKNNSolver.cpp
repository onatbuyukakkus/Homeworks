//
//  WeightedKNNSolver.cpp
//  Homework1
//
//  Created by Onat Buyukakkus on 13/04/2017.
//  Copyright © 2017 Onat Buyukakkus. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;

void parser (string fileName, vector<string> &labels, vector< vector<double> > &values) {
    ifstream stream(fileName.c_str());
    string line;
    
    //first line: labels
    getline(stream, line);
    istringstream ss(line);
    string token;
    
    while(getline(ss, token, ',')) { //parse line by comma
        labels.push_back(token);
    }
    
    //other lines: values
    while (getline(stream, line))
    {
        istringstream ss(line);
        string token;
        vector <double> temp;
        
        while(getline(ss, token, ',')) { //parse lines by comma
            double fTemp = atof(token.c_str()); //str to double casting
            temp.push_back(fTemp);
        }
        
        values.push_back(temp);
    }
}

double euclideanDistanceCalculator(vector<double> xMatrixRow, vector<double> attList) {
    double sum = 0;
    for(int i=0; i<xMatrixRow.size(); i++) {
        double diff = xMatrixRow[i] - attList[i];
        diff = pow(diff, 2);
        sum += diff;
    }
    return pow(sum, 0.5);
}

bool myComparison(const pair<double,double> &a,const pair<double,double> &b) {
    return a.first < b.first;
}

int main(int argc, const char * argv[]) {
    cout.precision(17);
    string inputFile  = argv[1]; //take input file name as argument
    int k = atoi(argv[2]); //take k as argument
    
    vector < string > labels;
    vector < vector<double> > values;
    
    parser(inputFile, labels, values); //read and parse .csv file
    
    if (!labels[labels.size()-1].empty() && labels[labels.size()-1][labels[labels.size()-1].size()-1] == '\r') {
        labels[labels.size()-1].erase(labels[labels.size()-1].size()-1); //remove '\r' from the last element
    }
    
    vector<double> attList;
    for(int i=0; i<labels.size()-1; i++) {
        attList.push_back(atof(argv[3+i])); //k times attributes
    }
    
    //create x matrix with elements to be values from dataset except the one that will be predicted
    vector< vector<double> > xMatrix(values.size(), vector<double>(values[0].size()-1));
    for(int i=0; i<values.size(); i++) {
        for(int j=0; j<values[i].size()-1; j++) {
            xMatrix[i][j] = values[i][j];
        }
    }
    
    
    //find k nearest instances
    
//    vector < pair<double,int> > nearestInstances(k, pair<double, int>(numeric_limits<double>::max(),0));
//    for(int i=0; i<xMatrix.size(); i++) {
//        double distance = euclideanDistanceCalculator(xMatrix[i], attList);
//        for(int j=nearestInstances.size()-1; j>=0; j--) {
//            if(distance < nearestInstances[j].first) {
//                pair<double, int> tempPair(distance, i);
//                nearestInstances[j] = tempPair;
//                break;
//            }
//        }
//        sort(nearestInstances.begin(), nearestInstances.end(), myComparison);
//    }
    
    vector < pair<double,int> > nearestInstances;
    for(int i=0; i<xMatrix.size(); i++) {
        double distance = euclideanDistanceCalculator(xMatrix[i], attList);
        pair<double, int> tempPair(distance, i);
        nearestInstances.push_back(tempPair);
    }
    sort(nearestInstances.begin(), nearestInstances.end(), myComparison);
    for(int i=0; i<k; i++) {
        if(nearestInstances[i].first < 0.01) nearestInstances[i].first = 0.01; //if distance is very small, take as small number
    }
    
    double weightedClassLabel = 0.0;
    double totalWeight = 0.0;
    
    //print
    cout << "k = " << k << endl;
    cout << endl;
    for(int i=0; i<labels.size()-1; i++) {
        cout << "Attribute " << i+1 << " (" << labels[i] << ") = " << attList[i] << endl;
    }
    cout << endl;
    for(int i=0; i<k; i++) {
        cout << "Instance " << i+1 << " : Index = " << nearestInstances[i].second << " , < ";
        for(int j=0; j<labels.size()-1; j++) {
            cout << values[nearestInstances[i].second][j];
            if(j != labels.size()-2) cout << " , "; //not to put an extra comma at the end of instance
        }
        cout << " > , Class Label = " << values[nearestInstances[i].second][labels.size()-1];
        cout << " , Distance = " << nearestInstances[i].first << " , Weight = " << 1/nearestInstances[i].first << endl;
        weightedClassLabel += values[nearestInstances[i].second][labels.size()-1]*1/nearestInstances[i].first;
        totalWeight += 1/nearestInstances[i].first;
    }
    cout << endl;
    cout << "Weighted class label (" << labels[labels.size()-1] << ") = " << weightedClassLabel/totalWeight << endl;
    
    return 0;
}


