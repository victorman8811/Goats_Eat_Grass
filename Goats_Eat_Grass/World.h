#ifndef _WORLD_H
#define _WORLD_H
#include "Goat.h"
#include "Grass.h"

class world{

	public:

		world(int numpass,int display,int seed);
		void goat_move(creature *arr[20][35],int move_count);
		void goat_child(creature *arr[20][35],int move_count);
		void grass_child(creature *arr[20][35],int move_count);
		void act_select(creature *arr[20][35]);
		void old(creature *arr[20][35]);
		void show(creature *arr[20][35]);
};


#endif
