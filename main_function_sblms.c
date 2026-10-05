#include <stdio.h>

int main()
{
    int choice;

    do
    {
        printf("\n=========================================\n");
        printf(" SMART BLOODLINK MANAGEMENT SYSTEM (SBMS)\n");
        printf("=========================================\n");

        printf("1. Admin Login\n");
        printf("2. Donor Registration\n");
        printf("3. Donor Login\n");
        printf("4. Patient Registration\n");
        printf("5. Patient Login\n");
        printf("6. Search Blood Donor\n");
        printf("7. Blood Request\n");
        printf("8. Reports\n");
        printf("9. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\nAdmin Login module coming soon...\n");
            break;

        case 2:
            printf("\nDonor Registration module coming soon...\n");
            break;

        case 3:
            printf("\nDonor Login module coming soon...\n");
            break;

        case 4:
            printf("\nPatient Registration module coming soon...\n");
            break;

        case 5:
            printf("\nPatient Login module coming soon...\n");
            break;

        case 6:
            printf("\nSearch Blood Donor module coming soon...\n");
            break;

        case 7:
            printf("\nBlood Request module coming soon...\n");
            break;

        case 8:
            printf("\nReports module coming soon...\n");
            break;

        case 9:
            printf("\nThank You For Using SBMS.\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    }
    while(choice!=9);

    return 0;
}
