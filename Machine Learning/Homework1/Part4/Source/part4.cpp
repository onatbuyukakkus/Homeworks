//
//  part4.cpp
//  Homework1
//
//  Created by Onat Buyukakkus on 23/04/2017.
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
#include <iomanip>
#include <float.h>
#include <algorithm>
using namespace std;

void parser(string fileName, vector< vector<double> > &values) {
    ifstream stream(fileName.c_str());
    string line;
    
    //first line: labels
    getline(stream, line);
    istringstream ss(line);
    string token;
    
    
    //other lines: values
    while (getline(stream, line))
    {
        int flag = 0;
        istringstream ss(line);
        string token;
        vector <double> temp;
        
        while(getline(ss, token, ',')) { //parse lines by comma
            if(flag != 0 && flag != 5) { //do not push date column
                double fTemp = atof(token.c_str()); //str to double casting
                temp.push_back(fTemp);
            }
            flag++;
        }
        
        values.push_back(temp);
    }
    stream.close();
}

void parser2 (string fileName, vector<string> &labels, vector< vector<double> > &values) {
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

vector <double> takeAverage(vector< vector<double> > values) {
    vector <double> result;
    
    for(int i=0; i<values.size(); i++) {
        double average = 0;
        for(int j=0; j<values[i].size(); j++) {
            average += values[i][j];
        }
        average /= (double) values[i].size();
        result.push_back(average);
    }
    return result;
}

void writeToFile(int windowSize, vector <double> values, string outputFile) {
    ofstream outfile;
    outfile.open(outputFile.c_str());
    
    for(int i=0; i<windowSize; i++) {
        outfile << "Attribute " << i+1;
        if(i<windowSize-1) {
            outfile << ",";
        }
    }
    outfile << endl;
    for(int i=0; i<values.size()-windowSize+1; i++) {
        for(int j=i; j<i+windowSize; j++) {
            outfile << std::fixed << std::setprecision(6) << values[j];
            if(j<i+windowSize-1) {
                outfile << ",";
            }
        }
        outfile << endl;
    }
    outfile.close();
}

double analyticalSolver(vector < string > labels, vector < vector<double> > values2016, vector< vector<double> > values2017) {
    //create x matrix with first elements of each row equal to 1 and
    //other elements to be values from dataset except the one that will be predicted
    vector< vector<double> > xMatrix2016(values2016.size(), vector<double>(values2016[0].size()));
    for(int i=0; i<values2016.size(); i++) {
        xMatrix2016[i][0] = 1;
        for(int j=1; j<values2016[i].size(); j++) {
            xMatrix2016[i][j] = values2016[i][j-1];
        }
    }
    
    vector< vector<double> > xMatrix2017(values2017.size(), vector<double>(values2017[0].size()));
    for(int i=0; i<values2017.size(); i++) {
        xMatrix2017[i][0] = 1;
        for(int j=1; j<values2017[i].size(); j++) {
            xMatrix2017[i][j] = values2017[i][j-1];
        }
    }
    
    //create y matrix containing value that will be predicted
    vector< vector<double> > yMatrix2016;
    for(int i=0; i<values2016.size(); i++) {
        vector<double> temp;
        temp.push_back(values2016[i][values2016[i].size()-1]);
        yMatrix2016.push_back(temp);
    }
    
    //create y matrix containing value that will be predicted
    vector< vector<double> > yMatrix2017;
    for(int i=0; i<values2017.size(); i++) {
        vector<double> temp;
        temp.push_back(values2017[i][values2017[i].size()-1]);
        yMatrix2017.push_back(temp);
    }
    
    //transpose x
    vector< vector<double> > xTransMatrix;
    xTransMatrix = matrixTransposer(xMatrix2016);
    
    //w = (X^T * X)^-1 * X^T * Y
    vector< vector<double> > wMatrix;
    wMatrix = matrixMultiplier(xTransMatrix, xMatrix2016); //(X^T * X)
    wMatrix = matrixInverser(wMatrix); //(X^T * X)^-1
    wMatrix = matrixMultiplier(wMatrix, xTransMatrix); //(X^T * X)^-1 * x^T
    wMatrix = matrixMultiplier(wMatrix, yMatrix2016); //(X^T * X)^-1 * x^T * Y
    
    vector<double> tempMatrix;
    for(int i=0; i<wMatrix.size(); i++) {
        tempMatrix.push_back(wMatrix[i][0]);
    }
    
    //RMS error
    double rmsError = 0;
    for(int i=0; i<xMatrix2017.size(); i++) { //for all rows
        double temp = 0.0;
        for(int j=0; j<xMatrix2017[i].size(); j++) {
            temp += xMatrix2017[i][j] * tempMatrix[j]; //multiply w value and corresponding a value
        }
        rmsError += pow(yMatrix2017[i][0] - temp,2); //extract multiplied value from prediction value and take square of it
    }
    rmsError = pow((rmsError/xMatrix2017.size()),0.5); //divide it to sample size
    
    //print w's
    for (int i=0; i<tempMatrix.size(); i++) {
        cout << "w" << i << " (" << labels[i] << ") " << "= " << tempMatrix[i] << endl;
    }
    cout << endl;
    
    return rmsError;
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

void iterativeSolver(double minChangeInRMS, double lambda, vector < string > labels, vector < vector<double> > values2016, vector< vector<double> > values2017) {
    //create x matrix with first elements of each row equal to 1 and
    //other elements to be values from dataset except the one that will be predicted
    vector< vector<double> > xMatrix2016(values2016.size(), vector<double>(values2016[0].size()));
    for(int i=0; i<values2016.size(); i++) {
        xMatrix2016[i][0] = 1;
        for(int j=1; j<values2016[i].size(); j++) {
            xMatrix2016[i][j] = values2016[i][j-1];
        }
    }
    
    vector< vector<double> > xMatrix2017(values2017.size(), vector<double>(values2017[0].size()));
    for(int i=0; i<values2017.size(); i++) {
        xMatrix2017[i][0] = 1;
        for(int j=1; j<values2017[i].size(); j++) {
            xMatrix2017[i][j] = values2017[i][j-1];
        }
    }
    
    //create y matrix containing value that will be predicted
    vector< vector<double> > yMatrix2016;
    for(int i=0; i<values2016.size(); i++) {
        vector<double> temp;
        temp.push_back(values2016[i][values2016[i].size()-1]);
        yMatrix2016.push_back(temp);
    }
    
    vector< vector<double> > yMatrix2017;
    for(int i=0; i<values2017.size(); i++) {
        vector<double> temp;
        temp.push_back(values2017[i][values2017[i].size()-1]);
        yMatrix2017.push_back(temp);
    }

    
    vector<double> wMatrix(xMatrix2016[0].size(), 0.0); //initial w matrix filled with zeros
    vector<double> wNewMatrix(xMatrix2016[0].size(), 0.0); //w matrix to be changed
    double rmsError = rootMeanSquaredErrorFinder(xMatrix2017, yMatrix2017, wMatrix);
    double newRmsError;
    
    while(true){ //loop until RMS error change is smaller than given argument
        cout << "< ";
        for(int i=0; i<wMatrix.size(); i++) {
            cout << wMatrix[i];
            if(i != wMatrix.size()-1) cout << " , "; //not to put an extra comma at the end of w vector
            double temp = meanSquaredErrorFinder(i, xMatrix2016, yMatrix2016, wMatrix);
            temp = wMatrix[i] - lambda*temp;
            wNewMatrix[i] = temp;
        }
        wMatrix = wNewMatrix;
        newRmsError = rootMeanSquaredErrorFinder(xMatrix2017, yMatrix2017, wMatrix);
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

void weightedKNNSolver(int k, vector<double> attList, vector < string > labels, vector < vector<double> > values2016) {
    if (!labels[labels.size()-1].empty() && labels[labels.size()-1][labels[labels.size()-1].size()-1] == '\r') {
        labels[labels.size()-1].erase(labels[labels.size()-1].size()-1); //remove '\r' from the last element
    }

    //create x matrix with elements to be values from dataset except the one that will be predicted
    vector< vector<double> > xMatrix2016(values2016.size(), vector<double>(values2016[0].size()-1));
    for(int i=0; i<values2016.size(); i++) {
        for(int j=0; j<values2016[i].size()-1; j++) {
            xMatrix2016[i][j] = values2016[i][j];
        }
    }
    
    vector < pair<double,int> > nearestInstances;
    for(int i=0; i<xMatrix2016.size(); i++) {
        double distance = euclideanDistanceCalculator(xMatrix2016[i], attList);
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
            cout << values2016[nearestInstances[i].second][j];
            if(j != labels.size()-2) cout << " , "; //not to put an extra comma at the end of instance
        }
        cout << " > , Class Label = " << values2016[nearestInstances[i].second][labels.size()-1];
        cout << " , Distance = " << nearestInstances[i].first << " , Weight = " << 1/nearestInstances[i].first << endl;
        weightedClassLabel += values2016[nearestInstances[i].second][labels.size()-1]*1/nearestInstances[i].first;
        totalWeight += 1/nearestInstances[i].first;
    }
    cout << endl;
    cout << "Weighted class label (" << labels[labels.size()-1] << ") = " << weightedClassLabel/totalWeight << endl;
}

int main(int argc, const char * argv[]) {
    cout.precision(17);
    string inputFile2016  = argv[1]; //take input file name as argument
    string inputFile2017  = argv[2]; //take input file name as argument
    int partNo = atoi(argv[3]);
    
    vector < vector<double> > values2016;
    vector < vector<double> > values2017;
    
    parser(inputFile2016, values2016); //read and parse .csv file
    parser(inputFile2017, values2017); //read and parse .csv file

    vector <double> averages2016 = takeAverage(values2016);
    vector <double> averages2017 = takeAverage(values2017);

    if(partNo == 1) {
        double minRmsError = DBL_MAX;
        for(int i=1; i<35; i++) {
           vector<string> labels2016;
           vector<string> labels2017;
       
           vector < vector<double> > newValues2016;
           vector < vector<double> > newValues2017;
       
           writeToFile(i, averages2016, "/Users/Onat1/Desktop/4TH YEAR/SPRING/CENG499/Homework1/Data/part4-goog-2016.csv");
           writeToFile(i, averages2017, "/Users/Onat1/Desktop/4TH YEAR/SPRING/CENG499/Homework1/Data/part4-goog-2017.csv");
           
           parser2("/Users/Onat1/Desktop/4TH YEAR/SPRING/CENG499/Homework1/Data/part4-goog-2016.csv", labels2016, newValues2016);
           parser2("/Users/Onat1/Desktop/4TH YEAR/SPRING/CENG499/Homework1/Data/part4-goog-2017.csv", labels2017, newValues2017);
           
           cout << "Window size = " << i << endl;
           double rmsError = analyticalSolver(labels2016, newValues2016, newValues2017);
           cout << "RMS Error = " << rmsError << endl;
           cout << "********" << endl;
       }
    }

    if(partNo == 2) {
        vector<string> labels2016;
        vector<string> labels2017;
       
        vector < vector<double> > newValues2016;
        vector < vector<double> > newValues2017;
       
        writeToFile(11, averages2016, "/Users/Onat1/Desktop/4TH YEAR/SPRING/CENG499/Homework1/Data/part4-goog-2016.csv");
        writeToFile(11, averages2017, "/Users/Onat1/Desktop/4TH YEAR/SPRING/CENG499/Homework1/Data/part4-goog-2017.csv");
       
        parser2("/Users/Onat1/Desktop/4TH YEAR/SPRING/CENG499/Homework1/Data/part4-goog-2016.csv", labels2016, newValues2016);
        parser2("/Users/Onat1/Desktop/4TH YEAR/SPRING/CENG499/Homework1/Data/part4-goog-2017.csv", labels2017, newValues2017);

        iterativeSolver(0.00001, 0.0000001, labels2016, newValues2016, newValues2017);
    }
    
    
    if(partNo == 3) {
        vector<string> labels2016;
        vector<string> labels2017;

        vector < vector<double> > newValues2016;
        vector < vector<double> > newValues2017;

        writeToFile(11, averages2016, "/Users/Onat1/Desktop/4TH YEAR/SPRING/CENG499/Homework1/Data/part4-goog-2016.csv");
        writeToFile(11, averages2017, "/Users/Onat1/Desktop/4TH YEAR/SPRING/CENG499/Homework1/Data/part4-goog-2017.csv");

        parser2("/Users/Onat1/Desktop/4TH YEAR/SPRING/CENG499/Homework1/Data/part4-goog-2016.csv", labels2016, newValues2016);
        parser2("/Users/Onat1/Desktop/4TH YEAR/SPRING/CENG499/Homework1/Data/part4-goog-2017.csv", labels2017, newValues2017);
        labels2016.erase(labels2016.begin());
        
        for(int i=0; i<newValues2017.size(); i++) {
            vector<double> attList = newValues2017[i];
            weightedKNNSolver(5, attList, labels2016, newValues2016);
            cout << "Original class label (Attribute 11) = " << newValues2017[i][newValues2017[i].size()-1] << endl;
            cout << "********" << endl;
        }
    }
    return 0;
}
