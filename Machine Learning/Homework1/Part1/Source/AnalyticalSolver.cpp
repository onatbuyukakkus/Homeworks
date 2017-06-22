//
//  AnalyticalSolver.cpp
//  Homework1
//
//  Created by Onat Buyukakkus on 10/04/2017.
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

vector <vector <double> > matrixMultiplier (vector <vector <double> > matrixA, vector <vector <double> > matrixB) {
    vector <vector <double> > matrixR(matrixA.size(), vector <double> (matrixB[0].size())); //declare result matrix
    
    if(matrixA[0].size() != matrixB.size()) {
        cout << "Matrix sizes do not match!" << endl;
        return matrixR;
    }
    //initialize elements of result matrix to 0
    for(int i=0; i<matrixA.size(); ++i) {
        for(int j=0; j<matrixB[0].size(); ++j) {
            matrixR[i][j]=0;
        }
    }
    
    //multiplicate matrixA and matrixB into matrixR
    for(int i=0; i<matrixA.size(); ++i) {
        for(int j=0; j<matrixB[0].size(); ++j) {
            for(int  k=0; k<matrixA[0].size(); ++k)
            {
                matrixR[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return matrixR;
}

vector <vector <double> > matrixTransposer (vector <vector <double> > matrix) {
    vector <vector <double> > matrixR(matrix[0].size(), vector <double> (matrix.size())); //declare result matrix
    
    //transpose matrix into matrixR
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            matrixR[j][i] = matrix[i][j];
        }
    }
    return matrixR;
}

vector <vector <double> > matrixInverser (vector <vector <double> > matrix) {
    int size = matrix.size();
    
    //construct unit matrix
    vector <vector <double> > matrixUnit(size,vector <double>(size));
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(i==j) {
                matrixUnit[i][j] = 1.0;
            }
            else {
                matrixUnit[i][j] = 0.0;
            }
        }
    }
    
    //convert matrix to unit matrix
    for(int i=0; i<size; i++) {
        double temp = matrix[i][i];
        for(int j=0; j<size; j++) {
            matrix[i][j] = matrix[i][j]/temp;
            matrixUnit[i][j] = matrixUnit[i][j]/temp;
        }
        for(int k=0; k<size; k++) {
            if(k != i) {
                double temp2 = matrix[k][i];
                for(int j=0; j<size; j++) {
                    matrix[k][j] = matrix[k][j] - (matrix[i][j]*temp2);
                    matrixUnit[k][j] = matrixUnit[k][j] - (matrixUnit[i][j]*temp2);
                }
            }
        }
    }
    return matrixUnit;
}

void print(vector < string > labels, vector<double> tempMatrix, double rmsError) {
    //print
    for (int i=0; i<tempMatrix.size(); i++) {
        cout << "w" << i << " (" << labels[i] << ") " << "= " << tempMatrix[i] << endl;
    }
    cout << endl;
    cout << "RMS Error = " << rmsError << endl;
}

void analyticalSolver(vector < string > labels, vector < vector<double> > values) {
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
    
    //transpose x
    vector< vector<double> > xTransMatrix;
    xTransMatrix = matrixTransposer(xMatrix);
    
    //w = (X^T * X)^-1 * X^T * Y
    vector< vector<double> > wMatrix;
    wMatrix = matrixMultiplier(xTransMatrix, xMatrix); //(X^T * X)
    wMatrix = matrixInverser(wMatrix); //(X^T * X)^-1
    wMatrix = matrixMultiplier(wMatrix, xTransMatrix); //(X^T * X)^-1 * x^T
    wMatrix = matrixMultiplier(wMatrix, yMatrix); //(X^T * X)^-1 * x^T * Y
    
    vector<double> tempMatrix;
    for(int i=0; i<wMatrix.size(); i++) {
        tempMatrix.push_back(wMatrix[i][0]);
    }
    
    //RMS error
    double rmsError = 0;
    for(int i=0; i<xMatrix.size(); i++) { //for all rows
        double temp = 0.0;
        for(int j=0; j<xMatrix[i].size(); j++) {
            temp += xMatrix[i][j] * tempMatrix[j]; //multiply w value and corresponding a value
        }
        rmsError += pow(yMatrix[i][0] - temp,2); //extract multiplied value from prediction value and take square of it
    }
    rmsError = pow((rmsError/xMatrix.size()),0.5); //divide it to sample size
    
    print(labels, tempMatrix, rmsError);
}

int main(int argc, const char * argv[]) {
    cout.precision(17);
    string inputFile  = argv[1]; //take input file name as argument
    
    vector < string > labels;
    vector < vector<double> > values;
    
    parser(inputFile, labels, values); //read and parse .csv file
    
    analyticalSolver(labels, values);
    
    return 0;
}
