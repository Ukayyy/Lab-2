#include <iostream>

#include "BoardObjectH.h"
#include "PlayerH.h"

void Player :: touch ()
		{ switch (status)
		  { case ALIVE : if (color1==getColor() )
			            setColor(color2);
			          else
			             setColor(color1);
                                   break;
		    case  DEAD :
			             setColor(YELLOW);
		  }
		//std::cerr << " Player Object touched\n";
		}
