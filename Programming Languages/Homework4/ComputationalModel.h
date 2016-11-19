#ifndef PA4_COMPUTATIONAL_MODEL_H
#define PA4_COMPUTATIONAL_MODEL_H

#include <string>
#include <vector>
#include "Configuration.h"

using std::string;
using std::vector;

class ComputationalModel {

	public:
	    virtual ~ComputationalModel(){}
		virtual string compute(const string& expression)  = 0;
		virtual string computeWithTrace(const string& expression, vector<Configuration*>& confList) = 0;
		virtual void loadFromFile(const string& modelFilePath)=0;
		virtual void print() const =0;
};

#endif // PA4_COMPUTATIONAL_MODEL_H