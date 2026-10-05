#include <stdio.h>
#include<string.h>
struct Donor
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char bloodGroup[5];
    char phone[15];
    char district[30];
};
void adminLogin();
void adminDashboard();
void donorRegistration();
struct Donor donor;
int main()
{
    int choice;

    do
    {
        printf("\n=============================================\n");
        printf("   SMART BLOODLINK MANAGEMENT SYSTEM (SBMS)\n");
        printf("=============================================\n");

        printf("  1. Admin Login\n");
        printf("  2. Donor Registration\n");
        printf("  3. Donor Login\n");
        printf("  4. Patient Registration\n");
        printf("  5. Patient Login\n");
        printf("  6. Search Blood Donor\n");
        printf("  7. Blood Request\n");
        printf("  8. Reports\n");
        printf("  9. Exit\n");

        printf("\n  Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                adminLogin();
                break;

            case 2:
                donorRegistration();
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
                printf("\n  Thank you for using Smart BloodLink.\n");
                break;

            default:
                printf("\n  Invalid Choice!\n");
        }

    } while(choice != 9);

    return 0;
}


void adminLogin()
{
    char username[20];
    char password[20];

    printf("\n========== ADMIN LOGIN ==========\n");

    printf("  Enter Username: ");
    scanf("%s", username);

    printf("  Enter Password: ");
    scanf("%s", password);

    if(strcmp(username, "fahim") == 0 && strcmp(password, "1122") == 0)
    {
        printf("\n  Login Successful!\n");

    adminDashboard();
}
    else
    {
        printf("\n  Invalid Username or Password!\n");
    }

}

void adminDashboard()
{
    int choice;

    do
    {
        printf("\n========== ADMIN DASHBOARD ==========\n");
        printf("  1. Add Donor\n");
        printf("  2. View Donors\n");
        printf("  3. Search Donor\n");
        printf("  4. Update Donor\n");
        printf("  5. Delete Donor\n");
        printf("  6. Reports\n");
        printf("  7. Logout\n");

        printf("\n  Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\n  Add Donor Module Coming Soon...\n");
                break;

            case 2:
                printf("\n  View Donors Module Coming Soon...\n");
                break;

            case 3:
                printf("\n  Search Module Coming Soon...\n");
                break;

            case 4:
                printf("\n  Update Module Coming Soon...\n");
                break;

            case 5:
                printf("\n  Delete Module Coming Soon...\n");
                break;

            case 6:
                printf("\n  Reports Module Coming Soon...\n");
                break;

            case 7:
                printf("\n  Logout Successful.\n");
                break;

            default:
                printf("\n  Invalid Choice!\n");
        }

    }while(choice!=7);
}
void donorRegistration()
{
    printf("\n========== DONOR REGISTRATION ==========\n");

    printf("Enter Donor ID: ");
    scanf("%d",&donor.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", donor.name);

    printf("Enter Age: ");
    scanf("%d",&donor.age);

    printf("Enter Gender: ");
    scanf("%s", donor.gender);

    printf("Enter Blood Group: ");
    scanf("%s", donor.bloodGroup);

    printf("Enter Phone Number: ");
    scanf("%s", donor.phone);

    printf("Enter District: ");
    scanf("%s", donor.district);

    printf("\n==================================\n");
    printf("Donor Registration Successful!\n");
    printf("==================================\n");

    printf("\nDonor Information:\n");

    printf("ID          : %d\n", donor.id);
    printf("Name        : %s\n", donor.name);
    printf("Age         : %d\n", donor.age);
    printf("Gender      : %s\n", donor.gender);
    printf("Blood Group : %s\n", donor.bloodGroup);
    printf("Phone       : %s\n", donor.phone);
    printf("District    : %s\n", donor.district);
}
