//
//  DpqTest.cpp
//  
//
//  Created by Dilek on 24/12/14.
//
//

#include <iostream>
#include "DynamicPriorityQueue.h"

using namespace std;

int main(int argc, char **argv) {
    
    long ITEM_NOT_ON_QUEUE = -1;
    long QUEUE_EMPTY = -1;
    DynamicPriorityQueue<long,int> customerQueue(ITEM_NOT_ON_QUEUE,QUEUE_EMPTY,4);
    
    customerQueue.insert(10,3);
    customerQueue.insert(8,5);
    customerQueue.insert(11,6);
    customerQueue.insert(19,2);
    
    cout << "Get  priority of 25: " << customerQueue.getPriority(25) << endl;
    cout << "Get  priority of 11: " << customerQueue.getPriority(11) << endl;
    cout << "Get  priority of 8: " << customerQueue.getPriority(8) << endl;
    cout << "Get  priority of 19: " << customerQueue.getPriority(19) << endl;
    cout << "Get  priority of 10: " << customerQueue.getPriority(10) << endl;
    cout << endl;
	//customerQueue.print();
    cout << "Min Key: "  << customerQueue.deleteMin() << endl;
	//customerQueue.print();
    customerQueue.updatePriority(11,1);

    cout << "Min Key: "  << customerQueue.deleteMin() << endl;
    	//customerQueue.print();
    customerQueue.updatePriority(10,7);

    cout << "Min Key: "  << customerQueue.deleteMin() << endl;
        //	customerQueue.print();
    cout << "Min Key: "  << customerQueue.deleteMin() << endl;
        //	customerQueue.print();
    cout << "Min Key: "  << customerQueue.deleteMin() << endl;
    	//customerQueue.print();

}
