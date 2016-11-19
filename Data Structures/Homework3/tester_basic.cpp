#include <iostream>
#include <vector>
#include "DynamicPriorityQueue.h"
using namespace std;
void case_1(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 15);

	vector<int> myResult; 
	caseQueue.updatePriority(5670, 52402);
	caseQueue.insert(69840,96041);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(86380, 9064);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(80892,56169);
	myResult.push_back(caseQueue.getPriority(80892)); //3
	caseQueue.insert(77224,19181);
	caseQueue.updatePriority(77224, 63600);
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(65521,75579);
	caseQueue.updatePriority(77224, 34954);
	caseQueue.updatePriority(65521, 82127);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(53653,60218);
	static const int resultListArray[] = {69840, -1, 56169, 80892, 77224}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(1): Basarili" << endl;
	else cout << "Case(1): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_2(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 10);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(83980,39635);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.updatePriority(55974, 33680);
	caseQueue.insert(95853,97627);
	myResult.push_back(caseQueue.getPriority(95853)); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(93985,13131);
	caseQueue.updatePriority(93985, 78031);
	caseQueue.insert(20724,90616);
	static const int resultListArray[] = {-1, 83980, 97627, 95853}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(2): Basarili" << endl;
	else cout << "Case(2): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_3(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 18);

	vector<int> myResult; 
	caseQueue.updatePriority(30287, 5295);
	caseQueue.insert(85300,15350);
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.getPriority(62435)); //2
	myResult.push_back(caseQueue.getPriority(4018)); //3
	myResult.push_back(caseQueue.getPriority(3804)); //4
	myResult.push_back(caseQueue.getPriority(70268)); //5
	myResult.push_back(caseQueue.getPriority(24949)); //6
	caseQueue.insert(11341,67599);
	caseQueue.insert(25352,6354);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(11341, 12654);
	caseQueue.insert(37727,27282);
	caseQueue.insert(7527,89363);
	myResult.push_back(caseQueue.getPriority(11341)); //8
	caseQueue.updatePriority(37727, 6092);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.insert(7166,60669);
	static const int resultListArray[] = {85300, -1, -1, -1, -1, -1, 25352, 12654, 37727}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(3): Basarili" << endl;
	else cout << "Case(3): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_4(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 23);

	vector<int> myResult; 
	caseQueue.insert(61054,21805);
	caseQueue.insert(86723,23327);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(86723, 40898);
	caseQueue.updatePriority(86723, 49995);
	caseQueue.insert(21022,98306);
	caseQueue.updatePriority(21022, 37928);
	caseQueue.updatePriority(21022, 20346);
	caseQueue.insert(19441,71504);
	caseQueue.updatePriority(19441, 38694);
	myResult.push_back(caseQueue.getPriority(21022)); //2
	caseQueue.insert(37825,45281);
	myResult.push_back(caseQueue.getPriority(86723)); //3
	caseQueue.insert(5790,16296);
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(91196,44953);
	caseQueue.insert(22475,21095);
	caseQueue.insert(15143,25102);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(6659,42443);
	caseQueue.updatePriority(37825, 55284);
	caseQueue.insert(21409,70178);
	caseQueue.insert(98664,60810);
	static const int resultListArray[] = {61054, 20346, 49995, 5790, 21022}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(4): Basarili" << endl;
	else cout << "Case(4): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_5(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 30);

	vector<int> myResult; 
	caseQueue.insert(19783,49339);
	myResult.push_back(caseQueue.getPriority(19783)); //1
	myResult.push_back(caseQueue.getPriority(19783)); //2
	myResult.push_back(caseQueue.getPriority(19783)); //3
	myResult.push_back(caseQueue.getPriority(19783)); //4
	myResult.push_back(caseQueue.getPriority(19783)); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.getPriority(155)); //7
	myResult.push_back(caseQueue.getPriority(24644)); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(89357, 9266);
	caseQueue.insert(2038,92473);
	caseQueue.insert(32288,9185);
	myResult.push_back(caseQueue.getPriority(2038)); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.insert(26907,81045);
	myResult.push_back(caseQueue.deleteMin()); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.insert(306,13068);
	caseQueue.insert(56087,31422);
	myResult.push_back(caseQueue.getPriority(306)); //15
	caseQueue.updatePriority(306, 39300);
	caseQueue.insert(31670,42513);
	caseQueue.insert(77095,88634);
	caseQueue.insert(96745,73889);
	myResult.push_back(caseQueue.getPriority(77095)); //16
	caseQueue.insert(64529,53867);
	myResult.push_back(caseQueue.deleteMin()); //17
	caseQueue.insert(39761,42813);
	static const int resultListArray[] = {49339, 49339, 49339, 49339, 49339, 19783, -1, -1, -1, 92473, 32288, 2038, 26907, -1, 13068, 88634, 56087}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(5): Basarili" << endl;
	else cout << "Case(5): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_6(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 21);

	vector<int> myResult; 
	caseQueue.updatePriority(65238, 29994);
	caseQueue.insert(45731,34474);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(35636, 20302);
	caseQueue.insert(16395,7314);
	caseQueue.updatePriority(16395, 93579);
	caseQueue.insert(40941,30788);
	myResult.push_back(caseQueue.getPriority(40941)); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(87384,8568);
	myResult.push_back(caseQueue.getPriority(87384)); //4
	caseQueue.updatePriority(16395, 75893);
	caseQueue.insert(29410,87402);
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.insert(92024,50728);
	myResult.push_back(caseQueue.getPriority(29410)); //7
	caseQueue.insert(42968,39705);
	caseQueue.insert(19930,39966);
	myResult.push_back(caseQueue.getPriority(42968)); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	static const int resultListArray[] = {45731, 30788, 40941, 8568, 87384, 16395, 87402, 39705, 42968}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(6): Basarili" << endl;
	else cout << "Case(6): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_7(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 45);

	vector<int> myResult; 
	caseQueue.updatePriority(57271, 58576);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(63594,50384);
	myResult.push_back(caseQueue.getPriority(63594)); //2
	caseQueue.insert(22285,51657);
	caseQueue.insert(27386,14370);
	myResult.push_back(caseQueue.deleteMin()); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.updatePriority(22285, 31099);
	myResult.push_back(caseQueue.getPriority(22285)); //5
	caseQueue.updatePriority(22285, 99452);
	myResult.push_back(caseQueue.getPriority(22285)); //6
	caseQueue.insert(87189,90726);
	myResult.push_back(caseQueue.getPriority(87189)); //7
	caseQueue.insert(40583,96257);
	caseQueue.insert(85451,36375);
	myResult.push_back(caseQueue.getPriority(22285)); //8
	caseQueue.insert(59900,13329);
	myResult.push_back(caseQueue.deleteMin()); //9
	myResult.push_back(caseQueue.deleteMin()); //10
	caseQueue.insert(81861,20728);
	caseQueue.insert(88093,42448);
	caseQueue.insert(22031,23088);
	myResult.push_back(caseQueue.getPriority(87189)); //11
	caseQueue.insert(74337,46879);
	caseQueue.updatePriority(40583, 80964);
	myResult.push_back(caseQueue.getPriority(81861)); //12
	caseQueue.updatePriority(22031, 7774);
	caseQueue.insert(74077,39865);
	myResult.push_back(caseQueue.getPriority(88093)); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	myResult.push_back(caseQueue.getPriority(74077)); //15
	caseQueue.insert(76472,31861);
	caseQueue.insert(49268,85221);
	myResult.push_back(caseQueue.deleteMin()); //16
	caseQueue.updatePriority(74077, 95814);
	myResult.push_back(caseQueue.deleteMin()); //17
	caseQueue.insert(41426,29077);
	caseQueue.insert(80074,16432);
	caseQueue.updatePriority(80074, 77946);
	caseQueue.insert(71376,13182);
	caseQueue.insert(74309,87475);
	caseQueue.updatePriority(22285, 55108);
	caseQueue.insert(21285,47449);
	myResult.push_back(caseQueue.deleteMin()); //18
	static const int resultListArray[] = {-1, 50384, 27386, 63594, 31099, 99452, 90726, 99452, 59900, 85451, 90726, 20728, 42448, 22031, 39865, 81861, 76472, 71376}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(7): Basarili" << endl;
	else cout << "Case(7): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_8(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 23);

	vector<int> myResult; 
	caseQueue.updatePriority(94581, 65892);
	myResult.push_back(caseQueue.getPriority(77374)); //1
	caseQueue.insert(66477,78424);
	caseQueue.updatePriority(66477, 24237);
	myResult.push_back(caseQueue.getPriority(66477)); //2
	caseQueue.insert(62047,78199);
	myResult.push_back(caseQueue.getPriority(62047)); //3
	myResult.push_back(caseQueue.getPriority(62047)); //4
	caseQueue.updatePriority(62047, 86508);
	caseQueue.updatePriority(62047, 80621);
	caseQueue.insert(73322,25406);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(11627,76019);
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.updatePriority(80110, 45195);
	myResult.push_back(caseQueue.getPriority(22942)); //9
	caseQueue.updatePriority(59351, 68388);
	caseQueue.insert(53874,43445);
	caseQueue.updatePriority(53874, 83654);
	caseQueue.insert(18656,86327);
	caseQueue.updatePriority(18656, 6641);
	static const int resultListArray[] = {-1, 24237, 78199, 78199, 66477, 73322, 11627, 62047, -1}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(8): Basarili" << endl;
	else cout << "Case(8): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_9(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 22);

	vector<int> myResult; 
	caseQueue.insert(66877,5366);
	caseQueue.insert(16148,85914);
	myResult.push_back(caseQueue.getPriority(66877)); //1
	caseQueue.insert(22534,68753);
	caseQueue.insert(26856,97688);
	myResult.push_back(caseQueue.getPriority(26856)); //2
	caseQueue.insert(64366,32444);
	caseQueue.updatePriority(26856, 42965);
	caseQueue.updatePriority(26856, 46901);
	caseQueue.insert(37899,86313);
	caseQueue.updatePriority(22534, 52283);
	myResult.push_back(caseQueue.getPriority(66877)); //3
	caseQueue.insert(58103,11000);
	caseQueue.insert(70385,67388);
	caseQueue.updatePriority(37899, 54515);
	myResult.push_back(caseQueue.getPriority(22534)); //4
	caseQueue.insert(55712,40094);
	myResult.push_back(caseQueue.getPriority(64366)); //5
	caseQueue.insert(59459,9781);
	caseQueue.insert(3673,75697);
	caseQueue.updatePriority(16148, 38573);
	caseQueue.insert(80812,26195);
	static const int resultListArray[] = {5366, 97688, 5366, 52283, 32444}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(9): Basarili" << endl;
	else cout << "Case(9): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_10(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 42);

	vector<int> myResult; 
	caseQueue.insert(64725,21916);
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.getPriority(1874)); //2
	myResult.push_back(caseQueue.getPriority(46683)); //3
	caseQueue.updatePriority(20255, 13657);
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.updatePriority(32624, 82858);
	caseQueue.insert(18322,3098);
	caseQueue.insert(93889,94206);
	caseQueue.updatePriority(18322, 62589);
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.insert(96504,71085);
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.getPriority(93889)); //8
	caseQueue.insert(64172,18077);
	caseQueue.insert(66228,6517);
	myResult.push_back(caseQueue.getPriority(64172)); //9
	caseQueue.updatePriority(64172, 94807);
	caseQueue.insert(8581,30033);
	caseQueue.insert(31355,10361);
	myResult.push_back(caseQueue.deleteMin()); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(22894,35026);
	caseQueue.insert(43163,67741);
	caseQueue.insert(78116,37598);
	caseQueue.insert(59595,18473);
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.updatePriority(8581, 1866);
	myResult.push_back(caseQueue.deleteMin()); //13
	caseQueue.updatePriority(78116, 42202);
	myResult.push_back(caseQueue.getPriority(43163)); //14
	myResult.push_back(caseQueue.deleteMin()); //15
	myResult.push_back(caseQueue.deleteMin()); //16
	caseQueue.updatePriority(93889, 90627);
	myResult.push_back(caseQueue.deleteMin()); //17
	caseQueue.updatePriority(64172, 16787);
	myResult.push_back(caseQueue.getPriority(93889)); //18
	caseQueue.insert(10197,93653);
	myResult.push_back(caseQueue.getPriority(10197)); //19
	caseQueue.updatePriority(93889, 65273);
	caseQueue.insert(77947,37258);
	static const int resultListArray[] = {64725, -1, -1, -1, -1, 18322, 96504, 94206, 18077, 66228, 31355, 59595, 8581, 67741, 22894, 78116, 43163, 90627, 93653}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(10): Basarili" << endl;
	else cout << "Case(10): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_11(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 43);

	vector<int> myResult; 
	caseQueue.updatePriority(39661, 56318);
	myResult.push_back(caseQueue.getPriority(98228)); //1
	myResult.push_back(caseQueue.getPriority(94874)); //2
	myResult.push_back(caseQueue.getPriority(37274)); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(54209,90394);
	caseQueue.insert(29550,75871);
	caseQueue.insert(49371,72524);
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.getPriority(54209)); //7
	caseQueue.insert(18566,34049);
	myResult.push_back(caseQueue.getPriority(54209)); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	myResult.push_back(caseQueue.deleteMin()); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(15026,11884);
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.updatePriority(60936, 78413);
	caseQueue.updatePriority(95228, 24772);
	caseQueue.updatePriority(23490, 28170);
	caseQueue.updatePriority(85481, 73934);
	caseQueue.insert(47586,93024);
	caseQueue.insert(97943,33706);
	myResult.push_back(caseQueue.getPriority(47586)); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.insert(48597,20738);
	caseQueue.updatePriority(47586, 89936);
	myResult.push_back(caseQueue.deleteMin()); //15
	caseQueue.insert(73896,12054);
	myResult.push_back(caseQueue.deleteMin()); //16
	myResult.push_back(caseQueue.getPriority(47586)); //17
	myResult.push_back(caseQueue.deleteMin()); //18
	caseQueue.insert(95502,95566);
	myResult.push_back(caseQueue.deleteMin()); //19
	myResult.push_back(caseQueue.deleteMin()); //20
	myResult.push_back(caseQueue.deleteMin()); //21
	caseQueue.insert(44346,62472);
	caseQueue.updatePriority(44346, 44894);
	caseQueue.insert(32929,96606);
	myResult.push_back(caseQueue.deleteMin()); //22
	caseQueue.insert(90795,48241);
	myResult.push_back(caseQueue.getPriority(90795)); //23
	static const int resultListArray[] = {-1, -1, -1, -1, 49371, 29550, 90394, 90394, 18566, 54209, -1, 15026, 93024, 97943, 48597, 73896, 89936, 47586, 95502, -1, -1, 44346, 48241}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(11): Basarili" << endl;
	else cout << "Case(11): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_12(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 30);

	vector<int> myResult; 
	caseQueue.insert(18264,21172);
	caseQueue.updatePriority(18264, 17340);
	myResult.push_back(caseQueue.getPriority(18264)); //1
	caseQueue.insert(7015,26634);
	myResult.push_back(caseQueue.getPriority(18264)); //2
	myResult.push_back(caseQueue.getPriority(18264)); //3
	myResult.push_back(caseQueue.getPriority(7015)); //4
	myResult.push_back(caseQueue.getPriority(18264)); //5
	myResult.push_back(caseQueue.getPriority(7015)); //6
	myResult.push_back(caseQueue.getPriority(7015)); //7
	caseQueue.insert(32894,93617);
	caseQueue.insert(27308,22088);
	caseQueue.insert(94001,34816);
	caseQueue.insert(69336,16259);
	caseQueue.insert(48439,10648);
	caseQueue.updatePriority(94001, 78932);
	caseQueue.insert(49204,68895);
	myResult.push_back(caseQueue.getPriority(18264)); //8
	myResult.push_back(caseQueue.getPriority(32894)); //9
	myResult.push_back(caseQueue.getPriority(7015)); //10
	caseQueue.updatePriority(48439, 41742);
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.getPriority(27308)); //12
	caseQueue.updatePriority(94001, 71519);
	myResult.push_back(caseQueue.getPriority(27308)); //13
	caseQueue.insert(2592,5601);
	caseQueue.insert(69830,26091);
	caseQueue.updatePriority(2592, 84511);
	caseQueue.insert(89184,73898);
	caseQueue.insert(79184,1402);
	static const int resultListArray[] = {17340, 17340, 17340, 26634, 17340, 26634, 26634, 17340, 93617, 26634, 69336, 22088, 22088}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(12): Basarili" << endl;
	else cout << "Case(12): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_13(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 45);

	vector<int> myResult; 
	caseQueue.insert(50538,48294);
	myResult.push_back(caseQueue.getPriority(50538)); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(25704,89496);
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.getPriority(84080)); //7
	myResult.push_back(caseQueue.getPriority(93831)); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(17237, 56149);
	myResult.push_back(caseQueue.getPriority(63848)); //10
	caseQueue.insert(19823,55494);
	caseQueue.insert(75475,71065);
	caseQueue.updatePriority(75475, 56045);
	caseQueue.updatePriority(75475, 67555);
	caseQueue.insert(69811,47704);
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(54775,22966);
	myResult.push_back(caseQueue.getPriority(54775)); //12
	caseQueue.insert(13241,44958);
	caseQueue.updatePriority(13241, 46115);
	caseQueue.insert(7579,12804);
	caseQueue.insert(77520,68249);
	caseQueue.insert(5309,79272);
	caseQueue.insert(73989,38830);
	myResult.push_back(caseQueue.deleteMin()); //13
	myResult.push_back(caseQueue.getPriority(19823)); //14
	caseQueue.insert(35392,28545);
	caseQueue.updatePriority(35392, 32873);
	caseQueue.insert(96289,68649);
	caseQueue.insert(58768,37311);
	myResult.push_back(caseQueue.deleteMin()); //15
	caseQueue.updatePriority(77520, 45112);
	myResult.push_back(caseQueue.deleteMin()); //16
	caseQueue.insert(6292,19143);
	caseQueue.insert(79479,95703);
	caseQueue.insert(71561,79839);
	caseQueue.updatePriority(5309, 70011);
	myResult.push_back(caseQueue.getPriority(77520)); //17
	caseQueue.insert(26980,72139);
	myResult.push_back(caseQueue.deleteMin()); //18
	caseQueue.insert(46330,61320);
	caseQueue.insert(17337,19998);
	static const int resultListArray[] = {48294, 50538, -1, 25704, -1, -1, -1, -1, -1, -1, 69811, 22966, 7579, 55494, 54775, 35392, 45112, 6292}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(13): Basarili" << endl;
	else cout << "Case(13): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_14(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 15);

	vector<int> myResult; 
	caseQueue.insert(7311,48862);
	caseQueue.insert(12245,89841);
	myResult.push_back(caseQueue.getPriority(12245)); //1
	caseQueue.updatePriority(7311, 23405);
	caseQueue.insert(30013,14413);
	caseQueue.insert(12253,97762);
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.getPriority(7311)); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(29779,41285);
	caseQueue.updatePriority(29779, 70513);
	caseQueue.updatePriority(12253, 79659);
	caseQueue.insert(80462,24833);
	myResult.push_back(caseQueue.deleteMin()); //6
	static const int resultListArray[] = {89841, 30013, 23405, 7311, 12245, 80462}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(14): Basarili" << endl;
	else cout << "Case(14): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_15(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 33);

	vector<int> myResult; 
	caseQueue.updatePriority(73313, 4665);
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.getPriority(86845)); //3
	caseQueue.updatePriority(87125, 56956);
	caseQueue.insert(89171,29502);
	myResult.push_back(caseQueue.getPriority(89171)); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(27766,20625);
	myResult.push_back(caseQueue.getPriority(27766)); //6
	caseQueue.updatePriority(27766, 3153);
	caseQueue.insert(59250,11335);
	caseQueue.insert(16621,91242);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.insert(54596,2859);
	myResult.push_back(caseQueue.getPriority(16621)); //8
	caseQueue.insert(97191,23831);
	caseQueue.insert(30818,85101);
	myResult.push_back(caseQueue.getPriority(97191)); //9
	caseQueue.insert(30664,79902);
	caseQueue.updatePriority(16621, 94843);
	caseQueue.insert(37122,31977);
	caseQueue.insert(48286,57260);
	caseQueue.updatePriority(30818, 8549);
	caseQueue.updatePriority(54596, 70132);
	caseQueue.insert(46633,68740);
	myResult.push_back(caseQueue.getPriority(30664)); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(6825,88405);
	myResult.push_back(caseQueue.getPriority(59250)); //12
	caseQueue.insert(95571,19461);
	caseQueue.insert(17373,61730);
	caseQueue.updatePriority(59250, 32297);
	static const int resultListArray[] = {-1, -1, -1, 29502, 89171, 20625, 27766, 91242, 23831, 79902, 30818, 11335}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(15): Basarili" << endl;
	else cout << "Case(15): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_16(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 39);

	vector<int> myResult; 
	caseQueue.insert(57802,22436);
	caseQueue.updatePriority(57802, 79538);
	caseQueue.updatePriority(57802, 60154);
	caseQueue.updatePriority(57802, 65538);
	caseQueue.insert(97001,9181);
	caseQueue.insert(21991,31064);
	myResult.push_back(caseQueue.getPriority(97001)); //1
	caseQueue.insert(72822,78926);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(71613,69532);
	caseQueue.insert(75285,7354);
	myResult.push_back(caseQueue.getPriority(75285)); //3
	caseQueue.updatePriority(21991, 63430);
	myResult.push_back(caseQueue.getPriority(72822)); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.updatePriority(21991, 68007);
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.getPriority(21991)); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	myResult.push_back(caseQueue.getPriority(72822)); //9
	caseQueue.insert(61858,9818);
	myResult.push_back(caseQueue.deleteMin()); //10
	caseQueue.updatePriority(72822, 91711);
	caseQueue.insert(14880,18573);
	caseQueue.updatePriority(71613, 52450);
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.getPriority(72822)); //12
	caseQueue.insert(28679,62570);
	caseQueue.updatePriority(71613, 85137);
	caseQueue.insert(89602,45735);
	caseQueue.insert(81978,25819);
	myResult.push_back(caseQueue.getPriority(72822)); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.insert(10814,44546);
	myResult.push_back(caseQueue.getPriority(71613)); //15
	myResult.push_back(caseQueue.getPriority(10814)); //16
	caseQueue.insert(34956,13175);
	caseQueue.updatePriority(72822, 58607);
	caseQueue.insert(31018,34586);
	static const int resultListArray[] = {9181, 97001, 7354, 78926, 75285, 57802, 68007, 21991, 78926, 61858, 14880, 91711, 91711, 81978, 85137, 44546}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(16): Basarili" << endl;
	else cout << "Case(16): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_17(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 28);

	vector<int> myResult; 
	caseQueue.insert(77548,32241);
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	myResult.push_back(caseQueue.getPriority(69503)); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(8676, 13651);
	caseQueue.insert(41060,57059);
	caseQueue.insert(50225,30735);
	myResult.push_back(caseQueue.getPriority(41060)); //8
	caseQueue.insert(19200,49439);
	caseQueue.updatePriority(41060, 74948);
	caseQueue.insert(79896,97791);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.insert(15260,27729);
	myResult.push_back(caseQueue.getPriority(41060)); //10
	myResult.push_back(caseQueue.getPriority(15260)); //11
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.insert(55123,78241);
	myResult.push_back(caseQueue.getPriority(55123)); //13
	caseQueue.updatePriority(55123, 34357);
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.insert(99951,94554);
	caseQueue.insert(67545,32690);
	caseQueue.insert(63947,20668);
	caseQueue.updatePriority(79896, 98301);
	static const int resultListArray[] = {77548, -1, -1, -1, -1, -1, -1, 57059, 50225, 74948, 27729, 15260, 78241, 55123}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(17): Basarili" << endl;
	else cout << "Case(17): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_18(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 11);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(61747,83686);
	myResult.push_back(caseQueue.getPriority(61747)); //2
	caseQueue.insert(61951,15902);
	caseQueue.insert(16367,21165);
	caseQueue.insert(11395,48070);
	caseQueue.insert(18052,4203);
	caseQueue.updatePriority(61951, 59626);
	caseQueue.insert(62866,75456);
	myResult.push_back(caseQueue.getPriority(62866)); //3
	caseQueue.insert(68307,82192);
	static const int resultListArray[] = {-1, 83686, 75456}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(18): Basarili" << endl;
	else cout << "Case(18): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_19(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 16);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.getPriority(47940)); //2
	myResult.push_back(caseQueue.getPriority(27322)); //3
	caseQueue.insert(8010,50498);
	caseQueue.insert(99404,88646);
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(44115,26186);
	caseQueue.insert(46310,67952);
	caseQueue.insert(14465,94589);
	caseQueue.updatePriority(14465, 4725);
	myResult.push_back(caseQueue.getPriority(46310)); //5
	myResult.push_back(caseQueue.getPriority(14465)); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	myResult.push_back(caseQueue.getPriority(46310)); //9
	caseQueue.insert(60382,79472);
	static const int resultListArray[] = {-1, -1, -1, 8010, 67952, 4725, 14465, 44115, 67952}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(19): Basarili" << endl;
	else cout << "Case(19): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_20(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 30);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(10797)); //1
	myResult.push_back(caseQueue.getPriority(81120)); //2
	caseQueue.insert(34435,14358);
	caseQueue.insert(55240,44276);
	caseQueue.insert(32480,9983);
	myResult.push_back(caseQueue.getPriority(55240)); //3
	caseQueue.insert(24841,99465);
	caseQueue.insert(83029,7791);
	caseQueue.insert(64257,89638);
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.updatePriority(64257, 86611);
	myResult.push_back(caseQueue.getPriority(34435)); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(64257, 92163);
	myResult.push_back(caseQueue.deleteMin()); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	myResult.push_back(caseQueue.deleteMin()); //10
	caseQueue.insert(97254,39193);
	caseQueue.updatePriority(97254, 66669);
	caseQueue.insert(30488,64064);
	caseQueue.insert(42580,60914);
	myResult.push_back(caseQueue.getPriority(97254)); //11
	caseQueue.updatePriority(42580, 32563);
	caseQueue.insert(34497,53683);
	myResult.push_back(caseQueue.getPriority(42580)); //12
	caseQueue.updatePriority(97254, 9170);
	caseQueue.insert(8891,19360);
	caseQueue.insert(30767,26676);
	myResult.push_back(caseQueue.getPriority(97254)); //13
	static const int resultListArray[] = {-1, -1, 44276, 83029, 32480, 14358, 34435, 55240, 64257, 24841, 66669, 32563, 9170}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(20): Basarili" << endl;
	else cout << "Case(20): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_21(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 21);

	vector<int> myResult; 
	caseQueue.insert(5206,76252);
	myResult.push_back(caseQueue.getPriority(5206)); //1
	caseQueue.updatePriority(5206, 96495);
	caseQueue.insert(98506,41755);
	myResult.push_back(caseQueue.getPriority(98506)); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(28884,96210);
	myResult.push_back(caseQueue.getPriority(28884)); //5
	caseQueue.insert(60994,23737);
	myResult.push_back(caseQueue.getPriority(28884)); //6
	myResult.push_back(caseQueue.getPriority(60994)); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.updatePriority(28884, 49563);
	caseQueue.insert(16458,4348);
	myResult.push_back(caseQueue.getPriority(28884)); //9
	caseQueue.updatePriority(28884, 41093);
	caseQueue.updatePriority(16458, 2130);
	caseQueue.insert(10337,84677);
	caseQueue.updatePriority(16458, 15780);
	myResult.push_back(caseQueue.getPriority(10337)); //10
	static const int resultListArray[] = {76252, 41755, 98506, 5206, 96210, 96210, 23737, 60994, 49563, 84677}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(21): Basarili" << endl;
	else cout << "Case(21): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_22(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 15);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(52341, 88607);
	caseQueue.updatePriority(86685, 18092);
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.getPriority(1450)); //3
	caseQueue.insert(36817,68979);
	myResult.push_back(caseQueue.getPriority(36817)); //4
	myResult.push_back(caseQueue.getPriority(36817)); //5
	caseQueue.updatePriority(36817, 76722);
	caseQueue.updatePriority(36817, 81933);
	caseQueue.updatePriority(36817, 63469);
	myResult.push_back(caseQueue.getPriority(36817)); //6
	myResult.push_back(caseQueue.getPriority(36817)); //7
	caseQueue.updatePriority(36817, 82869);
	caseQueue.insert(14124,77287);
	static const int resultListArray[] = {-1, -1, -1, 68979, 68979, 63469, 63469}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(22): Basarili" << endl;
	else cout << "Case(22): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_23(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 19);

	vector<int> myResult; 
	caseQueue.insert(90258,16883);
	caseQueue.insert(62131,27814);
	caseQueue.insert(50505,38360);
	myResult.push_back(caseQueue.getPriority(90258)); //1
	myResult.push_back(caseQueue.getPriority(50505)); //2
	caseQueue.insert(66291,34682);
	myResult.push_back(caseQueue.getPriority(50505)); //3
	caseQueue.insert(61683,26208);
	caseQueue.insert(1704,8482);
	caseQueue.updatePriority(50505, 33380);
	caseQueue.insert(70873,98508);
	myResult.push_back(caseQueue.getPriority(61683)); //4
	myResult.push_back(caseQueue.getPriority(50505)); //5
	caseQueue.updatePriority(66291, 53198);
	caseQueue.insert(82408,84154);
	caseQueue.insert(24364,93184);
	caseQueue.insert(12790,22791);
	myResult.push_back(caseQueue.getPriority(24364)); //6
	myResult.push_back(caseQueue.getPriority(62131)); //7
	static const int resultListArray[] = {16883, 38360, 38360, 26208, 33380, 93184, 27814}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(23): Basarili" << endl;
	else cout << "Case(23): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_24(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 23);

	vector<int> myResult; 
	caseQueue.updatePriority(14216, 55574);
	caseQueue.insert(67757,91864);
	myResult.push_back(caseQueue.getPriority(67757)); //1
	caseQueue.insert(60217,59071);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(83017,58499);
	caseQueue.insert(80374,72287);
	myResult.push_back(caseQueue.getPriority(83017)); //3
	myResult.push_back(caseQueue.getPriority(83017)); //4
	caseQueue.insert(70405,64908);
	caseQueue.insert(705,28760);
	caseQueue.insert(95060,30990);
	caseQueue.updatePriority(67757, 30767);
	myResult.push_back(caseQueue.getPriority(67757)); //5
	myResult.push_back(caseQueue.getPriority(705)); //6
	myResult.push_back(caseQueue.getPriority(95060)); //7
	caseQueue.insert(11501,22999);
	caseQueue.insert(14884,39405);
	caseQueue.updatePriority(67757, 42107);
	caseQueue.insert(70048,23856);
	caseQueue.insert(51863,32330);
	myResult.push_back(caseQueue.getPriority(11501)); //8
	caseQueue.insert(22893,39929);
	static const int resultListArray[] = {91864, 60217, 58499, 58499, 30767, 28760, 30990, 22999}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(24): Basarili" << endl;
	else cout << "Case(24): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_25(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 32);

	vector<int> myResult; 
	caseQueue.insert(30543,45865);
	caseQueue.insert(53171,63582);
	caseQueue.insert(68787,41864);
	caseQueue.updatePriority(53171, 14497);
	caseQueue.updatePriority(53171, 31140);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(49254,19001);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(67436,1810);
	myResult.push_back(caseQueue.getPriority(67436)); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.updatePriority(30543, 24052);
	caseQueue.insert(83125,84243);
	caseQueue.updatePriority(83125, 19912);
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	myResult.push_back(caseQueue.getPriority(12233)); //9
	caseQueue.updatePriority(38953, 97121);
	myResult.push_back(caseQueue.getPriority(79576)); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.getPriority(90107)); //12
	myResult.push_back(caseQueue.getPriority(47999)); //13
	caseQueue.insert(81761,9437);
	caseQueue.insert(62005,59500);
	myResult.push_back(caseQueue.getPriority(62005)); //14
	myResult.push_back(caseQueue.deleteMin()); //15
	caseQueue.insert(49837,67324);
	caseQueue.insert(36931,21407);
	caseQueue.insert(75894,14491);
	myResult.push_back(caseQueue.getPriority(36931)); //16
	static const int resultListArray[] = {53171, 49254, 1810, 67436, 68787, 83125, 30543, -1, -1, -1, -1, -1, -1, 59500, 81761, 21407}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(25): Basarili" << endl;
	else cout << "Case(25): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_26(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 31);

	vector<int> myResult; 
	caseQueue.insert(26452,53650);
	caseQueue.updatePriority(26452, 84163);
	caseQueue.insert(4046,38253);
	caseQueue.updatePriority(26452, 13042);
	caseQueue.insert(66954,11567);
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.getPriority(4046)); //2
	myResult.push_back(caseQueue.getPriority(26452)); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.getPriority(4046)); //5
	caseQueue.insert(11700,80511);
	caseQueue.updatePriority(4046, 61722);
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.insert(9314,99708);
	myResult.push_back(caseQueue.getPriority(9314)); //7
	caseQueue.insert(36357,13988);
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(54016,78392);
	caseQueue.updatePriority(11700, 46232);
	myResult.push_back(caseQueue.getPriority(54016)); //9
	caseQueue.insert(30249,17549);
	caseQueue.updatePriority(30249, 93969);
	caseQueue.insert(2188,35266);
	caseQueue.updatePriority(11700, 81663);
	caseQueue.updatePriority(54016, 61463);
	myResult.push_back(caseQueue.getPriority(9314)); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(81010,61914);
	caseQueue.insert(27701,6423);
	myResult.push_back(caseQueue.getPriority(30249)); //12
	myResult.push_back(caseQueue.getPriority(54016)); //13
	static const int resultListArray[] = {66954, 38253, 13042, 26452, 38253, 4046, 99708, 36357, 78392, 99708, 2188, 93969, 61463}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(26): Basarili" << endl;
	else cout << "Case(26): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_27(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 13);

	vector<int> myResult; 
	caseQueue.insert(88004,28734);
	myResult.push_back(caseQueue.getPriority(88004)); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.updatePriority(32209, 49890);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.updatePriority(30777, 75525);
	caseQueue.insert(18625,73592);
	myResult.push_back(caseQueue.getPriority(18625)); //4
	myResult.push_back(caseQueue.getPriority(18625)); //5
	caseQueue.updatePriority(18625, 19666);
	myResult.push_back(caseQueue.getPriority(18625)); //6
	myResult.push_back(caseQueue.getPriority(18625)); //7
	caseQueue.insert(1951,30136);
	static const int resultListArray[] = {28734, 88004, -1, 73592, 73592, 19666, 19666}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(27): Basarili" << endl;
	else cout << "Case(27): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_28(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 27);

	vector<int> myResult; 
	caseQueue.insert(93927,24385);
	myResult.push_back(caseQueue.getPriority(93927)); //1
	caseQueue.updatePriority(93927, 87250);
	caseQueue.insert(54980,17536);
	caseQueue.insert(63875,52257);
	caseQueue.insert(72184,59297);
	caseQueue.updatePriority(93927, 40185);
	caseQueue.updatePriority(63875, 59025);
	myResult.push_back(caseQueue.getPriority(93927)); //2
	myResult.push_back(caseQueue.getPriority(72184)); //3
	myResult.push_back(caseQueue.getPriority(72184)); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(13253,66987);
	myResult.push_back(caseQueue.getPriority(93927)); //6
	myResult.push_back(caseQueue.getPriority(63875)); //7
	myResult.push_back(caseQueue.getPriority(72184)); //8
	myResult.push_back(caseQueue.getPriority(72184)); //9
	caseQueue.updatePriority(63875, 61915);
	caseQueue.updatePriority(72184, 17649);
	caseQueue.insert(65192,37512);
	myResult.push_back(caseQueue.getPriority(13253)); //10
	caseQueue.insert(69485,28882);
	caseQueue.insert(52043,40908);
	myResult.push_back(caseQueue.getPriority(65192)); //11
	caseQueue.insert(91952,49115);
	caseQueue.updatePriority(13253, 10416);
	caseQueue.insert(26871,52459);
	static const int resultListArray[] = {24385, 40185, 59297, 59297, 54980, 40185, 59025, 59297, 59297, 66987, 37512}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(28): Basarili" << endl;
	else cout << "Case(28): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_29(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 13);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(97707,20842);
	caseQueue.insert(85851,93935);
	caseQueue.updatePriority(85851, 25598);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.updatePriority(85851, 26926);
	caseQueue.updatePriority(85851, 25832);
	caseQueue.updatePriority(85851, 36804);
	myResult.push_back(caseQueue.getPriority(85851)); //3
	caseQueue.updatePriority(85851, 78727);
	caseQueue.insert(70871,5018);
	caseQueue.insert(45912,9356);
	caseQueue.insert(10403,85688);
	static const int resultListArray[] = {-1, 97707, 36804}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(29): Basarili" << endl;
	else cout << "Case(29): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_30(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 50);

	vector<int> myResult; 
	caseQueue.updatePriority(32249, 27732);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(38724,74148);
	myResult.push_back(caseQueue.getPriority(38724)); //2
	caseQueue.insert(63860,3159);
	caseQueue.insert(60298,49231);
	myResult.push_back(caseQueue.getPriority(38724)); //3
	caseQueue.insert(16746,29805);
	myResult.push_back(caseQueue.getPriority(60298)); //4
	caseQueue.insert(80378,69513);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(63026,60243);
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.updatePriority(80378, 88929);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.insert(25834,22169);
	caseQueue.updatePriority(38724, 88851);
	myResult.push_back(caseQueue.getPriority(25834)); //8
	caseQueue.insert(65206,67809);
	myResult.push_back(caseQueue.getPriority(25834)); //9
	caseQueue.insert(56320,56510);
	caseQueue.insert(57068,14254);
	myResult.push_back(caseQueue.getPriority(63026)); //10
	caseQueue.updatePriority(38724, 2931);
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(16948,32427);
	caseQueue.insert(9239,42732);
	caseQueue.insert(61899,9884);
	myResult.push_back(caseQueue.getPriority(25834)); //12
	caseQueue.insert(89583,48861);
	caseQueue.updatePriority(80378, 91826);
	caseQueue.updatePriority(65206, 49552);
	myResult.push_back(caseQueue.getPriority(56320)); //13
	caseQueue.insert(13398,70238);
	caseQueue.insert(36021,23060);
	myResult.push_back(caseQueue.deleteMin()); //14
	myResult.push_back(caseQueue.deleteMin()); //15
	myResult.push_back(caseQueue.getPriority(80378)); //16
	caseQueue.insert(69417,49670);
	myResult.push_back(caseQueue.deleteMin()); //17
	caseQueue.insert(72900,5277);
	caseQueue.insert(6918,85650);
	caseQueue.updatePriority(80378, 78490);
	caseQueue.insert(63992,6611);
	myResult.push_back(caseQueue.getPriority(65206)); //18
	caseQueue.updatePriority(16948, 93254);
	caseQueue.insert(10385,88863);
	myResult.push_back(caseQueue.deleteMin()); //19
	caseQueue.insert(68199,46488);
	myResult.push_back(caseQueue.deleteMin()); //20
	static const int resultListArray[] = {-1, 74148, 74148, 49231, 63860, 16746, 60298, 22169, 22169, 60243, 38724, 22169, 56510, 61899, 57068, 91826, 25834, 49552, 72900, 63992}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(30): Basarili" << endl;
	else cout << "Case(30): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_31(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 17);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.getPriority(90038)); //3
	caseQueue.insert(50348,46755);
	myResult.push_back(caseQueue.getPriority(50348)); //4
	caseQueue.insert(56344,61861);
	myResult.push_back(caseQueue.getPriority(50348)); //5
	caseQueue.insert(2419,79253);
	caseQueue.updatePriority(2419, 12269);
	caseQueue.updatePriority(2419, 52493);
	myResult.push_back(caseQueue.getPriority(2419)); //6
	caseQueue.insert(31665,95297);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(2419, 54267);
	myResult.push_back(caseQueue.deleteMin()); //8
	myResult.push_back(caseQueue.getPriority(56344)); //9
	caseQueue.updatePriority(31665, 61133);
	static const int resultListArray[] = {-1, -1, -1, 46755, 46755, 52493, 50348, 2419, 61861}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(31): Basarili" << endl;
	else cout << "Case(31): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_32(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 40);

	vector<int> myResult; 
	caseQueue.insert(89948,17631);
	myResult.push_back(caseQueue.getPriority(89948)); //1
	myResult.push_back(caseQueue.getPriority(89948)); //2
	caseQueue.insert(23775,75086);
	caseQueue.insert(62878,80388);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(32543,74608);
	caseQueue.updatePriority(32543, 2160);
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.insert(70170,55674);
	caseQueue.insert(40754,59643);
	caseQueue.insert(66031,97260);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(66031, 56224);
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(11664,97718);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.insert(82940,32844);
	caseQueue.insert(62285,23987);
	myResult.push_back(caseQueue.deleteMin()); //10
	caseQueue.insert(19327,38017);
	caseQueue.updatePriority(82940, 39909);
	caseQueue.insert(48527,8258);
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(78406,64050);
	caseQueue.updatePriority(19327, 28954);
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.insert(91589,97456);
	myResult.push_back(caseQueue.deleteMin()); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	myResult.push_back(caseQueue.getPriority(11664)); //15
	caseQueue.updatePriority(91589, 207);
	caseQueue.updatePriority(91589, 72714);
	myResult.push_back(caseQueue.getPriority(11664)); //16
	myResult.push_back(caseQueue.deleteMin()); //17
	caseQueue.insert(76886,18755);
	myResult.push_back(caseQueue.getPriority(76886)); //18
	caseQueue.insert(8292,4281);
	static const int resultListArray[] = {17631, 17631, 89948, 32543, 23775, 62878, 70170, 66031, 40754, 62285, 48527, 19327, 82940, 78406, 97718, 97718, 91589, 18755}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(32): Basarili" << endl;
	else cout << "Case(32): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_33(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 41);

	vector<int> myResult; 
	caseQueue.insert(18950,89769);
	caseQueue.insert(5739,85746);
	myResult.push_back(caseQueue.getPriority(18950)); //1
	myResult.push_back(caseQueue.getPriority(18950)); //2
	myResult.push_back(caseQueue.getPriority(18950)); //3
	caseQueue.insert(36780,17925);
	caseQueue.insert(63016,15613);
	myResult.push_back(caseQueue.getPriority(63016)); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.getPriority(5739)); //6
	myResult.push_back(caseQueue.getPriority(36780)); //7
	caseQueue.insert(54976,89405);
	caseQueue.insert(18959,78350);
	caseQueue.insert(63452,9438);
	caseQueue.insert(5211,96061);
	caseQueue.updatePriority(18959, 84864);
	myResult.push_back(caseQueue.getPriority(18959)); //8
	myResult.push_back(caseQueue.getPriority(36780)); //9
	caseQueue.insert(8800,70822);
	caseQueue.insert(56603,58887);
	myResult.push_back(caseQueue.getPriority(63452)); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.updatePriority(18950, 5024);
	myResult.push_back(caseQueue.getPriority(56603)); //13
	caseQueue.insert(65398,36442);
	caseQueue.updatePriority(18959, 48221);
	caseQueue.insert(91237,67997);
	caseQueue.updatePriority(18959, 62401);
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.insert(72698,39533);
	myResult.push_back(caseQueue.deleteMin()); //15
	myResult.push_back(caseQueue.getPriority(5739)); //16
	myResult.push_back(caseQueue.deleteMin()); //17
	myResult.push_back(caseQueue.getPriority(91237)); //18
	caseQueue.updatePriority(54976, 78530);
	myResult.push_back(caseQueue.getPriority(91237)); //19
	caseQueue.updatePriority(56603, 25556);
	myResult.push_back(caseQueue.deleteMin()); //20
	caseQueue.updatePriority(5739, 78255);
	myResult.push_back(caseQueue.getPriority(18959)); //21
	static const int resultListArray[] = {89769, 89769, 89769, 15613, 63016, 85746, 17925, 84864, 17925, 9438, 63452, 36780, 58887, 18950, 65398, 85746, 72698, 67997, 67997, 56603, 62401}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(33): Basarili" << endl;
	else cout << "Case(33): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_34(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 31);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(42793)); //1
	caseQueue.updatePriority(94380, 59560);
	caseQueue.insert(4634,93255);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.updatePriority(33199, 93872);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(93653,83167);
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.getPriority(42352)); //5
	myResult.push_back(caseQueue.getPriority(79788)); //6
	caseQueue.updatePriority(81522, 2282);
	caseQueue.insert(21284,36027);
	myResult.push_back(caseQueue.getPriority(21284)); //7
	caseQueue.updatePriority(21284, 51025);
	caseQueue.insert(50471,88632);
	caseQueue.insert(54481,26599);
	myResult.push_back(caseQueue.deleteMin()); //8
	myResult.push_back(caseQueue.getPriority(50471)); //9
	caseQueue.insert(31995,19448);
	caseQueue.insert(48139,31395);
	caseQueue.updatePriority(50471, 29245);
	myResult.push_back(caseQueue.deleteMin()); //10
	myResult.push_back(caseQueue.getPriority(21284)); //11
	caseQueue.insert(28063,23139);
	caseQueue.insert(51567,4490);
	caseQueue.insert(28606,65520);
	caseQueue.insert(58414,22823);
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.updatePriority(50471, 38753);
	caseQueue.updatePriority(50471, 56333);
	caseQueue.insert(18585,16559);
	static const int resultListArray[] = {-1, 4634, -1, 93653, -1, -1, 36027, 54481, 88632, 31995, 51025, 51567}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(34): Basarili" << endl;
	else cout << "Case(34): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_35(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 16);

	vector<int> myResult; 
	caseQueue.insert(39026,84137);
	caseQueue.insert(44293,26424);
	caseQueue.insert(88996,22776);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(96140,7187);
	caseQueue.updatePriority(96140, 30788);
	caseQueue.insert(72997,81547);
	caseQueue.insert(97195,26317);
	myResult.push_back(caseQueue.getPriority(97195)); //2
	caseQueue.updatePriority(96140, 49230);
	caseQueue.insert(99012,57539);
	caseQueue.updatePriority(39026, 60221);
	caseQueue.insert(39425,85844);
	caseQueue.insert(68586,95026);
	myResult.push_back(caseQueue.getPriority(68586)); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	static const int resultListArray[] = {88996, 26317, 95026, 97195}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(35): Basarili" << endl;
	else cout << "Case(35): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_36(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 49);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(86661)); //1
	caseQueue.insert(50906,56421);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.updatePriority(52068, 43588);
	caseQueue.updatePriority(70609, 51470);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(46276,13329);
	caseQueue.insert(7765,6456);
	caseQueue.updatePriority(46276, 23230);
	caseQueue.insert(19025,38840);
	myResult.push_back(caseQueue.getPriority(19025)); //4
	myResult.push_back(caseQueue.getPriority(7765)); //5
	caseQueue.insert(57831,82940);
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.getPriority(19025)); //7
	caseQueue.insert(13216,18883);
	caseQueue.insert(23847,41186);
	myResult.push_back(caseQueue.deleteMin()); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(57831, 25352);
	myResult.push_back(caseQueue.getPriority(23847)); //10
	myResult.push_back(caseQueue.getPriority(23847)); //11
	caseQueue.insert(25963,61091);
	myResult.push_back(caseQueue.deleteMin()); //12
	myResult.push_back(caseQueue.deleteMin()); //13
	caseQueue.updatePriority(25963, 39252);
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.insert(57773,58831);
	myResult.push_back(caseQueue.getPriority(23847)); //15
	caseQueue.updatePriority(57773, 10306);
	myResult.push_back(caseQueue.getPriority(57773)); //16
	caseQueue.insert(66758,38202);
	myResult.push_back(caseQueue.deleteMin()); //17
	caseQueue.insert(89117,68178);
	caseQueue.updatePriority(23847, 31968);
	myResult.push_back(caseQueue.deleteMin()); //18
	myResult.push_back(caseQueue.deleteMin()); //19
	caseQueue.insert(90117,33501);
	caseQueue.updatePriority(89117, 31066);
	caseQueue.updatePriority(89117, 94193);
	caseQueue.updatePriority(89117, 55440);
	caseQueue.insert(7811,28535);
	caseQueue.updatePriority(89117, 45067);
	caseQueue.insert(33763,95094);
	caseQueue.insert(38293,69641);
	myResult.push_back(caseQueue.getPriority(90117)); //20
	caseQueue.updatePriority(33763, 3727);
	caseQueue.updatePriority(7811, 90709);
	myResult.push_back(caseQueue.deleteMin()); //21
	static const int resultListArray[] = {-1, 50906, -1, 38840, 6456, 7765, 38840, 13216, 46276, 41186, 41186, 57831, 19025, 25963, 41186, 10306, 57773, 23847, 66758, 33501, 33763}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(36): Basarili" << endl;
	else cout << "Case(36): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_37(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 36);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(1853,14059);
	caseQueue.insert(85595,17928);
	caseQueue.insert(4960,36659);
	myResult.push_back(caseQueue.getPriority(1853)); //2
	caseQueue.insert(62925,6763);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(70572,93610);
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.getPriority(70572)); //6
	caseQueue.insert(76580,4904);
	caseQueue.updatePriority(76580, 60920);
	caseQueue.insert(56990,98874);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(56990, 60092);
	caseQueue.insert(70097,22982);
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.updatePriority(76580, 57749);
	caseQueue.insert(86767,80146);
	caseQueue.updatePriority(86767, 32567);
	caseQueue.updatePriority(76580, 22411);
	caseQueue.insert(42304,54173);
	caseQueue.insert(34082,17085);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(76580, 63381);
	myResult.push_back(caseQueue.getPriority(70572)); //10
	myResult.push_back(caseQueue.getPriority(42304)); //11
	caseQueue.insert(22444,21327);
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.updatePriority(70572, 45128);
	myResult.push_back(caseQueue.deleteMin()); //13
	caseQueue.insert(83457,81243);
	myResult.push_back(caseQueue.deleteMin()); //14
	myResult.push_back(caseQueue.deleteMin()); //15
	caseQueue.updatePriority(83457, 36319);
	static const int resultListArray[] = {-1, 14059, 62925, 1853, 85595, 93610, 4960, 70097, 34082, 93610, 54173, 22444, 86767, 70572, 42304}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(37): Basarili" << endl;
	else cout << "Case(37): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_38(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 40);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(74660)); //1
	caseQueue.updatePriority(26849, 83083);
	caseQueue.updatePriority(23286, 90150);
	caseQueue.insert(48744,85023);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(80411,38418);
	caseQueue.insert(21674,52484);
	caseQueue.insert(83472,60371);
	caseQueue.updatePriority(21674, 90817);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.updatePriority(83472, 33928);
	caseQueue.updatePriority(21674, 31365);
	myResult.push_back(caseQueue.getPriority(83472)); //4
	myResult.push_back(caseQueue.getPriority(21674)); //5
	caseQueue.updatePriority(21674, 6076);
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.insert(39373,1351);
	caseQueue.insert(77544,36630);
	caseQueue.insert(54515,8764);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(54515, 77616);
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(69112,55096);
	myResult.push_back(caseQueue.deleteMin()); //9
	myResult.push_back(caseQueue.getPriority(69112)); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(13639,13383);
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.insert(56271,33786);
	caseQueue.updatePriority(56271, 4800);
	caseQueue.insert(9001,85839);
	myResult.push_back(caseQueue.getPriority(54515)); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	myResult.push_back(caseQueue.deleteMin()); //15
	caseQueue.insert(44706,70616);
	myResult.push_back(caseQueue.getPriority(9001)); //16
	caseQueue.updatePriority(9001, 78897);
	caseQueue.insert(46428,15962);
	caseQueue.insert(4711,15084);
	caseQueue.updatePriority(9001, 22088);
	static const int resultListArray[] = {-1, 48744, 80411, 33928, 31365, 21674, 39373, 83472, 77544, 55096, 69112, 13639, 77616, 56271, 54515, 85839}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(38): Basarili" << endl;
	else cout << "Case(38): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_39(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 39);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(5480,20857);
	caseQueue.updatePriority(5480, 80467);
	caseQueue.insert(51388,17724);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(47709,42266);
	myResult.push_back(caseQueue.getPriority(5480)); //3
	caseQueue.updatePriority(47709, 83656);
	caseQueue.insert(78737,17117);
	myResult.push_back(caseQueue.getPriority(78737)); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(58660,7183);
	caseQueue.insert(42899,59017);
	caseQueue.updatePriority(5480, 70863);
	caseQueue.updatePriority(42899, 9596);
	caseQueue.insert(84329,62204);
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.insert(96996,55654);
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(52971,98121);
	myResult.push_back(caseQueue.getPriority(52971)); //9
	myResult.push_back(caseQueue.deleteMin()); //10
	caseQueue.updatePriority(52971, 2411);
	caseQueue.updatePriority(47709, 10824);
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.getPriority(47709)); //12
	caseQueue.insert(69292,19090);
	myResult.push_back(caseQueue.deleteMin()); //13
	myResult.push_back(caseQueue.getPriority(69292)); //14
	myResult.push_back(caseQueue.deleteMin()); //15
	caseQueue.updatePriority(5480, 32476);
	caseQueue.updatePriority(5480, 69349);
	myResult.push_back(caseQueue.getPriority(5480)); //16
	caseQueue.insert(26374,10127);
	myResult.push_back(caseQueue.deleteMin()); //17
	caseQueue.insert(36305,80171);
	caseQueue.updatePriority(5480, 78661);
	caseQueue.updatePriority(5480, 45859);
	static const int resultListArray[] = {-1, 51388, 80467, 17117, 78737, 58660, 42899, 96996, 98121, 84329, 52971, 10824, 47709, 19090, 69292, 69349, 26374}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(39): Basarili" << endl;
	else cout << "Case(39): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_40(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 14);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(90148)); //1
	myResult.push_back(caseQueue.getPriority(22222)); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	myResult.push_back(caseQueue.getPriority(58211)); //4
	caseQueue.updatePriority(63739, 45097);
	caseQueue.insert(17973,81416);
	caseQueue.insert(33683,89686);
	myResult.push_back(caseQueue.getPriority(33683)); //5
	myResult.push_back(caseQueue.getPriority(33683)); //6
	caseQueue.insert(11787,70930);
	caseQueue.insert(50356,51580);
	caseQueue.insert(98518,64667);
	caseQueue.updatePriority(11787, 8332);
	caseQueue.updatePriority(33683, 73398);
	static const int resultListArray[] = {-1, -1, -1, -1, 89686, 89686}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(40): Basarili" << endl;
	else cout << "Case(40): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_41(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 25);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.getPriority(95074)); //2
	myResult.push_back(caseQueue.getPriority(98318)); //3
	caseQueue.updatePriority(77751, 96138);
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.updatePriority(58431, 19692);
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.getPriority(86515)); //6
	myResult.push_back(caseQueue.getPriority(81701)); //7
	caseQueue.insert(71771,86016);
	myResult.push_back(caseQueue.deleteMin()); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(4660, 72550);
	caseQueue.updatePriority(70203, 4111);
	myResult.push_back(caseQueue.getPriority(85348)); //10
	myResult.push_back(caseQueue.getPriority(98837)); //11
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.updatePriority(98235, 15970);
	caseQueue.insert(70418,24154);
	myResult.push_back(caseQueue.getPriority(70418)); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.insert(62687,49146);
	myResult.push_back(caseQueue.deleteMin()); //15
	myResult.push_back(caseQueue.deleteMin()); //16
	caseQueue.insert(2279,23263);
	static const int resultListArray[] = {-1, -1, -1, -1, -1, -1, -1, 71771, -1, -1, -1, -1, 24154, 70418, 62687, -1}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(41): Basarili" << endl;
	else cout << "Case(41): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_42(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 38);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(53601)); //1
	myResult.push_back(caseQueue.getPriority(6635)); //2
	caseQueue.insert(86354,28507);
	caseQueue.insert(97126,95787);
	myResult.push_back(caseQueue.getPriority(97126)); //3
	caseQueue.insert(72715,68528);
	myResult.push_back(caseQueue.getPriority(97126)); //4
	caseQueue.insert(51764,11340);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(32558,4831);
	caseQueue.insert(18780,18250);
	caseQueue.insert(67291,5870);
	caseQueue.updatePriority(32558, 85872);
	caseQueue.updatePriority(72715, 50424);
	caseQueue.updatePriority(32558, 12781);
	caseQueue.insert(16105,29827);
	caseQueue.insert(90279,57066);
	myResult.push_back(caseQueue.getPriority(18780)); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.getPriority(90279)); //8
	caseQueue.insert(82825,52737);
	caseQueue.updatePriority(16105, 35503);
	caseQueue.updatePriority(97126, 85474);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(18780, 27654);
	myResult.push_back(caseQueue.getPriority(86354)); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.getPriority(97126)); //12
	caseQueue.insert(62744,38932);
	myResult.push_back(caseQueue.getPriority(72715)); //13
	caseQueue.updatePriority(90279, 55402);
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.updatePriority(82825, 23799);
	caseQueue.updatePriority(72715, 26241);
	caseQueue.insert(83618,10384);
	caseQueue.insert(64380,2702);
	caseQueue.insert(50950,78215);
	myResult.push_back(caseQueue.getPriority(16105)); //15
	static const int resultListArray[] = {-1, -1, 95787, 95787, 51764, 18250, 67291, 57066, 32558, 28507, 18780, 85474, 50424, 86354, 35503}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(42): Basarili" << endl;
	else cout << "Case(42): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_43(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 12);

	vector<int> myResult; 
	caseQueue.insert(76177,23251);
	caseQueue.updatePriority(76177, 51388);
	caseQueue.insert(56911,93883);
	caseQueue.insert(34050,11900);
	myResult.push_back(caseQueue.getPriority(34050)); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.getPriority(76177)); //3
	caseQueue.insert(22397,26349);
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(66823,55414);
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	static const int resultListArray[] = {11900, 34050, 51388, 22397, 76177, 66823}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(43): Basarili" << endl;
	else cout << "Case(43): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_44(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 21);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(18824,96811);
	caseQueue.insert(1984,5576);
	myResult.push_back(caseQueue.getPriority(18824)); //2
	caseQueue.updatePriority(1984, 24040);
	caseQueue.updatePriority(1984, 23344);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(13833,45061);
	myResult.push_back(caseQueue.getPriority(13833)); //4
	caseQueue.updatePriority(13833, 3074);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(76020,74059);
	caseQueue.insert(37815,83977);
	myResult.push_back(caseQueue.getPriority(18824)); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(37815, 49923);
	caseQueue.updatePriority(37815, 37427);
	caseQueue.insert(81247,4970);
	caseQueue.insert(62648,50042);
	caseQueue.insert(93367,35490);
	caseQueue.updatePriority(37815, 2273);
	static const int resultListArray[] = {-1, 96811, 1984, 45061, 13833, 96811, 76020}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(44): Basarili" << endl;
	else cout << "Case(44): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_45(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 21);

	vector<int> myResult; 
	caseQueue.updatePriority(71322, 29310);
	caseQueue.insert(22941,42055);
	caseQueue.insert(47423,74340);
	caseQueue.insert(34843,46013);
	myResult.push_back(caseQueue.getPriority(47423)); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(53904,11674);
	myResult.push_back(caseQueue.getPriority(47423)); //3
	caseQueue.updatePriority(34843, 85938);
	caseQueue.insert(19554,90463);
	caseQueue.insert(20648,28340);
	myResult.push_back(caseQueue.getPriority(47423)); //4
	caseQueue.updatePriority(19554, 52597);
	myResult.push_back(caseQueue.getPriority(19554)); //5
	caseQueue.insert(45170,57091);
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.insert(50508,71546);
	caseQueue.insert(20478,58112);
	caseQueue.insert(76416,20754);
	myResult.push_back(caseQueue.deleteMin()); //8
	static const int resultListArray[] = {74340, 22941, 74340, 74340, 52597, 53904, 20648, 76416}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(45): Basarili" << endl;
	else cout << "Case(45): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_46(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 24);

	vector<int> myResult; 
	caseQueue.insert(35612,84576);
	caseQueue.insert(30601,98077);
	caseQueue.insert(9429,88498);
	myResult.push_back(caseQueue.getPriority(35612)); //1
	caseQueue.insert(252,29005);
	caseQueue.updatePriority(30601, 45512);
	caseQueue.updatePriority(30601, 38855);
	caseQueue.insert(49094,41907);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.updatePriority(49094, 30564);
	caseQueue.insert(18619,16741);
	caseQueue.insert(15645,95798);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(81679,61583);
	myResult.push_back(caseQueue.getPriority(9429)); //4
	caseQueue.insert(2957,62777);
	caseQueue.updatePriority(81679, 69630);
	myResult.push_back(caseQueue.getPriority(81679)); //5
	myResult.push_back(caseQueue.getPriority(30601)); //6
	myResult.push_back(caseQueue.getPriority(81679)); //7
	myResult.push_back(caseQueue.getPriority(9429)); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.insert(96573,14692);
	myResult.push_back(caseQueue.deleteMin()); //10
	static const int resultListArray[] = {84576, 252, 18619, 88498, 69630, 38855, 69630, 88498, 49094, 96573}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(46): Basarili" << endl;
	else cout << "Case(46): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_47(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 40);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.updatePriority(38305, 95112);
	caseQueue.insert(95981,17381);
	caseQueue.insert(24569,7381);
	caseQueue.insert(36804,66038);
	caseQueue.insert(72157,96229);
	caseQueue.insert(92320,53430);
	myResult.push_back(caseQueue.getPriority(36804)); //3
	caseQueue.insert(61178,64764);
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.getPriority(92320)); //5
	myResult.push_back(caseQueue.getPriority(92320)); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.getPriority(72157)); //8
	caseQueue.insert(14573,15472);
	myResult.push_back(caseQueue.getPriority(36804)); //9
	myResult.push_back(caseQueue.getPriority(92320)); //10
	myResult.push_back(caseQueue.getPriority(36804)); //11
	caseQueue.insert(34231,33077);
	caseQueue.insert(22067,22506);
	caseQueue.updatePriority(34231, 5992);
	caseQueue.insert(85765,66902);
	myResult.push_back(caseQueue.getPriority(85765)); //12
	caseQueue.updatePriority(34231, 27881);
	myResult.push_back(caseQueue.deleteMin()); //13
	caseQueue.insert(55400,46805);
	myResult.push_back(caseQueue.deleteMin()); //14
	myResult.push_back(caseQueue.deleteMin()); //15
	myResult.push_back(caseQueue.deleteMin()); //16
	caseQueue.insert(58437,94760);
	caseQueue.insert(33182,63270);
	myResult.push_back(caseQueue.deleteMin()); //17
	caseQueue.insert(72695,94909);
	caseQueue.insert(50481,16013);
	caseQueue.insert(19699,86316);
	myResult.push_back(caseQueue.getPriority(50481)); //18
	myResult.push_back(caseQueue.getPriority(61178)); //19
	caseQueue.updatePriority(85765, 82662);
	caseQueue.insert(84317,91470);
	static const int resultListArray[] = {-1, -1, 66038, 24569, 53430, 53430, 95981, 96229, 66038, 53430, 66038, 66902, 14573, 22067, 34231, 55400, 92320, 16013, 64764}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(47): Basarili" << endl;
	else cout << "Case(47): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_48(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 11);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(6970,85847);
	caseQueue.insert(2929,82023);
	caseQueue.updatePriority(6970, 10821);
	caseQueue.updatePriority(6970, 29556);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(2083,63912);
	caseQueue.insert(59334,17454);
	caseQueue.updatePriority(59334, 2729);
	myResult.push_back(caseQueue.getPriority(2929)); //3
	caseQueue.insert(34753,70676);
	static const int resultListArray[] = {-1, 6970, 82023}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(48): Basarili" << endl;
	else cout << "Case(48): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_49(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 33);

	vector<int> myResult; 
	caseQueue.insert(84188,54104);
	caseQueue.updatePriority(84188, 13508);
	caseQueue.insert(40814,2464);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(84188, 52410);
	myResult.push_back(caseQueue.getPriority(84188)); //2
	myResult.push_back(caseQueue.getPriority(84188)); //3
	myResult.push_back(caseQueue.getPriority(84188)); //4
	caseQueue.updatePriority(84188, 90041);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.updatePriority(93711, 47214);
	myResult.push_back(caseQueue.getPriority(91837)); //6
	caseQueue.insert(72501,35717);
	caseQueue.insert(31245,96460);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.insert(30625,84884);
	myResult.push_back(caseQueue.getPriority(31245)); //8
	caseQueue.insert(20998,11402);
	myResult.push_back(caseQueue.getPriority(20998)); //9
	myResult.push_back(caseQueue.getPriority(31245)); //10
	myResult.push_back(caseQueue.getPriority(20998)); //11
	myResult.push_back(caseQueue.getPriority(31245)); //12
	myResult.push_back(caseQueue.deleteMin()); //13
	caseQueue.insert(61631,7087);
	caseQueue.insert(8167,27553);
	caseQueue.insert(7868,53855);
	caseQueue.updatePriority(8167, 95320);
	caseQueue.insert(87889,17890);
	caseQueue.updatePriority(30625, 68898);
	myResult.push_back(caseQueue.getPriority(31245)); //14
	caseQueue.updatePriority(31245, 29904);
	myResult.push_back(caseQueue.deleteMin()); //15
	myResult.push_back(caseQueue.getPriority(31245)); //16
	static const int resultListArray[] = {40814, 52410, 52410, 52410, 84188, -1, 72501, 96460, 11402, 96460, 11402, 96460, 20998, 96460, 61631, 29904}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(49): Basarili" << endl;
	else cout << "Case(49): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_50(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 27);

	vector<int> myResult; 
	caseQueue.insert(39355,28183);
	caseQueue.updatePriority(39355, 35532);
	caseQueue.insert(23480,69522);
	myResult.push_back(caseQueue.getPriority(23480)); //1
	caseQueue.insert(99111,18853);
	myResult.push_back(caseQueue.getPriority(39355)); //2
	caseQueue.updatePriority(99111, 81645);
	caseQueue.updatePriority(39355, 64486);
	myResult.push_back(caseQueue.getPriority(23480)); //3
	caseQueue.insert(75471,73728);
	myResult.push_back(caseQueue.getPriority(23480)); //4
	caseQueue.insert(10527,9289);
	caseQueue.updatePriority(10527, 8569);
	caseQueue.insert(47832,35533);
	caseQueue.updatePriority(23480, 48753);
	myResult.push_back(caseQueue.getPriority(10527)); //5
	myResult.push_back(caseQueue.getPriority(23480)); //6
	caseQueue.updatePriority(99111, 90668);
	caseQueue.updatePriority(23480, 35411);
	caseQueue.insert(8785,73273);
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(95442,59020);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(95442, 1891);
	myResult.push_back(caseQueue.deleteMin()); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	static const int resultListArray[] = {69522, 35532, 69522, 69522, 8569, 48753, 10527, 23480, 47832, 95442, 39355}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(50): Basarili" << endl;
	else cout << "Case(50): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_51(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 46);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(81061)); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.updatePriority(11407, 11530);
	caseQueue.insert(23332,27559);
	caseQueue.updatePriority(23332, 31775);
	caseQueue.insert(93454,95594);
	caseQueue.updatePriority(93454, 31322);
	caseQueue.updatePriority(93454, 22253);
	caseQueue.insert(22801,4361);
	caseQueue.insert(8714,8732);
	myResult.push_back(caseQueue.getPriority(93454)); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.getPriority(23332)); //6
	caseQueue.insert(24495,8823);
	caseQueue.updatePriority(24495, 30701);
	caseQueue.updatePriority(24495, 86706);
	caseQueue.insert(32642,66011);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.insert(11533,85404);
	caseQueue.updatePriority(23332, 55498);
	caseQueue.insert(23802,38145);
	caseQueue.updatePriority(24495, 37065);
	caseQueue.updatePriority(23332, 27641);
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(56293,80161);
	caseQueue.insert(72629,52929);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(56293, 16970);
	caseQueue.updatePriority(32642, 59184);
	caseQueue.updatePriority(56293, 87798);
	myResult.push_back(caseQueue.getPriority(23802)); //10
	caseQueue.insert(28727,92584);
	myResult.push_back(caseQueue.getPriority(72629)); //11
	caseQueue.updatePriority(56293, 77813);
	caseQueue.updatePriority(32642, 9326);
	caseQueue.updatePriority(72629, 66613);
	caseQueue.updatePriority(28727, 6890);
	caseQueue.insert(28432,64171);
	myResult.push_back(caseQueue.deleteMin()); //12
	myResult.push_back(caseQueue.getPriority(23802)); //13
	caseQueue.insert(96461,33847);
	myResult.push_back(caseQueue.getPriority(32642)); //14
	caseQueue.insert(14335,72724);
	myResult.push_back(caseQueue.getPriority(23802)); //15
	caseQueue.updatePriority(23802, 47179);
	static const int resultListArray[] = {-1, -1, 22253, 22801, 8714, 31775, 93454, 23332, 24495, 38145, 52929, 28727, 38145, 9326, 38145}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(51): Basarili" << endl;
	else cout << "Case(51): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_52(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 39);

	vector<int> myResult; 
	caseQueue.insert(8188,59008);
	caseQueue.insert(75470,72594);
	caseQueue.insert(72753,58922);
	caseQueue.updatePriority(75470, 85013);
	myResult.push_back(caseQueue.getPriority(8188)); //1
	caseQueue.insert(77433,8059);
	caseQueue.insert(24649,41078);
	caseQueue.insert(98580,81812);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.updatePriority(24649, 47390);
	caseQueue.insert(95328,17150);
	caseQueue.updatePriority(98580, 2076);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(34244,70101);
	myResult.push_back(caseQueue.getPriority(8188)); //4
	caseQueue.insert(29196,67004);
	caseQueue.insert(99871,96446);
	caseQueue.updatePriority(8188, 81500);
	caseQueue.insert(27984,5719);
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.getPriority(72753)); //6
	myResult.push_back(caseQueue.getPriority(29196)); //7
	caseQueue.insert(44767,83772);
	caseQueue.insert(15953,70372);
	caseQueue.insert(8836,50319);
	myResult.push_back(caseQueue.getPriority(75470)); //8
	caseQueue.updatePriority(8836, 74859);
	caseQueue.insert(30587,89929);
	caseQueue.updatePriority(8188, 74682);
	myResult.push_back(caseQueue.deleteMin()); //9
	myResult.push_back(caseQueue.getPriority(24649)); //10
	caseQueue.insert(45707,9653);
	caseQueue.insert(90901,26999);
	caseQueue.updatePriority(99871, 8798);
	caseQueue.updatePriority(8836, 70306);
	caseQueue.insert(45205,59150);
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.getPriority(90901)); //12
	caseQueue.insert(74721,72465);
	static const int resultListArray[] = {59008, 77433, 98580, 59008, 27984, 58922, 67004, 85013, 95328, 47390, 99871, 26999}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(52): Basarili" << endl;
	else cout << "Case(52): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_53(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 24);

	vector<int> myResult; 
	caseQueue.insert(2010,27352);
	caseQueue.updatePriority(2010, 95714);
	caseQueue.updatePriority(2010, 64737);
	caseQueue.insert(24594,68020);
	caseQueue.updatePriority(24594, 19026);
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.getPriority(2010)); //2
	caseQueue.insert(2232,42867);
	myResult.push_back(caseQueue.getPriority(2010)); //3
	myResult.push_back(caseQueue.getPriority(2010)); //4
	caseQueue.insert(7885,75481);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(99148,3437);
	caseQueue.insert(57442,79753);
	caseQueue.insert(61266,18560);
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.getPriority(7885)); //7
	caseQueue.insert(34920,59101);
	caseQueue.insert(54573,21362);
	myResult.push_back(caseQueue.deleteMin()); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.insert(44243,1797);
	caseQueue.updatePriority(2010, 59420);
	myResult.push_back(caseQueue.deleteMin()); //10
	static const int resultListArray[] = {24594, 64737, 64737, 64737, 2232, 99148, 75481, 61266, 54573, 44243}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(53): Basarili" << endl;
	else cout << "Case(53): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_54(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 10);

	vector<int> myResult; 
	caseQueue.updatePriority(16305, 67613);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(21796,69055);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(97528,51974);
	myResult.push_back(caseQueue.getPriority(97528)); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.getPriority(23629)); //5
	myResult.push_back(caseQueue.getPriority(261)); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	static const int resultListArray[] = {-1, 21796, 51974, 97528, -1, -1, -1}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(54): Basarili" << endl;
	else cout << "Case(54): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_55(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 11);

	vector<int> myResult; 
	caseQueue.insert(67959,86527);
	caseQueue.updatePriority(67959, 27177);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(48379, 75109);
	caseQueue.insert(31798,13059);
	caseQueue.updatePriority(31798, 68138);
	caseQueue.insert(7891,4409);
	caseQueue.insert(40945,17012);
	caseQueue.insert(11081,77432);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(99759,25245);
	static const int resultListArray[] = {67959, 7891}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(55): Basarili" << endl;
	else cout << "Case(55): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_56(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 35);

	vector<int> myResult; 
	caseQueue.insert(60998,57444);
	caseQueue.insert(66078,53423);
	caseQueue.updatePriority(60998, 69110);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(87966,54010);
	caseQueue.insert(19401,84590);
	myResult.push_back(caseQueue.getPriority(87966)); //2
	caseQueue.insert(96259,67565);
	caseQueue.updatePriority(87966, 62102);
	myResult.push_back(caseQueue.deleteMin()); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.updatePriority(19401, 68033);
	myResult.push_back(caseQueue.getPriority(19401)); //6
	caseQueue.updatePriority(19401, 1224);
	caseQueue.updatePriority(19401, 9371);
	myResult.push_back(caseQueue.getPriority(19401)); //7
	caseQueue.insert(57172,99972);
	caseQueue.updatePriority(57172, 99332);
	caseQueue.insert(41508,785);
	myResult.push_back(caseQueue.getPriority(41508)); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(19401, 86273);
	caseQueue.insert(41485,51211);
	caseQueue.updatePriority(19401, 35081);
	myResult.push_back(caseQueue.getPriority(19401)); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(91417,82161);
	myResult.push_back(caseQueue.getPriority(91417)); //12
	myResult.push_back(caseQueue.deleteMin()); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.updatePriority(57172, 62768);
	caseQueue.insert(27049,64929);
	caseQueue.insert(5211,38022);
	caseQueue.updatePriority(57172, 73195);
	static const int resultListArray[] = {66078, 54010, 87966, 96259, 60998, 68033, 9371, 785, 41508, 35081, 19401, 82161, 41485, 91417}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(56): Basarili" << endl;
	else cout << "Case(56): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_57(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 20);

	vector<int> myResult; 
	caseQueue.insert(21657,38590);
	caseQueue.updatePriority(21657, 52711);
	caseQueue.updatePriority(21657, 21105);
	caseQueue.updatePriority(21657, 33131);
	myResult.push_back(caseQueue.getPriority(21657)); //1
	caseQueue.insert(52971,72237);
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.getPriority(52971)); //3
	caseQueue.updatePriority(52971, 79856);
	myResult.push_back(caseQueue.getPriority(52971)); //4
	myResult.push_back(caseQueue.getPriority(52971)); //5
	caseQueue.updatePriority(52971, 3697);
	caseQueue.insert(57273,29640);
	caseQueue.insert(85461,38482);
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.getPriority(57273)); //7
	myResult.push_back(caseQueue.getPriority(85461)); //8
	caseQueue.insert(88794,94047);
	myResult.push_back(caseQueue.getPriority(85461)); //9
	caseQueue.insert(5614,46169);
	static const int resultListArray[] = {33131, 21657, 72237, 79856, 79856, 52971, 29640, 38482, 38482}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(57): Basarili" << endl;
	else cout << "Case(57): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_58(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 25);

	vector<int> myResult; 
	caseQueue.insert(34292,14310);
	caseQueue.updatePriority(34292, 74242);
	caseQueue.insert(3140,47291);
	caseQueue.insert(62479,4104);
	caseQueue.insert(96018,93875);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(96018, 62334);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.updatePriority(96018, 36963);
	caseQueue.updatePriority(34292, 21306);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(21972,55870);
	caseQueue.insert(14312,76594);
	myResult.push_back(caseQueue.getPriority(96018)); //4
	caseQueue.insert(85620,60563);
	myResult.push_back(caseQueue.getPriority(85620)); //5
	caseQueue.updatePriority(96018, 23662);
	myResult.push_back(caseQueue.getPriority(21972)); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(81115,42035);
	myResult.push_back(caseQueue.getPriority(85620)); //9
	myResult.push_back(caseQueue.getPriority(81115)); //10
	caseQueue.updatePriority(81115, 46148);
	myResult.push_back(caseQueue.deleteMin()); //11
	static const int resultListArray[] = {62479, 3140, 34292, 36963, 60563, 55870, 96018, 21972, 60563, 42035, 81115}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(58): Basarili" << endl;
	else cout << "Case(58): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_59(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 16);

	vector<int> myResult; 
	caseQueue.insert(85316,88309);
	caseQueue.updatePriority(85316, 54315);
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.getPriority(85092)); //2
	caseQueue.insert(95918,86312);
	myResult.push_back(caseQueue.getPriority(95918)); //3
	myResult.push_back(caseQueue.getPriority(95918)); //4
	caseQueue.insert(48650,52727);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.updatePriority(95918, 73293);
	myResult.push_back(caseQueue.getPriority(95918)); //6
	caseQueue.updatePriority(95918, 64683);
	caseQueue.insert(16584,77519);
	caseQueue.updatePriority(95918, 10928);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.insert(87068,38468);
	static const int resultListArray[] = {85316, -1, 86312, 86312, 48650, 73293, 95918}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(59): Basarili" << endl;
	else cout << "Case(59): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_60(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 29);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(56743)); //1
	myResult.push_back(caseQueue.getPriority(85049)); //2
	myResult.push_back(caseQueue.getPriority(38312)); //3
	caseQueue.updatePriority(80405, 22942);
	myResult.push_back(caseQueue.getPriority(93429)); //4
	caseQueue.insert(83101,16969);
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.getPriority(1996)); //6
	caseQueue.insert(14119,69935);
	caseQueue.insert(27245,28530);
	caseQueue.updatePriority(27245, 79100);
	myResult.push_back(caseQueue.getPriority(27245)); //7
	caseQueue.updatePriority(27245, 65168);
	myResult.push_back(caseQueue.getPriority(27245)); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(14119, 12151);
	caseQueue.insert(95239,23772);
	caseQueue.insert(87277,43202);
	myResult.push_back(caseQueue.getPriority(95239)); //10
	caseQueue.insert(52711,83891);
	caseQueue.insert(22443,83011);
	caseQueue.updatePriority(95239, 73664);
	caseQueue.updatePriority(52711, 23625);
	caseQueue.insert(93208,21764);
	caseQueue.updatePriority(14119, 85645);
	caseQueue.updatePriority(95239, 56600);
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.deleteMin()); //12
	myResult.push_back(caseQueue.deleteMin()); //13
	static const int resultListArray[] = {-1, -1, -1, -1, 83101, -1, 79100, 65168, 27245, 23772, 93208, 52711, 87277}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(60): Basarili" << endl;
	else cout << "Case(60): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_61(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 25);

	vector<int> myResult; 
	caseQueue.insert(56923,32198);
	caseQueue.insert(23549,45439);
	myResult.push_back(caseQueue.getPriority(23549)); //1
	caseQueue.insert(2214,10588);
	caseQueue.updatePriority(23549, 16241);
	caseQueue.updatePriority(23549, 83674);
	myResult.push_back(caseQueue.getPriority(23549)); //2
	myResult.push_back(caseQueue.getPriority(2214)); //3
	caseQueue.insert(42565,88976);
	caseQueue.updatePriority(42565, 16812);
	myResult.push_back(caseQueue.getPriority(42565)); //4
	myResult.push_back(caseQueue.getPriority(23549)); //5
	myResult.push_back(caseQueue.getPriority(23549)); //6
	myResult.push_back(caseQueue.getPriority(42565)); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.updatePriority(42565, 91536);
	caseQueue.updatePriority(23549, 7707);
	myResult.push_back(caseQueue.getPriority(56923)); //9
	caseQueue.updatePriority(42565, 77885);
	myResult.push_back(caseQueue.deleteMin()); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(77978,61766);
	myResult.push_back(caseQueue.getPriority(42565)); //12
	myResult.push_back(caseQueue.getPriority(42565)); //13
	myResult.push_back(caseQueue.getPriority(77978)); //14
	static const int resultListArray[] = {45439, 83674, 10588, 16812, 83674, 83674, 16812, 2214, 32198, 23549, 56923, 77885, 77885, 61766}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(61): Basarili" << endl;
	else cout << "Case(61): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_62(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 46);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.getPriority(94292)); //2
	caseQueue.insert(69398,98387);
	caseQueue.updatePriority(69398, 64979);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(66421,7765);
	caseQueue.updatePriority(66421, 22751);
	myResult.push_back(caseQueue.getPriority(66421)); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(77023,1856);
	caseQueue.insert(93825,45737);
	caseQueue.insert(46550,89517);
	caseQueue.updatePriority(77023, 50147);
	caseQueue.updatePriority(93825, 91167);
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.updatePriority(46550, 4661);
	myResult.push_back(caseQueue.getPriority(46550)); //7
	myResult.push_back(caseQueue.getPriority(46550)); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	myResult.push_back(caseQueue.deleteMin()); //10
	caseQueue.insert(68785,12188);
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.updatePriority(67505, 93995);
	myResult.push_back(caseQueue.getPriority(48689)); //12
	caseQueue.updatePriority(95346, 21398);
	caseQueue.insert(11260,37386);
	myResult.push_back(caseQueue.deleteMin()); //13
	caseQueue.updatePriority(87085, 13548);
	caseQueue.updatePriority(80974, 36849);
	caseQueue.insert(58834,18871);
	myResult.push_back(caseQueue.getPriority(58834)); //14
	caseQueue.insert(99869,15847);
	caseQueue.updatePriority(58834, 66165);
	caseQueue.insert(13791,44967);
	caseQueue.updatePriority(99869, 90831);
	caseQueue.insert(23394,84804);
	myResult.push_back(caseQueue.getPriority(13791)); //15
	caseQueue.updatePriority(58834, 42607);
	caseQueue.insert(64203,42748);
	myResult.push_back(caseQueue.getPriority(13791)); //16
	caseQueue.insert(18429,85550);
	caseQueue.insert(40964,58845);
	caseQueue.insert(26940,74872);
	myResult.push_back(caseQueue.deleteMin()); //17
	caseQueue.insert(2412,14361);
	caseQueue.insert(233,45931);
	static const int resultListArray[] = {-1, -1, 69398, 22751, 66421, 77023, 4661, 4661, 46550, 93825, 68785, -1, 11260, 18871, 44967, 44967, 58834}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(62): Basarili" << endl;
	else cout << "Case(62): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_63(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 17);

	vector<int> myResult; 
	caseQueue.updatePriority(20232, 41220);
	caseQueue.insert(8503,77856);
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.getPriority(4884)); //2
	caseQueue.insert(55232,48305);
	caseQueue.insert(13468,41173);
	myResult.push_back(caseQueue.getPriority(13468)); //3
	myResult.push_back(caseQueue.getPriority(55232)); //4
	caseQueue.insert(71867,32788);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.updatePriority(55232, 21095);
	myResult.push_back(caseQueue.getPriority(55232)); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.insert(87088,52932);
	caseQueue.updatePriority(87088, 3980);
	myResult.push_back(caseQueue.deleteMin()); //8
	myResult.push_back(caseQueue.getPriority(13468)); //9
	static const int resultListArray[] = {8503, -1, 41173, 48305, 71867, 21095, 55232, 87088, 41173}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(63): Basarili" << endl;
	else cout << "Case(63): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_64(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 44);

	vector<int> myResult; 
	caseQueue.insert(39302,48192);
	caseQueue.updatePriority(39302, 75276);
	caseQueue.insert(75372,72494);
	caseQueue.insert(52843,5538);
	caseQueue.insert(41646,62969);
	caseQueue.insert(82568,99734);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(82568, 23739);
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.getPriority(75372)); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.updatePriority(39302, 42150);
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.getPriority(75372)); //6
	caseQueue.insert(48198,47700);
	caseQueue.updatePriority(75372, 4144);
	caseQueue.updatePriority(75372, 58767);
	caseQueue.updatePriority(48198, 50587);
	myResult.push_back(caseQueue.getPriority(48198)); //7
	caseQueue.insert(78454,55646);
	caseQueue.insert(91220,69036);
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(54872,44119);
	caseQueue.updatePriority(78454, 32430);
	myResult.push_back(caseQueue.getPriority(78454)); //9
	myResult.push_back(caseQueue.deleteMin()); //10
	caseQueue.updatePriority(91220, 46512);
	caseQueue.insert(49391,24729);
	caseQueue.insert(30807,2434);
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.deleteMin()); //12
	myResult.push_back(caseQueue.deleteMin()); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	myResult.push_back(caseQueue.getPriority(75372)); //15
	caseQueue.updatePriority(75372, 18350);
	caseQueue.insert(49380,51693);
	caseQueue.insert(89893,52141);
	caseQueue.insert(86112,3225);
	caseQueue.updatePriority(49380, 87730);
	caseQueue.updatePriority(75372, 50758);
	myResult.push_back(caseQueue.deleteMin()); //16
	caseQueue.insert(40500,23211);
	caseQueue.insert(17618,70678);
	myResult.push_back(caseQueue.getPriority(75372)); //17
	static const int resultListArray[] = {52843, 82568, 72494, 41646, 39302, 72494, 50587, 48198, 32430, 78454, 30807, 49391, 54872, 91220, 58767, 86112, 50758}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(64): Basarili" << endl;
	else cout << "Case(64): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_65(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 32);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(50109)); //1
	myResult.push_back(caseQueue.getPriority(33007)); //2
	caseQueue.insert(69151,12584);
	caseQueue.updatePriority(69151, 12198);
	caseQueue.insert(24895,27776);
	caseQueue.updatePriority(24895, 86380);
	caseQueue.updatePriority(24895, 46646);
	caseQueue.updatePriority(69151, 19524);
	myResult.push_back(caseQueue.getPriority(24895)); //3
	caseQueue.insert(65260,40586);
	caseQueue.updatePriority(24895, 83744);
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.updatePriority(65260, 89074);
	myResult.push_back(caseQueue.getPriority(65260)); //5
	caseQueue.updatePriority(65260, 94707);
	myResult.push_back(caseQueue.getPriority(65260)); //6
	myResult.push_back(caseQueue.getPriority(24895)); //7
	caseQueue.updatePriority(24895, 59123);
	myResult.push_back(caseQueue.getPriority(24895)); //8
	caseQueue.updatePriority(65260, 15744);
	caseQueue.updatePriority(65260, 87545);
	caseQueue.insert(75810,91854);
	caseQueue.insert(27688,122);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.insert(14727,6098);
	caseQueue.insert(38633,15099);
	caseQueue.updatePriority(14727, 60332);
	myResult.push_back(caseQueue.getPriority(14727)); //10
	caseQueue.insert(21882,82834);
	myResult.push_back(caseQueue.getPriority(65260)); //11
	myResult.push_back(caseQueue.deleteMin()); //12
	myResult.push_back(caseQueue.getPriority(14727)); //13
	static const int resultListArray[] = {-1, -1, 46646, 69151, 89074, 94707, 83744, 59123, 27688, 60332, 87545, 38633, 60332}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(65): Basarili" << endl;
	else cout << "Case(65): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_66(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 23);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(45783,49511);
	caseQueue.insert(48827,8342);
	myResult.push_back(caseQueue.getPriority(45783)); //2
	caseQueue.insert(48436,62892);
	caseQueue.insert(21562,31280);
	caseQueue.updatePriority(48436, 9885);
	caseQueue.insert(79951,79542);
	myResult.push_back(caseQueue.getPriority(48827)); //3
	caseQueue.insert(1388,31794);
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(74930,37568);
	caseQueue.updatePriority(45783, 49529);
	caseQueue.insert(90044,76905);
	caseQueue.insert(73584,48485);
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.updatePriority(73584, 78908);
	caseQueue.insert(40789,96891);
	caseQueue.insert(98149,95566);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.insert(26097,4604);
	caseQueue.insert(71381,11214);
	static const int resultListArray[] = {-1, 49511, 8342, 48827, 48436, 21562, 1388}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(66): Basarili" << endl;
	else cout << "Case(66): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_67(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 38);

	vector<int> myResult; 
	caseQueue.insert(59011,47028);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(89201,73894);
	myResult.push_back(caseQueue.getPriority(89201)); //2
	caseQueue.updatePriority(89201, 34256);
	myResult.push_back(caseQueue.getPriority(89201)); //3
	caseQueue.insert(11793,71842);
	caseQueue.updatePriority(11793, 41328);
	caseQueue.insert(86425,61456);
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(94600,99253);
	caseQueue.insert(66928,55049);
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.getPriority(86425)); //7
	caseQueue.insert(83949,33395);
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(44206,7237);
	myResult.push_back(caseQueue.getPriority(94600)); //9
	myResult.push_back(caseQueue.getPriority(94600)); //10
	caseQueue.insert(65817,24727);
	caseQueue.updatePriority(44206, 41886);
	caseQueue.updatePriority(94600, 40323);
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.getPriority(44206)); //12
	caseQueue.updatePriority(44206, 83493);
	caseQueue.insert(24996,5833);
	caseQueue.insert(42594,7070);
	caseQueue.insert(14804,96781);
	myResult.push_back(caseQueue.deleteMin()); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.insert(33716,4333);
	myResult.push_back(caseQueue.deleteMin()); //15
	myResult.push_back(caseQueue.getPriority(94600)); //16
	myResult.push_back(caseQueue.deleteMin()); //17
	myResult.push_back(caseQueue.deleteMin()); //18
	caseQueue.updatePriority(44206, 5103);
	myResult.push_back(caseQueue.deleteMin()); //19
	static const int resultListArray[] = {59011, 73894, 34256, 89201, 11793, 66928, 61456, 83949, 99253, 99253, 65817, 41886, 24996, 42594, 33716, 40323, 94600, 86425, 44206}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(67): Basarili" << endl;
	else cout << "Case(67): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_68(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 19);

	vector<int> myResult; 
	caseQueue.insert(75615,91223);
	caseQueue.insert(7998,73379);
	caseQueue.insert(53616,50670);
	myResult.push_back(caseQueue.getPriority(75615)); //1
	caseQueue.insert(39693,31682);
	caseQueue.insert(57914,18229);
	caseQueue.updatePriority(39693, 5223);
	myResult.push_back(caseQueue.getPriority(39693)); //2
	myResult.push_back(caseQueue.getPriority(75615)); //3
	caseQueue.insert(25951,28484);
	caseQueue.insert(69775,79121);
	myResult.push_back(caseQueue.getPriority(39693)); //4
	caseQueue.insert(7207,2553);
	caseQueue.insert(51068,32392);
	caseQueue.insert(39091,5828);
	caseQueue.insert(92502,51035);
	caseQueue.insert(57813,7541);
	caseQueue.insert(53197,64945);
	myResult.push_back(caseQueue.deleteMin()); //5
	static const int resultListArray[] = {91223, 5223, 91223, 5223, 7207}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(68): Basarili" << endl;
	else cout << "Case(68): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_69(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 22);

	vector<int> myResult; 
	caseQueue.insert(66049,85198);
	caseQueue.insert(21083,38892);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(67497,81621);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.updatePriority(66049, 37894);
	myResult.push_back(caseQueue.getPriority(66049)); //3
	caseQueue.insert(7237,21722);
	myResult.push_back(caseQueue.getPriority(7237)); //4
	caseQueue.updatePriority(7237, 5193);
	myResult.push_back(caseQueue.getPriority(7237)); //5
	myResult.push_back(caseQueue.getPriority(66049)); //6
	caseQueue.insert(8560,31136);
	caseQueue.updatePriority(66049, 56562);
	caseQueue.insert(54012,56646);
	caseQueue.updatePriority(7237, 40887);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.insert(57405,48047);
	myResult.push_back(caseQueue.getPriority(7237)); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(54012, 24870);
	caseQueue.insert(70396,67035);
	static const int resultListArray[] = {21083, 67497, 37894, 21722, 5193, 37894, 8560, 40887, 7237}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(69): Basarili" << endl;
	else cout << "Case(69): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_70(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 40);

	vector<int> myResult; 
	caseQueue.updatePriority(73747, 83806);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(47812, 86399);
	caseQueue.insert(73092,26243);
	caseQueue.insert(3080,50215);
	caseQueue.insert(15030,49509);
	caseQueue.insert(65123,53298);
	caseQueue.insert(47351,62364);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(70439,39838);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.updatePriority(3080, 83438);
	caseQueue.insert(17701,93198);
	myResult.push_back(caseQueue.getPriority(15030)); //4
	myResult.push_back(caseQueue.getPriority(47351)); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.updatePriority(17701, 15083);
	caseQueue.insert(12659,92145);
	caseQueue.insert(56988,92327);
	myResult.push_back(caseQueue.getPriority(47351)); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(90902,45066);
	caseQueue.insert(46705,84794);
	caseQueue.insert(80597,45971);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(56988, 50641);
	caseQueue.insert(71177,64749);
	caseQueue.updatePriority(47351, 51516);
	caseQueue.updatePriority(56988, 96427);
	myResult.push_back(caseQueue.deleteMin()); //10
	caseQueue.insert(39227,65279);
	caseQueue.updatePriority(47351, 45004);
	caseQueue.insert(84525,89);
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.updatePriority(65123, 65959);
	caseQueue.updatePriority(65123, 43516);
	caseQueue.insert(54449,39833);
	caseQueue.insert(95495,28033);
	myResult.push_back(caseQueue.getPriority(46705)); //13
	static const int resultListArray[] = {-1, 73092, 70439, 49509, 62364, 15030, 62364, 17701, 90902, 80597, 84525, 47351, 84794}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(70): Basarili" << endl;
	else cout << "Case(70): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_71(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 19);

	vector<int> myResult; 
	caseQueue.insert(40887,78382);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(92556, 57421);
	caseQueue.insert(24520,82103);
	caseQueue.insert(92504,95680);
	myResult.push_back(caseQueue.getPriority(92504)); //2
	caseQueue.insert(2302,70268);
	caseQueue.insert(88968,74137);
	caseQueue.updatePriority(2302, 91723);
	caseQueue.insert(12391,52907);
	caseQueue.insert(6301,53643);
	caseQueue.updatePriority(24520, 3048);
	caseQueue.updatePriority(24520, 18958);
	caseQueue.updatePriority(6301, 93352);
	myResult.push_back(caseQueue.deleteMin()); //3
	myResult.push_back(caseQueue.getPriority(92504)); //4
	caseQueue.insert(96322,98120);
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	static const int resultListArray[] = {40887, 95680, 24520, 95680, 12391, 88968}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(71): Basarili" << endl;
	else cout << "Case(71): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_72(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 26);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(47902)); //1
	caseQueue.insert(71762,44031);
	myResult.push_back(caseQueue.getPriority(71762)); //2
	caseQueue.insert(46400,88564);
	caseQueue.updatePriority(46400, 94668);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(87552,8113);
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.getPriority(46400)); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.insert(98856,16850);
	caseQueue.insert(55254,32973);
	caseQueue.insert(50675,38230);
	caseQueue.updatePriority(50675, 97983);
	caseQueue.updatePriority(98856, 76252);
	myResult.push_back(caseQueue.getPriority(50675)); //7
	caseQueue.updatePriority(50675, 85133);
	myResult.push_back(caseQueue.deleteMin()); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	myResult.push_back(caseQueue.getPriority(50675)); //10
	caseQueue.insert(24127,83632);
	caseQueue.insert(96029,8842);
	myResult.push_back(caseQueue.getPriority(50675)); //11
	caseQueue.insert(96885,46677);
	myResult.push_back(caseQueue.deleteMin()); //12
	myResult.push_back(caseQueue.deleteMin()); //13
	static const int resultListArray[] = {-1, 44031, 71762, 87552, 94668, 46400, 97983, 55254, 98856, 85133, 85133, 96029, 96885}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(72): Basarili" << endl;
	else cout << "Case(72): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_73(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 33);

	vector<int> myResult; 
	caseQueue.insert(98329,73320);
	caseQueue.updatePriority(98329, 4990);
	caseQueue.updatePriority(98329, 39368);
	caseQueue.insert(97900,3243);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(74477,35824);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(83755,60176);
	caseQueue.updatePriority(98329, 36616);
	myResult.push_back(caseQueue.deleteMin()); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(54313,22964);
	caseQueue.insert(21152,79583);
	caseQueue.updatePriority(54313, 18280);
	caseQueue.insert(67012,77252);
	caseQueue.insert(75206,36249);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.updatePriority(75206, 88534);
	caseQueue.insert(89324,2937);
	caseQueue.updatePriority(21152, 76361);
	caseQueue.insert(38825,13985);
	caseQueue.updatePriority(75206, 57743);
	caseQueue.updatePriority(89324, 13788);
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.updatePriority(75206, 30037);
	caseQueue.insert(81419,37081);
	myResult.push_back(caseQueue.getPriority(75206)); //7
	caseQueue.insert(73432,52168);
	myResult.push_back(caseQueue.getPriority(73432)); //8
	myResult.push_back(caseQueue.getPriority(38825)); //9
	caseQueue.insert(40672,81326);
	myResult.push_back(caseQueue.getPriority(40672)); //10
	caseQueue.insert(20863,60887);
	static const int resultListArray[] = {97900, 74477, 98329, 83755, 54313, 89324, 30037, 52168, 13985, 81326}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(73): Basarili" << endl;
	else cout << "Case(73): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_74(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 10);

	vector<int> myResult; 
	caseQueue.insert(76529,25818);
	myResult.push_back(caseQueue.getPriority(76529)); //1
	myResult.push_back(caseQueue.getPriority(76529)); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(51935,3927);
	caseQueue.updatePriority(51935, 32298);
	caseQueue.insert(51850,1861);
	caseQueue.insert(25459,70620);
	myResult.push_back(caseQueue.deleteMin()); //5
	static const int resultListArray[] = {25818, 25818, 76529, -1, 51850}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(74): Basarili" << endl;
	else cout << "Case(74): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_75(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 19);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(57596)); //1
	caseQueue.updatePriority(56136, 14156);
	caseQueue.insert(25253,49188);
	myResult.push_back(caseQueue.getPriority(25253)); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	myResult.push_back(caseQueue.getPriority(7944)); //4
	caseQueue.insert(83601,73909);
	caseQueue.insert(69870,52666);
	caseQueue.updatePriority(83601, 81017);
	myResult.push_back(caseQueue.getPriority(83601)); //5
	caseQueue.insert(8450,21004);
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.insert(43360,97517);
	caseQueue.updatePriority(69870, 46891);
	caseQueue.insert(96156,60404);
	caseQueue.insert(6577,38655);
	caseQueue.insert(1373,18510);
	caseQueue.insert(22291,80983);
	caseQueue.insert(61324,26794);
	static const int resultListArray[] = {-1, 49188, 25253, -1, 81017, 8450}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(75): Basarili" << endl;
	else cout << "Case(75): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_76(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 26);

	vector<int> myResult; 
	caseQueue.insert(55073,95249);
	myResult.push_back(caseQueue.getPriority(55073)); //1
	myResult.push_back(caseQueue.getPriority(55073)); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(985,75372);
	caseQueue.insert(1646,10534);
	caseQueue.insert(44364,9179);
	caseQueue.insert(76025,71937);
	caseQueue.insert(33394,81142);
	caseQueue.insert(70062,92026);
	caseQueue.insert(71206,28221);
	myResult.push_back(caseQueue.getPriority(76025)); //5
	caseQueue.insert(41369,42847);
	caseQueue.insert(21306,44679);
	caseQueue.insert(55610,5224);
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.getPriority(33394)); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	myResult.push_back(caseQueue.deleteMin()); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.updatePriority(21306, 1534);
	caseQueue.insert(78080,27879);
	caseQueue.updatePriority(33394, 33388);
	myResult.push_back(caseQueue.getPriority(78080)); //12
	static const int resultListArray[] = {95249, 95249, 55073, -1, 71937, 55610, 44364, 81142, 1646, 71206, 41369, 27879}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(76): Basarili" << endl;
	else cout << "Case(76): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_77(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 45);

	vector<int> myResult; 
	caseQueue.insert(24678,41538);
	caseQueue.insert(57466,33003);
	caseQueue.insert(38929,84598);
	caseQueue.insert(24336,3612);
	caseQueue.updatePriority(24336, 24757);
	caseQueue.insert(67724,9238);
	caseQueue.insert(37062,23761);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(52537,41025);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(88933,10349);
	myResult.push_back(caseQueue.getPriority(24336)); //3
	caseQueue.updatePriority(38929, 76662);
	caseQueue.updatePriority(38929, 47992);
	caseQueue.insert(6004,81846);
	caseQueue.updatePriority(52537, 74583);
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(76897,13840);
	caseQueue.updatePriority(52537, 9893);
	caseQueue.updatePriority(57466, 76181);
	myResult.push_back(caseQueue.getPriority(24336)); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.updatePriority(24678, 60074);
	caseQueue.updatePriority(6004, 1166);
	myResult.push_back(caseQueue.getPriority(38929)); //9
	myResult.push_back(caseQueue.deleteMin()); //10
	caseQueue.insert(54704,72584);
	caseQueue.insert(76992,39874);
	myResult.push_back(caseQueue.getPriority(38929)); //11
	caseQueue.insert(45459,58321);
	myResult.push_back(caseQueue.deleteMin()); //12
	myResult.push_back(caseQueue.getPriority(57466)); //13
	caseQueue.insert(89740,12048);
	myResult.push_back(caseQueue.getPriority(38929)); //14
	myResult.push_back(caseQueue.getPriority(38929)); //15
	myResult.push_back(caseQueue.getPriority(38929)); //16
	caseQueue.insert(7396,5921);
	caseQueue.insert(39951,58614);
	myResult.push_back(caseQueue.deleteMin()); //17
	myResult.push_back(caseQueue.deleteMin()); //18
	caseQueue.insert(14353,71037);
	myResult.push_back(caseQueue.getPriority(39951)); //19
	caseQueue.insert(88681,52272);
	static const int resultListArray[] = {67724, 37062, 24757, 88933, 24757, 52537, 76897, 24336, 47992, 6004, 47992, 76992, 76181, 47992, 47992, 47992, 7396, 89740, 58614}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(77): Basarili" << endl;
	else cout << "Case(77): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_78(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 45);

	vector<int> myResult; 
	caseQueue.updatePriority(31269, 29439);
	caseQueue.insert(56260,53707);
	caseQueue.insert(59962,22869);
	caseQueue.updatePriority(59962, 5508);
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(80144,85089);
	caseQueue.insert(84807,28060);
	caseQueue.insert(29377,97230);
	caseQueue.insert(84512,34301);
	caseQueue.insert(51442,28483);
	caseQueue.updatePriority(29377, 44436);
	caseQueue.updatePriority(29377, 37949);
	caseQueue.insert(23504,13396);
	caseQueue.updatePriority(29377, 76483);
	myResult.push_back(caseQueue.getPriority(51442)); //3
	myResult.push_back(caseQueue.getPriority(84512)); //4
	caseQueue.insert(87426,54273);
	caseQueue.insert(74719,22714);
	caseQueue.insert(54431,3804);
	myResult.push_back(caseQueue.getPriority(29377)); //5
	myResult.push_back(caseQueue.getPriority(84512)); //6
	caseQueue.insert(48944,84697);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.insert(91539,94830);
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(25055,9661);
	caseQueue.insert(91019,44641);
	myResult.push_back(caseQueue.getPriority(84807)); //9
	caseQueue.insert(90483,74837);
	caseQueue.insert(66249,62517);
	myResult.push_back(caseQueue.deleteMin()); //10
	myResult.push_back(caseQueue.getPriority(51442)); //11
	myResult.push_back(caseQueue.getPriority(66249)); //12
	caseQueue.insert(23373,86120);
	caseQueue.insert(22504,94458);
	myResult.push_back(caseQueue.deleteMin()); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.insert(96177,17306);
	caseQueue.updatePriority(87426, 32274);
	myResult.push_back(caseQueue.deleteMin()); //15
	myResult.push_back(caseQueue.getPriority(66249)); //16
	caseQueue.insert(87449,85972);
	caseQueue.insert(22930,65460);
	myResult.push_back(caseQueue.getPriority(80144)); //17
	static const int resultListArray[] = {59962, 56260, 28483, 34301, 76483, 34301, 54431, 23504, 28060, 25055, 28483, 62517, 74719, 84807, 96177, 62517, 85089}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(78): Basarili" << endl;
	else cout << "Case(78): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_79(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 39);

	vector<int> myResult; 
	caseQueue.updatePriority(24719, 95287);
	myResult.push_back(caseQueue.getPriority(89550)); //1
	caseQueue.updatePriority(17691, 24132);
	myResult.push_back(caseQueue.getPriority(90669)); //2
	myResult.push_back(caseQueue.getPriority(89227)); //3
	myResult.push_back(caseQueue.getPriority(25439)); //4
	caseQueue.insert(98082,62274);
	myResult.push_back(caseQueue.getPriority(98082)); //5
	myResult.push_back(caseQueue.getPriority(98082)); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(26966, 34164);
	myResult.push_back(caseQueue.getPriority(12357)); //8
	caseQueue.updatePriority(53492, 69210);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.updatePriority(86178, 35817);
	myResult.push_back(caseQueue.getPriority(45651)); //10
	caseQueue.insert(63880,80396);
	myResult.push_back(caseQueue.getPriority(63880)); //11
	myResult.push_back(caseQueue.getPriority(63880)); //12
	caseQueue.updatePriority(63880, 50962);
	caseQueue.insert(9931,25497);
	myResult.push_back(caseQueue.deleteMin()); //13
	caseQueue.insert(34114,46049);
	caseQueue.insert(95141,23307);
	caseQueue.insert(8184,86818);
	caseQueue.insert(49046,56831);
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.insert(54299,19788);
	myResult.push_back(caseQueue.getPriority(49046)); //15
	caseQueue.insert(8902,7561);
	caseQueue.updatePriority(34114, 17535);
	caseQueue.insert(25235,83140);
	myResult.push_back(caseQueue.deleteMin()); //16
	myResult.push_back(caseQueue.deleteMin()); //17
	caseQueue.insert(58077,6792);
	myResult.push_back(caseQueue.getPriority(25235)); //18
	caseQueue.insert(12414,30088);
	myResult.push_back(caseQueue.getPriority(63880)); //19
	caseQueue.insert(63151,24287);
	static const int resultListArray[] = {-1, -1, -1, -1, 62274, 62274, 98082, -1, -1, -1, 80396, 80396, 9931, 95141, 56831, 8902, 34114, 83140, 50962}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(79): Basarili" << endl;
	else cout << "Case(79): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_80(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 11);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(20310)); //1
	myResult.push_back(caseQueue.getPriority(20809)); //2
	caseQueue.insert(34190,22031);
	caseQueue.insert(28172,5480);
	caseQueue.updatePriority(28172, 82542);
	caseQueue.updatePriority(34190, 13853);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(2550,76437);
	caseQueue.insert(52521,78419);
	myResult.push_back(caseQueue.getPriority(52521)); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	static const int resultListArray[] = {-1, -1, 34190, 78419, 2550}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(80): Basarili" << endl;
	else cout << "Case(80): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_81(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 29);

	vector<int> myResult; 
	caseQueue.updatePriority(54511, 55542);
	caseQueue.updatePriority(85194, 61094);
	caseQueue.insert(6102,93301);
	myResult.push_back(caseQueue.getPriority(6102)); //1
	myResult.push_back(caseQueue.getPriority(6102)); //2
	caseQueue.insert(75222,55578);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.updatePriority(6102, 44854);
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.updatePriority(83767, 83350);
	caseQueue.updatePriority(424, 15626);
	caseQueue.updatePriority(34137, 36467);
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.insert(60859,86227);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.insert(14734,4006);
	caseQueue.updatePriority(14734, 68682);
	caseQueue.insert(58786,32606);
	caseQueue.insert(50955,17559);
	caseQueue.insert(37664,52825);
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(11302,24101);
	caseQueue.insert(15992,68687);
	caseQueue.updatePriority(15992, 40258);
	caseQueue.insert(14360,22672);
	caseQueue.updatePriority(15992, 85750);
	caseQueue.insert(65971,34422);
	caseQueue.insert(76603,40695);
	static const int resultListArray[] = {93301, 93301, 75222, 6102, -1, -1, 60859, 50955}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(81): Basarili" << endl;
	else cout << "Case(81): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_82(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 28);

	vector<int> myResult; 
	caseQueue.insert(52064,590);
	caseQueue.updatePriority(52064, 70344);
	myResult.push_back(caseQueue.getPriority(52064)); //1
	caseQueue.updatePriority(52064, 60627);
	caseQueue.insert(67444,2499);
	myResult.push_back(caseQueue.getPriority(67444)); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.updatePriority(52064, 56043);
	caseQueue.insert(40982,7001);
	myResult.push_back(caseQueue.getPriority(52064)); //4
	caseQueue.insert(53875,21201);
	caseQueue.updatePriority(40982, 37249);
	caseQueue.insert(64055,73859);
	myResult.push_back(caseQueue.getPriority(52064)); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.updatePriority(64055, 54922);
	caseQueue.updatePriority(52064, 27946);
	caseQueue.insert(27893,83426);
	caseQueue.updatePriority(27893, 9510);
	caseQueue.insert(16969,38009);
	caseQueue.insert(88376,22144);
	caseQueue.insert(65766,89005);
	myResult.push_back(caseQueue.getPriority(40982)); //7
	myResult.push_back(caseQueue.getPriority(16969)); //8
	caseQueue.updatePriority(16969, 17377);
	myResult.push_back(caseQueue.getPriority(16969)); //9
	myResult.push_back(caseQueue.deleteMin()); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	static const int resultListArray[] = {70344, 2499, 67444, 56043, 56043, 53875, 37249, 38009, 17377, 27893, 16969}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(82): Basarili" << endl;
	else cout << "Case(82): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_83(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 25);

	vector<int> myResult; 
	caseQueue.insert(76037,77471);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(64580, 5552);
	caseQueue.updatePriority(97636, 76496);
	caseQueue.updatePriority(56152, 20262);
	caseQueue.insert(68720,39365);
	myResult.push_back(caseQueue.getPriority(68720)); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.updatePriority(91590, 90621);
	caseQueue.insert(65101,12690);
	caseQueue.updatePriority(65101, 19072);
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.updatePriority(51282, 43276);
	caseQueue.insert(30950,5407);
	caseQueue.updatePriority(30950, 12122);
	myResult.push_back(caseQueue.getPriority(30950)); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.getPriority(4698)); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.insert(10092,40162);
	myResult.push_back(caseQueue.getPriority(10092)); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.updatePriority(59354, 96759);
	caseQueue.updatePriority(65353, 24665);
	static const int resultListArray[] = {76037, 39365, 68720, 65101, 12122, 30950, -1, -1, -1, 40162, 10092}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(83): Basarili" << endl;
	else cout << "Case(83): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_84(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 46);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(82463,97120);
	myResult.push_back(caseQueue.getPriority(82463)); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	myResult.push_back(caseQueue.getPriority(86441)); //4
	caseQueue.updatePriority(97051, 94482);
	caseQueue.insert(3117,18833);
	caseQueue.insert(38080,49176);
	myResult.push_back(caseQueue.getPriority(38080)); //5
	caseQueue.insert(85979,1811);
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.updatePriority(3117, 85837);
	caseQueue.updatePriority(38080, 94420);
	caseQueue.insert(75459,37568);
	caseQueue.insert(3158,39264);
	caseQueue.insert(51306,37029);
	caseQueue.updatePriority(3158, 3631);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(3117, 78295);
	caseQueue.updatePriority(75459, 90336);
	caseQueue.insert(54443,68862);
	caseQueue.updatePriority(3117, 47591);
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.updatePriority(3117, 19810);
	caseQueue.insert(98613,95303);
	myResult.push_back(caseQueue.getPriority(3117)); //9
	myResult.push_back(caseQueue.getPriority(38080)); //10
	caseQueue.insert(41092,2480);
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.getPriority(38080)); //12
	caseQueue.insert(18420,24141);
	caseQueue.insert(68297,1638);
	caseQueue.insert(3698,86353);
	myResult.push_back(caseQueue.deleteMin()); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.insert(93512,34183);
	caseQueue.insert(16747,59350);
	caseQueue.insert(65166,81624);
	caseQueue.insert(29522,73027);
	caseQueue.insert(21764,44344);
	myResult.push_back(caseQueue.getPriority(21764)); //15
	myResult.push_back(caseQueue.getPriority(54443)); //16
	caseQueue.insert(14275,19226);
	caseQueue.insert(73630,5842);
	myResult.push_back(caseQueue.getPriority(16747)); //17
	caseQueue.insert(60650,61181);
	static const int resultListArray[] = {-1, 97120, 82463, -1, 49176, 85979, 3158, 51306, 19810, 94420, 41092, 94420, 68297, 3117, 44344, 68862, 59350}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(84): Basarili" << endl;
	else cout << "Case(84): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_85(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 38);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(3001)); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(96787,21216);
	myResult.push_back(caseQueue.getPriority(96787)); //4
	myResult.push_back(caseQueue.getPriority(96787)); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.getPriority(40158)); //7
	caseQueue.updatePriority(84781, 40205);
	caseQueue.insert(39565,9033);
	myResult.push_back(caseQueue.getPriority(39565)); //8
	caseQueue.insert(7934,89263);
	myResult.push_back(caseQueue.getPriority(7934)); //9
	caseQueue.updatePriority(7934, 24735);
	myResult.push_back(caseQueue.getPriority(7934)); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	myResult.push_back(caseQueue.getPriority(7934)); //12
	myResult.push_back(caseQueue.deleteMin()); //13
	caseQueue.insert(82972,17270);
	myResult.push_back(caseQueue.getPriority(82972)); //14
	caseQueue.updatePriority(82972, 4573);
	caseQueue.insert(89693,29160);
	caseQueue.insert(72710,75544);
	myResult.push_back(caseQueue.deleteMin()); //15
	caseQueue.insert(51628,15020);
	myResult.push_back(caseQueue.deleteMin()); //16
	myResult.push_back(caseQueue.deleteMin()); //17
	myResult.push_back(caseQueue.deleteMin()); //18
	caseQueue.insert(73387,7754);
	caseQueue.insert(79572,14462);
	caseQueue.updatePriority(73387, 4013);
	myResult.push_back(caseQueue.deleteMin()); //19
	caseQueue.updatePriority(79572, 17671);
	caseQueue.insert(85482,46468);
	myResult.push_back(caseQueue.deleteMin()); //20
	caseQueue.insert(37994,3377);
	caseQueue.insert(78792,90383);
	caseQueue.updatePriority(85482, 65133);
	static const int resultListArray[] = {-1, -1, -1, 21216, 21216, 96787, -1, 9033, 89263, 24735, 39565, 24735, 7934, 17270, 82972, 51628, 89693, 72710, 73387, 79572}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(85): Basarili" << endl;
	else cout << "Case(85): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_86(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 32);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(77267)); //1
	caseQueue.updatePriority(36505, 68256);
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.getPriority(35941)); //3
	caseQueue.insert(9595,46390);
	caseQueue.updatePriority(9595, 9620);
	caseQueue.insert(11894,96512);
	caseQueue.updatePriority(9595, 25891);
	caseQueue.insert(51609,80779);
	caseQueue.updatePriority(11894, 20004);
	caseQueue.updatePriority(11894, 19713);
	caseQueue.updatePriority(51609, 54008);
	caseQueue.updatePriority(51609, 68114);
	myResult.push_back(caseQueue.getPriority(9595)); //4
	caseQueue.insert(47957,75702);
	caseQueue.updatePriority(9595, 52347);
	caseQueue.insert(30250,71759);
	caseQueue.insert(8098,9092);
	caseQueue.updatePriority(11894, 57316);
	caseQueue.insert(79123,4695);
	myResult.push_back(caseQueue.deleteMin()); //5
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(11894, 80459);
	caseQueue.insert(60697,92641);
	caseQueue.updatePriority(60697, 45500);
	caseQueue.insert(78809,68541);
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(90951,6192);
	caseQueue.updatePriority(47957, 54479);
	caseQueue.updatePriority(51609, 25720);
	caseQueue.updatePriority(11894, 80263);
	static const int resultListArray[] = {-1, -1, -1, 25891, 79123, 8098, 9595, 60697}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(86): Basarili" << endl;
	else cout << "Case(86): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_87(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 11);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.getPriority(23285)); //3
	caseQueue.insert(45113,92248);
	myResult.push_back(caseQueue.getPriority(45113)); //4
	myResult.push_back(caseQueue.getPriority(45113)); //5
	caseQueue.insert(95314,39207);
	caseQueue.insert(99890,78463);
	caseQueue.insert(63777,43263);
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.insert(93356,39888);
	static const int resultListArray[] = {-1, -1, -1, 92248, 92248, 95314}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(87): Basarili" << endl;
	else cout << "Case(87): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_88(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 32);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(5183,29937);
	caseQueue.insert(95299,19204);
	caseQueue.updatePriority(5183, 56546);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(59176,45269);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(50754,75832);
	caseQueue.insert(7211,84596);
	caseQueue.insert(84426,6425);
	caseQueue.updatePriority(50754, 42314);
	caseQueue.insert(34739,50614);
	caseQueue.updatePriority(5183, 51991);
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.getPriority(50754)); //5
	myResult.push_back(caseQueue.getPriority(5183)); //6
	caseQueue.insert(25255,61636);
	caseQueue.updatePriority(7211, 91690);
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.getPriority(7211)); //8
	myResult.push_back(caseQueue.getPriority(34739)); //9
	myResult.push_back(caseQueue.deleteMin()); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(25265,31563);
	caseQueue.insert(93477,77689);
	caseQueue.insert(44251,67825);
	caseQueue.insert(50963,52997);
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.insert(81399,24687);
	caseQueue.insert(40669,23705);
	caseQueue.updatePriority(93477, 88936);
	caseQueue.insert(56555,76149);
	static const int resultListArray[] = {-1, 95299, 59176, 84426, 42314, 51991, 50754, 91690, 50614, 34739, 5183, 25265}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(88): Basarili" << endl;
	else cout << "Case(88): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_89(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 12);

	vector<int> myResult; 
	caseQueue.insert(33705,2031);
	caseQueue.insert(40126,84689);
	caseQueue.insert(90678,71135);
	caseQueue.insert(27279,89974);
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.getPriority(90678)); //2
	myResult.push_back(caseQueue.getPriority(90678)); //3
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.getPriority(27279)); //5
	caseQueue.insert(59666,36338);
	myResult.push_back(caseQueue.getPriority(59666)); //6
	caseQueue.insert(44591,83181);
	static const int resultListArray[] = {33705, 71135, 71135, 90678, 89974, 36338}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(89): Basarili" << endl;
	else cout << "Case(89): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_90(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 17);

	vector<int> myResult; 
	caseQueue.insert(44876,99940);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(16190, 92998);
	caseQueue.insert(5166,38228);
	caseQueue.insert(31503,71821);
	caseQueue.updatePriority(31503, 71210);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(65359,91826);
	caseQueue.insert(27938,13352);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.updatePriority(65359, 53169);
	caseQueue.updatePriority(31503, 45665);
	caseQueue.insert(12696,24082);
	caseQueue.insert(24482,81728);
	caseQueue.updatePriority(24482, 40375);
	caseQueue.insert(82295,94232);
	caseQueue.updatePriority(12696, 99956);
	static const int resultListArray[] = {44876, 5166, 27938}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(90): Basarili" << endl;
	else cout << "Case(90): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_91(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 10);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(40529)); //1
	caseQueue.insert(30068,34111);
	myResult.push_back(caseQueue.getPriority(30068)); //2
	caseQueue.updatePriority(30068, 77199);
	caseQueue.insert(24649,7934);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(37589,55051);
	caseQueue.insert(14366,46099);
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.updatePriority(37589, 96821);
	static const int resultListArray[] = {-1, 34111, 24649, 14366}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(91): Basarili" << endl;
	else cout << "Case(91): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_92(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 10);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(95026, 50334);
	caseQueue.updatePriority(18506, 36088);
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(91114,96188);
	caseQueue.insert(87203,8922);
	caseQueue.insert(93777,53417);
	caseQueue.updatePriority(91114, 88472);
	caseQueue.insert(75649,32746);
	static const int resultListArray[] = {-1, -1, -1}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(92): Basarili" << endl;
	else cout << "Case(92): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_93(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 42);

	vector<int> myResult; 
	myResult.push_back(caseQueue.deleteMin()); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(57135,88528);
	myResult.push_back(caseQueue.deleteMin()); //3
	myResult.push_back(caseQueue.getPriority(54438)); //4
	caseQueue.insert(27119,7235);
	caseQueue.insert(28940,29235);
	myResult.push_back(caseQueue.getPriority(28940)); //5
	caseQueue.insert(67892,59586);
	myResult.push_back(caseQueue.getPriority(67892)); //6
	caseQueue.insert(27630,43095);
	myResult.push_back(caseQueue.getPriority(67892)); //7
	caseQueue.insert(36728,45881);
	caseQueue.insert(44713,72692);
	myResult.push_back(caseQueue.getPriority(27119)); //8
	caseQueue.updatePriority(28940, 94937);
	caseQueue.insert(515,53490);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.insert(94508,96191);
	caseQueue.insert(16487,95456);
	myResult.push_back(caseQueue.deleteMin()); //10
	caseQueue.updatePriority(515, 95366);
	caseQueue.insert(18698,60186);
	myResult.push_back(caseQueue.getPriority(44713)); //11
	myResult.push_back(caseQueue.getPriority(28940)); //12
	caseQueue.insert(87317,16856);
	caseQueue.updatePriority(67892, 84165);
	myResult.push_back(caseQueue.deleteMin()); //13
	caseQueue.updatePriority(94508, 79465);
	caseQueue.updatePriority(67892, 37585);
	myResult.push_back(caseQueue.getPriority(36728)); //14
	caseQueue.insert(98710,69355);
	caseQueue.insert(84680,7396);
	caseQueue.updatePriority(94508, 56287);
	myResult.push_back(caseQueue.deleteMin()); //15
	caseQueue.updatePriority(18698, 87192);
	caseQueue.insert(90628,53871);
	caseQueue.updatePriority(36728, 99129);
	myResult.push_back(caseQueue.deleteMin()); //16
	caseQueue.updatePriority(90628, 60898);
	myResult.push_back(caseQueue.getPriority(28940)); //17
	caseQueue.insert(93134,16041);
	static const int resultListArray[] = {-1, -1, 57135, -1, 29235, 59586, 59586, 7235, 27119, 27630, 72692, 94937, 87317, 45881, 84680, 67892, 94937}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(93): Basarili" << endl;
	else cout << "Case(93): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_94(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 48);

	vector<int> myResult; 
	caseQueue.insert(88414,2100);
	caseQueue.updatePriority(88414, 64787);
	caseQueue.updatePriority(88414, 24755);
	myResult.push_back(caseQueue.getPriority(88414)); //1
	caseQueue.insert(5101,99593);
	caseQueue.insert(50275,92571);
	caseQueue.insert(26271,73796);
	caseQueue.updatePriority(5101, 85625);
	caseQueue.insert(32592,40034);
	myResult.push_back(caseQueue.getPriority(88414)); //2
	caseQueue.insert(7483,68789);
	myResult.push_back(caseQueue.getPriority(7483)); //3
	caseQueue.updatePriority(26271, 97230);
	myResult.push_back(caseQueue.getPriority(7483)); //4
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.updatePriority(5101, 6188);
	caseQueue.updatePriority(7483, 19617);
	caseQueue.updatePriority(5101, 39963);
	caseQueue.insert(18712,72314);
	myResult.push_back(caseQueue.deleteMin()); //6
	caseQueue.insert(35356,3224);
	myResult.push_back(caseQueue.getPriority(26271)); //7
	caseQueue.insert(34616,78238);
	caseQueue.updatePriority(35356, 71250);
	myResult.push_back(caseQueue.getPriority(34616)); //8
	caseQueue.updatePriority(50275, 50678);
	caseQueue.insert(88741,52833);
	caseQueue.insert(45193,82235);
	myResult.push_back(caseQueue.deleteMin()); //9
	myResult.push_back(caseQueue.deleteMin()); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(1768,36668);
	caseQueue.updatePriority(34616, 7590);
	myResult.push_back(caseQueue.getPriority(35356)); //12
	myResult.push_back(caseQueue.getPriority(26271)); //13
	caseQueue.insert(62192,54469);
	caseQueue.updatePriority(18712, 24743);
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.insert(88339,86983);
	caseQueue.insert(65491,81807);
	myResult.push_back(caseQueue.getPriority(88741)); //15
	caseQueue.updatePriority(18712, 93473);
	myResult.push_back(caseQueue.deleteMin()); //16
	caseQueue.insert(67277,27765);
	myResult.push_back(caseQueue.deleteMin()); //17
	caseQueue.updatePriority(88339, 69738);
	caseQueue.updatePriority(26271, 75096);
	caseQueue.insert(88559,11848);
	static const int resultListArray[] = {24755, 24755, 68789, 68789, 88414, 7483, 97230, 78238, 5101, 32592, 50275, 71250, 97230, 34616, 52833, 1768, 67277}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(94): Basarili" << endl;
	else cout << "Case(94): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_95(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 33);

	vector<int> myResult; 
	caseQueue.insert(92663,85232);
	caseQueue.insert(55432,96350);
	myResult.push_back(caseQueue.getPriority(92663)); //1
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(87884,97433);
	caseQueue.insert(57424,52789);
	myResult.push_back(caseQueue.deleteMin()); //3
	caseQueue.insert(15863,55387);
	caseQueue.insert(42981,11954);
	caseQueue.updatePriority(55432, 59830);
	caseQueue.insert(92174,42424);
	caseQueue.updatePriority(55432, 22309);
	caseQueue.insert(31179,14959);
	myResult.push_back(caseQueue.getPriority(15863)); //4
	caseQueue.insert(79896,82948);
	caseQueue.insert(7971,43618);
	caseQueue.updatePriority(55432, 95185);
	caseQueue.insert(83191,41051);
	caseQueue.insert(48943,13537);
	myResult.push_back(caseQueue.getPriority(83191)); //5
	caseQueue.insert(58258,53446);
	caseQueue.insert(88426,50747);
	caseQueue.updatePriority(55432, 45211);
	caseQueue.insert(87878,78256);
	caseQueue.insert(10616,93100);
	caseQueue.insert(35133,56548);
	caseQueue.insert(53272,12338);
	myResult.push_back(caseQueue.deleteMin()); //6
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(15863, 16387);
	caseQueue.insert(18814,38404);
	caseQueue.insert(35830,519);
	caseQueue.insert(38188,85369);
	static const int resultListArray[] = {85232, 92663, 57424, 55387, 41051, 42981, 53272}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(95): Basarili" << endl;
	else cout << "Case(95): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_96(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 47);

	vector<int> myResult; 
	caseQueue.insert(59218,64487);
	caseQueue.insert(36594,93151);
	caseQueue.updatePriority(36594, 36401);
	caseQueue.insert(47354,14995);
	caseQueue.updatePriority(36594, 85313);
	caseQueue.insert(67065,83383);
	caseQueue.updatePriority(59218, 38352);
	caseQueue.updatePriority(67065, 70409);
	caseQueue.insert(99147,45689);
	caseQueue.updatePriority(59218, 55729);
	caseQueue.updatePriority(59218, 96308);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(4025,39156);
	myResult.push_back(caseQueue.getPriority(4025)); //2
	caseQueue.insert(107,44094);
	myResult.push_back(caseQueue.getPriority(59218)); //3
	caseQueue.updatePriority(4025, 7827);
	myResult.push_back(caseQueue.getPriority(99147)); //4
	caseQueue.insert(46342,89772);
	caseQueue.insert(56449,9273);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(9521,43053);
	myResult.push_back(caseQueue.getPriority(36594)); //6
	caseQueue.insert(12737,16345);
	caseQueue.updatePriority(9521, 37967);
	myResult.push_back(caseQueue.getPriority(107)); //7
	caseQueue.updatePriority(59218, 36225);
	caseQueue.updatePriority(36594, 91761);
	caseQueue.updatePriority(46342, 24573);
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(89799,34981);
	myResult.push_back(caseQueue.deleteMin()); //9
	myResult.push_back(caseQueue.getPriority(89799)); //10
	caseQueue.insert(17868,22154);
	myResult.push_back(caseQueue.getPriority(46342)); //11
	myResult.push_back(caseQueue.getPriority(36594)); //12
	caseQueue.insert(76245,32094);
	caseQueue.insert(8907,56767);
	caseQueue.insert(72298,66612);
	caseQueue.updatePriority(107, 82289);
	caseQueue.insert(82070,52561);
	caseQueue.insert(44515,32024);
	myResult.push_back(caseQueue.getPriority(82070)); //13
	caseQueue.updatePriority(8907, 25359);
	myResult.push_back(caseQueue.getPriority(99147)); //14
	caseQueue.insert(93180,14917);
	caseQueue.updatePriority(76245, 63022);
	static const int resultListArray[] = {47354, 39156, 96308, 45689, 4025, 85313, 44094, 56449, 12737, 34981, 24573, 91761, 52561, 45689}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(96): Basarili" << endl;
	else cout << "Case(96): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_97(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 41);

	vector<int> myResult; 
	myResult.push_back(caseQueue.getPriority(59613)); //1
	caseQueue.updatePriority(70892, 91096);
	myResult.push_back(caseQueue.deleteMin()); //2
	myResult.push_back(caseQueue.getPriority(7930)); //3
	caseQueue.insert(70394,38159);
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.getPriority(56666)); //5
	myResult.push_back(caseQueue.getPriority(31892)); //6
	caseQueue.insert(84942,82853);
	myResult.push_back(caseQueue.deleteMin()); //7
	caseQueue.updatePriority(62309, 86843);
	caseQueue.insert(62320,11981);
	caseQueue.insert(79014,79259);
	caseQueue.updatePriority(79014, 23947);
	myResult.push_back(caseQueue.getPriority(79014)); //8
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.insert(87118,15604);
	caseQueue.insert(3004,39810);
	caseQueue.insert(79883,37651);
	caseQueue.updatePriority(79014, 47917);
	myResult.push_back(caseQueue.getPriority(79883)); //10
	caseQueue.updatePriority(79883, 12419);
	caseQueue.insert(65760,73596);
	caseQueue.insert(78177,77584);
	caseQueue.insert(88690,69230);
	myResult.push_back(caseQueue.getPriority(87118)); //11
	caseQueue.updatePriority(78177, 83031);
	caseQueue.insert(6438,75169);
	myResult.push_back(caseQueue.deleteMin()); //12
	caseQueue.updatePriority(6438, 60844);
	myResult.push_back(caseQueue.getPriority(6438)); //13
	caseQueue.updatePriority(87118, 96398);
	caseQueue.insert(31479,18348);
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.updatePriority(88690, 88924);
	caseQueue.insert(88143,69606);
	caseQueue.updatePriority(3004, 67398);
	caseQueue.updatePriority(88690, 79286);
	caseQueue.updatePriority(3004, 75091);
	caseQueue.updatePriority(3004, 19388);
	myResult.push_back(caseQueue.deleteMin()); //15
	static const int resultListArray[] = {-1, -1, -1, 70394, -1, -1, 84942, 23947, 62320, 37651, 15604, 79883, 60844, 31479, 3004}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(97): Basarili" << endl;
	else cout << "Case(97): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_98(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 37);

	vector<int> myResult; 
	caseQueue.updatePriority(29667, 59246);
	myResult.push_back(caseQueue.getPriority(47436)); //1
	caseQueue.insert(51639,45708);
	caseQueue.insert(40223,37945);
	caseQueue.insert(24857,61842);
	caseQueue.insert(77071,75920);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.insert(94079,69528);
	caseQueue.updatePriority(77071, 19292);
	caseQueue.updatePriority(77071, 46858);
	myResult.push_back(caseQueue.getPriority(51639)); //3
	caseQueue.insert(58327,42045);
	myResult.push_back(caseQueue.deleteMin()); //4
	caseQueue.insert(82669,85253);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(83520,49083);
	caseQueue.updatePriority(82669, 61456);
	myResult.push_back(caseQueue.getPriority(94079)); //6
	myResult.push_back(caseQueue.getPriority(83520)); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(92022,16676);
	caseQueue.insert(44756,67075);
	caseQueue.insert(97508,39445);
	caseQueue.insert(86240,9579);
	caseQueue.insert(21836,87604);
	myResult.push_back(caseQueue.getPriority(92022)); //9
	myResult.push_back(caseQueue.deleteMin()); //10
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(16655,10819);
	myResult.push_back(caseQueue.getPriority(16655)); //12
	caseQueue.insert(79676,36200);
	caseQueue.insert(44376,99125);
	caseQueue.updatePriority(16655, 34530);
	caseQueue.insert(48357,52586);
	myResult.push_back(caseQueue.getPriority(16655)); //13
	myResult.push_back(caseQueue.deleteMin()); //14
	caseQueue.updatePriority(83520, 54502);
	static const int resultListArray[] = {-1, 40223, 45708, 58327, 51639, 69528, 49083, 77071, 16676, 86240, 92022, 10819, 34530, 16655}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(98): Basarili" << endl;
	else cout << "Case(98): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_99(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 35);

	vector<int> myResult; 
	caseQueue.insert(84852,68633);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.updatePriority(28682, 55464);
	caseQueue.insert(40518,76554);
	caseQueue.insert(27773,16578);
	myResult.push_back(caseQueue.getPriority(27773)); //2
	caseQueue.insert(17414,59317);
	caseQueue.updatePriority(27773, 37797);
	caseQueue.insert(94442,29938);
	caseQueue.insert(46418,4829);
	caseQueue.insert(91657,14468);
	myResult.push_back(caseQueue.getPriority(91657)); //3
	caseQueue.insert(60485,95582);
	myResult.push_back(caseQueue.getPriority(94442)); //4
	caseQueue.updatePriority(27773, 38742);
	myResult.push_back(caseQueue.deleteMin()); //5
	caseQueue.insert(21410,2736);
	myResult.push_back(caseQueue.getPriority(27773)); //6
	caseQueue.insert(13047,8783);
	caseQueue.insert(78276,28566);
	caseQueue.insert(40095,86194);
	caseQueue.insert(50867,81272);
	caseQueue.updatePriority(13047, 72389);
	caseQueue.insert(92287,75378);
	caseQueue.updatePriority(13047, 37871);
	myResult.push_back(caseQueue.deleteMin()); //7
	myResult.push_back(caseQueue.getPriority(92287)); //8
	caseQueue.insert(49896,10551);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.insert(91849,56723);
	myResult.push_back(caseQueue.deleteMin()); //10
	caseQueue.updatePriority(91849, 11967);
	myResult.push_back(caseQueue.deleteMin()); //11
	caseQueue.insert(13168,94915);
	caseQueue.insert(17650,47502);
	static const int resultListArray[] = {84852, 16578, 14468, 29938, 46418, 38742, 21410, 75378, 49896, 91657, 91849}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(99): Basarili" << endl;
	else cout << "Case(99): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

