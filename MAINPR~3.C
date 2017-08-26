#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
static void force_fpf()
{
float x,*y;
y=&x;
x=*y;
}

long int id1;                             //global variables
FILE *f1,*f2;

struct stud                               //student's id structure
{
long int id;
char pass[10];
char batch[3];
}k;

struct attend                             //student's attendace structure
{
long int id;
char s1[8][100];
float at[8];
}b;
														//admin structure
struct admin                             //admin struct
{
long int id;
char pass[10],adname[20];
}ad;

struct editinfo                     //student info str
{
long int id;
char name[20];
char fname[20];
char mname[20];
char cellno[12];
char email[20];
char address[50];
}e;

struct academic                           //student marks struct
{
long int id;
int marks[5];
}m;

void timedis()                           //time & date fn
{
time_t t;
time(&t);
gotoxy(310,1);
printf("%s",ctime(&t));
}

void editattd()				       //uploading attendace
{
long int ids;
int code,len,i,j,n,k;
char date[10],ch;
f1=fopen("STUDatd.txt","r+");
printf("Enter id for which attendence is to be uploaded-- ");
scanf("%ld",&ids);
i=0;
n=fread(&b,sizeof(b),1,f1);
do
{
i++;
if(ids==b.id)
 {
 do
 {
 printf(" Want To Upload Attendance For -- \nCode\t Subject\n");
 printf(" 0\tPHYSICS\n 1\tICP\n 2\tECA\n 3\tMATHS\n 4\tPD\n 5\tPHYSICS LAB\n 6\tECA LAB\n 7\tICP LAB\n");
 printf(" Enter Your Code-- ");
 scanf("%d",&code);
 len=strlen(b.s1[code]);
 printf("The Date for Which The Attendance Is To Be Marked(DD/MM/YY)--");flushall();
 gets(date);flushall();
 printf("\nMark 'p' for Present and 'a' for absent-");flushall();
 scanf("%c",&ch);flushall();
 b.s1[code][len]=ch;
 len++;
 b.s1[code][len]='\0';
 j=0;
 k=0;
 for(;b.s1[code][j];j++)
 {
 if(b.s1[code][j]=='p')
 k++;
 }
 printf("THE NO. OF PRESENTS--> %d \nTHE NO. OF TOTAL DAYS-->%d \n\n",k,j);
 b.at[code]=((float)k/j)*100;
 fseek(f1,(i-1)*(sizeof(b)),0);
 fwrite(&b,sizeof(b),1,f1);
 printf("Want to Mark More Attendance For The Same Student(y/n)?");flushall();
 scanf("%c",&ch);flushall();
 }while(ch=='y');
}
n=fread(&b,sizeof(b),1,f1);
}while(n>0);
fclose(f1);
}

void markdetail()                                      //uploading marks
{int n,i;
long int id2;
char c,type[5];
f1=fopen("marks.txt","r+");
do
{
i=0;
printf("\n");
printf("\n        STUDENT'S ID FOR WHICH THE MARKS ARE TO BE UPLOADED:");
scanf("%ld",&id2);
do
{i++;
n=fread(&m,sizeof(m),1,f1);
if(id2==m.id)
 {
printf("\n        ENTER EXAM TYPE/TERM(T1/T2/T3): ");
scanf("%s",type);
printf("\n        ENTER STUDENT'S (%ld) MARKS",m.id);flushall();
printf("\n                    PHYSICS: ");
scanf("%d",&m.marks[0]);
printf("\n                    MATHEMATICS-1: ");
scanf("%d",&m.marks[1]);
printf("\n                    ECA: ");
scanf("%d",&m.marks[2]);
printf("\n                    ICP: ");
scanf("%d",&m.marks[3]);
printf("\n                    P&C SKILLS:");
scanf("%d",&m.marks[4]);
fseek(f1,(i-1)*(sizeof(m)),0);
fwrite(&m,sizeof(m),1,f1);
}
n=fread(&m,sizeof(m),1,f1);
}while(n>0);
printf("Do You Want To Edit Marks For Another Student?? (y/n)");flushall();
scanf("%c",&c);flushall();
}while(c=='y');
fclose(f1);
}

