#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "student.h"
#include "event.h"
#include "panel.h"

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
            case 1: studentRegistration(); break;
            case 2: studentLogin(); break;
            case 3: viewEvents(); break;
            case 4: registerEvent(); break;
            case 5: payment(); break;
            case 6: coordinatorPanel(); break;
            case 7: adminPanel(); break;
            case 8: reports(); break;
            case 9: printf("\nThank You.\n"); exit(0);
            default: printf("\nInvalid Choice!");
        }

        printf("\n\n");
        system("pause");
        system("cls");
    }

    return 0;
}