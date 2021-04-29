#include "World.h"
#include<stdlib.h>
#include <stdio.h>
#include<iostream>
//#include "Goat.h"
//#include "Grass.h"
//10=show
//69=world
//151=act_select
//214=old
//343=goat_child
//240=grass_child

using namespace std;

void world::show(creature *arr[20][35]){

	int count=0;

	printf(" ");

	for(int i=0;i<35;i++){

		if(count==10){
			count=0;
		}

		printf(" ");
		printf("%d",count);
		count++;
	}

	count=0;
	printf("\n");

	for(int i=0;i<20;i++){

		if(count==10){
			count=0;
		}
		printf("%d",count);
		count++;

		for(int j=0;j<35;j++){

			if(arr[i][j]==NULL){

				printf("  ");

			}

			else if((arr[i][j])->judge==1){

				printf(" X");

			}

			else if((arr[i][j])->judge==0){

				printf(" I");

			}

		}
		printf("\n");

	}

		printf("------------------------------------------------------------------------\n");

	
}





world::world(int numpass,int display,int seed){

	creature *arr[20][35];

	for(int i=0;i<20;i++){

		for(int j=0;j<35;j++){

			arr[i][j]=NULL;

		}
	}

    srand(seed);

	for(int i=0;i<5;i++){

		int count=0;
		int x;
		int y;

		while(count==0){

			x=rand()%20;
			y=rand()%35;

			
			if(arr[x][y]==NULL){

				count=1;

			}
	
		}
		

		
		arr[x][y]=new goat;

		(arr[x][y])->age=0;
		(arr[x][y])->point=20;
		(arr[x][y])->judge=1;
		(arr[x][y])->move=0;

	}

	for(int i=0;i<10;i++){

		int count=0;
		int x;
		int y;

		while(count==0){

			x=rand()%20;
			y=rand()%35;

			if(arr[x][y]==NULL){

				count=1;

			}
		}

			
		arr[x][y]=new grass;

		(arr[x][y])->age=0;
		(arr[x][y])->judge=0;
		(arr[x][y])->move=0;


	}

	show(arr);

	int count_display=0;

	for(int i=0;i<numpass;i++){

		old(arr);
		act_select(arr);
		goat_move(arr,i);
		goat_child(arr,i);
		grass_child(arr,i);
		if(count_display==display){

			show(arr);
			count_display=0;

		}
		(count_display)++;

	}	


}

void world::act_select(creature *arr[20][35]){

	for(int i=0;i<20;i++){

		for(int j=0;j<35;j++){

			if(arr[i][j]==NULL){

				continue;

			}

			else if(arr[i][j]->judge==1){

				
				if(arr[i][j]->age<50 || arr[i][j]->age>55){
				
					(arr[i][j]->act)=0;
				
				}

				else{
					(arr[i][j]->act)=2;
				}


			}

			else if(arr[i][j]->judge==0){

				if(arr[i][j]->age>2 && arr[i][j]->age<6){

					(arr[i][j]->act)=4;


				}
				else{
					(arr[i][j])->move=(arr[i][j])->move+1;

				}
				
			}
			}
		}
	}






void world::old(creature *arr[20][35]){

	for(int i=0;i<20;i++){

		for(int j=0;j<35;j++){

			if(arr[i][j]!=NULL){

				int temp=0;
				(arr[i][j]->age)++;
				
				if(arr[i][j]->judge==1){

					arr[i][j]->point=(arr[i][j]->point)-1;

				}


				temp=(arr[i][j])->die_judge();
				if(temp==1){

					arr[i][j]=NULL;

				}

			}

		}
	}
}

