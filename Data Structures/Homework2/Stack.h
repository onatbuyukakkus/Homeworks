#include <cstdlib>// This library is added for the NULL keyword

class StackException// Throw this exception class when invalid stack operation is performed
{
	public:
   		StackException() : message( "Stack is Empty !! Invalid Operation !" ) { }
   		const char *show() const { return message; }
	private:
   		const char *message;
};

template <typename T>
class Stack
{
	public:
   		Stack();// Default Constructor
		Stack(const Stack<T>& aStack);// Copy Constructor
		Stack<T>& operator=(const Stack<T>& rhs);// Overloading assignment
   		~Stack();// Destructor

		bool isEmpty() const;// Check whether the stack is empty or not. Return true if empty, otherwise return false
   		void push(const T& newItem);// Add an element to the top of the stack
   		void pop();// Remove the top of the stack
   		T top() const;// Return the top of the stack without removing it

	private:
   		struct stackNode 
		{       
      			T item;// Value of a stack node
      			stackNode *next;// Next pointer of a stack node
   		};  
   		stackNode *topPtr;// Initial stack pointer
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* IMPLEMENT YOUR SOLUTION BELOW THIS MESSAGE. DO NOT MODIFIY AND DELETE ANYTHING IN THIS MESSAGE AND ABOVE !! */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/****constructor****/
template <typename T>
Stack<T>::Stack()
{
	topPtr = new stackNode;
	topPtr = NULL;
}

/****copy constructor******/
template <typename T>
Stack<T>::Stack(const Stack<T>& aStack)
{
	*this = aStack;	
}

/****= operator****/
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& rhs)
{
	if(this != &rhs)
	{
		if(!rhs.topPtr)
		{
		topPtr = NULL;
		}
		else
		{
			topPtr = new stackNode;
			topPtr->item = rhs.topPtr->item;
			stackNode* q = rhs.topPtr->next;
			stackNode* p = topPtr;
			while(q)
			{
				p->next = new stackNode;
				p->next->item = q->item;
				p = p->next;
				q = q->next;
			}
			p->next = NULL;
		}
	}
	return *this;
}

/******destructor*****/
template <typename T>
Stack<T>::~Stack()
{
	while(!isEmpty())
	{
	 pop();
	}
}

/*****is empty*****/
template <typename T>
bool Stack<T>::isEmpty() const
{
	return topPtr == NULL;
}

/******push******/
template <typename T>
void Stack<T>::push(const T& newItem)
{
	stackNode *newPtr = new stackNode;
	newPtr->item = newItem;
	newPtr->next = topPtr;
	topPtr = newPtr;
}

/******pop*****/
template <typename T>
void Stack<T>::pop()
{
	if(isEmpty())
	{
		throw StackException();
	}
	else
	{
		stackNode *tmp = topPtr;
		topPtr = topPtr->next;
		delete tmp;
	}	
}

/*****top*****/
template <typename T>
T Stack<T>::top() const
{
	if(isEmpty())
	{
		throw StackException();
	}
	else
	{
		return topPtr->item;
	}
}






