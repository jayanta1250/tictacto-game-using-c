#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
char b[3][3]={{'X','O',' '},{' ','X','O'},{' ',' ',' '}}; //global board variable
void clear(void)
{
	int i,j;
	for(i=0;i<3;i++) for(j=0;j<3;j++) b[i][j]=' ';
}

void print(void)
{
	int i,j;
	printf(" -----------\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++) printf("| %c ",b[i][j]);
		printf("|\n -----------\n");
	}
	printf("\n");
}

char iswin(void)
{
	char win=0,i,j;
	for(i=0;i<3;i++) //row check
	{
		if((b[i][0]==b[i][1])&&(b[i][1]==b[i][2])&&(b[i][2]!=' ')) return b[i][0];
	}
	for(i=0;i<3;i++) //row check
	{
		if((b[0][i]==b[1][i])&&(b[1][i]==b[2][i])&&(b[2][i]!=' ')) return b[0][i];
	}
	if((b[0][0]==b[1][1])&&(b[1][1]==b[2][2])&&(b[1][1]!=' ')) return b[1][1];
	if((b[0][2]==b[1][1])&&(b[1][1]==b[2][0])&&(b[1][1]!=' ')) return b[1][1];
	return 0;	
}
typedef struct Player
{
	char name[15];
	char sym;
}player;

player p[2]; //Global player variables
int turn=0;  //represents current player

void autoplay()
{
	int n;
	while(1)
	{
		n=(rand()%9)+1;
		if(b[(n-1)/3][(n-1)%3]==' ')
		{
			b[(n-1)/3][(n-1)%3]=p[turn].sym;
			printf("%s Entered: %d\n",p[0].name,n);
			turn++;
			turn%=2;
			break;
		}
	}
	print();
}

void play()
{
	if(turn == 0)
	{
		autoplay();
		return;
	}
	printf("%s enter between(1~9): ",p[turn].name);
	int n;
	while(1)
	{
		scanf("%d",&n);
		if((b[(n-1)/3][(n-1)%3]==' ')&&(n>=1)&&(n<=9))
		{
			b[(n-1)/3][(n-1)%3]=p[turn].sym;
			turn++;
			turn%=2;
			break;
		}
		printf("Retry: ");
	}
	print();
}

int main()
{
	char str[15];
	strcpy(p[0].name,"Computer");
	p[0].sym='X';
	printf("Enter Player name: ");
	scanf("%s",str);
	strcpy(p[1].name,str);
	p[1].sym='O';

	clear();
	int i;
	for(i=0;i<9;i++)
	{
		play();
		if(iswin())
		{
			printf("\n%c is the winner",iswin());
			break;
		}
	}
	if(i==9) printf("Draw Situation");
	return 0;
}
