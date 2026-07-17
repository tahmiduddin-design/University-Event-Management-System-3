#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void studentRegistration();
void studentLogin();
void viewEvents();
void registerEvent();
void payment();
void coordinatorPanel();
void adminPanel();
void reports();
void searchStudent();
void deleteStudent();
void updateStudent();
void searchRegistration();
void searchPayment();
void dashboard();
struct Student
{
    char studentId[20];
    char name[50];
    char department[50];
    char phone[20];
    char password[20];
};
void studentRegistration();
int main()
{
    int choice;

    while (1)
    {
        printf("\n==========================================");
        printf("\n   UNIVERSITY EVENT MANAGEMENT SYSTEM");
        printf("\n==========================================");

        printf("\n1. Student Registration");
        printf("\n2. Student Login");
        printf("\n3. View Events");
        printf("\n4. Register For Event");
        printf("\n5. Payment");
        printf("\n6. Event Coordinator");
        printf("\n7. Admin Panel");
        printf("\n8. Reports");
        printf("\n9. Exit");

        printf("\n\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
           case 1:
    studentRegistration();
    break;

            case 2:
             studentLogin();
              break;

            case 3:
             viewEvents();
             break;

            case 4:
             registerEvent();
            break;

            case 5:
            payment();
            break;

            case 6:
               coordinatorPanel();
               break;

            case 7:
              adminPanel();
             break;

            case 8:
    reports();
    break;
            case 9:
                printf("\nThank You.\n");
                exit(0);

            default:
                printf("\nInvalid Choice!");
        }

        printf("\n\n");
        system("pause");
        system("cls");
    }

    return 0;
}
void studentRegistration()
{
    struct Student s;
    struct Student temp;

    FILE *fp;

    int found = 0;

    printf("\n====================================");
    printf("\n      STUDENT REGISTRATION");
    printf("\n====================================");

    printf("\nEnter Student ID : ");
    scanf("%19s", s.studentId);

    printf("\nEnter Student Name : ");
    scanf(" %49[^\n]", s.name);

    printf("\nEnter Department : ");
    scanf(" %49[^\n]", s.department);

    printf("\nEnter Phone Number : ");
    scanf("%19s", s.phone);

    printf("\nEnter Password : ");
    scanf("%19s", s.password);

    fp = fopen("student.txt", "r");

    if(fp != NULL)
    {
        while(fscanf(fp,
        "%19[^|]|%49[^|]|%49[^|]|%19[^|]|%19[^\n]\n",
        temp.studentId,
        temp.name,
        temp.department,
        temp.phone,
        temp.password) == 5)
        {
            if(strcmp(temp.studentId, s.studentId) == 0)
            {
                found = 1;
                break;
            }
        }

        fclose(fp);
    }

    if(found)
    {
        printf("\nStudent ID Already Exists!");
        return;
    }

    fp = fopen("student.txt", "a");

    if(fp == NULL)
    {
        printf("\nFile Cannot Open!");
        return;
    }

    fprintf(fp,"%s|%s|%s|%s|%s\n",
            s.studentId,
            s.name,
            s.department,
            s.phone,
            s.password);

    fclose(fp);

    printf("\n====================================");
    printf("\nRegistration Successful!");
    printf("\n====================================");
}

