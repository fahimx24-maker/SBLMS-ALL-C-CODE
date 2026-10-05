#include <stdio.h>
#include <string.h>
struct Donor donor;
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
