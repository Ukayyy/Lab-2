#include <iostream>
#include "BoardObjectH.h"
#include "ListBoardObjectsH.h"

ListBoardObjects:: ListBoardObjects(pBoardObject newOne):list()
	{
	 	std::vector <pBoardObject>:: iterator it;
	 	it=list.begin();
	 	list.insert(it,newOne);
        }

pBoardObject ListBoardObjects:: theFirst()
	{
	   if (0 < list.size()  ) 
		{ internalIterator=list.begin();
	   	  return (*internalIterator);
		}
	   else
		return NULL;
	}


void ListBoardObjects:: addOne(pBoardObject newOne)
	 { 
	 	std::vector <pBoardObject>:: iterator it;
	 	it=list.begin();
	 	list.insert(it,newOne);
	 }

pBoardObject ListBoardObjects :: theNext()
	{ 
	   internalIterator++;
	   if (internalIterator < list.end())
	   {
		   return (*internalIterator);
	   }
	   else
		return NULL;
	}

void ListBoardObjects :: removeOnePlayer()
	{
	   std::vector <pBoardObject>:: iterator it;
	   it=list.begin();
	   while (it<list.end())
		{ if (A_PLAYER==(*it)->getType())
		   { list.erase(it); return;}
                  it++;
		}

	   return ;
	}


bool ListBoardObjects :: isThereAWall()
	{
	   std::vector <p_BoardObject>:: iterator it;
	   it=list.begin();
	   while (it<list.end())
		{ if (A_WALL==(*it)->get_Type())
		   {  return true;}
                  it++;
		}

	   return false ;
	}


int ListBoardObjects :: isCookieValue()
	{   int temp=0;
	   std::vector <pBoardObject>:: iterator it;
	   it=list.begin();
	   while (it<list.end())
		{ if (A_COOKIE==(*it)->getType())
		   { temp= ((Cookie *)(*it))->get_value();
		     list.erase(it); 
		     return temp;
                   }
                  it++;
		}

	   return temp ;
	}
