#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
using namespace std;

vector < vector <string> > commandsAndArguments;
vector < vector <int> > inputs;
vector < vector <int> > outputs;
vector <int> busyPipesInput;
vector <int> busyPipesOutput;
vector <int*> pipes;
vector <int> openPipeList;
vector <int*> repeaterPipes;


bool find(vector<string> lines, string match) {

	for(int i=0; i<lines.size(); i++) {
		if(lines[i]==match) {
			return true;
		}
	}
	return false;
}

bool findInt(vector<int> lines, int match) {

	for(int i=0; i<lines.size(); i++) {
		if(lines[i]==match) {
			return true;
		}
	}
	return false;
}

int indexFinder(vector<int> vect, int match) {

	for(int i=0; i<vect.size(); i++) {
		if(vect[i]==match) {
			return i;
		}
	}
	return -1;
}

void openPipe(int type) {

	int* fd = new int(2);
	pipe(fd);
	pipes.push_back(fd);
	if(type==1) {
		repeaterPipes.push_back(fd);
	}
}

void myForkInput(int fd[], vector <string> args) {
	
	//string arg = args[0];
	if (!fork()) {

		char **commandChar = new char*[args.size()+1];
		for(size_t i=0; i<args.size();i++){
			commandChar[i] = new char[args[i].size()+1];
			commandChar[i] = (char*) args[i].c_str();
		}
		commandChar[args.size()] = NULL;

		close(fd[0]);
		dup2(fd[1],1);
		close(fd[1]);

		for(int i=0; i<pipes.size(); i++) {
			close(pipes[i][0]);
			close(pipes[i][1]);
		}

		/*if(arg=="ls")
			execl("/bin/ls","ls","-l",NULL);
		if(arg=="cat")
			execl("/bin/cat","cat","/etc/group",NULL);
		if(arg=="echo")
			execl("/bin/echo","echo","ananisikimos",NULL);*/
	
		execvp(commandChar[0],commandChar);
	}
}

void myForkOutput(int fd[], vector <string> args) {

	//string arg = args[0];
	if (!fork()) {

		char **commandChar = new char*[args.size()+1];
		for(size_t i=0; i<args.size();i++){
			commandChar[i] = new char[args[i].size()+1];
			commandChar[i] = (char*) args[i].c_str();
		}
		commandChar[args.size()] = NULL;

		close(fd[1]);
		dup2(fd[0],0);
		close(fd[0]);

		for(int i=0; i<pipes.size(); i++) {
			close(pipes[i][0]);
			close(pipes[i][1]);
		}

		/*if(arg=="tr")
			execl("/usr/bin/tr","tr","/a-k/","/A-K/",NULL);
		if(arg=="tr2")
			execl("/usr/bin/tr","tr","/K-Z/","/k-z/",NULL);
		if(arg=="cat")
			execl("/bin/cat","cat","-n",NULL);
		if(arg=="grep")
			execl("/bin/grep","grep","1",NULL);*/

		execvp(commandChar[0],commandChar);
	}
}

void myForkInpOut(int fd[], int fd2[], vector <string> args) {
	
	if (!fork()) {

		char **commandChar = new char*[args.size()+1];
		for(size_t i=0; i<args.size();i++){
			commandChar[i] = new char[args[i].size()+1];
			commandChar[i] = (char*) args[i].c_str();
		}
		commandChar[args.size()] = NULL;

		dup2(fd[0],0);
		close(fd[0]);
		close(fd[1]);

		dup2(fd2[1],1);
		close(fd2[1]);
		close(fd2[0]);
		
		for(int i=0; i<pipes.size(); i++) {
			close(pipes[i][0]);
			close(pipes[i][1]);
		}

		/*if(arg=="tr")
			execl("/usr/bin/tr","tr","/a-z/","/A-Z/",NULL);*/

		execvp(commandChar[0],commandChar);

	}
}

void noPipes(vector <string> args) {

	if(!fork()) {
		char **commandChar = new char*[args.size()+1];
		for(size_t i=0; i<args.size();i++){
			commandChar[i] = (char*) args[i].c_str();
		}
		commandChar[args.size()] = NULL;

		execvp(commandChar[0],commandChar);
	}
}

