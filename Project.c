//January 25,2022

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void login();
void signup();
void menu();
void registration();
void view();
void search();
void update();
void deleterec();
void paybill();
void routine();
void sadd();
void add();
void sview();
void ssearch();
void supdate();
void sdelete();

struct login
{
    char fname[100];
    char lname[20];
    char username[20];
    char password[20];
};
struct student
{
    char name[25];
    char club[50];
    int rollno;
    char depertment[20];
    char batch[20];
    char mobile[20];
};
struct routine
{
    char cname[20];
    char first[20];
    char second[20];
    char third[20];
    char fourth[20];
    char fifth[20];
    char sixth[20];
};
int main()
{
    system("COLOR 02");
    int choice;
    printf("\n\n\n\n\t\t\t\t****************************\n");
    printf("\t\t\t\tWelcome to Project CSE-1316");
    printf("\n\t\t\t\t****************************");
    printf("\n\t\t\t\t   Shuvo Sonjoy ");
    printf("\n\t\t\t\t---------------------------\n\n\n");

    printf("\n\t\t\t\t1. Signup as Admin\n\t\t\t\t2. Admin Login\n\t\t\t\t3. Exit\n\n\n\n\nEnter Your choice: ");

    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system ("CLS");

        signup();
        break;
    case 2:
        system("CLS");
        login();
        break;
    case 3:
        system("CLS");
        exit(1);
        break;
    default:
        system("cls");
        printf("\n\t\tError input\n\n");
        printf("\t\tenter any key to go entry page");
        getch();
        system("CLS");
        fflush(stdin);
        main();


    }

}

void signup()
{
    FILE *log;
    log=fopen("login12.txt","w");
    struct login l;
    printf("Enter Firstname: ");
    scanf("%s",&l.fname);
    printf("Enter lastname: ");
    scanf("%s",&l.lname);
    printf("Enter username: ");
    scanf("%s",&l.username);
    printf("Password: ");
    scanf("%s",&l.password);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);
    printf("\npress any key to continue");
    getch();
    system("CLS");
    login();

}

void login()
{
    char username[200],password[20];
    FILE *log;
    log=fopen("login12.txt","r");
    struct login l;
    printf("\n\n\n\t\t\t\tUser ID: ");
    scanf("%s",&username);
    printf("\n\t\t\t\tPassword: ");
    scanf("%s",&password);

    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {

            system("cls");
            printf("\n\n\t\t\tLogin Successful!!!!\n\n");
            printf("\n\n\t\t\tPress Enter to continue_");
            getch();
            system("cls");

            add();

        }
        else
        {
            system("cls");
            printf("\n\n\t\tEnter correct User ID or Password....\n\n");
            printf("\n\n\t\tPress any button to Retry from homepage");
            getch();
            system("CLS");
            main();
        }
    }
    fclose(log);
}
void add()
{


    int choice;
    printf("\n\n\t\t\t\tProject: Leading University Club Management and CSE Class Schedule.\n");
    printf("\t\t\t\t--------------------------------------------------------------------\n\n");
    printf("\n\n\n\t\t1.Leading University Club Management\n\t\t2.CSE class schedule\n\t\t3.Exit\n\n\tEnter Your Choice_");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system("cls");
        menu();
        break;

    case 2:
        system("cls");
        routine();
        break;
    case 3:
        exit(1);
        break;
    default:
        system("cls");
        printf("\nInvalid Input");

        fflush(stdin);
        getch();
        system("cls");
        add();
}


}