void case_100(){

	int ITEM_NOT_ON_QUEUE = -1;
	int QUEUE_EMPTY = -1;
	DynamicPriorityQueue<int,int> caseQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY, 45);

	vector<int> myResult; 
	caseQueue.insert(86536,57870);
	caseQueue.updatePriority(86536, 82630);
	caseQueue.insert(33846,67605);
	myResult.push_back(caseQueue.deleteMin()); //1
	caseQueue.insert(11181,2845);
	caseQueue.insert(26194,6746);
	caseQueue.updatePriority(26194, 72575);
	caseQueue.updatePriority(86536, 71699);
	caseQueue.updatePriority(86536, 94840);
	caseQueue.updatePriority(86536, 32623);
	caseQueue.updatePriority(86536, 2394);
	caseQueue.insert(98113,36674);
	caseQueue.insert(72491,28142);
	caseQueue.updatePriority(72491, 95386);
	caseQueue.insert(46647,88866);
	myResult.push_back(caseQueue.deleteMin()); //2
	caseQueue.updatePriority(98113, 50405);
	myResult.push_back(caseQueue.getPriority(98113)); //3
	caseQueue.insert(39271,65220);
	myResult.push_back(caseQueue.deleteMin()); //4
	myResult.push_back(caseQueue.getPriority(98113)); //5
	caseQueue.updatePriority(46647, 23682);
	caseQueue.updatePriority(72491, 35147);
	caseQueue.insert(49204,85428);
	myResult.push_back(caseQueue.getPriority(26194)); //6
	myResult.push_back(caseQueue.getPriority(46647)); //7
	myResult.push_back(caseQueue.deleteMin()); //8
	caseQueue.insert(61052,26314);
	caseQueue.insert(64745,26284);
	caseQueue.insert(23251,71653);
	caseQueue.insert(16668,46430);
	myResult.push_back(caseQueue.deleteMin()); //9
	caseQueue.insert(35445,37596);
	caseQueue.insert(99082,95373);
	caseQueue.insert(1036,87818);
	caseQueue.updatePriority(35445, 38597);
	caseQueue.updatePriority(98113, 38044);
	myResult.push_back(caseQueue.getPriority(16668)); //10
	caseQueue.insert(97523,7507);
	caseQueue.insert(58889,56068);
	caseQueue.insert(3081,41379);
	caseQueue.insert(62896,21430);
	caseQueue.updatePriority(61052, 76039);
	myResult.push_back(caseQueue.getPriority(1036)); //11
	caseQueue.insert(46940,43907);
	static const int resultListArray[] = {33846, 86536, 50405, 11181, 50405, 72575, 23682, 46647, 64745, 46430, 87818}; 
	vector<int> resultList (resultListArray, resultListArray + sizeof(resultListArray) / sizeof(resultListArray[0]) );
	if(resultList == myResult) cout << "Case(100): Basarili" << endl;
	else cout << "Case(100): Hatali" << endl;
