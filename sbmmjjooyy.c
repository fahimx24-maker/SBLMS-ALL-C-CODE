#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ================= STRUCTURES ================= */

struct Donor
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char bloodGroup[5];
    char phone[15];
    char district[30];
    char password[20];
};

struct Patient
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char bloodGroup[5];
    char phone[15];
    char district[30];
    char password[20];
};

struct BloodRequest
{
    int requestId;
    char patientName[50];
    char bloodGroup[5];
    int unitsNeeded;
    char hospital[50];
    char phone[15];
    char status[15];   /* Pending / Fulfilled */
};

#define DONOR_FILE   "donors.dat"
#define PATIENT_FILE "patients.dat"
#define REQUEST_FILE "requests.dat"

/* ================= PROTOTYPES ================= */

void adminLogin();
void adminDashboard();

void donorRegistration();
void donorLogin();
void donorDashboard(struct Donor d);

void patientRegistration();
void patientLogin();
void patientDashboard(struct Patient p);

void searchBloodDonor();
void bloodRequest();
void reports();

/* admin helpers */
void viewAllDonors();
void searchDonorAdmin();
void updateDonorAdmin();
void deleteDonorAdmin();
void adminReports();

/* utility */
int nextDonorId();
int nextPatientId();
int nextRequestId();
void clearInputBuffer();

/* ================= MAIN ================= */

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
        if(scanf("%d", &choice) != 1)
        {
            clearInputBuffer();
            choice = -1;
            printf("\n  Invalid input!\n");
            continue;
        }

        switch(choice)
        {
            case 1: adminLogin();        break;
            case 2: donorRegistration();  break;
            case 3: donorLogin();         break;
            case 4: patientRegistration();break;
            case 5: patientLogin();       break;
            case 6: searchBloodDonor();   break;
            case 7: bloodRequest();       break;
            case 8: reports();            break;
            case 9: printf("\n  Thank you for using Smart BloodLink.\n"); break;
            default: printf("\n  Invalid Choice!\n");
        }

    } while(choice != 9);

    return 0;
}

/* ================= UTILITY ================= */

void clearInputBuffer()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int nextDonorId()
{
    FILE *fp = fopen(DONOR_FILE, "rb");
    int count = 0;
    struct Donor d;
    if(fp != NULL)
    {
        while(fread(&d, sizeof(struct Donor), 1, fp) == 1)
            count++;
        fclose(fp);
    }
    return count + 1;
}

int nextPatientId()
{
    FILE *fp = fopen(PATIENT_FILE, "rb");
    int count = 0;
    struct Patient p;
    if(fp != NULL)
    {
        while(fread(&p, sizeof(struct Patient), 1, fp) == 1)
            count++;
        fclose(fp);
    }
    return count + 1;
}

int nextRequestId()
{
    FILE *fp = fopen(REQUEST_FILE, "rb");
    int count = 0;
    struct BloodRequest r;
    if(fp != NULL)
    {
        while(fread(&r, sizeof(struct BloodRequest), 1, fp) == 1)
            count++;
        fclose(fp);
    }
    return count + 1;
}

/* ================= ADMIN ================= */

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
        if(scanf("%d", &choice) != 1)
        {
            clearInputBuffer();
            choice = -1;
            printf("\n  Invalid input!\n");
            continue;
        }

        switch(choice)
        {
            case 1: donorRegistration();  break;
            case 2: viewAllDonors();      break;
            case 3: searchDonorAdmin();   break;
            case 4: updateDonorAdmin();   break;
            case 5: deleteDonorAdmin();   break;
            case 6: adminReports();       break;
            case 7: printf("\n  Logout Successful.\n"); break;
            default: printf("\n  Invalid Choice!\n");
        }

    } while(choice != 7);
}

void viewAllDonors()
{
    FILE *fp = fopen(DONOR_FILE, "rb");
    struct Donor d;
    int found = 0;

    printf("\n========== ALL REGISTERED DONORS ==========\n");

    if(fp == NULL)
    {
        printf("  No donor records found.\n");
        return;
    }

    printf("  %-4s %-20s %-5s %-8s %-5s %-14s %-15s\n",
           "ID", "Name", "Age", "Gender", "Grp", "Phone", "District");
    printf("  --------------------------------------------------------------------\n");

    while(fread(&d, sizeof(struct Donor), 1, fp) == 1)
    {
        printf("  %-4d %-20s %-5d %-8s %-5s %-14s %-15s\n",
               d.id, d.name, d.age, d.gender, d.bloodGroup, d.phone, d.district);
        found = 1;
    }

    if(!found)
        printf("  No donor records found.\n");

    fclose(fp);
}

