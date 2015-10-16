#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	int matrixSize,direction=-1,x=0,y=0;
	cout<<"matrix size"<<endl; 
	cin>>matrixSize;
	int size = matrixSize*matrixSize , counter = 0,currentStep=0,step = 1,lineSize = 0 /*tamano de linea*/,turn = 1 /*x=1,y=0*/,i=0,signo=1,max = 3 ;
	int *matrix = (int *)malloc(matrixSize * matrixSize * sizeof(int));
	lineSize = matrixSize-1;
	cout<<x<<","<<y<<endl;
	while(counter < size-1){

			i+=turn;
		if(turn > 0){
			y+= step;
			cout<<x<<","<<y<<endl;
			
		}
		else{
			x+=step;
			cout<<x<<","<<y<<endl;
			
		}
			if((i*turn)==lineSize){
			turn *= -1;
			i=0;
			if(signo % 2 == 0){
				step*=-1;
			}
			currentStep++;
			if(currentStep == max){
				lineSize--;
				currentStep = 0;
				max = max > 2 ? --max : max;
			}

			signo++;
			

		}

		counter++;
	}
}


/*
00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44

00 
01 
02 
03
13
10 11 12 
20 21 22 23
30 31 32 33
*/