void studentLogin()
{
    FILE *fp;
    struct Student s;

    char id[20];
    char password[20];

    int found = 0;

    printf("\n====================================");
    printf("\n         STUDENT LOGIN");
    printf("\n====================================");

    printf("\nEnter Student ID : ");
    scanf("%s", id);

    printf("\nEnter Password : ");
    scanf("%s", password);

    fp = fopen("student.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Registered Student Found!");
        return;
    }

    while(fscanf(fp,
"%19[^|]|%49[^|]|%49[^|]|%19[^|]|%19[^\n]\n",
s.studentId,
s.name,
s.department,
s.phone,
s.password)==5)
    {
        if(strcmp(id,s.studentId)==0 &&
           strcmp(password,s.password)==0)
        {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if(found)
    {
        printf("\n====================================");
        printf("\nLogin Successful!");
        printf("\nWelcome %s",s.name);
        printf("\nDepartment : %s",s.department);
        printf("\n====================================");
    }
    else
    {
        printf("\nInvalid Student ID Or Password!");
    }
}
void viewEvents()
{
    printf("\n===============================================");
    printf("\n        AVAILABLE UNIVERSITY EVENTS");
    printf("\n===============================================");

    printf("\n1. Seminar");
    printf("\n   Date : 10 August 2026");
    printf("\n   Fee  : 200 TK\n");

    printf("\n2. Programming Contest");
    printf("\n   Date : 15 August 2026");
    printf("\n   Fee  : 500 TK\n");

    printf("\n3. Workshop");
    printf("\n   Date : 20 August 2026");
    printf("\n   Fee  : 300 TK\n");

    printf("\n4. Hackathon");
    printf("\n   Date : 25 August 2026");
    printf("\n   Fee  : 700 TK\n");

    printf("\n5. Cultural Fest");
    printf("\n   Date : 30 August 2026");
    printf("\n   Fee  : 400 TK\n");

    printf("\n6. Job Fair");
    printf("\n   Date : 05 September 2026");
    printf("\n   Fee  : Free\n");

    printf("\n7. Sports Tournament");
    printf("\n   Date : 10 September 2026");
    printf("\n   Fee  : 250 TK\n");

    printf("\n8. Orientation Program");
    printf("\n   Date : 15 September 2026");
    printf("\n   Fee  : Free\n");

    printf("\n9. Convocation");
    printf("\n   Date : 20 September 2026");
    printf("\n   Fee  : 1000 TK\n");

    printf("\n10. Foundation Day");
    printf("\n    Date : 25 September 2026");
    printf("\n    Fee  : Free\n");

    printf("\n===============================================");
}
void registerEvent()
{
    char studentId[20];
    char name[50];
    int event;

    FILE *fp;
    char eventName[50];

    printf("\n====================================");
    printf("\n      EVENT REGISTRATION");
    printf("\n====================================");

    printf("\nEnter Student ID : ");
    scanf("%s", studentId);

    printf("\nEnter Student Name : ");
    scanf(" %[^\n]", name);

    printf("\nSelect Event");
    printf("\n1. Seminar");
    printf("\n2. Programming Contest");
    printf("\n3. Workshop");
    printf("\n4. Hackathon");
    printf("\n5. Cultural Fest");
    printf("\n6. Job Fair");
    printf("\n7. Sports Tournament");
    printf("\n8. Orientation Program");
    printf("\n9. Convocation");
    printf("\n10. Foundation Day");

    printf("\n\nEnter Event Number : ");
    scanf("%d", &event);

    switch(event)
    {
        case 1:
            strcpy(eventName, "Seminar");
            break;

        case 2:
            strcpy(eventName, "Programming Contest");
            break;

        case 3:
            strcpy(eventName, "Workshop");
            break;

        case 4:
            strcpy(eventName, "Hackathon");
            break;

        case 5:
            strcpy(eventName, "Cultural Fest");
            break;

        case 6:
            strcpy(eventName, "Job Fair");
            break;

        case 7:
            strcpy(eventName, "Sports Tournament");
            break;

        case 8:
            strcpy(eventName, "Orientation Program");
            break;

        case 9:
            strcpy(eventName, "Convocation");
            break;

        case 10:
            strcpy(eventName, "Foundation Day");
            break;

        default:
            printf("\nInvalid Event!");
            return;
    }

    fp = fopen("registration.txt", "a");

    if(fp == NULL)
    {
        printf("\nFile Cannot Open!");
        return;
    }

    fprintf(fp, "%s|%s|%s\n",
            studentId,
            name,
            eventName);

    fclose(fp);

    printf("\n====================================");
    printf("\nRegistration Successful!");
    printf("\n====================================");

    printf("\nStudent ID   : %s", studentId);
    printf("\nStudent Name : %s", name);
    printf("\nEvent        : %s", eventName);
}
void payment()
{
    FILE *fp;

    char studentId[20];
    char eventName[50];

    int fee;

    printf("\n====================================");
    printf("\n         PAYMENT MODULE");
    printf("\n====================================");

    printf("\nEnter Student ID : ");
    scanf("%s", studentId);

    printf("\nEnter Event Name : ");
    scanf(" %[^\n]", eventName);

    printf("\nEnter Registration Fee : ");
    scanf("%d", &fee);

    fp = fopen("payment.txt", "a");

    if(fp == NULL)
    {
        printf("\nFile Cannot Open!");
        return;
    }

    fprintf(fp,"%s|%s|%d|Paid\n",
            studentId,
            eventName,
            fee);

    fclose(fp);

    printf("\n====================================");
    printf("\nPayment Successful!");
    printf("\n====================================");

    printf("\nStudent ID : %s", studentId);
    printf("\nEvent : %s", eventName);
    printf("\nAmount : %d TK", fee);
    printf("\nStatus : Paid");
}
void coordinatorPanel()
{
    FILE *fp;
    char line[300];

    char username[20];
    char password[20];

    int choice;

    printf("\n========================================");
    printf("\n       COORDINATOR LOGIN");
    printf("\n========================================");

    printf("\nEnter Username : ");
    scanf("%s", username);

    printf("Enter Password : ");
    scanf("%s", password);

    if(strcmp(username, "coordinator") != 0 || strcmp(password, "1234") != 0)
    {
        printf("\nInvalid Username or Password!");
        return;
    }

    printf("\n\nLogin Successful!");

    while(1)
    {
        printf("\n========================================");
        printf("\n        COORDINATOR PANEL");
        printf("\n========================================");

        printf("\n1. View Event Registrations");
printf("\n2. Search Registration");
printf("\n3. Back");
        printf("\n\nEnter Your Choice : ");
        scanf("%d",&choice);

        switch(choice)
{
case 1:

    fp = fopen("registration.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Registration Found!");
    }
    else
    {
        printf("\n\n===== EVENT REGISTRATION LIST =====\n\n");

        while(fgets(line,sizeof(line),fp)!=NULL)
        {
            printf("%s",line);
        }

        fclose(fp);
    }

    break;

case 2:
    searchRegistration();
    break;

case 3:
    return;

default:
    printf("\nInvalid Choice!");
}
        printf("\n\n");
        system("pause");
        system("cls");
    }
}
void adminPanel()
{
    FILE *fp;
    char line[300];

    char username[20];
    char password[20];

    int choice;

    printf("\n========================================");
    printf("\n            ADMIN LOGIN");
    printf("\n========================================");

    printf("\nEnter Username : ");
    scanf("%s", username);

    printf("Enter Password : ");
    scanf("%s", password);

    if(strcmp(username, "admin") != 0 || strcmp(password, "1234") != 0)
    {
        printf("\nInvalid Admin Username or Password!");
        return;
    }

    printf("\n\nLogin Successful!");

    while(1)
    {
        printf("\n========================================");
        printf("\n            ADMIN PANEL");
        printf("\n========================================");

        printf("\n1. Dashboard");
printf("\n2. View All Students");
printf("\n3. Search Student");
printf("\n4. Update Student");
printf("\n5. Delete Student");
printf("\n6. View All Event Registrations");
printf("\n7. View All Payments");
printf("\n8. Search Payment");
printf("\n9. Back");
        printf("\n\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
{
case 1:

    dashboard();

    break;

case 2:

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo Student Found!");
    }
    else
    {
        printf("\n\n===== STUDENT LIST =====\n\n");

        while(fgets(line, sizeof(line), fp) != NULL)
        {
            printf("%s", line);
        }

        fclose(fp);
    }

    break;

case 3:

    searchStudent();

    break;

case 4:

    updateStudent();

    break;

case 5:

    deleteStudent();

    break;

case 6:

    fp = fopen("registration.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo Registration Found!");
    }
    else
    {
        printf("\n\n===== EVENT REGISTRATION LIST =====\n\n");

        while(fgets(line, sizeof(line), fp) != NULL)
        {
            printf("%s", line);
        }

        fclose(fp);
    }

    break;

case 7:

    fp = fopen("payment.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo Payment Found!");
    }
    else
    {
        printf("\n\n===== PAYMENT LIST =====\n\n");

        while(fgets(line, sizeof(line), fp) != NULL)
        {
            printf("%s", line);
        }

        fclose(fp);
    }

    break;

case 8:

    searchPayment();

    break;

case 9:

    return;

default:

    printf("\nInvalid Choice!");
}