void distributor(int fd[], vector <string> args) {
	if(!fork()) {

		int copyFD[2];
		pipe(copyFD);

		close(fd[1]);
		dup2(fd[0],0);
		close(fd[0]);

		for(int i=0; i<repeaterPipes.size(); i++) {
			close(repeaterPipes[i][0]);
		}
		
		if(!fork()) {
			char output;

			close(0);
			
			close(copyFD[1]);
			while(read(copyFD[0],&output,1)>0) {
					for(int i=0; i<repeaterPipes.size(); i++) {
						write(repeaterPipes[i][1],&output,1);
					}
			}
			close(copyFD[0]);

			for(int i=0; i<repeaterPipes.size(); i++) {
				close(repeaterPipes[i][1]);
			}
			
			exit(0);
		}

		close(copyFD[0]);
		dup2(copyFD[1],1);
		close(copyFD[1]);

		for(int i=0; i<repeaterPipes.size(); i++) {
			close(repeaterPipes[i][1]);
		}

		char **commandChar = new char*[args.size()+1];
		for(size_t i=0; i<args.size();i++){
			commandChar[i] = new char[args[i].size()+1];
			commandChar[i] = (char*) args[i].c_str();
		}
		commandChar[args.size()] = NULL;
		repeaterPipes.clear();
		execvp(commandChar[0],commandChar);
	}
}

void execute() {

	int* argument;
	for(int i=0; i<inputs.size(); i++) {

		if(inputs[i].size()==1) {

			if(inputs[i][0]!=-1 && outputs[i][0]==-1) {
				if(findInt(openPipeList, inputs[i][0])==true){
					int index = indexFinder(openPipeList,inputs[i][0]);
					myForkInput(pipes[index], commandsAndArguments[i]);
				}
				else if(findInt(openPipeList, inputs[i][0])==false) {
					openPipe(0);
					openPipeList.push_back(inputs[i][0]);
					myForkInput(pipes.back(), commandsAndArguments[i]);
				}
				
			}
			if(inputs[i][0]!=-1 && outputs[i][0]!=-1) {

				if(findInt(openPipeList, outputs[i][0])!=false && findInt(openPipeList, inputs[i][0])==false) {

					openPipe(0);
					openPipeList.push_back(inputs[i][0]);
					int index = indexFinder(openPipeList, outputs[i][0]);
					myForkInpOut(pipes[index],pipes.back(),commandsAndArguments[i]);
				}
				
				else if(findInt(openPipeList, outputs[i][0])==false && findInt(openPipeList, inputs[i][0])==false) {

					openPipe(0);
					openPipeList.push_back(inputs[i][0]);
					openPipe(0);
					openPipeList.push_back(outputs[i][0]);
					myForkInpOut(pipes.back(), pipes[pipes.size()-2] ,commandsAndArguments[i]);
				}
				else if(findInt(openPipeList, outputs[i][0])==false && findInt(openPipeList, inputs[i][0])!=false) {

					openPipe(0);
					openPipeList.push_back(outputs[i][0]);
					int index = indexFinder(openPipeList, inputs[i][0]);

					myForkInpOut(pipes.back(), pipes[index], commandsAndArguments[i]);
				}
				else {

					int index1 = indexFinder(openPipeList, inputs[i][0]);
					int index2 = indexFinder(openPipeList, outputs[i][0]);

					myForkInpOut(pipes[index2], pipes[index1], commandsAndArguments[i]);
				}
			}
			if(inputs[i][0]==-1 && outputs[i][0]!=-1) {
				if(findInt(openPipeList, outputs[i][0])==true) {
					int index = indexFinder(openPipeList, outputs[i][0]);
					myForkOutput(pipes[index], commandsAndArguments[i]);
				}
				else if(findInt(openPipeList, outputs[i][0])==false) {
					openPipe(0);
					openPipeList.push_back(outputs[i][0]);
					myForkOutput(pipes.back(), commandsAndArguments[i]);
				}	
			}
			if(inputs[i][0]==-1 && outputs[i][0]==-1) {
				noPipes(commandsAndArguments[i]);
			}
		}
		else {

			if(outputs[i][0]==-1) {

				for(int j=0; j<inputs[i].size(); j++) {
					if(findInt(openPipeList, inputs[i][j])==false) {
						openPipe(0);
						openPipeList.push_back(inputs[i][j]);
						myForkInput(pipes.back(), commandsAndArguments[i]);
					}
					else {
						int index = indexFinder(openPipeList, inputs[i][j]);
						myForkInput(pipes[index], commandsAndArguments[i]);
					}
				}
			}
			else {

				if(findInt(openPipeList, outputs[i][0])==false) {
					openPipe(0);
					openPipeList.push_back(outputs[i][0]);
					argument = pipes.back();
				}
				else {
					int index = indexFinder(openPipeList, outputs[i][0]);
					argument = pipes[index];
				}
					
				/*for(int j=0; j<inputs[i].size(); j++) {
					if(findInt(openPipeList, inputs[i][j])==false) {
						openPipe();
						openPipeList.push_back(inputs[i][j]);
						repeaterPipes.push_back(inputs[i][j]);
					}
					else {
						repeaterPipes.push_back(inputs[i][j]);
					}
				}*/

				for(int j=0; j<inputs[i].size(); j++) {
					if(findInt(openPipeList, inputs[i][j])==false) {
						openPipe(1);
						openPipeList.push_back(inputs[i][j]);
					}
					else if(findInt(openPipeList, inputs[i][j]==true)) {
						int index = indexFinder(openPipeList, inputs[i][j]);
						repeaterPipes.push_back(pipes[index]);
					}
				}
				distributor(argument, commandsAndArguments[i]);
			}
		}
	}

	int status_child;
	for(int i=0; i<pipes.size(); i++) {
		int stat;
		close(pipes[i][0]);
		close(pipes[i][1]);
		wait(&stat);
	}

	for(int i=0; i<commandsAndArguments.size(); i++) {
		 wait(&status_child);
	}

	for(int i=0; i<commandsAndArguments.size(); i++) {
		commandsAndArguments[i].clear();
	}

	for(int i=0; i<inputs.size(); i++) {
		inputs[i].clear();
	}

	for(int i=0; i<outputs.size(); i++) {
		outputs[i].clear();
	}

	commandsAndArguments.clear();
	inputs.clear();
	outputs.clear();
	busyPipesInput.clear();
	busyPipesOutput.clear();
	openPipeList.clear();
	repeaterPipes.clear();
	pipes.clear();

}

