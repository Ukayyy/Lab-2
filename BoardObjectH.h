#ifndef H_BOARD_OBJECT
#define H_BOARD_OBJECT
enum ObjectColours { BLACK, YELLOW, BLUE, RED, INVISIBLE, BACKGROUND};
enum ObjectTypes { THE_BACKGROUND, A_COOKIE, A_PLAYER ,A_WALL};


class BoardObject
{

private:
        int x,y;
        ObjectColours currentColor;
protected:
	ObjectTypes myClass;
	//int unique_ID;
	//static int count;
public:
        BoardObject (int startX, int startY)
                { x=startX; y=startY;
                  currentColor=BACKGROUND; 
		  myClass=THE_BACKGROUND;
		  
		  //unique_ID=count++;
                };

        //int get_ID() { return unique_ID;};

        int getX() { return x;};
        int getX() { return y;};
	ObjectTypes get_Type() {return myClass;}
	

        ObjectColours getColor() {return currentColor; }

        virtual void touch() {currentColor=BACKGROUND; }

protected:

	void set_color(ObjectColours new_color)
		{currentColor=new_color;};
        void setX(int new_x) { x=new_x;};
        void setY(int new_y) {y=new_y;};


};

//int BoardObject::count=0;
#endif // H_BOARD_OBJECT

