#include "event.h"
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
    int eventType;
    int runningStudent;
    int alumni;
    int department;
    int finalFee;

    printf("\n====================================");
    printf("\n         PAYMENT MODULE");
    printf("\n====================================");

    printf("\nEnter Student ID : ");
    scanf("%s", studentId);

    printf("\nEnter Event Name : ");
    scanf(" %[^\n]", eventName);

    printf("\nEnter Event Fee : ");
    scanf("%d", &fee);

    printf("\nEvent Type");
    printf("\n1. Department Event");
    printf("\n2. Club Event");
    printf("\n3. Central Event");
    printf("\nEnter Choice : ");
    scanf("%d", &eventType);

    if(eventType == 2 || eventType == 3)
    {
        finalFee = 0;
        printf("\nThis Event Is Free.");
    }
    else
    {
        finalFee = fee;

        printf("\nRunning Student?");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoice : ");
        scanf("%d", &runningStudent);

        if(runningStudent == 1)
        {
            finalFee = finalFee - (finalFee * 10 / 100);
            printf("\nRunning Student Discount (10%%) Applied.");
        }

        printf("\nAre You Alumni?");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nChoice : ");
        scanf("%d", &alumni);

        if(alumni == 1)
        {
            finalFee = finalFee - (finalFee * 10 / 100);
            printf("\nAlumni Discount (10%%) Applied.");
        }

        printf("\nDepartment");
        printf("\n1. SWE");
        printf("\n2. CSE");
        printf("\n3. EEE");
        printf("\n4. Other");
        printf("\nChoice : ");
        scanf("%d", &department);

        if(department == 1 || department == 2 || department == 3)
        {
            finalFee = finalFee - (finalFee * 5 / 100);
            printf("\nDepartment Discount (5%%) Applied.");
        }
    }

    fp = fopen("payment.txt", "a");

    if(fp == NULL)
    {
        printf("\nFile Cannot Open!");
        return;
    }

    fprintf(fp, "%s|%s|%d|Paid\n",
            studentId,
            eventName,
            finalFee);

    fclose(fp);

    printf("\n====================================");
    printf("\nPayment Successful!");
    printf("\n====================================");

    printf("\nStudent ID    : %s", studentId);
    printf("\nEvent         : %s", eventName);
    printf("\nFinal Amount  : %d TK", finalFee);
    printf("\nStatus        : Paid");
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