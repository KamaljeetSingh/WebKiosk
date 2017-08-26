#include<stdio.h>
#include<conio.h>
struct stud             //student str
{long int id;
char pass[10];
char batch[3];
}a;

struct attend           //attend str
{long int id;
char s1[8][100];
float at[8];
}b;

struct admin            //admin str
{
long int id;
char pass[10],adname[20];
}ad;

struct editinfo           //student info str
{
long int id;
char name[20];
char fname[20];
char mname[20];
char cellno[12];
char email[20];
char address[50];
}e;

struct academic                    //student marks struct
{
long int id;
int marks[5];
}m;

void markdetail()                                      //entering marks
{
FILE *fp;
int i;
fp=fopen("marks.txt","w");
for(i=0;i<15;i++)
{
printf("\n enter id:");
scanf("%ld",&m.id);
printf("\n physics:");
scanf("%d",&m.marks[0]);
printf("\n maths:");
scanf("%d",&m.marks[1]);
printf("\n eca");
scanf("%d",&m.marks[2]);
printf("\n icp:");
scanf("%d",&m.marks[3]);
printf("\n pd:");
scanf("%d",&m.marks[4]);
fwrite(&m,sizeof(m),1,fp);
}
fclose(fp);
}

void inputadid()                            //entering admin details
{
FILE *fp;
long int i;
fp=fopen("admin.txt","w");
for(i=0;i<2;i++)
{
printf("\n enter your name");flushall();
gets(ad.adname);flushall();
printf("\n id:");flushall();
scanf("%ld",&ad.id);flushall();
printf("\n adpass:");flushall();
gets(ad.pass);flushall();
fwrite(&ad,sizeof(ad),1,fp);
}
fclose(fp);
}


void attd()                                  //entering simple attd
{
FILE *f2;
int i,j,k,n=0;
{
f2=fopen("STUDatd.txt","w");
for(i=0;i<15;i++)
{
printf("Enter id--");
scanf("%ld",&b.id);
for(j=0;j<8;j++)
{
printf("%d-- ",j+1);flushall();
gets(b.s1[j]);flushall();
n=0;
for(k=0;b.s1[j][k];k++)
{
if(b.s1[j][k]=='p')
n++;
}
b.at[j]=((float)n/k)*100;
}
fwrite(&b,sizeof(b),1,f2);
}
}
fclose(f2);
}

void perdetails()                                  //studen information fn
{
FILE *fp;
int i;
fp=fopen("per.txt","w");
for(i=0;i<15;i++)
{
printf("\n enter your id ");flushall();
scanf("%ld",&e.id);flushall();
printf("\nname:");flushall();
gets(e.name);flushall();
printf("\n fathers name:");flushall();
gets(e.fname);flushall();
printf("\n mothers name:");flushall();
gets(e.mname);flushall();
printf("\n residential address:");flushall();
gets(e.address);flushall();
printf("\nmobile no:");flushall();
gets(e.cellno); flushall();
printf("\nemail:"); flushall();
gets(e.email);  flushall();
fwrite(&e,sizeof(e),1,fp);
}
fclose(fp);
}






void main()
{
FILE *f1;int i;
clrscr();
if(0)
{
printf("Enter Student details--\n");                //entering student details
f1=fopen("STUDpro.txt","w");
for(i=0;i<15;i++)
{
printf("Enter roll no.--");
scanf("%ld",&a.id);
printf("Enter pass--");flushall();
gets(a.pass);
printf("Enter Batch-- ");flushall();
gets(a.batch);flushall();
fwrite(&a,sizeof(a),1,f1);
}
fclose(f1);
}
if(0)
{
clrscr();
printf("Enter Admin details--\n");
inputadid();
}
if(0)
{
clrscr();
printf("Enter Attendance details--\n");
attd();
}
if(0)
{
clrscr();
printf("Enter Student Information--\n");
perdetails();
}
if(0)
{
clrscr();
printf("Enter Marks--\n");
markdetail();
}

getch();
}