void world::grass_child(creature *arr[20][35],int move_count){

	
	for(int i=0;i<20;i++){

		for(int j=0;j<35;j++){

			if(arr[i][j]!=NULL && (arr[i][j]->judge)==0 && (arr[i][j]->age)>2 && (arr[i][j]->age)<6 && (arr[i][j]->move)==move_count && (arr[i][j]->act)==4){

				(arr[i][j]->move)++;

				int direct;
				int count=0;
	
				while(count==0){
				
				
					direct=rand()%4;//0 is up,1 is down,2 is right,3 is left

					if(direct==0 && i-1>0){

						count=1;

					}

					if(direct==1 && i+1<20){

						count=1;

					}

					if(direct==2 && j+1<35){

						count=1;

					}

					if(direct==3 && j-1>0){

						count=1;

					}

				}

				if(direct==0){

					if(arr[i-1][j]==NULL){
			
						arr[i-1][j]=new grass;
						arr[i-1][j]->age=0;
						arr[i-1][j]->move=move_count+1;
						arr[i-1][j]->judge=0;
						

					}

				}

				if(direct==1){

					if(arr[i+1][j]==NULL){
			
						arr[i+1][j]=new grass;
						arr[i+1][j]->age=0;
						arr[i+1][j]->move=move_count+1;
						arr[i+1][j]->judge=0;

					}

				}

				if(direct==2){

					if(arr[i][j+1]==NULL){
			
						arr[i][j+1]=new grass;
						arr[i][j+1]->age=0;
						arr[i][j+1]->move=move_count+1;
						arr[i][j+1]->judge=0;
						

					}

				}

				if(direct==3){

					if(arr[i][j-1]==NULL){
			
						arr[i][j-1]=new grass;
						arr[i][j-1]->age=0;
						arr[i][j-1]->move=move_count+1;
						arr[i][j-1]->judge=0;

					}

				}
			}
		}
	}
}


void world::goat_child(creature *arr[20][35],int move_count){

	
	for(int i=0;i<20;i++){

		for(int j=0;j<35;j++){

			if(arr[i][j]!=NULL && (arr[i][j]->judge)==1 && (arr[i][j]->age)>49 && (arr[i][j]->age)<56 && (arr[i][j]->move)==move_count && (arr[i][j]->act)==2){

				(arr[i][j]->move)++;

				int direct;
				int count=0;
	

				while(count==0){
				
				
					direct=rand()%4;//0 is up,1 is down,2 is right,3 is left

					if(direct==0 && i-1>0){

						count=1;

					}

					if(direct==1 && i+1<20){

						count=1;

					}

					if(direct==2 && j+1<35){

						count=1;

					}

					if(direct==3 && j-1>0){

						count=1;

					}

				}

				if(direct==0){

					if(arr[i-1][j]!=NULL && arr[i-1][j]->judge==0){

						arr[i-1][j]=NULL;

						arr[i-1][j]=new goat;
						arr[i-1][j]->age=0;
						arr[i-1][j]->point=20;
						arr[i-1][j]->move=move_count+1;
						arr[i-1][j]->judge=1;

					}

					if(arr[i-1][j]==NULL){
			
						arr[i-1][j]=new goat;
						arr[i-1][j]->age=0;
						arr[i-1][j]->point=20;
						arr[i-1][j]->move=move_count+1;
						arr[i-1][j]->judge=1;
						

					}

				}

				if(direct==1){

					if(arr[i+1][j]!=NULL && arr[i+1][j]->judge==0){

						arr[i+1][j]=NULL;

						arr[i+1][j]=new goat;
						arr[i+1][j]->age=0;
						arr[i+1][j]->point=20;
						arr[i+1][j]->move=move_count+1;
						arr[i+1][j]->judge=1;
					}

					if(arr[i+1][j]==NULL){
			
						arr[i+1][j]=new goat;
						arr[i+1][j]->age=0;
						arr[i+1][j]->point=20;
						arr[i+1][j]->move=move_count+1;
						arr[i+1][j]->judge=1;

					}

				}

				if(direct==2){

					if(arr[i][j+1]!=NULL && arr[i][j+1]->judge==0){

						arr[i][j+1]=NULL;

						arr[i][j+1]=new goat;
						arr[i][j+1]->age=0;
						arr[i][j+1]->point=20;
						arr[i][j+1]->move=move_count+1;
						arr[i][j+1]->judge=1;
					}

					if(arr[i][j+1]==NULL){
			
						arr[i][j+1]=new goat;
						arr[i][j+1]->age=0;
						arr[i][j+1]->point=20;
						arr[i][j+1]->move=move_count+1;
						arr[i][j+1]->judge=1;
						

					}

				}

				if(direct==3){

					if(arr[i][j-1]!=NULL && arr[i][j-1]->judge==0){

						arr[i][j-1]=NULL;

						arr[i][j-1]=new goat;
						arr[i][j-1]->age=0;
						arr[i][j-1]->point=20;
						arr[i][j-1]->move=move_count+1;
						arr[i][j-1]->judge=1;

					}

					if(arr[i][j-1]==NULL){
			
						arr[i][j-1]=new goat;
						arr[i][j-1]->age=0;
						arr[i][j-1]->point=20;
						arr[i][j-1]->move=move_count+1;
						arr[i][j-1]->judge=1;

					}

				}
			}
		}
	}
}

