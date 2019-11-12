#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int i,j,k,a[3][3]={0,0,2,0,1,0,3,0,0},b[4][4]={0,3,4,0,0,0,1,0,3,0,2,0,0,1,0,0},c[5][5]={0,3,5,0,0,5,0,0,0,3,4,0,0,5,0,0,5,0,4,1,0,0,1,3,0},d[9][9]={0,0,0,2,6,0,7,0,1,6,8,0,0,7,0,0,9,0,1,9,0,0,0,4,5,0,0,8,2,0,1,0,0,0,4,0,0,0,4,6,0,2,9,0,0,0,5,0,0,0,3,0,2,8,0,0,9,3,0,0,0,7,4,0,4,0,0,5,0,0,3,6,7,0,3,0,1,8,0,0,0};
int a1[3][3]={1,3,2,2,1,3,3,2,1};
int b1[4][4]={1,3,4,2,4,2,1,3,3,4,2,1,2,1,3,4};
int c1[5][5]={1,3,5,2,4,5,2,4,1,3,4,1,3,5,2,3,5,2,4,1,2,4,1,3,5};
int d1[9][9]={4,3,5,2,6,9,7,8,1,6,8,2,5,7,1,4,9,3,1,9,7,8,3,4,5,6,2,8,2,6,1,9,5,3,4,7,3,7,4,6,8,2,9,1,5,9,5,1,7,4,3,6,2,8,5,1,9,3,2,6,8,7,4,2,4,8,9,5,7,1,3,6,7,6,3,4,1,8,2,5,9};
void playgame();
void instructions();
void highscores();
void playgame3();
void playgame4();
void playgame5();
void playgame9();
int checksudoku3(int a[3][3],int a1[3][3]);
int checksudoku4(int b[4][4],int b1[4][4]);
int checksudoku5(int c[5][5],int c1[5][5]);
int checksudoku9(int d[9][9],int d1[9][9]);
void thankyou();
void mainmenu();
int gd = DETECT,gm,opt;
char name[50];
void main()
{
  clrscr();gotoxy(25,14);
  printf("Welcome to suduko game");gotoxy(25,14);
  printf("Enter your name:");
  gets(name);
  mainmenu();
  getch();
}
void mainmenu()
{
 int gd = DETECT,gm,opt;
 clrscr();
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 setbkcolor(6);
 gotoxy(30,3);
 main:
 printf(" S  |   U   |    \n");gotoxy(30,4);
 printf("____|_______|_____\n");gotoxy(30,5);
 printf("    |       |     \n");gotoxy(30,6);
 printf("    |   D   |  O  \n");gotoxy(30,7);
 printf("____|_______|_____\n");gotoxy(30,8);
 printf("    |       |     \n");gotoxy(30,9);
 printf(" K  |   U   |     \n");gotoxy(30,12);
 printf("1.Play game\n");gotoxy(30,14);
 printf("2.Instructions\n");gotoxy(30,16);
 printf("3.Highscores\n");gotoxy(30,18);
 printf("4.Exit\n");gotoxy(30,20);
 printf("Enter a option:");
 scanf("%d",&opt);
 switch(opt)
 {
  case 1:playgame();break;
  case 2:instructions();break;
  case 3:highscores();break;
  case 4:exit(1);
  default :gotoxy(30,23);printf("invalid option");
 }
 getch();
 closegraph();
 mainmenu();
}

