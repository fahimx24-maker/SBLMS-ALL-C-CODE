
//admin dashboard after login

void adminDashboard()
{
    int choice;

    do
    {
        printf("\n=================================\n");
        printf("      ADMIN DASHBOARD\n");
        printf("=================================\n");

        printf("1. Add Donor\n");
        printf("2. View Donor\n");
        printf("3. Search Donor\n");
        printf("4. Update Donor\n");
        printf("5. Delete Donor\n");
        printf("6. Reports\n");
        printf("7. Logout\n");

        printf("\nEnter Your Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\nAdd Donor Module Coming Soon...\n");
            break;

        case 2:
            printf("\nView Donor Module Coming Soon...\n");
            break;

        case 3:
            printf("\nSearch Donor Module Coming Soon...\n");
            break;

        case 4:
            printf("\nUpdate Donor Module Coming Soon...\n");
            break;

        case 5:
            printf("\nDelete Donor Module Coming Soon...\n");
            break;

        case 6:
            printf("\nReports Module Coming Soon...\n");
            break;

        case 7:
            printf("\nLogout Successful.\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    }while(choice!=7);
}