void world::goat_move(creature *arr[20][35],int move_count){



	for(int i=0;i<20;i++){

		for(int j=0;j<35;j++){
			
			if(arr[i][j]!=NULL && (arr[i][j])->judge==1 && ((arr[i][j])->age<50 || ((arr[i][j])->age>55 && (arr[i][j])->age<70)) && (arr[i][j])->move==move_count && (arr[i][j]->act)==0){

				int count=0;

				int direct;

				((arr[i][j])->move)++;

				
				while(count==0){
				
				
					direct=rand()%4;//0 is up,1 is down,2 is right,3 is left

					if(direct==0 && i-1>0){

						count=1;

					}

					if(direct==1 && i+1<20){

						count=1;

					}

					if(direct==2 && j+1<35){

						count=1;

					}

					if(direct==3 && j-1>0){

						count=1;

					}

				}

			
				if(direct==0){

					if(arr[i-1][j]==NULL){
			
						arr[i-1][j]=arr[i][j];
						arr[i][j]=NULL;

					}

					if(arr[i-1][j]!=NULL && arr[i-1][j]->judge==0){

						arr[i-1][j]=NULL;
						arr[i][j]->point=(arr[i][j]->point)+5;
						arr[i-1][j]=arr[i][j];
						arr[i][j]=NULL;

					}

				}

				if(direct==1){

					if(arr[i+1][j]==NULL){
			
						arr[i+1][j]=arr[i][j];
						arr[i][j]=NULL;

					}

					if(arr[i+1][j]!=NULL && arr[i+1][j]->judge==0){

						arr[i+1][j]=NULL;
						arr[i][j]->point=(arr[i][j]->point)+5;
						arr[i+1][j]=arr[i][j];
						arr[i][j]=NULL;

					}
				}

				if(direct==2){

					if(arr[i][j+1]==NULL){
			
						arr[i][j+1]=arr[i][j];
						arr[i][j]=NULL;

					}

					if(arr[i][j+1]!=NULL && arr[i][j+1]->judge==0){

						arr[i][j+1]=NULL;
						arr[i][j]->point=(arr[i][j]->point)+5;
						arr[i][j+1]=arr[i][j];
						arr[i][j]=NULL;

					}
				}

				if(direct==3){

					if(arr[i][j-1]==NULL){
			
						arr[i][j-1]=arr[i][j];
						arr[i][j]=NULL;

					}

					if(arr[i][j-1]!=NULL && arr[i][j-1]->judge==0){

						arr[i][j-1]=NULL;
						arr[i][j]->point=(arr[i][j]->point)+5;
						arr[i][j-1]=arr[i][j];
						arr[i][j]=NULL;

					}
				}

				
			
				
			}
		
	}

}
}


