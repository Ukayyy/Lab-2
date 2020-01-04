
#include  <string>
#include <iostream>
#include  "BoardH.h"
#include  "ListBoardObjectsH.h"

using namespace std;


void touch_all (pListBoardObjects aList)
{
	pBoardObject toIterate;

	toIterate=aList->theFirst();

	while (NULL!=toIterate)
	{
		toIterate->touch();

		//cerr << "Touching "<< toIterate->get_x() <<"," <<toIterate->get_y() << std::endl;
		toIterate=aList->theNext();

	}

}

char game_all (pListBoardObjects aList)
{
	
	pBoardObject toIterate;

	toIterate=aList->theFirst();

	ObjectColours color =  BACKGROUND;

	while (NULL!=toIterate)
	{
		if ( BACKGROUND != toIterate->get_Color() )
		   color=toIterate->get_Color();

		toIterate=aList->theNext();
	}

	switch (color)
	{	case YELLOW : return 'Y';
	 	case BLACK : return '#';
	 	case BLUE : return 'B';
	 	case RED : return 'R';
	 	case INVISIBLE : return 'I';
	 	case BACKGROUND : return '*';
	}
}

void Board:: move(char command)
{
	if ('p'!=command)
	{
	  switch (command)
	   { case 'e': if (playerIdX<=0) break;
			else
			  { 
                            if (!  mySpace[playerIdX-1][playerIdY]->isThereAWall())
			      { mySpaceplayerIdX][playerIdY]->removeOnePlayer();
			        playerIdX--;
			        startPlayer = new Player(playerIdX,playerIdY);
                                mySpace[playerIdX][playerIdY]->addOne(startPlayer);

                              }
			  }
		     break;
	     case 'x': if (playerIdX>=the_rows-1) break;
			else
			  { 
                            if (!  mySpace[playerIdX-1][playerIdY]->isThereAWall())
			      { mySpaceplayerIdX][playerIdY]->removeOnePlayer();
			        playerIdX--;
			        startPlayer = new Player(playerIdX,playerIdY);
                                mySpace[playerIdX][playerIdY]->addOne(startPlayer);
                              }
			  }
		     break;
	     case 's': if (player_id_y<=0) break;
			else
			  { 
                            if (!  mySpace[playerIdX-1][playerIdY]->isThereAWall())
			      { mySpaceplayerIdX][playerIdY]->removeOnePlayer();
			        playerIdX--;
			        startPlayer = new Player(playerIdX,playerIdY);
                                mySpace[playerIdX][playerIdY]->addOne(startPlayer);
                              }
			  }
		     break;
	     case 'd': if (playerIdY>=the_cols-1) break;
                       else
			  { 
                           if (!  mySpace[playerIdX-1][playerIdY]->isThereAWall())
			      { mySpaceplayerIdX][playerIdY]->removeOnePlayer();
			        playerIdX--;
			        startPlayer = new Player(playerIdX,playerIdY);
                                mySpace[playerIdX][playerIdY]->addOne(startPlayer);
                              }
			  }
		     break;
	   }
	   int cookieValue = mySpace[playerIdX][playerIdY]->isCookieValue();
	   if (cookieValue>0)
		{
		    std::cerr << "Ate a cookie\n";
		    currentScore+=cookieValue;
		}

	}
}

void Board:: paint()
	{ char draw;
          std::string row;

          for (int i=0; i<the_rows; i++)
	   { row="";
	     for (int j=0; j<the_cols; j++)
		{  touch_all (mySpace[i][j]);
		   draw =game_all(mySpace[i][j]);
		   row.push_back(draw);
		}
              cout << row << endl;
           }
	   cout << "CURRENT SCORE : "<< currentScore << endl;
	}

