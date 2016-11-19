#include "qtree.h"
#include "rectangle.h"
#include <iostream>
using namespace std;

QTree::QTree(int a)
{
	size = a;
	level = 0;
	firstChild = NULL;
	secondChild = NULL;
	thirdChild = NULL;
	fourthChild = NULL;
	recChild = NULL;
	firstCoor.setx(0);
	firstCoor.sety(0);
	rectang = new Rectangle(Coordinate(0,0), Coordinate(0,0));
		rectang->setTopLeft(Coordinate(firstCoor.getx(),firstCoor.gety()));
		rectang->setBottomRight(Coordinate(size-1,size-1));
}

QTree::QTree(const QTree& a)
{
	rectang = new Rectangle(Coordinate(0,0), Coordinate(0,0));

	recChild = a.recChild;
	level = a.level;
	size = a.size;
	rectang = a.rectang;
	firstCoor.setx(a.firstCoor.getx());
	firstCoor.sety(a.firstCoor.gety());

	if (a.firstChild != NULL)
	{
		firstChild = new QTree(size/2);
		secondChild = new QTree(size/2);
		thirdChild = new QTree(size/2);
		fourthChild = new QTree(size/2);
		*firstChild = *(a.firstChild);
		*secondChild = *(a.secondChild);
		*thirdChild = *(a.thirdChild);
		*fourthChild = *(a.fourthChild);
	}
	else
	{
		firstChild = NULL;
		secondChild = NULL;
		thirdChild = NULL;
		fourthChild = NULL;
	}

}


QTree::~QTree()
{
	if (firstChild) delete firstChild;
	if (secondChild) delete secondChild;
	if (thirdChild) delete thirdChild;
	if (fourthChild) delete fourthChild;
	if (rectang) delete rectang;
}

int QTree::finder(Rectangle a)
{
	int result;
	if (firstChild->rectang->intersects(a) && secondChild->rectang->intersects(a) && thirdChild->rectang->intersects(a) && fourthChild->rectang->intersects(a))
	{
		result = 1234;
	}
	else if (thirdChild->rectang->intersects(a) && fourthChild->rectang->intersects(a))
	{
		result = 34;
	}
	else if (secondChild->rectang->intersects(a) && thirdChild->rectang->intersects(a))
	{
		result = 23;
	}
	else if (firstChild->rectang->intersects(a) && fourthChild->rectang->intersects(a))
	{
		result = 14;
	}
	else if (firstChild->rectang->intersects(a) && secondChild->rectang->intersects(a))
	{
		result = 12;
	}
	else if (firstChild->rectang->intersects(a))
	{
		result = 1;
	}
	else if (secondChild->rectang->intersects(a))
	{
		result = 2;
	}
	else if (thirdChild->rectang->intersects(a))
	{
		result = 3;
	}
	else if (fourthChild->rectang->intersects(a))
	{
		result = 4;
	}

	return result;

}

void QTree::insert(const Rectangle& a)
{
	if (firstChild == NULL && secondChild == NULL && thirdChild==NULL && fourthChild == NULL && recChild == NULL)
	{
		recChild = &a;
	}
	else
	{
		if (firstChild == NULL && secondChild == NULL && thirdChild==NULL && fourthChild == NULL)
		{
			firstChild = new QTree(size/2);
			firstChild->rectang = new Rectangle (Coordinate(firstCoor.getx(),firstCoor.gety()), Coordinate(((size/2)+(firstCoor.getx())-1),((size/2)+(firstCoor.gety())-1)));
			firstChild->firstCoor.setx(firstCoor.getx());
			firstChild->firstCoor.sety(firstCoor.gety());
			firstChild->level = this -> level + 4;

			secondChild = new QTree(size/2);
			secondChild->rectang = new Rectangle (Coordinate((size/2)+(firstCoor.getx()),firstCoor.gety()), Coordinate((size-1)+firstCoor.getx(),(size/2)-1+(firstCoor.gety())));
			secondChild->firstCoor.setx((size/2)+(firstCoor.getx()));
			secondChild->firstCoor.sety((firstCoor.gety()));
			secondChild->level = this -> level + 4;

			thirdChild = new QTree(size/2);
			thirdChild->rectang = new Rectangle (Coordinate((size/2)+(firstCoor.getx()),(size/2)+(firstCoor.gety())), Coordinate(firstCoor.getx()+(size-1),firstCoor.gety()+(size-1)));
			thirdChild->firstCoor.setx((size/2)+(firstCoor.getx()));
			thirdChild->firstCoor.sety((size/2)+(firstCoor.gety()));
			thirdChild->level = this -> level + 4;

			fourthChild = new QTree(size/2);
			fourthChild->rectang = new Rectangle (Coordinate(firstCoor.getx(),(size/2)+(firstCoor.gety())), Coordinate((size/2)-1+(firstCoor.getx()),(firstCoor.gety()+size-1)));
			fourthChild->firstCoor.setx(firstCoor.getx());
			fourthChild->firstCoor.sety((size/2)+(firstCoor.gety()));
			fourthChild->level = this -> level + 4;
		}

		if(recChild != NULL)
		{
			if (finder(*recChild) == 1)
			{
				firstChild->recChild = this->recChild;
			}
			if (finder(*recChild) == 2)
			{
				secondChild->recChild = this->recChild;
			}
			if (finder(*recChild) == 3)
			{
				thirdChild->recChild = this->recChild;
			}
			if (finder(*recChild) == 4)
			{
				fourthChild->recChild = this->recChild;
			}
			if (finder(*recChild) == 12)
			{
				firstChild->recChild = this->recChild;
				secondChild->recChild = this->recChild;
			}
			if (finder(*recChild) == 14)
			{
				firstChild->recChild = this->recChild;
				fourthChild->recChild = this->recChild;
			}
			if (finder(*recChild) == 23)
			{
				secondChild->recChild = this->recChild;
				thirdChild->recChild = this->recChild;
			}
			if (finder(*recChild) == 34)
			{
				thirdChild->recChild = this->recChild;
				fourthChild->recChild = this->recChild;
			}
			if (finder(*recChild) == 1234)
			{
				firstChild->recChild = this->recChild;
				secondChild->recChild = this->recChild;
				thirdChild->recChild = this->recChild;
				fourthChild->recChild = this->recChild;
			}
			recChild = NULL;
		}


		if (finder(a) == 1)
		{
			firstChild->insert(a);
 		}
		if (finder(a) == 2)
		{
			secondChild->insert(a);
		}
		if (finder(a) == 3)
		{
			thirdChild->insert(a);
		}
		if (finder(a) == 4)
		{
			fourthChild->insert(a);
		}
		if (finder(a) == 12)
		{
			firstChild->insert(a);
			secondChild->insert(a);
		}
		if (finder(a) == 14)
		{
			firstChild->insert(a);
			fourthChild->insert(a);
		}
		if (finder(a) == 23)
		{
			secondChild->insert(a);
			thirdChild->insert(a);
		}
		if (finder(a) == 34)
		{
			thirdChild->insert(a);
			fourthChild->insert(a);
		}
		if (finder(a) == 1234)
		{
			firstChild->insert(a);
			secondChild->insert(a);
			thirdChild->insert(a);
			fourthChild->insert(a);
		}
	}
}

