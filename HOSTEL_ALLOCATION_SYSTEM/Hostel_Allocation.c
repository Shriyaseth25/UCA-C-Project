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

int login()
{
        int a = 0, i = 0;
        char uname[20], c = ' ';
        char pswd[10],code[10];
        char user[10] = "user";
        char pass[10] = "pass";
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
        printf("************      ADD STUDENT DETAILS     ************");
        printf("ENTER ROLL NUMBER: ");
        scanf("%d", &check);
        if(check == add.roll)
        {
                printf("Student's roll number is already in use");
                goto roll;
        }
        add.roll = check;
        printf("ENTER THE NAME: ");
        scanf("%s", &add.name);


}