void instructions()
{
 FILE *fa;
 char ch;
 clrscr();
 initgraph(&gd,&gm,"C://TURBOC3//BGI");
 setbkcolor(12);
 fa=fopen("a.txt","r");
 if(fa==NULL)
 {
  printf("\nsource file error");
 }
 else
 {
  while((ch=fgetc(fa))!=EOF)
  {
   putchar(ch);
  }
 }
 getch();
 mainmenu();
}
void highscores()
{
 clrscr();
 initgraph(&gd,&gm,"C://TURBOC3//BGI");
 setbkcolor(1);
 printf("the high scores are:");
 printf("\nalex....");
 getch();
 mainmenu();
}
 void playgame()
{
 int opt;clrscr();
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 setbkcolor(1);
 gotoxy(25,4);
 printf("Select the size of sudoku.....");
 gotoxy(7,10);
 printf("1.3x3");
 gotoxy(25,12);
 printf("2.4x4");
 gotoxy(45,14);
 printf("3.5x5");
 gotoxy(63,16);
 printf("4.9x9");
 gotoxy(30,23);
 printf("Enter your option:");
 scanf("%d",&opt);
 switch(opt)
{
  case 1:playgame3();break;
  case 2:playgame4();break;
  case 3:playgame5();break;
  case 4:playgame9();break;
  default:gotoxy(30,25);printf("\ninvalid option.");
}
 getch();
 mainmenu();
}
void playgame3()
{
 int row,col,n,ans;
 clrscr();
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 setbkcolor(1);
 printf("\t\t In this game the 1st row is 0th row,1 st coloumn is 0th col\n\n");
 printf("\t\t Similarly others\n\n");
 printf("\t\t To check enter 15 for both row and coloumn\n\n");
 printf("\t\t Enter 10 for both row and coloumn to go to mainmenu\n\n\n\n");
 printf(" ______________________\n\n");
 printf("|");
 for(i=0;i<3;i++)
 {
   for(j=0;j<3;j++)
   {
     printf("|__%2d__",a[i][j]);
   }printf("||\n\n|");

 }
 printf("Enter the row|:");
 scanf("%d",&row);
 printf("|Enter the coloumn|:");
 scanf("%d",&col);
 if(row==10 || col==10)
 {
   mainmenu();
 }
  if(row==15 || col==15)
  {
   goto check;
  }

 printf("Enter the number:");
 scanf("%d",&n);

 a[row][col]=n;
 printf("_______________________\n");
 printf("|");
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
    printf("|__%2d__",a[i][j]);
   }printf("|\n\n|");
 }

printf("_______________________\n");
playgame3();

