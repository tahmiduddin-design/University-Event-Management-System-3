#include "panel.h"
#include "student.h"
#include "event.h"

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
    char username[20], password[20];
    int choice;

    printf("\n========== ADMIN LOGIN ==========");

    printf("\nUsername : ");
    scanf("%19s", username);

    printf("Password : ");
    scanf("%19s", password);

    if(strcmp(username,"admin")!=0 || strcmp(password,"1234")!=0)
    {
        printf("\nInvalid Username or Password!");
        return;
    }

    printf("\nLogin Successful!");

    while(1)
    {
        printf("\n\n===== ADMIN PANEL =====");
        printf("\n1. Dashboard");
        printf("\n2. View Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. View Registrations");
        printf("\n7. View Payments");
        printf("\n8. Search Payment");
        printf("\n9. Back");

        printf("\nChoice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            dashboard();
            break;

        case 2:
            fp=fopen("student.txt","r");
            if(fp==NULL)
                printf("\nNo Student Found!");
            else
            {
                while(fgets(line,300,fp))
                    printf("%s",line);
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
            fp=fopen("registration.txt","r");
            if(fp==NULL)
                printf("\nNo Registration Found!");
            else
            {
                while(fgets(line,300,fp))
                    printf("%s",line);
                fclose(fp);
            }
            break;

        case 7:
            fp=fopen("payment.txt","r");
            if(fp==NULL)
                printf("\nNo Payment Found!");
            else
            {
                while(fgets(line,300,fp))
                    printf("%s",line);
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

        system("pause");
        system("cls");
    }
}

void reports()
{
    FILE *studentFile;
    FILE *registrationFile;
    FILE *paymentFile;

    char line[300];

    int studentCount = 0;
    int registrationCount = 0;
    int paymentCount = 0;

    printf("\n====================================");
    printf("\n         SYSTEM REPORT");
    printf("\n====================================");

    studentFile = fopen("student.txt", "r");

    if(studentFile == NULL)
    {
        printf("\nStudent File Not Found!");
    }
    else
    {
        while(fgets(line, sizeof(line), studentFile))
        {
            studentCount++;
        }
        fclose(studentFile);
    }

    registrationFile = fopen("registration.txt", "r");

    if(registrationFile == NULL)
    {
        printf("\nRegistration File Not Found!");
    }
    else
    {
        while(fgets(line, sizeof(line), registrationFile))
        {
            registrationCount++;
        }
        fclose(registrationFile);
    }

    paymentFile = fopen("payment.txt", "r");

    if(paymentFile == NULL)
    {
        printf("\nPayment File Not Found!");
    }
    else
    {
        while(fgets(line, sizeof(line), paymentFile))
        {
            paymentCount++;
        }
        fclose(paymentFile);
    }

    printf("\n\n========== REPORT ==========");
    printf("\nRegistered Students : %d", studentCount);
    printf("\nEvent Registrations : %d", registrationCount);
    printf("\nTotal Payments      : %d", paymentCount);
    printf("\nTotal Events        : 10");
    printf("\n============================");
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