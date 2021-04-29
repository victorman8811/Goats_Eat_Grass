#ifndef _CREATURE_H
#define _CREATURE_H

class creature{


	public:

		int age;
		int point;
		int judge;//1=goat,0=grass
		int move;//1=has moved,0=didn't move
		int act;//0 is move,2 is goat_child,1 is eat_grass,4 is grass_child
		virtual int die_judge();

};

#endif