void viewdet()                             //viewing details fn
{
int m;
f1=fopen("per.txt","r");
m=fread(&e,sizeof(e),1,f1);
do
{
if(id1==e.id)
{
clrscr();
printf("\n                  YOUR PERSONAL DETAILS");
printf("\n STUDENT'S NAME: ");
puts(e.name);
printf("\n FATHER'S NAME: ");
puts(e.fname);
printf("\n MOTHER'S NAME: ");
puts(e.mname);
printf("\n RESIDENTIAL ADDRESS: ");
puts(e.address);
printf("\n MOBILE NO.: ");
puts(e.cellno);
printf("\n EMAIL ID: ");
puts(e.email);
printf("\n\n");
}
m=fread(&e,sizeof(e),1,f1);
}while(m>0);
fclose(f1);
}

void editinfo()                                  //edit profile fn
{
int i,m,c;
char ch;
f1=fopen("per.txt","r+");
m=fread(&e,sizeof(e),1,f1);
i=0;
do
{
i++;
if(id1==e.id)
{
do
{
clrscr();
printf("                       EDIT YOUR INFORMATION MENU--\n");
printf("   1.NAME\n    2.FATHERS NAME\n    3.MOTHERS NAME\n    4.MOBILE NUMBER\n    5.ADDRESS\n    6.EMAIL ADDRESS\n");
printf("ENTER YOUR CHOICE?? ");flushall();
scanf("%d",&c);
switch(c)
   {
   case 1:printf("Enter New Name-- ");flushall();
			 gets(e.name);flushall();
			 break;
  case 2:printf("Enter New Father's Name-- ");flushall();
			 gets(e.fname);flushall();
			  break;
  case 3:printf("Enter New Mother's Name-- ");flushall();
			 gets(e.mname);flushall();
			  break;
  case 4:printf("Enter New Mobile Number-- ");flushall();
			 gets(e.cellno);flushall();
			  break;
  case 5:printf("Enter New Residential Address-- ");flushall();
		gets(e.address);flushall();
			  break;
  case 6:printf("Enter E-mail Address-- ");flushall();
			 gets(e.email);flushall();
			 break;
	}
fseek(f1,(i-1)*(sizeof(e)),0);
fwrite(&e,sizeof(e),1,f1);flushall();
printf("Want To Edit More Information-- (y/n)??");flushall();
scanf("%c",&ch);flushall();
}while(ch=='y');
}
m=fread(&e,sizeof(e),1,f1);
}while(m>0);
fclose(f1);
}



void viewmark()                            //showing marks fn
{
int pa;
f1=fopen("marks.txt","r");
pa=fread(&m,sizeof(m),1,f1);
do
{
if(id1==m.id)
{
printf(" WELCOME %ld",m.id);
printf("\n\n\t\tSUBJECT           MARKS");
printf("\n\t\tPHYSICS:            %d",m.marks[0]);
printf("\n\t\tMATHEMATICS-1:      %d",m.marks[1]);
printf("\n\t\tICP:                %d",m.marks[2]);
printf("\n\t\tP&C SKILLS:         %d",m.marks[3]);
printf("\n\t\tECA:                %d\n\n",m.marks[4]);
}
pa=fread(&m,sizeof(m),1,f1);
}while(pa>0);
fclose(f1);
}

void showattd()                     //showing attendance
{
int n;
f1=fopen("STUDatd.txt","r");
n=fread(&b,sizeof(b),1,f1);
clrscr();
timedis();
do
{
if(b.id==id1)
{printf("YOUR ATTENDANCE TILL DATE-");
printf("\nSUBJECT       ATTENDACE(%)");
printf("\nPHYSICS:      %2.1f",b.at[0]);
printf("\n ICP:         %2.1f",b.at[1]);
printf("\n ECA:         %2.1f",b.at[2]);
printf("\n MATHS:       %2.1f",b.at[3]);
printf("\n PD:          %2.1f",b.at[4]);
printf("\n PHYSICS LAB: %2.1f",b.at[5]);
printf("\n ECA LAB:     %2.1f",b.at[6]);
printf("\n ICP LAB      %2.1f\n\n",b.at[7]);
}
n=fread(&b,sizeof(b),1,f1);
}while(n>0);
fclose(f1);

}
						     //B4 tt
