#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room
{
    int roomnumber;
    char username[20];
    char password[20];
    int roomprice;
    int watercost;
    int eleccost;
    int pay;
};
struct room Room[5];

// Function //
void dataroom();//อ่านข้อมูลจากไฟล์//
void savedataroom();//บันทึกข้อมูลลงไฟล์//
void mainmenu();

void employeelogin();
void employeemenu();
void showallroom();

void customerlogin();
void customerroom(char *username);

void payment(struct room *room);//ชำระเงิน//

// Main //
int main()
{
    dataroom();
    mainmenu();
    return 0;
}

// Data //
void dataroom()
{
    FILE *fp;
    fp = fopen("roomdata.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("roomdata.txt", "w");
        fprintf(fp,"101 take 1658 3800 2 124 0\n");
        fprintf(fp,"102 ray 7326 3800 2 76 0\n");
        fprintf(fp,"103 mark 1550 3800 4 44 0\n");
        fprintf(fp,"104 patty 8186 3800 2 69 1\n");
        fprintf(fp,"105 khun 4165 3800 1 35 0\n");

        fclose(fp);
        fp = fopen("roomdata.txt", "r");
    }
    for(int i=0;i<5;i++)//อ่านข้อมูลจากไฟล์//
    {
        fscanf(fp,"%d %s %s %d %d %d %d",&Room[i].roomnumber,Room[i].username,Room[i].password,&Room[i].roomprice,&Room[i].watercost,&Room[i].eleccost,&Room[i].pay);
    }
    fclose(fp);
}

// Save data //
void savedataroom()
{
    FILE *fp;
    fp = fopen("roomdata.txt", "w");
    if(fp == NULL)
    {
        printf("Cannot open file\n");
        return;
    }
    for(int i=0;i<5;i++)
    {
        fprintf(fp,"%d %s %s %d %d %d %d\n",Room[i].roomnumber,Room[i].username,Room[i].password,Room[i].roomprice,Room[i].watercost,Room[i].eleccost,Room[i].pay);
    }
    fclose(fp);
}

// Main menu //
void mainmenu()
{
    int choice;
    do
    {
        printf("\n============================================\n");
        printf("            APARTMENT BILL SYSTEM");
        printf("\n============================================\n");

        printf("1) Employee\n");
        printf("2) Customer\n");
        printf("3) Exit\n");
        printf("Enter your select: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1: employeelogin();
            break;
            case 2: customerlogin();
            break;
            case 3: printf("\nThank you for using the system. Goodbye!\n");
            exit(0);//ออกจากโปรแกรม// //return จะออกแค่ ฟังก์ชันปัจจุบันเท่านั้น ไม่ได้ปิดโปรแกรมทั้งหมด//
            default: printf("\nIncorrect select. Please try again.\n");
        }
    } while (choice != 3);//ออกจากโปรแกรม//
}

// Employee login //
void employeelogin()
{
    char username[20];
    char password[20];
    int wrong = 0;

    while (wrong < 3)
    {
        printf("\n============ EMPLOYEE LOGIN ============\n");
        printf("Enter 3 to go back main menu.\n");
        printf("Username: ");
        scanf("%19s",username);
        strlwr(username);//เปลี่ยนตัวอักษรเป็นตัวเล็ก//
        if (strcmp(username, "3") == 0)
            return; // Return to main menu

        printf("Password: ");
        scanf("%19s",password);
        if (strcmp(password, "3") == 0)
            return; // Return to main menu
    
        if ((strcmp(username,"cream") == 0 && strcmp(password,"2709") == 0) || (strcmp(username,"nam") == 0 && strcmp(password,"1012") == 0))
        {
            printf("\nLogin successful. Welcome, %s!\n",username);
            employeemenu();
            return;
        }
        else
        {
            wrong++;
            printf("\nIncorrect username or password (%d/3). Please try again.\n", wrong);
        }
    }
}
  
// Employee menu //
void employeemenu()
{
    int choice;
    do
    {
        printf("\n============================================\n");
        printf("                EMPLOYEE MENU");
        printf("\n============================================\n");

        printf("1) Show All Rooms\n");
        printf("2) Exit\n");
        printf("Enter your select: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: showallroom();
        break;
        case 2: printf("\nReturn to main menu...\n");
        return;
        default: printf("\nIncorrect select. Please try again.\n");
        break;
        }

    } while (1);//ออกจากเมนูพนักงาน//
}