void menu()
{
    int choice;
    system("cls");
    printf("\n\n\n\t\t\t\t<--:MENU:-->\n");
    printf("\t\t\t\t------------\n\n\n");
    printf("\t\t1 : Registration.\n");
    printf("\t\t2 : View Club Member List.\n");
    printf("\t\t3 : Search Member.\n");
    printf("\t\t4 : Update Information.\n");
    printf("\t\t5 : Delete.\n");
    printf("\t\t6 : Homepage.\n");
    printf("\t\t7 : Exit");
    printf("\n\t\t\t\tEnter your choice_");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        registration();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        update();
        break;

    case 5:
        deleterec();
        break;
    case 6:
        system("cls");
        add();
        break;

    case 7:
        exit(1);
        break;

    default:
        system("cls");
        printf("Invalid Choice.");
    }
    fflush(stdin);
    getch();
    menu();
}
void registration()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","a");
    if(fp == NULL)
    {

        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {

        printf("\n\t\t\t<--:Registration:-->\n\n\n");
        printf("Enter details of student.\n");
        printf("--------------------------\n");

        printf("\n\t\tEnter Name : ");
        gets(std.name);

        printf("\t\tEnter Club name to join : ");
        gets(std.club);

        printf("\t\tEnter Roll No : ");
        scanf("%d",&std.rollno);
        fflush(stdin);

        printf("\t\tEnter Department : ");
        gets(std.depertment);
        printf("\t\tEnter Batch : ");
        gets(std.batch);
        printf("\t\tEnter Contact Number: ");
        gets(std.mobile);
        fwrite(&std,sizeof(std),1,fp);
        system("CLS");
        printf("\n\t\t\t  Payment Interface\n");
        printf("\t\t\t----------------------\n\n\n");
        paybill();
        system("CLS");

        printf("\n\n\t\t\tRegistration Successful.!!!");
        printf("\n\t\t\t-----------------------------\n\n\n");
        printf("\nMore registration? if yes then press 'y' else press 'n'_");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);

    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");

    printf("\n\n\n\n\n\n\t\t\t\t\t\t<--:VIEW Members information:-->\n\n\n");
    printf("S.No   Name of Student              Club               Roll No           Department         Batch        Mobile\n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    fp = fopen("record.txt","r");
    if(fp == NULL)
    {
        system("cls");

        printf("Error opening file.\n\n");
        printf(" press any key");
        getch();
        menu();

    }
    while(fread(&std,sizeof(std),1,fp) == 1)
    {

        printf("%-7d%-28s%-20s%-19d%-18s%-12s%-13s\n",i,std.name,std.club,std.rollno,std.depertment,std.batch,std.mobile);
        i++;
    }
    fclose(fp);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname[25];
    system("cls");

    printf("<--:SEARCH Student Information:-->\n\n");

    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","r");
    if(fp == NULL)
    {
        system("cls");
        printf("\n\t\tError opening file....");
        fflush(stdin);
        getch();
        menu();
    }
    while(fread(&std,sizeof(std),1,fp ) == 1)
    {
        if(strcmp(stname,std.name) == 0)
        {

            printf("\n\nName : %s\n",std.name);
            printf("Club : %s\n",std.club);
            printf("Roll No : %d\n",std.rollno);
            printf("Department : %s\n",std.depertment);
            printf("Batch : %s\n",std.batch);
            printf("Contact: %s\n",std.mobile);
        }
    }
    fclose(fp);

    printf("\n\n\nPress any key to continue.");
    getch();
    menu();
}
void update()
{
    char stname[20];
    FILE *fp;
    struct student std;
    system("cls");
    printf("<--:Update Information:-->\n");
    printf("Enter name of student to update: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        printf("Error opening file");
        fflush(stdin);
        menu();
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0){
            printf("Enter name: ");
            gets(std.name);
            printf("Enter Club : ");
            gets(std.club);
            printf("Enter roll no : ");
            scanf("%d",&std.rollno);
            printf("Enter Department : ");
            fflush(stdin);
            gets(std.depertment);
            printf("Enter Batch : ");
            fflush(stdin);
            gets(std.batch);
            fflush(stdin);
            printf("Enter Contact Number: ");
            gets(std.mobile);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }

    fclose(fp);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct student std;
    system("cls");
    printf("<--:DELETE Information:-->\n");
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    scanf("%s",&stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {    system("cls");
        printf("\n\t\tInvalid, File might be empty..");
        fflush(stdin);
        printf("\n\n\t\tPress any key___ ");
        getch();
        menu();
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL)
    {    system("cls");
        printf("\n\t\tInvalid operation, File might be Empty");
        fflush(stdin);
        printf("\n\n\t\tPress any key___ ");
        getch();
        menu();
    }
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    printf("Press any key to continue.");
    getch();
    menu();
}
void paybill()
{
    int n,cash;
    char trnid[20];
    printf("Total clubs joined: ");
    scanf("%d",&n);
    cash=n*300;
    printf("\n\nTotal cash=%d*300 BDT = %d BDT",n,cash);
    printf("\n\n\n\nPay Registration fee on 01700000000 bkash account \n\n");
    printf("If students pay registration fee,then please enter the Transaction ID bellow-----\n\n");
    printf("\t\t\tTransaction ID: ");
    scanf("%s",&trnid);

}
void routine()
{
    printf("\n\n\t\t\t\tCSE Class Schedule---");

    int choice;
    printf("\n\n\t\t1.Add Classes \n\t\t2.View Classes\n\t\t3.Search\n\t\t4.update\n\t\t5.delete\n\t\t6.Homepage\n\t\t7.Exit");
    printf("\n\n\t\tEnter Your Choice_");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        sadd();
        break;
    case 2:
        sview();
        break;
    case 3:
        ssearch();
        break;
    case 4:
        supdate();
        break;
    case 5:
        sdelete();
        break;
    case 6:
        system("cls");
        add();
        break;
    case 7:
        exit(1);
        break;
    default:
        system("cls");
        printf("\n\n\t\tInvalid Choice\n");
        fflush(stdin);
        getch();
        system("cls");
        routine();

    }

}
void sadd()
{
    FILE *sc;
    struct routine sch;
    char another ='y';
    sc=fopen("routine.txt","a");
    if(sc==NULL)
    {

        printf("Error opening");
        exit(1);
    }
    fflush(stdin);
    while(another=='y')
    {
        system("cls");
        printf("\n\n\t\t\tAdd Classes---\n\n");
        printf("\n\tWhich batch? : ");
        gets(sch.cname);

        printf("\n\tFirst Class: ");
        gets(sch.first);
        printf("\n\tSecond Class: ");
        gets(sch.second);
        printf("\n\tThird Class: ");
        gets(sch.third);
        printf("\n\tFourth Class: ");
        gets(sch.fourth);
        printf("\n\tFifth Class: ");
        gets(sch.fifth);
        printf("\n\tSixth Class: ");
        gets(sch.sixth);
        fwrite(&sch,sizeof(sch),1,sc);
        system("cls");
        printf("\n\t\tAdd more if yes then press-Y or press-N");
        fflush(stdin);
        another=getch();
        system("cls");
        fflush(stdin);
    }
    fclose(sc);
    printf("Press any key");
    getch();
    system("cls");
    routine();

}
void sview()
{
    FILE *sc;
    struct routine sch;
    int i=1;
    system("cls");
    printf("\nS.No    Batch\t8:55AM-9:45AM\t9:50AM-10:40AM\t10:45-11:35AM\t12:35AM-1:25PM\t2:15PM-3:05PM\t3:10PM-4:00PM\n");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    sc=fopen("routine.txt","r");
    if(sc==NULL)
    {
        system("cls");
        printf("Error opening file");
        getch();
         system("cls");
        routine();
    }
    while(fread(&sch,sizeof(sch),1,sc)==1)
    {
        printf("%-8d%-8s%-16s%-16s%-16s%-16s%-16s%-16s\n",i,sch.cname,sch.first,sch.second,sch.third,sch.fourth,sch.fifth,sch.sixth);
        i++;

    }
    fclose(sc);
    getch();
    system("cls");
    routine();

}
void ssearch()
{
    FILE *sc;
    struct routine sch;
    char batch[10];
    system("cls");
    fflush(stdin);
    printf("Enter batch: ");
    scanf("%s",&batch);
    sc=fopen("routine.txt","r");
    if(sc==NULL)
    {
        printf("error opening file");
        exit(1);
    }
    while(fread(&sch,sizeof(sch),1,sc)==1)
    {
        if(strcmp(batch,sch.cname)==0)
        {
            printf("Batch: %s\n\n",sch.cname);
            printf("08:55AM-09:45AM: %s\n",sch.first);
            printf("09:50AM-10:40AM: %s\n",sch.second);
            printf("10:45AM-11:35AM: %s\n",sch.third);
            printf("12:35AM-01:25PM: %s\n",sch.fourth);
            printf("02:15PM-03:05PM: %s\n",sch.fifth);
            printf("03:10PM-04:00PM: %s\n",sch.sixth);
        }

    }
    fclose(sc);
    getch();
    system("cls");
    routine();
}
void supdate()
{
    FILE *sc;
    char batch[20];
    struct routine sch;
    system("cls");

    fflush(stdin);
    printf("\n\n\t\tWhich Batch: ");
    gets(batch);
    printf("\n\n\t\t\tUpdate schedule--");

    sc=fopen("routine.txt","r");
    if(sc==NULL)
    {

        printf("Error opening");
        exit(1);
    }
    rewind(sc);
    fflush(stdin);
    while(fread(&sch,sizeof(sch),1,sc)==1)
    {
        if(strcmp(batch,sch.cname)==0)
        {
            printf("\n\tBatch: ");
            gets(sch.cname);

            printf("\n\tFirst Class: ");
            gets(sch.first);

            printf("\n\tSecond Class: ");
            gets(sch.second);
            printf("\n\tThird Class: ");
            gets(sch.third);
            printf("\n\tFourth Class: ");
            gets(sch.fourth);
            printf("\n\tFifth Class: ");
            gets(sch.fifth);
            printf("\n\tSixth Class: ");
            gets(sch.sixth);
            fseek(sc,-sizeof(sch),SEEK_CUR);
            fwrite(&sch,sizeof(sch),1,sc);
            break;


        }
    }
    fclose(sc);
    getch();
    system("cls");
    routine();

}
void sdelete()
{
    char sbatch[20];
    FILE *st,*sc;
    struct routine rsch;
    system("cls");
    printf("<--:DELETE-->\n");
    printf(" select batch to delete record: ");
    fflush(stdin);
    scanf("%s",&sbatch);
    sc = fopen("routine.txt","rb+");
    if(sc == NULL)
    {
        printf("Error opening file");
        getch();
        routine();
    }
    st= fopen("routine2.txt","wb+");
    if(st == NULL)
    {
        printf("Error opening file");
        getch();
        routine();
    }
    while(fread(&rsch,sizeof(rsch),1,sc) == 1)
    {
        if(strcmp(sbatch,rsch.cname)!=0)
            fwrite(&rsch,sizeof(rsch),1,sc);
    }
    fclose(sc);
    fclose(st);
    remove("routine.txt");
    rename("routine2.txt","routine.txt");
    printf("Press any key to continue.");
    getch();
    routine();
}