printf("\n\n");
system("pause");
system("cls");
}
}
void reports()
{
    FILE *studentFile, *registrationFile, *paymentFile;
    char line[300];

    int studentCount = 0;
    int registrationCount = 0;
    int paymentCount = 0;

    printf("\n========================================");
    printf("\n          SYSTEM REPORT");
    printf("\n========================================");

    /* Count Students */
    studentFile = fopen("student.txt", "r");

    if(studentFile == NULL)
    {
        printf("\nStudent File Not Found!");
    }
    else
    {
        while(fgets(line, sizeof(line), studentFile) != NULL)
        {
            studentCount++;
        }
        fclose(studentFile);
    }

    /* Count Event Registrations */
    registrationFile = fopen("registration.txt", "r");

    if(registrationFile == NULL)
    {
        printf("\nRegistration File Not Found!");
    }
    else
    {
        while(fgets(line, sizeof(line), registrationFile) != NULL)
        {
            registrationCount++;
        }
        fclose(registrationFile);
    }

    /* Count Payments */
    paymentFile = fopen("payment.txt", "r");

    if(paymentFile == NULL)
    {
        printf("\nPayment File Not Found!");
    }
    else
    {
        while(fgets(line, sizeof(line), paymentFile) != NULL)
        {
            paymentCount++;
        }
        fclose(paymentFile);
    }

    printf("\n\n========== REPORT ==========");
    printf("\nTotal Registered Students : %d", studentCount);
    printf("\nTotal Event Registrations : %d", registrationCount);
    printf("\nTotal Payments            : %d", paymentCount);
    printf("\nTotal Events              : 10");
    printf("\n============================");
}
void searchStudent()
{
    FILE *fp;
    struct Student s;

    char id[20];
    int found = 0;

    printf("\n========================================");
    printf("\n        SEARCH STUDENT");
    printf("\n========================================");

    printf("\nEnter Student ID : ");
    scanf("%s", id);

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("\nStudent File Not Found!");
        return;
    }

    while(fscanf(fp,
    "%19[^|]|%49[^|]|%49[^|]|%19[^|]|%19[^\n]\n",
    s.studentId,
    s.name,
    s.department,
    s.phone,
    s.password) == 5)
    {
        if(strcmp(id, s.studentId) == 0)
        {
            found = 1;

            printf("\n========================================");
            printf("\n       STUDENT FOUND");
            printf("\n========================================");

            printf("\nStudent ID : %s", s.studentId);
            printf("\nName       : %s", s.name);
            printf("\nDepartment : %s", s.department);
            printf("\nPhone      : %s", s.phone);

            break;
        }
    }

    fclose(fp);

    if(found == 0)
    {
        printf("\nStudent Not Found!");
    }
}
void updateStudent()
{
    FILE *fp, *temp;
    struct Student s;

    char id[20];
    int found = 0;

    printf("\n====================================");
    printf("\n       UPDATE STUDENT");
    printf("\n====================================");

    printf("\nEnter Student ID : ");
    scanf("%s", id);

    fp = fopen("student.txt", "r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL)
    {
        printf("\nStudent File Not Found!");
        return;
    }

    while(fscanf(fp,"%19[^|]|%49[^|]|%49[^|]|%19[^|]|%19[^\n]\n",
          s.studentId,
          s.name,
          s.department,
          s.phone,
          s.password)==5)
    {
        if(strcmp(id,s.studentId)==0)
        {
            found = 1;

            printf("\nNew Name : ");
            scanf(" %[^\n]", s.name);

            printf("New Department : ");
            scanf(" %[^\n]", s.department);

            printf("New Phone : ");
            scanf("%s", s.phone);

            printf("New Password : ");
            scanf("%s", s.password);
        }

        fprintf(temp,"%s|%s|%s|%s|%s\n",
                s.studentId,
                s.name,
                s.department,
                s.phone,
                s.password);
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt","student.txt");

    if(found)
        printf("\nStudent Updated Successfully!");
    else
        printf("\nStudent Not Found!");
}
void deleteStudent()
{
    FILE *fp, *temp;
    struct Student s;

    char id[20];
    int found = 0;

    printf("\n========================================");
    printf("\n         DELETE STUDENT");
    printf("\n========================================");

    printf("\nEnter Student ID : ");
    scanf("%s", id);

    fp = fopen("student.txt", "r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL)
    {
        printf("\nStudent File Not Found!");
        return;
    }

    while(fscanf(fp,
        "%19[^|]|%49[^|]|%49[^|]|%19[^|]|%19[^\n]\n",
        s.studentId,
        s.name,
        s.department,
        s.phone,
        s.password) == 5)
    {
        if(strcmp(id, s.studentId) == 0)
        {
            found = 1;
        }
        else
        {
            fprintf(temp,"%s|%s|%s|%s|%s\n",
                    s.studentId,
                    s.name,
                    s.department,
                    s.phone,
                    s.password);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt","student.txt");

    if(found)
    {
        printf("\nStudent Deleted Successfully!");
    }
    else
    {
        printf("\nStudent Not Found!");
    }
}
void searchRegistration()
{
    FILE *fp;

    char studentId[20];
    char id[20];
    char name[50];
    char event[50];

    int found = 0;

    printf("\n========================================");
    printf("\n     SEARCH REGISTRATION");
    printf("\n========================================");

    printf("\nEnter Student ID : ");
    scanf("%s", studentId);

    fp = fopen("registration.txt","r");

    if(fp == NULL)
    {
        printf("\nRegistration File Not Found!");
        return;
    }

    while(fscanf(fp,"%19[^|]|%49[^|]|%49[^\n]\n",
          id,name,event)==3)
    {
        if(strcmp(studentId,id)==0)
        {
            found=1;

            printf("\n========================================");
            printf("\n Registration Found");
            printf("\n========================================");

            printf("\nStudent ID : %s",id);
            printf("\nName       : %s",name);
            printf("\nEvent      : %s",event);

            break;
        }
    }

    fclose(fp);

    if(found==0)
    {
        printf("\nRegistration Not Found!");
    }
}
void searchPayment()
{
    FILE *fp;

    char searchId[20];
    char id[20];
    char event[50];
    char status[20];

    int amount;
    int found = 0;

    printf("\n========================================");
    printf("\n          SEARCH PAYMENT");
    printf("\n========================================");

    printf("\nEnter Student ID : ");
    scanf("%s", searchId);

    fp = fopen("payment.txt", "r");

    if(fp == NULL)
    {
        printf("\nPayment File Not Found!");
        return;
    }

    while(fscanf(fp,"%19[^|]|%49[^|]|%d|%19[^\n]\n",
                 id,event,&amount,status)==4)
    {
        if(strcmp(searchId,id)==0)
        {
            found=1;

            printf("\n========================================");
            printf("\n          PAYMENT FOUND");
            printf("\n========================================");

            printf("\nStudent ID : %s",id);
            printf("\nEvent      : %s",event);
            printf("\nAmount     : %d TK",amount);
            printf("\nStatus     : %s",status);

            break;
        }
    }

    fclose(fp);

    if(found==0)
    {
        printf("\nPayment Record Not Found!");
    }
}
void dashboard()
{
    FILE *fp;
    char line[300];

    int student = 0;
    int registration = 0;
    int payment = 0;

    fp = fopen("student.txt","r");

    if(fp != NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            student++;

        fclose(fp);
    }

    fp = fopen("registration.txt","r");

    if(fp != NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            registration++;

        fclose(fp);
    }

    fp = fopen("payment.txt","r");

    if(fp != NULL)
    {
        while(fgets(line,sizeof(line),fp)!=NULL)
            payment++;

        fclose(fp);
    }

    printf("\n========================================");
    printf("\n             DASHBOARD");
    printf("\n========================================");

    printf("\nTotal Students      : %d", student);
    printf("\nTotal Registrations : %d", registration);
    printf("\nTotal Payments      : %d", payment);

    printf("\n========================================");
}