// Show all rooms //
void showallroom()
{
    int waterunit = 34;
    int elecunit = 7;

    while(getchar() != '\n');//เคลียร์บัฟเฟอร์ก่อนรับค่า Enter//

    printf("\n============================================\n");
    printf("                 ALL ROOMS");
    printf("\n============================================\n");

    for(int i=0;i<5;i++)
    {
        int water = Room[i].watercost * waterunit;
        int elec = Room[i].eleccost * elecunit;
        int total = Room[i].roomprice + water + elec;

        printf("Room Number: %d\n", Room[i].roomnumber);
        printf("Username: %s\n", Room[i].username);
        printf("Room Price: %d\n", Room[i].roomprice);
        printf("Water Cost ( Unit: 1/%d ): %d \n", waterunit, water);
        printf("Electricity Cost ( Unit: 1/%d ): %d \n", elecunit, elec);
        printf("Total: %d\n", total);
        printf("Payment: %s\n", Room[i].pay == 1 ? "Paid" : "Unpaid");
        printf("==============================================\n");

        if(i < 4)
        {
            printf("Please pass enter to see next room...");
            getchar();//หยุดรอรับค่า Enter เพื่อแสดงห้องถัดไป//
        }
    }
        int choice;
        printf("Press 3 to go back to main menu: ");
        scanf("%d", &choice);
        
        if (choice == 3)
        mainmenu(); //main menu
}

// Customer login //
void customerlogin()
{
    char username[20];
    char password[20];
    int wrong = 0;

    while (wrong < 3)
    {
        int found = 0;

        printf("\n============ CUSTOMER LOGIN ============\n");
        printf("Enter 3 to go back main menu.\n");
        printf("Username: ");
        scanf("%19s",username);
        strlwr(username);//เปลี่ยนตัวอักษรเป็นตัวเล็ก//

        if (strcmp(username, "3") == 0)
            mainmenu(); // Return to main menu

        printf("Password: ");
        scanf("%19s",password);
        if (strcmp(password, "3") == 0)
            mainmenu(); // Return to main menu
        
        for (int i=0;i<5;i++)
        {
            if (strcmp(username,Room[i].username) == 0 && strcmp(password,Room[i].password) == 0)
            {
            found = 1;
            printf("\nLogin successful. Welcome, %s!\n",username);
            customerroom(username);//ส่งชื่อผู้ใช้ไปยังฟังก์ชันห้องลูกค้า//
            return;
            }
        }
        
        if(found == 0)
        {
            wrong++;
            printf("\nIncorrect username or password (%d/3). Please try again.\n", wrong);
        }
    }
}

// Customer room //
void customerroom(char *username)
{
    int waterunit = 34;
    int elecunit = 7;
    int room;
    int wrong = 0;

    while (wrong < 3)
    {
        int found = 0;
        
        printf("\n============ CUSTOMER ROOM ============\n");
        printf("Enter your room number: ");
        scanf("%d", &room);

        for (int i=0;i<5;i++)
        {
            if (room == Room[i].roomnumber && strcmp(username,Room[i].username) == 0)
            {
                found = 1;

                int water = Room[i].watercost * waterunit;
                int elec = Room[i].eleccost * elecunit;
                int total = Room[i].roomprice + water + elec;

                printf("\n============================================\n");
                printf("                BILL DETAILS");
                printf("\n============================================\n");
                printf("Room Number: %d\n", Room[i].roomnumber);
                printf("Username: %s\n", Room[i].username);
                printf("Room Price: %d\n", Room[i].roomprice);
                printf("Water Cost ( Unit: 1/%d ): %d \n", waterunit, water);
                printf("Electricity Cost ( Unit: 1/%d ): %d \n", elecunit, elec);
                printf("----------------------------------------------\n");
                printf("Total: %d\n", total);
                printf("==============================================\n");

                if (Room[i].pay == 0)
                {
                    printf("Please pass enter to continue...");
                    while (getchar() != '\n');
                    getchar();

                    payment(&Room[i]);
                }
                else
                {
                    printf("You have already paid. Thank you!\n");
                    printf("Please pass enter to continue...");
                    while (getchar() != '\n');
                    getchar();
                    return;
                }  
            }
        }  
            if (found == 0)
            {
                wrong++;
                printf("Not found your room or username (%d/3). Please try again.\n", wrong);
            }
    } 

// Payment //
void payment(struct room *room)
{
    char choice;

    printf("\n============================================\n");
    printf("               PAYMENT SYSTEM");
    printf("\n============================================\n");
    printf("Confirm payment (Yes/No) : ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y')
    {
        room->pay = 1; // อัปเดตสถานะการชำระเงินเป็น "ชำระแล้ว" //
        savedataroom(); // บันทึกข้อมูลที่อัปเดตลงไฟล์//
        printf("Payment confirmed. Thank you!\n");
    }
    else if (choice == 'N' || choice == 'n')
    {
        printf("Payment cancelled.\n");
    }

    while (getchar() != '\n');
    getchar();
    customerlogin(); // กลับไปยังเมนูหลังจากการชำระเงิน//
} 