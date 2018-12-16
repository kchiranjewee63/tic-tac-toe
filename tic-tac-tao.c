// simple way of making tic-tac-teo game c code.
// '*' symbol  is for user and '+' symbol is for system. 

#include<stdio.h>
#include<stdlib.h>

int pos[9]={1,2,3,4,5,6,7,8,9};

int give_scr();//Function that exime how good is the choosen move

void play();//Function that execute game

void printboard();//Function for printing board

int main()
{
printf("--------------------------------tic-tac-teo-------------------------------\n");

play();

printf("--------------------------------tic-tac-teo-------------------------------\n");
return 0;
}

//give_scr function defination
int give_scr()
{

int usrscr=0,sysscr=0,i;//usrscr is score given to user move and sysscr is score given to system move 

//All possible wining permutation 
int b[8][3]=
{
{0,1,2},
{3,4,5},
{6,7,8},
{0,3,6},
{1,4,7},
{2,5,8},
{0,4,8},
{2,4,6}
};

//Calculating usrscr 
for(i=0;i<8;i++)//Iterating over all possible winning permutation stored in two dimenson array b[8][3]
{

//Wining case.
if(pos[b[i][0]]=='*'&&pos[b[i][1]]=='*'&&pos[b[i][2]]=='*')
{

//Printing Board and terminating game
printboard();
printf("\nCongartulation you win!!!!!!!!!\n"); exit(0);

}


//One step sort of winning giving 100 score to each of such permutation and this permutation most be distroyed by system if possible  
if(pos[b[i][0]]=='*'&&pos[b[i][1]]=='*'&&pos[b[i][2]]<10||pos[b[i][0]]<10&&pos[b[i][1]]=='*'&&pos[b[i][2]]=='*'||pos[b[i][0]]=='*'&&pos[b[i][1]]<10&&pos[b[i][2]]=='*') 

usrscr+=100;

//Two step sort of winning giving 5 score to each of such permutation 
if(pos[b[i][0]]<10&&pos[b[i][1]]<10&&pos[b[i][2]]=='*'||pos[b[i][0]]=='*'&&pos[b[i][1]]<10&&pos[b[i][2]]<10||pos[b[i][0]]<10&&pos[b[i][1]]=='*'&&pos[b[i][2]]<10) 

usrscr+=5;

}

//Calculating sysscr
for(i=0;i<8;i++)
{

//Wining case   
if(pos[b[i][0]]=='+'&&pos[b[i][1]]=='+'&&pos[b[i][2]]=='+')
{
//Printing Board
printboard();
printf("\nGame over.You lose.\n"); exit(0);
} 

//One step sort of winning giving score of 10.It is less then the one given to user in this permutation becaue next will be user's turn and user can win if such permutation is there for user and in system case this permutation does not guarantee victory.
if(pos[b[i][0]]=='+'&&pos[b[i][1]]=='+'&&pos[b[i][2]]<10||pos[b[i][0]]<10&&pos[b[i][1]]=='+'&&pos[b[i][2]]=='+'||pos[b[i][0]]=='+'&&pos[b[i][1]]<10&&pos[b[i][2]]=='+') 

sysscr+=10;

//Two step sort of winning giving 5 score for each of such permutaion
if(pos[b[i][0]]<10&&pos[b[i][1]]<10&&pos[b[i][2]]=='+'||pos[b[i][0]]=='+'&&pos[b[i][1]]<10&&pos[b[i][2]]<10||pos[b[i][0]]<10&&pos[b[i][1]]=='+'&&pos[b[i][2]]<10) 
sysscr+=5;

}

//Return the difference of score of system and user
return (sysscr-usrscr);

}//End of function eval

// play function defination
void play()
{

int t,flag,all_eval[9],j;

flag=0;

// Initilizing each element of array to very small value.
for(t=0;t<9;t++) all_eval[t]=-10000;

//Printing Board
printf("Board position is\n");
printboard();

//Reading user choice
printf("\nEnter you option:\n");

while(flag==0)
{

scanf(" %d",&t);

if(pos[t-1]<10)//Empty postion is filled by the number for 1 to 9 and occupied position is filled by '*' and '+' ascii value of '*' and '+' is larger than 10. So, if occupied position if choosen it ask again.
{
pos[t-1]='*'; flag=1;//flag indicating choosen position is available
}
 
else printf("Position already filled.Enter another postion:"); 

}


flag=1;////Flag to check if game has ended up in tie.

//Iterating over all the possible position for system and calculating the eval(difference of system score and user score) and choosing the one with higest value.
for(t=0;t<9;t++)
{

if(pos[t]<10)//Checking if position is empty.It is empty if filled by any numbers for 1 to 9. 
{

pos[t]='+';//Trying filling at this position  
all_eval[t]=eval();//Calculating corrosponding move eval and storing in array. 
pos[t]=t+1;//Freeing the filled position. 
flag=0; //Flag to check if game has ended up in tie.
}

}//For loop end

//tie condition
if(flag==1) 
{

printf("Board position is\n");
printboard();
printf("Game tie!!!\n"); exit(0);

}
//Finding max eval among all possible moves
j=0;
for(t=1;t<9;t++) if(all_eval[t]>all_eval[j]) j=t;//j will hold the best position to move.
pos[j]='+';

play();//Calling the play function for another move.

}

//Function for printing board
void printboard()
{
int j;
for(j=0;j<9;j++) 
{
if(pos[j]=='*'||pos[j]=='+')

printf("%c\t",pos[j]); 
else 
printf("%d\t",pos[j]); 

if((j+1)%3==0) printf("\n\n");

}//End of for loop.

}