check:
ans=checksudoku3(a,a1);
if(ans==1)
{
  playgame3();
}
if(ans==0)
{
thankyou();
}
}
void playgame4()
{
 int row,col,n,ans;
  clrscr();
 initgraph(&gd,&gm,"C://TURBOC3//BGI");
 setbkcolor(1);
 printf("\t\t In this game the 1st row is 0th row,1 st coloumn is 0th col\n\n");
 printf("\t\t Similarly others\n\n");
 printf("\t\t To check enter 15 for both row and coloumn\n\n");
 printf("\t\t Enter 10 for both row and coloumn to go to mainmenu\n\n\n\n");
 printf(" ____________________________\n");
 printf("|");
 for(i=0;i<4;i++)
 {
   for(j=0;j<4;j++)
   {
     printf("|__%2d__",b[i][j]);
   }printf("|\n\n|");

 }
 printf("Enter the row|:");
 scanf("%d",&row);
 printf("Enter the coloumn:");
 scanf("%d",&col);
 if(row==10 || col==10)
 {
   mainmenu();
 }
  if(row==15 || col==15)
  {
   goto check;
  }
 printf("Enter the number:");
 scanf("%d",&n);

 b[row][col]=n;
 printf("_________________________\n\n");
 printf("|");
 for(i=0;i<4;i++)
 {
  for(j=0;j<4;j++)
  {
    printf("|__%2d__",b[i][j]);
   }printf("\n\n|");
 }
 printf("_________________________\n");

playgame4();

check:
ans=checksudoku4(b,b1);
if(ans==1)
{
  playgame4();

}
if(ans==0)
{
thankyou();
}

}
void playgame5()
{
 int row,col,n,ans;
 textbackground(RED);
 clrscr();
 initgraph(&gd,&gm,"C://TURBOC3//BGI");
 setbkcolor(1);
 printf("\t\t In this game the 1st row is 0th row,1 st coloumn is 0th col\n\n");
 printf("\t\t Similarly others\n\n");
 printf("\t\t To check enter 15 for both row and coloumn\n\n");
 printf("\t\t Enter 10 for both row and coloumn to go to mainmenu\n\n\n\n");
 printf(" ___________________________________\n");
 printf("|");
 for(i=0;i<5;i++)
 {
   for(j=0;j<5;j++)
   {
     printf("|__%2d__",c[i][j]);
   }printf("|\n\n|");

 }
 printf("Enter the row|:");
 scanf("%d",&row);
 printf("Enter the coloumn:");
 scanf("%d",&col);
 if(row==10 || col==10)
 {
   mainmenu();
 }
  if(row==15 || col==15)
  {
   goto check;
  }
 printf("Enter the number:");
 scanf("%d",&n);

 c[row][col]=n;
printf("_________________________\n\n");
 printf("|");
 for(i=0;i<5;i++)
 {
  for(j=0;j<5;j++)
  {
    printf("|__%2d__",c[i][j]);
   }printf("\n\n|");
 }

 printf("_________________________\n");
playgame5();

check:
ans=checksudoku5(c,c1);
if(ans==1)
{
  playgame5();
}
if(ans==0)
{
thankyou();
}
}
void playgame9()
{
  int row,col,n,ans;
 clrscr();
 initgraph(&gd,&gm,"C://TURBOC3//BGI");
 setbkcolor(1);
 printf("\t\t In this game the 1st row is 0th row,1 st coloumn is 0th col\n\n");
 printf("\t\t Similarly others\n\n");
 printf("\t\t To check enter 15 for both row and coloumn\n\n");
 printf("\t\t Enter 10 for both row and coloumn to go to mainmenu\n\n\n\n");
 printf(" _______________________________________________________________\n");
 printf("|");
 for(i=0;i<9;i++)
 {
   for(j=0;j<9;j++)
   {
     printf("|__%2d__",d[i][j]);
   }printf("|\n\n|");

 }
 printf("Enter the row|:");
 scanf("%d",&row);
 printf("Enter the coloumn:");
 scanf("%d",&col);
 if(row==10 || col==10)
 {
   mainmenu();
 }
  if(row==15 || col==15)
  {
   goto check;
  }
 printf("Enter the number:");
 scanf("%d",&n);

 d[row][col]=n;
printf("_________________________\n\n");
 printf("|");
 for(i=0;i<9;i++)
 {
  for(j=0;j<9;j++)
  {
    printf("|__%2d__",d[i][j]);
   }printf("\n\n|");
 }

 printf("_________________________\n");

playgame9();

check:
ans=checksudoku9(d,d1);
if(ans==1)
{
  playgame9();
}
if(ans==0)
{
thankyou();
}
}
int checksudoku3(int a[3][3],int a1[3][3])
{
   for(i=0;i<3;i++)
   {
  for(j=0;j<3;j++)
    {
    if((a[i][j])!=a1[i][j])
     {
       printf("\nError in sudoku at %d row and %d col\nplease check........",i,j);
       k=1;
    }

   }
  }

getch();
if(k==1)
return 1;
else
return 0;
}
int checksudoku4(int b[4][4],int b1[4][4])
{

    for(i=0;i<4;i++)
 {
  for(j=0;j<4;j++)
  {
    if((b[i][j])!=b1[i][j])
    {
       printf("\nError in sudoku at %d row and %d col\nplease check........",i,j);
       k=1;
    }

   }
  }
getch();
if(k==1)
return 1;
else
return 0;
}
int checksudoku5(int c[5][5],int c1[5][5])
{
     for(i=0;i<5;i++)
 {
  for(j=0;j<5;j++)
  {
    if((c[i][j])!=c1[i][j])
    {
       printf("\nError in sudoku at %d row and %d col\nplease check........",i,j);
       k=1;
    }

   }
  }
getch();
if(k==1)
return 1;
else
return 0;
}
int checksudoku9(int d[9][9],int d1[9][9])
{
    for(i=0;i<9;i++)
 {
  for(j=0;j<9;j++)
  {
    if((d[i][j])!=d1[i][j])
    {
       printf("\nError in sudoku at %d row and %d col\nplease check........",i,j);
       k=1;
    }
   }
  }
getch();
if(k==1)
return 1;
else
return 0;
}
void thankyou()
{ 
  initgraph(&gd,&gm,"C://TURBOC3//BGI");
  clrscr();
  setbkcolor(12);
  gotoxy(25,12);
  printf("Thank you for playing......");
  gotoxy(25,14);
  printf("congratulation.....%s!!",name);
  getch();
  mainmenu();

}