const Rectangle* QTree::operator[](const Coordinate& a) const
{
	if(recChild != NULL)
	{
		if(recChild->contains(a))
		{
			return recChild;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		if(firstChild->rectang->contains(a))
		{
			return (*firstChild)[a];
		}
		if(secondChild->rectang->contains(a))
		{
			return (*secondChild)[a];
		}
		if(thirdChild->rectang->contains(a))
		{
			return (*thirdChild)[a];
		}
		if(fourthChild->rectang->contains(a))
		{
			return (*fourthChild)[a];
		}
	}	
}

ostream& operator<<(ostream& ost,  const QTree& qTree)
{
	if (qTree.recChild != NULL)
	{
		ost << "(" << qTree.rectang->getTopLeft().getx() << "," << qTree.rectang->getTopLeft().gety() << ")" << " " << "[" << qTree.size << "]" << " " << "***" << " " << "(" << qTree.recChild->getTopLeft().getx() << "," << qTree.recChild->getTopLeft().gety() << ")" << " " << "[" << qTree.recChild->getBottomRight().getx() - qTree.recChild->getTopLeft().getx() + 1 << "," << qTree.recChild->getBottomRight().gety() - qTree.recChild->getTopLeft().gety() + 1 << "]" << " " << "***" << "\n";
	}
	else
	{
		ost << "(" << qTree.rectang->getTopLeft().getx() << "," << qTree.rectang->getTopLeft().gety() << ")" << " " << "[" << qTree.size << "]" << " " << "..." << "\n"; 
		if (qTree.firstChild != NULL)
		{
			for(int i=0; i<=qTree.firstChild->level; i++)
			{
				ost << " ";
			}
			ost << *(qTree.firstChild);
		}
		if (qTree.secondChild != NULL)
		{
			for(int i=0; i<=qTree.secondChild->level; i++)
			{
				ost << " ";
			}
			ost << *(qTree.secondChild);
		}
		if (qTree.thirdChild != NULL)
		{
			for(int i=0; i<=qTree.thirdChild->level; i++)
			{
				ost << " ";
			}
			ost << *(qTree.thirdChild);
		}
		if (qTree.fourthChild != NULL)
		{
			for(int i=0; i<=qTree.fourthChild->level; i++)
			{
				ost << " ";
			}
			ost << *(qTree.fourthChild);
		}
	}
	return ost;
}

QTree& QTree::operator=(const QTree& a)
{
	if(firstChild) delete firstChild;
	if(secondChild) delete secondChild;
	if(thirdChild) delete thirdChild;
	if(fourthChild) delete fourthChild;
	if(rectang) delete rectang;
	
	rectang = new Rectangle(Coordinate (a.rectang->getTopLeft().getx(), a.rectang->getTopLeft().gety()),Coordinate ((a.rectang->getBottomRight().getx()), (a.rectang->getBottomRight().gety())));

	recChild = a.recChild;
	level = a.level;
	size = a.size;
	firstCoor.setx(a.firstCoor.getx());
	firstCoor.sety(a.firstCoor.gety());

	if (a.firstChild != NULL)
	{
		firstChild = new QTree(size/2);
		secondChild = new QTree(size/2);
		thirdChild = new QTree(size/2);
		fourthChild = new QTree(size/2);
		*firstChild = *(a.firstChild);
		*secondChild = *(a.secondChild);
		*thirdChild = *(a.thirdChild);
		*fourthChild = *(a.fourthChild);
	}
	else
	{
		firstChild = NULL;
		secondChild = NULL;
		thirdChild = NULL;
		fourthChild = NULL;
	}
	return *this;
}

	