void B4()
{ int gd=DETECT,gm;
int i;
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  setbkcolor(2);
  rectangle(40,40,600,460);
for(i=1;i<=7;i++)
rectangle(40,40,600,40+60*i);
rectangle(40,40,110,460);
rectangle(40,40,250,460);
rectangle(40,40,390,460);
rectangle(40,160,320,220);
for(i=1;i<=3;i++)
rectangle(390,40,390+70*i,460);
rectangle(40,40,180,100);
rectangle(40,40,320,160);
rectangle(110,160,180,280);
rectangle(250,280,320,460);
rectangle(40,400,180,460);
outtextxy(200,20,"B.TECH 1 SEMESTER TIMETABLE(BATCH-B4)");
outtextxy(50,65,"DAY     9-9:50AM 10-      11-      12-     2-2:50PM 3-3:50PM 4-4:50PM");
outtextxy(185,75,"10:50AM  11:50AM  12:50AM");
outtextxy(50,125,"MONDAY   P(CL171)VM/CL1   L(MA111)L(CL111) T(MA111)");
outtextxy(260,135,"PR/G7   AYU/G7   PR/TS5");
outtextxy(50,185,"TUESDAY L(CL111) L(PD111) T(PH111)         L(PH171)");
outtextxy(115,195,"AYU/CS3  SAN/CS3  SR/TS7           VS/G9");
outtextxy(40,245,"WEDNESDAY         L(PH171) P(EC171)SCH/BEL2  L(MA111)L(EC111)");
outtextxy(120,255,"        VS/G9                      PR/G7   SSB/G7");
outtextxy(45,305,"THURSDAY  P(PH171)BCJ/PL1          L(EC111) L(CL111) ");
outtextxy(115,315,"                          SSB/G9   AYU/G7");
outtextxy(50,365,"FRIDAY   P(CL111)VM/CL1   L(MA111)L(EC111) T(EC111)");
outtextxy(115,375,"                  PR/G7   SSB/G7   TC/F10");
outtextxy(45,425,"SATURDAY         L(PH171) T(CL111)");
outtextxy(115,435,"        VS/G9     AJ/TS10");

  getch();
  closegraph();
}                                                   //B5 tt
void B5()
{
int gd=DETECT,gm;
int i;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setbkcolor(5);
rectangle(40,40,600,460);
for(i=1;i<=7;i++)
rectangle(40,40,600,40+60*i);
rectangle(40,40,110,460);
rectangle(40,40,250,460);
rectangle(40,40,390,460);
for(i=1;i<=3;i++)
rectangle(390,40,390+70*i,460);
rectangle(40,40,180,100);
rectangle(40,40,320,160);
rectangle(110,160,180,280);
rectangle(250,280,320,460);
rectangle(40,400,180,460);
outtextxy(200,20,"B.TECH 1 SEMESTER TIMETABLE(BATCH-B5)");
outtextxy(50,65,"DAY     9-9:50AM 10-      11-      12-     2-2:50PM 3-3:50PM 4-4:50PM");
outtextxy(185,75,"10:50AM  11:50AM  12:50AM");
outtextxy(50,125,"MONDAY   P(CL171)VM/CL1   L(MA111) L(CL111)");
outtextxy(260,135,"PR/G7   AYU/G7");
outtextxy(50,185,"TUESDAY L(CL111) L(PD111)  P(PH171)PC/PL1  L(PH171)");
outtextxy(115,195,"AYU/CS3  SAN/CS3                   VS/G9");
outtextxy(40,245,"WEDNESDAY T(MA111)L(PH171)  T(PD111)PP/TS2  L(MA111) L(EC111)");
outtextxy(120,255,"LK/TS5  VS/G9                      PR/G7   SSB/G7");
outtextxy(45,305,"THURSDAY  P(EC171)SY/BEL1 T(CL111) L(EC111) L(CL111) T(EC111)");
outtextxy(115,315,"                 VS/TS10  SSB/G9   AYU/G7   AKS/F10");
outtextxy(50,365,"FRIDAY   P(CL111)VM/CL1   L(MA111)L(EC111)");
outtextxy(115,375,"                  PR/G7   SSB/G7");
outtextxy(45,425,"SATURDAY          L(PH171)         T(PH171)");
outtextxy(115,435,"         VS/G9            SR/TS7");
getch();
closegraph();
}
void B6()                                            //B6 tt
{
int gd=DETECT,gm,i;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setbkcolor(RED);
rectangle(40,40,600,460);
for(i=1;i<=7;i++)
rectangle(40,40,600,40+60*i);
rectangle(40,40,110,460);
rectangle(40,40,250,460);
rectangle(40,40,390,460);
for(i=1;i<=3;i++)
rectangle(390,40,390+70*i,460);
rectangle(40,40,180,100);
rectangle(40,40,320,160);
rectangle(110,160,180,280);
rectangle(250,280,320,460);
rectangle(40,400,180,460);
outtextxy(200,20,"B.TECH 1 SEMESTER TIMETABLE(BATCH-B6)");
outtextxy(50,65,"DAY     9-9:50AM 10-      11-      12-     2-2:50PM 3-3:50PM 4-4:50PM");
outtextxy(185,75,"10:50AM  11:50AM  12:50AM");
outtextxy(50,125,"MONDAY   P(CL171)VM/CL1   L(MA111)L(CL111)");
outtextxy(260,135,"PR/G7   AYU/G7");
outtextxy(50,185,"TUESDAY L(CL111) L(PD111)  T(PD111)SD/TS10 L(PH171)");
outtextxy(115,195,"AYU/CS3  SAN/CS3                   VS/G9");
outtextxy(40,245,"WEDNESDAY         L(PH171) T(CL111) T(MA111)L(MA111) L(EC111)");
outtextxy(120,255,"        VS/G9    VS/TS10  YG/TS5  PR/G7    SSB/G7");
line(320,220,320,280);
outtextxy(45,305,"THURSDAY  P(CL171)SAA/CL1 T(CL111) L(EC111) L(CL111) T(EC111)");
outtextxy(115,315,"                 VS/TS10  SSB/G9   AYU/G7   AKS/F10");
outtextxy(50,365,"FRIDAY   P(PH171)VS/PL1  (MA111)  (EC111)");
outtextxy(115,375,"                  PR/G7   SSB/G7   VS/F10");
outtextxy(45,425,"SATURDAY          L(PH171)         T(PH171)");
outtextxy(115,435,"         VS/G9");
getch();
closegraph();}


