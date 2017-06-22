//
//  IterativeSolver.cpp
//  Homework1
//
//  Created by Onat Buyukakkus on 11/04/2017.
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
using namespace std;

void parser (string fileName, vector<string> &labels, vector< vector<double> > &values) {
    ifstream stream(fileName.c_str());
    string line;
    
    //first line: labels
    labels.push_back("1.0");
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

double meanSquaredErrorFinder(int aj, vector< vector<double> > xMatrix, vector< vector<double> > yMatrix, vector<double> wMatrix) {
    double msError = 0;
    for(int i=0; i<xMatrix.size(); i++) { //for all rows
        double temp = 0.0;
        for(int j=0; j<xMatrix[i].size(); j++) {
            temp += xMatrix[i][j] * wMatrix[j]; //multiply w value and corresponding a value
        }
        msError += -xMatrix[i][aj]*(yMatrix[i][0] - temp); //extract multiplied value from prediction value and multiply it with a_j value
    }
    msError = 2*msError/xMatrix.size(); //multiply by 2 and divide it to sample size
    return msError;
}

double rootMeanSquaredErrorFinder(vector< vector<double> > xMatrix, vector< vector<double> > yMatrix, vector<double> wMatrix) {
    double rmsError = 0;
    for(int i=0; i<xMatrix.size(); i++) { //for all rows
        double temp = 0.0;
        for(int j=0; j<xMatrix[i].size(); j++) {
            temp += xMatrix[i][j] * wMatrix[j]; //multiply w value and corresponding a value
        }
        rmsError += pow(yMatrix[i][0] - temp,2); //extract multiplied value from prediction value and take square of it
    }
    rmsError = pow((rmsError/xMatrix.size()),0.5); //divide it to sample size
    return rmsError;
}

int main(int argc, const char * argv[]) {
    cout.precision(17);
    string inputFile  = argv[1]; //take input file name as argument
    double lambda = atof(argv[2]); //take lambda as argument
    double minChangeInRMS = atof(argv[3]); //take minimum change in RMS as argument
    
    vector < string > labels;
    vector < vector<double> > values;
    
    parser(inputFile, labels, values); //read and parse .csv file
    
    //create x matrix with first elements of each row equal to 1 and
    //other elements to be values from dataset except the one that will be predicted
    vector< vector<double> > xMatrix(values.size(), vector<double>(values[0].size()));
    for(int i=0; i<values.size(); i++) {
        xMatrix[i][0] = 1;
        for(int j=1; j<values[i].size(); j++) {
            xMatrix[i][j] = values[i][j-1];
        }
    }
    
    //create y matrix containing value that will be predicted
    vector< vector<double> > yMatrix;
    for(int i=0; i<values.size(); i++) {
        vector<double> temp;
        temp.push_back(values[i][values[i].size()-1]);
        yMatrix.push_back(temp);
    }
    
    vector<double> wMatrix(xMatrix[0].size(), 0.0); //initial w matrix filled with zeros
    vector<double> wNewMatrix(xMatrix[0].size(), 0.0); //w matrix to be changed
    double rmsError = rootMeanSquaredErrorFinder(xMatrix, yMatrix, wMatrix);
    double newRmsError;
    
    while(true){ //loop until RMS error change is smaller than given argument
        cout << "< ";
        for(int i=0; i<wMatrix.size(); i++) {
            cout << wMatrix[i];
            if(i != wMatrix.size()-1) cout << " , "; //not to put an extra comma at the end of w vector
            double temp = meanSquaredErrorFinder(i, xMatrix, yMatrix, wMatrix);
            temp = wMatrix[i] - lambda*temp;
            wNewMatrix[i] = temp;
        }
        wMatrix = wNewMatrix;
        newRmsError = rootMeanSquaredErrorFinder(xMatrix, yMatrix, wMatrix);
        cout << " > ," << " RMS Error = " << rmsError << endl;
        
        if(fabs(rmsError-newRmsError) < minChangeInRMS) { //final print for right value and break
            cout << "< ";
            for(int i=0; i<wMatrix.size(); i++) {
                cout << wMatrix[i];
                if(i != wMatrix.size()-1) cout << " , "; //not to put an extra comma at the end of w vector
            }
            cout << " > ," << " RMS Error = " << rmsError << endl;
            cout << endl;
            
            for(int i=0; i<wMatrix.size(); i++) {
                cout << "w" << i << " (" << labels[i] << ") " << "= " << wMatrix[i] << endl;
            }
            cout << endl;
            cout << "RMS Error = " << rmsError << endl;
            break;
        }
        rmsError = newRmsError;
    }
    
    return 0;
}

