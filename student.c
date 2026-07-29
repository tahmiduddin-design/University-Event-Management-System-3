#include "student.h"

void md5Hash(char *input, char *output)
{
    HCRYPTPROV hProv = 0;
    HCRYPTHASH hHash = 0;

    BYTE hash[16];
    DWORD hashLen = 16;

    if(!CryptAcquireContext(
        &hProv,
        NULL,
        NULL,
        PROV_RSA_FULL,
        CRYPT_VERIFYCONTEXT))
    {
        strcpy(output, "");
        return;
    }

    if(!CryptCreateHash(
        hProv,
        CALG_MD5,
        0,
        0,
        &hHash))
    {
        CryptReleaseContext(hProv, 0);
        strcpy(output, "");
        return;
    }

    CryptHashData(
        hHash,
        (BYTE*)input,
        strlen(input),
        0
    );

    CryptGetHashParam(
        hHash,
        HP_HASHVAL,
        hash,
        &hashLen,
        0
    );

    for(int i = 0; i < 16; i++)
    {
        sprintf(&output[i * 2], "%02x", hash[i]);
    }

    output[32] = '\0';

    CryptDestroyHash(hHash);
    CryptReleaseContext(hProv, 0);
}

void studentRegistration()
{
    struct Student s;
    FILE *fp;
    char password[20];
    char hashedPassword[33];

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
    scanf("%19s", password);

    md5Hash(password, hashedPassword);

    printf("\nMD5 Hash : %s", hashedPassword);

    fp = fopen("student.txt", "a");

    if(fp == NULL)
    {
        printf("\nFile Cannot Open!");
        return;
    }

    fprintf(fp, "%s|%s|%s|%s|%s\n",
            s.studentId, s.name, s.department, s.phone, hashedPassword);

    fclose(fp);

    printf("\n\n====================================");
    printf("\nRegistration Successful!");
    printf("\n====================================");
}

void studentLogin()
{
    FILE *fp;
    struct Student s;
    char id[20];
    char password[20];
    char hashedPassword[33];
    int found = 0;

    printf("\n====================================");
    printf("\n         STUDENT LOGIN");
    printf("\n====================================");

    printf("\nEnter Student ID : ");
    scanf("%19s", id);

    printf("\nEnter Password : ");
    scanf("%19s", password);

    md5Hash(password, hashedPassword);

    printf("\nMD5 Hash : %s", hashedPassword);

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo Registered Student Found!");
        return;
    }

    while(fscanf(fp,
        "%19[^|]|%49[^|]|%49[^|]|%19[^|]|%32[^\n]\n",
        s.studentId, s.name, s.department, s.phone, s.password) == 5)
    {
        if(strcmp(id, s.studentId) == 0 &&
           strcmp(hashedPassword, s.password) == 0)
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
        printf("\nWelcome %s", s.name);
        printf("\nDepartment : %s", s.department);
        printf("\n====================================");
    }
    else
    {
        printf("\nInvalid Student ID Or Password!");
    }
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
    s.studentId, s.name, s.department, s.phone, s.password) == 5)
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
    char newPassword[20];
    char hashedPassword[33];
    int found = 0;

    printf("\n====================================");
    printf("\n       UPDATE STUDENT");
    printf("\n====================================");

    printf("\nEnter Student ID : ");
    scanf("%19s", id);

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("\nStudent File Not Found!");
        return;
    }

    temp = fopen("temp.txt", "w");

    while(fscanf(fp,
          "%19[^|]|%49[^|]|%49[^|]|%19[^|]|%32[^\n]\n",
          s.studentId, s.name, s.department, s.phone, s.password) == 5)
    {
        if(strcmp(id, s.studentId) == 0)
        {
            found = 1;

            printf("\nNew Name : ");
            scanf(" %49[^\n]", s.name);

            printf("New Department : ");
            scanf(" %49[^\n]", s.department);

            printf("New Phone : ");
            scanf("%19s", s.phone);

            printf("New Password : ");
            scanf("%19s", newPassword);

            md5Hash(newPassword, hashedPassword);
            strcpy(s.password, hashedPassword);
        }

        fprintf(temp, "%s|%s|%s|%s|%s\n",
                s.studentId, s.name, s.department, s.phone, s.password);
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

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
        s.studentId, s.name, s.department, s.phone, s.password) == 5)
    {
        if(strcmp(id, s.studentId) == 0)
        {
            found = 1;
        }
        else
        {
            fprintf(temp,"%s|%s|%s|%s|%s\n",
                    s.studentId, s.name, s.department, s.phone, s.password);
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