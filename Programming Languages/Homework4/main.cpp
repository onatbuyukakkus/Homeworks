#ifndef PA4_MAIN_CPP
#define PA4_MAIN_CPP

#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include "DFSA.h"
#include "DPDA.h"

void printAppCommands(){
	cout << "Please enter one of the commands to continue:" << endl;
	cout << "r input ( Prints output of the model on the input" << endl;
	cout << "h input ( Prints configuration history of the model on the input" << endl;
	cout << "q (quit) " << endl;
}

int main(int argv, char** argc){

	if (argv == 3){

		string modelFilePath(argc[1]);
		string modelType(argc[2]);

		ComputationalModel* model = NULL;

		if (modelType.compare("dfsa") == 0){
			model = new DFSA();
		 
		} else if (modelType.compare("dpda") == 0){
			model = new DPDA();
		} else {
			cout << "Unsupported model type " << endl;
		}


		cout << "Loading model from " << modelFilePath << endl;
		model->loadFromFile(modelFilePath);
		cout << "Model Loaded Succesfully "  << endl;
		cout << endl;
		model->print();
		cout << endl;
		
		printAppCommands();
		
		cout <<   endl;

		string cmd;
		string input;
		bool quit = false;

		while ( !quit ){
			cin >> cmd;
			if (cmd.compare("q") == 0){
				quit = true;
				continue;
			}

			if (cmd.compare("r") == 0){
				cin >> input;
				cout << "Input: " << input << endl;
				cout << "Output: " << model->compute(input) << endl;

			} else if (cmd.compare("h") == 0){
				cin >> input;
				cout << "Input: " << input << endl;
				cout << "Computation History:" << endl;
				vector<Configuration*> history;
				string r(model->computeWithTrace(input,history));
				for ( vector<Configuration*>::const_iterator it = history.begin(); it != history.end(); it++){
					(*it)->print();
					delete (*it); 
				}
                cout  << r << endl;
				
			} else {
				printAppCommands();
			}
		} 
		delete model;

		cout << "Quitting..." << endl;
		return 0;

	} else {

		cout << "Usage:" << endl;
		cout << "./studyComp <modelFile> <modeltype>" << endl;
		cout << "<modeltype>: dfsa dpda" << endl;
		return -1;
	}


}

#endif //PA4_MAIN_CPP