void completeControl() {

	int counter=0;
	if(busyPipesInput.size() == busyPipesOutput.size()) {
		for(int i=0; i<busyPipesInput.size(); i++) {
			if(findInt(busyPipesOutput, busyPipesInput[i])==true) {
				counter++;
			}
		}
	}
	if(counter == busyPipesInput.size() && counter == busyPipesOutput.size()) {
		execute();

		for(int i=0; i<commandsAndArguments.size(); i++) {
			commandsAndArguments[i].clear();
		}

		for(int i=0; i<inputs.size(); i++) {
			inputs[i].clear();
		}

		for(int i=0; i<outputs.size(); i++) {
			outputs[i].clear();
		}

		commandsAndArguments.clear();
		inputs.clear();
		outputs.clear();
		busyPipesInput.clear();
		busyPipesOutput.clear();
		openPipeList.clear();
		pipes.clear();
		repeaterPipes.clear();
	}
}

void advancedParse(vector <string> lines) {
	for(int i=0; i<lines.size(); i++) {
		if(lines[i] == ">|") {
			int j=i+1;
			vector <int> temp;
			while(j<lines.size() ) {
				if(lines[j] != "<|"){
					int id;
					id=atoi(lines[j].c_str());
					temp.push_back(id);

					if(findInt(busyPipesInput, id)==false) {
						busyPipesInput.push_back(id);
					}

					j++;
				}
			}
			inputs.push_back(temp);
		}
		if(lines[i] == "<|") {
			int id;
			int j=i+1;
			vector <int> temp;
			id=atoi(lines[j].c_str());
			temp.push_back(id);

			if(findInt(busyPipesOutput, id)==false) {
				busyPipesOutput.push_back(id);
			}

			outputs.push_back(temp);
		}
	}

	vector <string> stringTemp;
	for(int k=0; k<lines.size(); k++) {
		if(lines[k]!=">|" && lines[k]!="<|") {
			stringTemp.push_back(lines[k]);
		}
		else {
			break;
		}
	}
	commandsAndArguments.push_back(stringTemp);

	if(find(lines, "<|") == false){
		vector <int> temp;
		temp.push_back(-1);
		outputs.push_back(temp);
	}
	if(find(lines, ">|") == false){
		vector <int> temp;
		temp.push_back(-1);
		inputs.push_back(temp);
	}

	completeControl();
}

vector<string> parse(string str, char delimiter) {
	vector<string> parsedLine;
	stringstream ss(str);
	string tok;

	while(getline(ss, tok, delimiter)) {
		parsedLine.push_back(tok);
	}
	return parsedLine;
}


void readLines() {
	int flag=0;
	while(flag != 1) {
		string name;
		getline (cin,name);
		if(name=="quit") {
			flag=1;
			continue;
		}
		advancedParse(parse(name,' '));
	}
}

int main() {
	readLines();
	return 0;
}
