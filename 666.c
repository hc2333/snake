#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#define LENGTH 15
#define BREADTH 15
#define LENGTHS LENGTH+1
#define BREADTHS BREADTH+1
void game(char a[][BREADTHS]);
void print_board(char a[][BREADTHS]);
struct snake_list * snake_move(struct snake_list* head,char a[][BREADTHS],char x );
void meanu();
void explain();
void food(char a[][16]) ;
void check(struct snake_list*head,char a[][16]);
void gameover();
int xx,yy,score = 3;
int ex,ey;
struct snake_list * snake_init(char chest[][BREADTHS]);

struct snake_list{
    int x ,y;
    char dir;
    struct snake_list * next;
};



int main(void)
{
    int i;
    srand((unsigned)time(NULL));
   	char chest[ LENGTHS] [BREADTHS]={32};
    do
    {
           meanu();

            scanf(" %d", &i);
            switch(i)
            {
                case 1:
                     game(chest);
                     getch();
                     break;
                case 2:
                    explain();
                    break;
                case 0:
                    printf("退出游戏!\n");
                    break;
                default :
                    printf("请输入正确选项\n");
                    break;
            }
    }while(i);
}

void game(char a[][BREADTHS])
{
    char x;
    struct snake_list * head;
    system("cls");
    char * snakep = &a[7][7];
    head = snake_init(a);
    food(a);
    print_board(a);
    while(1)
{
    head = snake_move(head,a,x);
    check(head,a);

}
}
void print_board(char a[][BREADTHS])
{
    int i,j,k,n;
for(i=0;i<=LENGTH;i++)
	{
		a[0][i]=42;
		a[15][i]=42;
	}
	for(n=1;n<=BREADTH-1;n++)
		for(j=0;j<=LENGTH;j++)
		{
			if(j==0||j==15)
				a[n][j]=42;
		}
	for(i=0;i<=LENGTH;i++)
	{
		for(j=0;j<=BREADTH;j++)
		{
			printf("%c",a[i][j]);
			printf(" ");

		}
		printf("\n");
	}
}

void meanu()
{
        printf("*************************\n");
        printf("*           贪吃蛇       *\n");
        printf("*                        *\n");
        printf("*         1.开始游戏     *\n");
        printf("*         2.查看说明     *\n");
        printf("*         0.退出游戏     *\n");
        printf("*************************\n");
}


void explain()
{
system("cls");
printf("w,a,s,d移动\nw向上移动,a向左移动\ns向下移动，d向又移动\n");
}


struct snake_list * snake_move(struct snake_list* head,char a[][BREADTHS],char x )
{
    int i;
    struct snake_list*node;
    struct snake_list* nexthead;
    struct snake_list* p;
    nexthead = (struct snake_list*)malloc(sizeof(struct snake_list));
    node = head->next;

    switch(getch())
    {
        case 'w':

            p = nexthead;
            p->next = head;
            a[head->x][head->y] = 'X';
            while(node->next!=NULL)
            {
                a[node->x][node->y] = 'X';
                if(node->next->next == NULL)
                {
                    a[node->next->x][node->next->y] = ' ';
                    ex = node->next->x;
                    ey = node->next->y;
                    node->next = NULL;
                    break;
                }
            }
           p->x = head->x - 1;
            p->y = head->y;
            a[p->x][p->y] = 'H';
            system("cls");
            print_board(a);
            break;
        case 's':
            p = nexthead;
            p->next = head;
            a[head->x][head->y] = 'X';
            while(node->next!=NULL)
            {
                a[node->x][node->y] = 'X';
                if(node->next->next == NULL)
                {
                    a[node->next->x][node->next->y] = ' ';
                   ex = node->next->x;
                    ey = node->next->y;
                    node->next = NULL;
                    break;
                }
            }
           p->x = head->x + 1;
            p->y = head->y;
            a[p->x][p->y] = 'H';
            system("cls");
            print_board(a);
            break;
        case 'a':
           p = nexthead;
            p->next = head;
            a[head->x][head->y] = 'X';
            while(node->next!=NULL)
            {
                a[node->x][node->y] = 'X';
                if(node->next->next == NULL)
                {
                    a[node->next->x][node->next->y] = ' ';
                   ex = node->next->x;
                    ey = node->next->y;
                    node->next = NULL;
                    break;
                }
            }
           p->x = head->x ;
            p->y = head->y-1;
            a[p->x][p->y] = 'H';
            system("cls");
            print_board(a);
            break;
        case 'd':
           p = nexthead;
            p->next = head;
            a[head->x][head->y] = 'X';
            while(node->next!=NULL)
            {
                a[node->x][node->y] = 'X';
                if(node->next->next == NULL)
                {
                    a[node->next->x][node->next->y] = ' ';
                   ex = node->next->x;
                    ey = node->next->y;
                    node->next = NULL;
                    break;
                }
            }
           p->x = head->x ;
            p->y = head->y+1;
            a[p->x][p->y] = 'H';
            system("cls");
            print_board(a);
            break;
        default: break;
    }

    return nexthead;
}



struct snake_list * snake_init(char a[][BREADTHS])
{   struct snake_list * head, * body, *end;
    head = (struct snake_list*)malloc(sizeof(struct snake_list));
    body = (struct snake_list*)malloc(sizeof(struct snake_list));
    end  = (struct snake_list*)malloc(sizeof(struct snake_list));
    head->next = body;
    body->next = end;
    end->next = NULL;
    head->x = 7;head->y = 7;
    body->x = 7;body->y = 6;
    end->x = 7;end->y = 5;
    a[head->x][head->y] = 'H';
    a[body->x][body->y] = 'X';
    a[ end->x][end->y] = 'X';

    return head;
}

void food(char a[][16])
{
	srand((unsigned)time(NULL));

	while(1)
	{
		xx=rand()%14+1;
		yy=rand()%14+1;
		if(a[xx][yy]==32||a[xx][yy]==0)
		{
			a[xx][yy]='$';
			break;}
	}
}

void check(struct snake_list*head,char a[][16])
{
struct snake_list *n;
   n = head;
	if(head->x==0)
		gameover();
	else if(head->x==15)
		gameover();
	else if(head->y==15)
		gameover();
	else if(head->y==0)
		gameover();
	else if(head->x==xx&&head->y==yy)
		{score=score+1;
		 while(n->next == NULL)
         {
             n = n->next;
         }
         n ->next = (struct snake_list*)malloc(sizeof(struct snake_list));
         n->next->next = NULL;
         n->next->  x = ex;
         n->next-> y = ey;
         system("cls");
         food(a);
         print_board(a);
		}
}
void gameover()
{
	system("cls");

	if(score==196)
		printf("YOU WIN");
	else
		printf("GAME OVER");

}
void loop(){
}