void searchDonorAdmin()
{
    FILE *fp = fopen(DONOR_FILE, "rb");
    struct Donor d;
    int id, found = 0;

    if(fp == NULL)
    {
        printf("\n  No donor records found.\n");
        return;
    }

    printf("\n  Enter Donor ID to search: ");
    scanf("%d", &id);

    while(fread(&d, sizeof(struct Donor), 1, fp) == 1)
    {
        if(d.id == id)
        {
            printf("\n  ID       : %d\n", d.id);
            printf("  Name     : %s\n", d.name);
            printf("  Age      : %d\n", d.age);
            printf("  Gender   : %s\n", d.gender);
            printf("  Group    : %s\n", d.bloodGroup);
            printf("  Phone    : %s\n", d.phone);
            printf("  District : %s\n", d.district);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("\n  Donor with ID %d not found.\n", id);

    fclose(fp);
}

void updateDonorAdmin()
{
    FILE *fp = fopen(DONOR_FILE, "rb+");
    struct Donor d;
    int id, found = 0;

    if(fp == NULL)
    {
        printf("\n  No donor records found.\n");
        return;
    }

    printf("\n  Enter Donor ID to update: ");
    scanf("%d", &id);

    while(fread(&d, sizeof(struct Donor), 1, fp) == 1)
    {
        if(d.id == id)
        {
            found = 1;

            printf("  Enter New Phone Number: ");
            scanf("%s", d.phone);

            printf("  Enter New District: ");
            scanf(" %[^\n]", d.district);

            printf("  Enter New Blood Group: ");
            scanf("%s", d.bloodGroup);

            fseek(fp, -(long)sizeof(struct Donor), SEEK_CUR);
            fwrite(&d, sizeof(struct Donor), 1, fp);

            printf("\n  Donor record updated successfully!\n");
            break;
        }
    }

    if(!found)
        printf("\n  Donor with ID %d not found.\n", id);

    fclose(fp);
}

void deleteDonorAdmin()
{
    FILE *fp = fopen(DONOR_FILE, "rb");
    FILE *temp = fopen("temp_donors.dat", "wb");
    struct Donor d;
    int id, found = 0;

    if(fp == NULL)
    {
        printf("\n  No donor records found.\n");
        if(temp) fclose(temp);
        return;
    }

    printf("\n  Enter Donor ID to delete: ");
    scanf("%d", &id);

    while(fread(&d, sizeof(struct Donor), 1, fp) == 1)
    {
        if(d.id == id)
        {
            found = 1;
            continue;
        }
        fwrite(&d, sizeof(struct Donor), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(DONOR_FILE);
    rename("temp_donors.dat", DONOR_FILE);

    if(found)
        printf("\n  Donor with ID %d deleted successfully!\n", id);
    else
        printf("\n  Donor with ID %d not found.\n", id);
}

void adminReports()
{
    FILE *fp;
    struct Donor d;
    struct Patient p;
    struct BloodRequest r;

    int totalDonors = 0, totalPatients = 0, totalRequests = 0, pending = 0, fulfilled = 0;
    int aPos=0,aNeg=0,bPos=0,bNeg=0,abPos=0,abNeg=0,oPos=0,oNeg=0;

    printf("\n========== ADMIN REPORTS ==========\n");

    fp = fopen(DONOR_FILE, "rb");
    if(fp != NULL)
    {
        while(fread(&d, sizeof(struct Donor), 1, fp) == 1)
        {
            totalDonors++;
            if(strcmp(d.bloodGroup,"A+")==0) aPos++;
            else if(strcmp(d.bloodGroup,"A-")==0) aNeg++;
            else if(strcmp(d.bloodGroup,"B+")==0) bPos++;
            else if(strcmp(d.bloodGroup,"B-")==0) bNeg++;
            else if(strcmp(d.bloodGroup,"AB+")==0) abPos++;
            else if(strcmp(d.bloodGroup,"AB-")==0) abNeg++;
            else if(strcmp(d.bloodGroup,"O+")==0) oPos++;
            else if(strcmp(d.bloodGroup,"O-")==0) oNeg++;
        }
        fclose(fp);
    }

    fp = fopen(PATIENT_FILE, "rb");
    if(fp != NULL)
    {
        while(fread(&p, sizeof(struct Patient), 1, fp) == 1)
            totalPatients++;
        fclose(fp);
    }

    fp = fopen(REQUEST_FILE, "rb");
    if(fp != NULL)
    {
        while(fread(&r, sizeof(struct BloodRequest), 1, fp) == 1)
        {
            totalRequests++;
            if(strcmp(r.status,"Fulfilled")==0) fulfilled++;
            else pending++;
        }
        fclose(fp);
    }

    printf("  Total Registered Donors   : %d\n", totalDonors);
    printf("  Total Registered Patients : %d\n", totalPatients);
    printf("  Total Blood Requests      : %d\n", totalRequests);
    printf("      Pending               : %d\n", pending);
    printf("      Fulfilled             : %d\n", fulfilled);

    printf("\n  Donor Count by Blood Group:\n");
    printf("      A+  : %d\n", aPos);
    printf("      A-  : %d\n", aNeg);
    printf("      B+  : %d\n", bPos);
    printf("      B-  : %d\n", bNeg);
    printf("      AB+ : %d\n", abPos);
    printf("      AB- : %d\n", abNeg);
    printf("      O+  : %d\n", oPos);
    printf("      O-  : %d\n", oNeg);
}

/* ================= DONOR ================= */

void donorRegistration()
{
    struct Donor d;
    FILE *fp;

    printf("\n========== DONOR REGISTRATION ==========\n");

    fp = fopen(DONOR_FILE, "ab");
    if(fp == NULL)
    {
        printf("  Error opening donor file!\n");
        return;
    }

    d.id = nextDonorId();
    printf("  Your Donor ID is: %d\n", d.id);

    printf("  Enter Name: ");
    scanf(" %[^\n]", d.name);

    printf("  Enter Age: ");
    scanf("%d", &d.age);

    printf("  Enter Gender (Male/Female/Other): ");
    scanf("%s", d.gender);

    printf("  Enter Blood Group (e.g. A+, O-): ");
    scanf("%s", d.bloodGroup);

    printf("  Enter Phone Number: ");
    scanf("%s", d.phone);

    printf("  Enter District: ");
    scanf(" %[^\n]", d.district);

    printf("  Set a Password (for Donor Login): ");
    scanf("%s", d.password);

    fwrite(&d, sizeof(struct Donor), 1, fp);
    fclose(fp);

    printf("\n  Donor Registered Successfully! Please remember your Donor ID: %d\n", d.id);
}

void donorLogin()
{
    FILE *fp = fopen(DONOR_FILE, "rb");
    struct Donor d;
    char phone[15], password[20];
    int found = 0;

    printf("\n========== DONOR LOGIN ==========\n");

    if(fp == NULL)
    {
        printf("  No donor records found. Please register first.\n");
        return;
    }

    printf("  Enter Phone Number: ");
    scanf("%s", phone);

    printf("  Enter Password: ");
    scanf("%s", password);

    while(fread(&d, sizeof(struct Donor), 1, fp) == 1)
    {
        if(strcmp(d.phone, phone) == 0 && strcmp(d.password, password) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if(found)
    {
        printf("\n  Login Successful! Welcome, %s.\n", d.name);
        donorDashboard(d);
    }
    else
    {
        printf("\n  Invalid Phone Number or Password!\n");
    }
}

void donorDashboard(struct Donor d)
{
    int choice;

    do
    {
        printf("\n========== DONOR DASHBOARD ==========\n");
        printf("  1. View My Profile\n");
        printf("  2. Logout\n");
        printf("\n  Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n  ID       : %d\n", d.id);
                printf("  Name     : %s\n", d.name);
                printf("  Age      : %d\n", d.age);
                printf("  Gender   : %s\n", d.gender);
                printf("  Group    : %s\n", d.bloodGroup);
                printf("  Phone    : %s\n", d.phone);
                printf("  District : %s\n", d.district);
                break;
            case 2:
                printf("\n  Logout Successful.\n");
                break;
            default:
                printf("\n  Invalid Choice!\n");
        }
    } while(choice != 2);
}

/* ================= PATIENT ================= */

void patientRegistration()
{
    struct Patient p;
    FILE *fp;

    printf("\n========== PATIENT REGISTRATION ==========\n");

    fp = fopen(PATIENT_FILE, "ab");
    if(fp == NULL)
    {
        printf("  Error opening patient file!\n");
        return;
    }

    p.id = nextPatientId();
    printf("  Your Patient ID is: %d\n", p.id);

    printf("  Enter Name: ");
    scanf(" %[^\n]", p.name);

    printf("  Enter Age: ");
    scanf("%d", &p.age);

    printf("  Enter Gender (Male/Female/Other): ");
    scanf("%s", p.gender);

    printf("  Enter Required Blood Group (e.g. A+, O-): ");
    scanf("%s", p.bloodGroup);

    printf("  Enter Phone Number: ");
    scanf("%s", p.phone);

    printf("  Enter District: ");
    scanf(" %[^\n]", p.district);

    printf("  Set a Password (for Patient Login): ");
    scanf("%s", p.password);

    fwrite(&p, sizeof(struct Patient), 1, fp);
    fclose(fp);

    printf("\n  Patient Registered Successfully! Please remember your Patient ID: %d\n", p.id);
}

void patientLogin()
{
    FILE *fp = fopen(PATIENT_FILE, "rb");
    struct Patient p;
    char phone[15], password[20];
    int found = 0;

    printf("\n========== PATIENT LOGIN ==========\n");

    if(fp == NULL)
    {
        printf("  No patient records found. Please register first.\n");
        return;
    }

    printf("  Enter Phone Number: ");
    scanf("%s", phone);

    printf("  Enter Password: ");
    scanf("%s", password);

    while(fread(&p, sizeof(struct Patient), 1, fp) == 1)
    {
        if(strcmp(p.phone, phone) == 0 && strcmp(p.password, password) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if(found)
    {
        printf("\n  Login Successful! Welcome, %s.\n", p.name);
        patientDashboard(p);
    }
    else
    {
        printf("\n  Invalid Phone Number or Password!\n");
    }
}

void patientDashboard(struct Patient p)
{
    int choice;

    do
    {
        printf("\n========== PATIENT DASHBOARD ==========\n");
        printf("  1. View My Profile\n");
        printf("  2. Search Blood Donor\n");
        printf("  3. Make Blood Request\n");
        printf("  4. Logout\n");
        printf("\n  Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n  ID       : %d\n", p.id);
                printf("  Name     : %s\n", p.name);
                printf("  Age      : %d\n", p.age);
                printf("  Gender   : %s\n", p.gender);
                printf("  Group    : %s\n", p.bloodGroup);
                printf("  Phone    : %s\n", p.phone);
                printf("  District : %s\n", p.district);
                break;
            case 2:
                searchBloodDonor();
                break;
            case 3:
                bloodRequest();
                break;
            case 4:
                printf("\n  Logout Successful.\n");
                break;
            default:
                printf("\n  Invalid Choice!\n");
        }
    } while(choice != 4);
}

/* ================= SEARCH / REQUEST / REPORTS ================= */

void searchBloodDonor()
{
    FILE *fp = fopen(DONOR_FILE, "rb");
    struct Donor d;
    char group[5];
    int found = 0;

    printf("\n========== SEARCH BLOOD DONOR ==========\n");

    if(fp == NULL)
    {
        printf("  No donor records found.\n");
        return;
    }

    printf("  Enter Blood Group to search (e.g. A+, O-): ");
    scanf("%s", group);

    printf("\n  %-4s %-20s %-5s %-14s %-15s\n", "ID", "Name", "Grp", "Phone", "District");
    printf("  ---------------------------------------------------------\n");

    while(fread(&d, sizeof(struct Donor), 1, fp) == 1)
    {
        if(strcmp(d.bloodGroup, group) == 0)
        {
            printf("  %-4d %-20s %-5s %-14s %-15s\n",
                   d.id, d.name, d.bloodGroup, d.phone, d.district);
            found = 1;
        }
    }

    if(!found)
        printf("  No donors found for blood group %s.\n", group);

    fclose(fp);
}

void bloodRequest()
{
    struct BloodRequest r;
    FILE *fp = fopen(REQUEST_FILE, "ab");

    printf("\n========== BLOOD REQUEST ==========\n");

    if(fp == NULL)
    {
        printf("  Error opening request file!\n");
        return;
    }

    r.requestId = nextRequestId();

    printf("  Enter Patient Name: ");
    scanf(" %[^\n]", r.patientName);

    printf("  Enter Required Blood Group (e.g. A+, O-): ");
    scanf("%s", r.bloodGroup);

    printf("  Enter Units Needed: ");
    scanf("%d", &r.unitsNeeded);

    printf("  Enter Hospital Name: ");
    scanf(" %[^\n]", r.hospital);

    printf("  Enter Contact Phone: ");
    scanf("%s", r.phone);

    strcpy(r.status, "Pending");

    fwrite(&r, sizeof(struct BloodRequest), 1, fp);
    fclose(fp);

    printf("\n  Blood Request Submitted Successfully!\n");
    printf("  Your Request ID is: %d (Status: Pending)\n", r.requestId);
}

void reports()
{
    FILE *fp;
    struct Donor d;
    struct BloodRequest r;
    int totalDonors = 0, totalRequests = 0, pending = 0, fulfilled = 0;

    printf("\n========== PUBLIC REPORTS ==========\n");

    fp = fopen(DONOR_FILE, "rb");
    if(fp != NULL)
    {
        while(fread(&d, sizeof(struct Donor), 1, fp) == 1)
            totalDonors++;
        fclose(fp);
    }

    fp = fopen(REQUEST_FILE, "rb");
    if(fp != NULL)
    {
        while(fread(&r, sizeof(struct BloodRequest), 1, fp) == 1)
        {
            totalRequests++;
            if(strcmp(r.status,"Fulfilled")==0) fulfilled++;
            else pending++;
        }
        fclose(fp);
    }

    printf("  Total Registered Donors : %d\n", totalDonors);
    printf("  Total Blood Requests    : %d\n", totalRequests);
    printf("      Pending             : %d\n", pending);
    printf("      Fulfilled           : %d\n", fulfilled);
}
