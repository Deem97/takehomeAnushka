#include <stdio.h>

void addToWaitingRoom(char,char []);   //this is used to add clients to the waitingroom
void Leave(char []);                  //this is used to indicate leaving of client


int max;                             //this variable is used to get the number of chairs in the waiting room
int rear =0,front=0;
int count=0;


int main(){
	int i;
	int baberStatus = 0;                                        //indicates whether baber sleep or not and busy or not (if baberStatus=0 it indicates that baber is sleep and not busy)
	char waitingRoom[max];
	char action;
	
	printf("\t\t\t\t........Sleeping Barber.....\n\n");
	printf("\t|___MENU__|\n\n");
	printf("1) Enter 'A' to indicate coming of client.\n");       //line 21 to 23 shows instructions for the user
	printf("2) Enter 'L' to indicate leaving of client.\n");
	printf("3) Enter 'S' to stop the process.\n");
	printf(".............................................\n\n");
	printf("Enter the number of chairs in the saloon:");
	scanf("%d",&max);
	
	printf("\n");
	printf("Enter the details about the clinet:");
	scanf(" %c",&action);
	printf("\n");
	
	while(action!='S'&&(action=='A'||action=='L')){

		if(action=='A' && baberStatus== 0 ){
			
			printf("Clinet comes and he wakes the barber\n");           //this part is used to indicate the arriving of first client
		    printf("Client is getting a haircut\n\n");
		    baberStatus=1;
			
		}else if(action=='A' && baberStatus== 1 ){
			
			addToWaitingRoom(action,waitingRoom);                    //add clients to the waiting line
		}else if(action=='L'&&count!=0){
		
			Leave(waitingRoom);
		
		}else if(action=='L'&&count==0&&baberStatus==0){
			printf("Invalid Input\n\n");                            //this is use to idicate invalid input(when there are no clients if user input 'L' it is a invalid input)

		}else if(action=='L'&&count==0&&baberStatus==1){
			printf("Client leaves\nThere are no clients then barber goes to sleep\n\n");    //this part is used to indicate the leaving of last client
			baberStatus=0;
		}else if (action=='S'){
			break;                                         //here end the while loop
		}
		
		printf("Enter the details about the clinet:");
		scanf(" %c",&action);
	}
	return 0;
}



void addToWaitingRoom(char x,char c[]){
	if(count==max){

		printf("There are no chairs available then clinet leaves\n\n");
	}else{
		count++;
		c[rear]=x;
		
		rear = (rear+1)%max;
		printf("Barber is busy and client sits and waits\n\n");
	}
	return 0;
}

void Leave(char c[]){
	if(count==0){
		printf("INVALID INPUT\nWaiting room is empty\n\n");
	}else{
		printf("Client who having hair cut leaves\nWaiting room has free chairs\nClient who in the front of waiting room moves to get haircut\n\n");
	}	front = (front+1)%max;
	count--;
	return 0; 
}