/*	 int opCount = 1;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for(it = myResult.begin(), it2 = resultList.begin() ; it != myResult.end(); ++it, ++it2)
		std::cout << (*it) << " - " << (*it2) <<  " / Operation(" << opCount++ << ")" << endl;
*/
}

int main(int argc, char **argv) {
	case_1();
	case_2();
	case_3();
	case_4();
	case_5(); 
	case_6();
	case_7();
	case_8();
	case_9();
	case_10();
	case_11();
	case_12();
	case_13();
	case_14();
	case_15();
	case_16();
	case_17();
	case_18();
	case_19();
	case_20();
	case_21();
	case_22();
	case_23();
	case_24();
	case_25();
	case_26();
	case_27();
	case_28();
	case_29();
	case_30();
	case_31();
	case_32();
	case_33();
	case_34();
	case_35();
	case_36();
	case_37();
	case_38();
	case_39();
	case_40();
	case_41();
	case_42();
	case_43();
	case_44();
	case_45();
	case_46();
	case_47();
	case_48();
	case_49();
	case_50();
	case_51();
	case_52();
	case_53();
	case_54();
	case_55();
	case_56();
	case_57();
	case_58();
	case_59();
	case_60();
	case_61();
	case_62();
	case_63();
	case_64();
	case_65();
	case_66();
	case_67();
	case_68();
	case_69();
	case_70();
	case_71();
	case_72();
	case_73();
	case_74();
	case_75();
	case_76();
	case_77();
	case_78();
	case_79();
	case_80();
	case_81();
	case_82();
	case_83();
	case_84();
	case_85();
	case_86();
	case_87();
	case_88();
	case_89();
	case_90();
	case_91();
	case_92();
	case_93();
	case_94();
	case_95();
	case_96();
	case_97();
	case_98();
	case_99();
	case_100(); 
}