void main()                                                //main function
{
char choice,pass1[10],batch[3];
int m,l,no,i,flag,r,c;
int gd=DETECT,gm,j;
initgraph(&gd,&gm,"c:\\TC\\BGI");
setbkcolor(MAGENTA);
setcolor(YELLOW);

outtextxy(50,50,"                  JIIT WEBKIOSK");
for(m=0;m<100;m+=10)
{
for(l=0;l<100;l++)
{
line(190+m,70,200+l,70);

delay(2);
}
}
outtextxy(70,200,"DEVELOPED BY KAMALJEET SINGH, SANYAM BATRA, SHUBHAM CHAUHAN");
for(m=0;m<100;m+=20)
{
for(l=0;l<100;l++)
{
line(445+l,213,70+l,213);
delay(2);
}
}
outtextxy(50,335,"         WAHEGURU JI DA KHALSA, WAHEGURU JI DI FATEH");
getch();
setbkcolor(RED);
setcolor(BLUE);
setfillstyle(1,YELLOW);
rectangle(25,20,620,450);
floodfill(60,100,BLUE);
setcolor(WHITE);
setfillstyle(1,LIGHTBLUE);
rectangle(55,36,590,430);
floodfill(70,80,WHITE);
setcolor(YELLOW);
outtextxy(135,50,"JAYPEE INSTITUTE OF INFORMATION TECHNOLOGY");
outtextxy(205,79,"****WELCOME TO JIIT WEBKIOSK****");
setcolor(BLUE);
outtextxy(265,120,"OUR VISION");
setcolor(WHITE);
outtextxy(275,155,"TO BECOME");
outtextxy(220,180,"A CENTER OF EXCELLENCE");
outtextxy(178,205,"IN FIELD OF IT EDUCATION AND TRAINING");
outtextxy(185,300,"PRESS ENTER TO GET STARTED!!!!!!!!");
getch();
closegraph();
front:
flag=0;
clrscr();
timedis();
fclose(f1);
fclose(f2);
printf("\n                 ******  WEBKIOSK JIIT  ******     ");
printf("\n");
printf("\n                  Do you want to login as:\n");
printf("                            1:ADMIN\n");
printf("                            2:STUDENT\n");
printf("                            3:EXIT\n");
printf("   Please Enter Your Choice:\n");
scanf("%d",&no);
switch(no)
{
 case 1:clrscr();timedis();
		  printf("\n    Please Enter The Administrator Id-- ");
		  scanf("%ld",&id1);
		  printf("\n    Please Enter Your Password-- ");flushall();
		  gets(pass1);flushall();
		  f1=fopen("admin.txt","r");
		  r=fread(&ad,sizeof(ad),1,f1);
		  do
		  {
			if(id1==ad.id&&strcmp(pass1,ad.pass)==0)
			{
			flag=1;
			do
			{
			clrscr();
			timedis();
			printf("\n");
			printf("WELCOME (%ld) %s",ad.id,ad.adname);
			f1=fopen("admin.txt","r");
			printf("\n                ****** YOUR MENU*****\n");
			printf("\n                 1.UPLOADING OF MARKS\n");
			printf("\n                 2.UPLOADING OF ATTENDENCE\n");
			printf("\n                 3.LOGOUT!!");
			printf("\n Enter your choice\n");
			scanf("%d",&c);
			if(c==1)
			{
			fclose(f1);
			 markdetail();
			 }
			if(c==2)
			{
			fclose(f1);
			editattd();
			}
			if(c==3)
			{
			fclose(f1);
			printf("You Have Successfully logged out!!(Press any Key)!");
			goto front;
			}
			printf("\nDo You Want to Go to Main Menu?? Otherwise You Are Logged Out.(y/n)\n");flushall();
			scanf("%c",&choice);
			}while(choice=='y');
			}
		  if(choice=='n')
		  {
		  printf("You Have Successfully logged out!!(Press any Key)!");
			getch();
			goto front;
		  }
			r=fread(&ad,sizeof(ad),1,f1);
			}while(r>0);
			fclose(f1);
			if(flag==0)
			{
			printf("The Entered Id or Password Is Wrong..Sorry!!");
			getch();
			goto front;
			}
		  break;

case 2: clrscr();timedis();
		 f2=fopen("STUDpro.txt","r");
		 printf("\n       Please Enter Your Username Id-- ");
		 scanf("%ld",&id1);flushall();
		 printf("\n       Enter Your Password-- "); flushall();
		 gets(pass1);flushall();
		 r=fread(&k,sizeof(k),1,f2);
		 do
		 {
		 if(id1==k.id&&strcmpi(pass1,k.pass)==0)
		 {
		 flag=1;
		 do
		 {
		 clrscr();
		 timedis();
		 printf("\n");
		 printf(" WELCOME %ld",k.id);
		 f2=fopen("STUDpro.txt","r");
		 printf("\n                            ********* YOUR MENU*******\n");
		 printf("                                1. VIEW PERSONNEL DETAIL\n");
		 printf("                                2. EDIT PROFILE\n");
		 printf("                                3. VIEW MARKS\n");
		 printf("                                4. TIME TABLE\n");
		 printf("                                5. VIEW ATTENDANCE\n");
		 printf("                                6. LOGOUT!!");
		 printf("\n Select Your Desired Option-- ");
		 scanf("%d",&c);
		 switch(c)
		 {
		 case 1:fclose(f2);
					viewdet();
					break;
		  case 2:fclose(f2);
					editinfo();
					break;
		  case 3:fclose(f2);
					viewmark();
					break;
		  case 4:strcpy(batch,k.batch);
					fclose(f2);
					if(strcmpi(batch,"b4")==0)
					B4();
					if(strcmpi(batch,"b5")==0)
					B5();
					if(strcmpi(batch,"b6")==0)
					B6();
					break;
		  case 5:fclose(f2);
			 showattd();
			 break;
		  case 6:fclose(f2);
		  printf("You have successfully logged out!");getch();
					goto front;

		 }
		 printf("Do you want to go to Main Menu??(y/n) Otherwise You Are Logged Out.");flushall();
		 scanf("%c",&choice);
		 }while(choice=='y');
		if(choice=='n')
		  {
		  printf("You Have Successfully logged out!!(Press any Key)!");
			getch();
			goto front;
		  }
		 }
		 r=fread(&k,sizeof(k),1,f2);
		 }while(r>0);
		 fclose(f2);
		 if(flag==0)
			{
			printf("The Entered Id or Password Is Wrong..Sorry!!");
			getch();
			goto front;
			}
		  break;

case 3:exit(0);break;
}
getch();
}

