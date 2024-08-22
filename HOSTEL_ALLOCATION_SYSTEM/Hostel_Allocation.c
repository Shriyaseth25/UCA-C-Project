#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//global variables and methods
void newStu();
void update();
void display();
void delete();
void exit();
void menu();

int check;    //for entry check through roll numbers
int i, j, mexit;

struct date
{
        int month, day ,year;
}

struct student
{
        char name[50];
        int age;
        char city[50];
        char mail[50];
        char hostel_name[10];
        char room[5];
        char father_name[50];
        char mother_name[50];
        int phone;
        int parent_phone;
        int roll;
} add, upd, rem, sort, qwe[100], temp;


int main()
{
        int ch;
        printf("************WELCOME TO CHITKARA UNIVERSITY************");
        printf("************     HOSTEL ALLOTMENT: IBN    ************");
        printf("************ 1. LOGIN                     ************");
        printf("************ 2. SIGN IN                   ************");
        scanf("%d" , &ch);
        if(ch == 1)
                login();
        else
                signin();
        menu();
        return 0;
}

int login(void)
{
        int a = 0, i = 0;
        char uname[20], c = ' ';
        char pswd[10],code[10];
        char user[10] = "Shriya";
        char pass[10] = "12345";
        do
        {
                system("cls");
                printf("************WELCOME TO CHITKARA UNIVERSITY************");
                printf("************     HOSTEL ALLOTMENT: IBN    ************");
                printf("************            LOGIN             ************");
                printf("************ ENTER THE USERNAME:          ************");
                scanf("%s", &uname);
                printf("************ ENTER THE PASSWORD:          ************");

                while(i < 10)
                {
                        pswd[i] = getch();
                        c = pswd[i];
                        if(c == 13)     // 13 is ASCII code for enter
                                break;
                        else
                                printf("*");
                        i++;
                }
                pswd[i] = '\0';
                i = 0;
                if(strcmp(uname,user) == 0 && strcmp(pswd,pass) == 0)
                {
                        printf("************       LOGIN SUCCESSFUL       ************");
                        system("PAUSE");
                        break;
                }
                else
                {
                        printf("************      LOGIN UNSUCCESSFUL     ************");
                        system("PAUSE");
                        a++;
                        getch();
                }
        }
        while(a <= 2);

        if(a>2)
        {
                printf("SORRY YOU HAVE ENTERED WRONG PASSWORD MORE THAN THREE TIMES");
                getch();
        }
        system("cls");

}

void menu()
{
        int choice;

        system("CLS");  //to clear the screen

        printf("************WELCOME TO CHITKARA UNIVERSITY************");
        printf("************     HOSTEL ALLOTMENT: IBN    ************");
        printf("************           MAIN MENU          ************");
        printf("************ 1. ENTER NEW STUDENT DETAILS ************");
        printf("************ 2. UPDATE STUDENT DETAILS    ************");
        printf("************ 3. DISPLAY STUDENT DETAILS   ************");
        printf("************ 4. REMOVE STUDENT DETAILS    ************");
        printf("************ 5. EXIT                      ************");

        scanf("%d" ,&choice);

        switch(choice)
        {
                case 1:
                        newStu();
                        break;
                case 2:
                        update();
                        break;
                case 3:
                        display();
                        break;
                case 4:
                        delete();
                        break;
                case 5:
                        exit();
                        break;
                default:
                        menu();
        }

}

