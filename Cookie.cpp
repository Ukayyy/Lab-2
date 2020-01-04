


#include "BoardObjectH.h"
#include "CookieH.h"

int PrizeValues[]={10,20,30,40};

void Cookie :: touch ()
		{ switch (status)
		  { case VISIBLE : if (color1==getColor() )
			            set_color(color2);
			          else
			             setColor(color1);
                                   break;
		    case  EATEN :
		    case  EXPIRED :
			             setColor(BACKGROUND);
		  }
		}

int Cookie :: getValue ()
	{return PrizeValues[valueIndex]; }

