#include <stdio.h>
#include <string.h>

void adminLogin();

int main()
{
    int choice;

    do
    {
        printf("\n=========================================\n");
        printf(" SMART BLOODLINK MANAGEMENT SYSTEM (SBMS)\n");
        printf("=========================================\n");

        printf("1. Admin Login\n");
        printf("2. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            adminLogin();
            break;

        case 2:
            printf("\nThank You For Using SBMS.\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    }
    while(choice!=2);

    return 0;
}

void adminLogin()
{
    char username[20];
    char password[20];

    printf("\n========== ADMIN LOGIN ==========\n");

    printf("Enter Username : ");
    scanf("%s", username);

    printf("Enter Password : ");
    scanf("%s", password);

    if(strcmp(username,"fahim")==0 && strcmp(password,"1122")==0)
    {

        printf("      \n\nLOGIN SUCCESSFUL\n");

    }
    else
    {
        printf("\nInvalid Username or Password!\n");
    }
}