void newStu()
{
        system("cls");
        int choice;
        FILE *ptr, *hostel;
        ptr = fopen("student_record.dat","a+");

        roll:
        printf("************      ADD STUDENT DETAILS     ************");
        printf("ENTER ROLL NUMBER: ");
        scanf("%d", &check);

        while(fscanf(ptr,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",&add.roll, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, &add.mail, &add.father_name, &add.parent_phone, &add.room, &add.hostel_name)!=EOF)
        {
                if(check == add.roll)
                {
                        printf("Student's roll number is already in use");
                        goto roll;
                }
        }

        add.roll = check;

        printf("ENTER THE NAME: ");
        scanf("%s", &add.name);

        int z=1;

        while(z!=0)
        {
                int mm,dd,y;
                printf("ENTER THE DATE OF BIRTH (MM/DD/YYYY): ");
                scanf("%d/%d/%d",&mm,&dd,&y);
                if(y>=1900 && y<=9999)
                {
                        if(mm>=1 && mm<=12)
                        {
                                if(((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)) || ((dd>=1 && dd<=30)&&(mm==4 || mm==6 || mm==9 || mm==11)) || ((dd>=1 && dd<=28) && (mm==2)) || (dd==29 && mm==2 && (y%400==0 || (y%4==0 && y%100!=0))))
                                {
                                        add.dob.month=mm;
                                        add.dob.year=y;
                                        add.dob.day=dd;
                                }
                                else
                                {
                                        printf("Day is invalid.\n");
                                        continue;
                                }
                        }
                        else
                        {
                                printf("Month is not valid.\n");
                                continue;
                        }
                }
                else
                {
                        printf("Year is not valid.\n");
                        continue;
                }
        z=0;
        }
        printf("ENTER THE AGE: ");
        scanf("%d", &add.age);
        printf("ENTER THE CITY: ");
        scanf("%s", &add.city);
        printf("ENTER THE PHONE NUMBER: ");
        scanf("%d", &add.phone);
        printf("ENTER THE EMAIL ID: ");
        scanf("%s", &add.mail);
        printf("ENTER THE FATHER'S NAME: ");
        scanf("%s", &add.father_name);
        printf("ENTER THE PARENT'S PHONE NUMBER: ");
        scanf("%d", &add.parent_phone);
        printf("ENTER THE ROOM NUMBER: ");
        scanf("%d", &add.room);
        printf("ENTER THE HOSTEL NAME");
        scanf("%d", &add.hostel_name);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail, add.father_name, add.parent_phone, add.room, add.hostel_name);
        fclose(ptr);
        printf("***********  STUDENT ADDED SUCCESSFULLY   ************");
        add_invalid:
                printf("ENTER 1 TO GO TO MAIN MENU AND 0 TO EXIT: ");
                scanf("%d", &mexit);
                if(exit == 1)
                        menu();
                else if(mexit == 0)
                        exit();
                else
                {
                        printf("INVALID!!!!");
                        goto add_invalid;
                }
}

void update()
{
        system("CLS");
        int choice, test = 0;
        FILE *old, *newrec;
        old = fopen("student_record.dat","r");
        newrec = fopen("new_record.dat","w");

        printf("ENTER THE ROLL NUMBER YOU WANT TO CHANGE THE DETAILS OF: ");
        scanf("%s",upd.roll);

        while(fscanf(old,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",&add.roll, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.city, &add.phone, &add.mail, &add.father_name, &add.parent_phone, &add.room, &add.hostel_name)!=EOF)
        {
                if(add.roll == upd.roll)
                {
                        test = 1;
                        printf("ENTER : ");
                        printf("1. ROOM NUMBER");
                        printf("2. PHONE NUMBER");
                        scanf("%d", &choice);

                        if(choice == 1)
                        {
                                printf("ENTER NEW ROOM NUMBER");
                                scanf("%S", &upd.room);
                                fprintf(newrec,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail, add.father_name, add.parent_phone, upd.room, add.hostel_name);
                                printf("Changes saved!");
                        }

                        else if(choice == 2)
                        {
                                printf("Enter the new phone number:");
                                scanf("%d",&upd.phone);
                                fprintf(newrec,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, upd.phone, add.mail, add.father_name, add.parent_phone, add.room, add.hostel_name);
                                printf("Changes saved!");
                        }
                }
                else
                       fprintf(newrec,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail, add.father_name, add.parent_phone, add.room, add.hostel_name);
        }
        fclose(old);
        fclose(newrec);
        remove("student_record.dat");
        rename("new_record.dat","record.dat");

        if(test != 1)
                printf("RECORD NOT FOUND!!!");
        edit_invalid:
        printf("ENTER 0 TO TRY AGAIN, 1 TO RETURN TO MAIN MENU AND 2 TO EXIT: ");
        scanf("%d",&mexit);
        if (mexit==1)
                menu();
        else if (mexit==2)
                exit();
        else if(mexit==0)
                update();
        else
        {
                printf("\nInvalid!\a");
            goto edit_invalid;
        }
}
