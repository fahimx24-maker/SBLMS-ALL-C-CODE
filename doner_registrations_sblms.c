#include <stdio.h>
#include <string.h>

// Function Prototype
void adminLogin();
void adminDashboard();
void donorRegistration();

// Structure
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

// Global Variable
struct Donor donor;

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

        printf("\nEnter Your Choice : ");
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

    }while(choice!=2);

    return 0;
}

//================ ADMIN LOGIN ==================

void adminLogin()
{
    char username[20];
    char password[20];

    printf("\n========== ADMIN LOGIN ==========\n");

    printf("Username : ");
    scanf("%s",username);

    printf("Password : ");
    scanf("%s",password);

    if(strcmp(username,"admin")==0 && strcmp(password,"1234")==0)
    {
        printf("\nLogin Successful!\n");

        adminDashboard();
    }
    else
    {
        printf("\nInvalid Username or Password!\n");
    }
}

//================ ADMIN DASHBOARD ==================

void adminDashboard()
{
    int choice;

    do
    {
        printf("\n========== ADMIN DASHBOARD ==========\n");

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
            donorRegistration();
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

//================ DONOR REGISTRATION ==================

void donorRegistration()
{
    printf("\n========== DONOR REGISTRATION ==========\n");

    printf("Enter Donor ID : ");
    scanf("%d",&donor.id);

    printf("Enter Donor Name : ");
    scanf(" %[^\n]", donor.name);

    printf("Enter Age : ");
    scanf("%d",&donor.age);

    printf("Enter Gender : ");
    scanf("%s", donor.gender);

    printf("Enter Blood Group : ");
    scanf("%s", donor.bloodGroup);

    printf("Enter Phone Number : ");
    scanf("%s", donor.phone);

    printf("Enter District : ");
    scanf("%s", donor.district);

    printf("\n=====================================\n");
    printf(" Registration Successful!\n");
    printf("=====================================\n");

    printf("\n===== DONOR INFORMATION =====\n");

    printf("ID          : %d\n", donor.id);
    printf("Name        : %s\n", donor.name);
    printf("Age         : %d\n", donor.age);
    printf("Gender      : %s\n", donor.gender);
    printf("Blood Group : %s\n", donor.bloodGroup);
    printf("Phone       : %s\n", donor.phone);
    printf("District    : %s\n", donor.district);
}
