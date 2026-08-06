#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
struct room Room01[5];
struct room Room02[5];

// Function //
void dataroom01();//อ่านข้อมูลจากไฟล์//
void savedataroom01();//บันทึกข้อมูลลงไฟล์//
void dataroom02();//อ่านข้อมูลจากไฟล์สำหรับระบบประเภทที่ 2//
void savedataroom02();//บันทึกข้อมูลลงไฟล์สำหรับระบบประเภทที่ 2//
void mainmenu();

void employeelogin();
void employeemenu();
void allroom();
void month01();
void month02();

void customerlogin();
void customerroom(char *username);
void customerbill01(char *username);
void customerbill02(char *username);
void customermenu(char *username);

void payment(struct room *room);//ชำระเงิน//

void smallword(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i]= tolower (str[i]);
    }
}

// Main //
int main()
{
    dataroom01();
    dataroom02();
    mainmenu();
    return 0;
}

// Data 1 //
void dataroom01()
{
    FILE *fp;
    fp = fopen("roomdata1.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("roomdata1.txt", "w");
        fprintf(fp,"101 take 1658 3800 2 124 1\n");
        fprintf(fp,"102 ray 7326 3800 2 76 1\n");
        fprintf(fp,"103 mark 1550 3800 4 44 1\n");
        fprintf(fp,"104 patty 8186 3800 2 69 1\n");
        fprintf(fp,"105 khun 4165 3800 1 35 1\n");

        fclose(fp);
        fp = fopen("roomdata1.txt", "r");
    }
    for(int i=0;i<5;i++)//อ่านข้อมูลจากไฟล์//
    {
        fscanf(fp,"%d %s %s %d %d %d %d",&Room01[i].roomnumber,Room01[i].username,Room01[i].password,&Room01[i].roomprice,&Room01[i].watercost,&Room01[i].eleccost,&Room01[i].pay);
    }
    fclose(fp);
}

// Data 2 //
void dataroom02()
{
    FILE *fp;
    fp = fopen("roomdata2.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("roomdata2.txt", "w");
        fprintf(fp,"101 take 1658 3800 2 130 0\n");
        fprintf(fp,"102 ray 7326 3800 2 77 0\n");
        fprintf(fp,"103 mark 1550 3800 4 85 0\n");
        fprintf(fp,"104 patty 8186 3800 2 105 0\n");
        fprintf(fp,"105 khun 4165 3800 1 68 0\n");

        fclose(fp);
        fp = fopen("roomdata2.txt", "r");
    }
    for(int i=0;i<5;i++)//อ่านข้อมูลจากไฟล์//
    {
        fscanf(fp,"%d %s %s %d %d %d %d",&Room02[i].roomnumber,Room02[i].username,Room02[i].password,&Room02[i].roomprice,&Room02[i].watercost,&Room02[i].eleccost,&Room02[i].pay);
    }
    fclose(fp);
}

// Save data 1 //
void savedataroom01()
{
    FILE *fp;
    fp = fopen("roomdata1.txt", "w");
    if(fp == NULL)
    {
        printf("Cannot open file\n");
        return;
    }
    for(int i=0;i<5;i++)
    {
        fprintf(fp,"%d %s %s %d %d %d %d\n",Room01[i].roomnumber,Room01[i].username,Room01[i].password,Room01[i].roomprice,Room01[i].watercost,Room01[i].eleccost,Room01[i].pay);
    }
    fclose(fp);
}

// Save data 2 //
void savedataroom02()
{
    FILE *fp;
    fp = fopen("roomdata2.txt", "w");
    if(fp == NULL)
    {
        printf("Cannot open file\n");
        return;
    }
    for(int i=0;i<5;i++)
    {
        fprintf(fp,"%d %s %s %d %d %d %d\n",Room02[i].roomnumber,Room02[i].username,Room02[i].password,Room02[i].roomprice,Room02[i].watercost,Room02[i].eleccost,Room02[i].pay);
    }
    fclose(fp);
}

// Main menu //
void mainmenu()
{
    int choice;
    while (1)
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
    }
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
        smallword(username);//เปลี่ยนตัวอักษรเป็นตัวเล็ก//
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
    while (1)
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
        case 1: allroom();
        break;
        case 2: printf("\nReturn to main menu...\n");
        return;
        default: printf("\nIncorrect select. Please try again.\n");
        break;
        }
    }
}

// all rooms //
void allroom()
{
    int choice;

    printf("\n============================================\n");
    printf("                 ALL ROOMS");
    printf("\n============================================\n");

    printf("1) January bill\n");
    printf("2) February bill\n");
    printf("3) Exit\n");
    printf("Enter your select: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
        case 1: month01();
        break;
        case 2: month02();
        break;
        case 3: printf("\nReturn to main menu...\n");
        mainmenu();
        default: printf("\nIncorrect select. Please try again.\n");
        allroom();
    }
}

// Month 1 //
void month01()
{
    int waterunit = 34;
    int elecunit = 7;

    while(getchar() != '\n');//เคลียร์ก่อนรับค่า Enter//

        for (int i=0;i<5;i++)
        {
            int water = Room01[i].watercost * waterunit;
            int elec = Room01[i].eleccost * elecunit;
            int total = Room01[i].roomprice + water + elec;

            printf("\n============================================\n");
            printf("             JANUARY BILL DETAILS");
            printf("\n============================================\n");
            printf("Room Number: %d\n", Room01[i].roomnumber);
            printf("Username: %s\n", Room01[i].username);
            printf("Room Price: %d\n", Room01[i].roomprice);
            printf("Water Cost ( Unit: 1/%d ): %d \n", waterunit, water);
            printf("Electricity Cost ( Unit: 1/%d ): %d \n", elecunit, elec);
            printf("Total: %d\n", total);
            printf("----------------------------------------------\n");
            printf("Payment: %s\n", Room01[i].pay == 1 ? "Paid" : "Unpaid");
            printf("==============================================\n");

            if(i < 4)
            {
            printf("Please pass enter to see next room...");
            getchar();//หยุดรอรับค่า Enter เพื่อแสดงห้องถัดไป//
            }
        }
            int choice;
            printf("Press 3 to go back to all rooms: ");
            scanf("%d", &choice);
        
            if (choice == 3)
            allroom(); //all rooms
}

// Month 2 //
void month02()
{
    int waterunit = 34;
    int elecunit = 7;

    while(getchar() != '\n');//เคลียร์บัฟเฟอร์ก่อนรับค่า Enter//

        for (int i=0;i<5;i++)
        {
            int water = Room02[i].watercost * waterunit;
            int elec = Room02[i].eleccost * elecunit;
            int total = Room02[i].roomprice + water + elec;

            printf("\n============================================\n");
            printf("             FEBRUARY BILL DETAILS");
            printf("\n============================================\n");
            printf("Room Number: %d\n", Room02[i].roomnumber);
            printf("Username: %s\n", Room02[i].username);
            printf("Room Price: %d\n", Room02[i].roomprice);
            printf("Water Cost ( Unit: 1/%d ): %d \n", waterunit, water);
            printf("Electricity Cost ( Unit: 1/%d ): %d \n", elecunit, elec);
            printf("Total: %d\n", total);
            printf("----------------------------------------------\n");
            printf("Payment: %s\n", Room02[i].pay == 1 ? "Paid" : "Unpaid");
            printf("==============================================\n");

            if(i < 4)
            {
            printf("Please pass enter to see next room...");
            getchar();//หยุดรอรับค่า Enter เพื่อแสดงห้องถัดไป//
            }
        }   
            int choice;
            printf("Press 3 to go back to all rooms: ");
            scanf("%d", &choice);
        
            if (choice == 3)
            allroom(); //Show all rooms
}

// Customer login //
void customerlogin()
{
    char username[20];
    char password[20];
    int wrong = 0;

    while (wrong < 3)
    {
        printf("\n============ CUSTOMER LOGIN ============\n");
        printf("Enter 3 to go back main menu.\n");
        printf("Username: ");
        scanf("%19s",username);
        smallword(username);//เปลี่ยนตัวอักษรเป็นตัวเล็ก//

        if (strcmp(username, "3") == 0)
            mainmenu(); // Return to main menu

        printf("Password: ");
        scanf("%19s",password);
        if (strcmp(password, "3") == 0)
            mainmenu(); // Return to main menu
        
        for (int i=0;i<5;i++)
        {
            if (strcmp(username,Room01[i].username) == 0 && strcmp(password,Room01[i].password) == 0)
            {
            printf("\nLogin successful. Welcome, %s!\n",username);
            customerroom(username);//ส่งชื่อผู้ใช้ไปยังฟังก์ชันห้องลูกค้า//
            return;
            }

            if (strcmp(username,Room02[i].username) == 0 && strcmp(password,Room02[i].password) == 0)
            {
            printf("\nLogin successful. Welcome, %s!\n",username);
            customerroom(username);//ส่งชื่อผู้ใช้ไปยังฟังก์ชันห้องลูกค้า//
            return;
            }
        }
        
        wrong++;
        printf("\nIncorrect username or password (%d/3). Please try again.\n", wrong);
    }
}

// Customer room //
void customerroom(char *username)
{
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
            if (room == Room01[i].roomnumber && strcmp(username,Room01[i].username) == 0)
            {
            found = 1;
            customermenu(username);//ส่งชื่อผู้ใช้ไปยังฟังก์ชันบิลเดือนมกราคม//
            return;
            }  
        
            if (room == Room02[i].roomnumber && strcmp(username,Room02[i].username) == 0)
            {
            found = 1;
            customermenu(username);//ส่งชื่อผู้ใช้ไปยังฟังก์ชันบิลเดือนกุมภาพันธ์//
            return;
            } 
        }

        if (found == 0)
        {
            wrong++;
            printf("Not found your room or username (%d/3). Please try again.\n", wrong);
        }
    }
}

// Customer menu //
void customermenu(char *username)
{
    int choice;

    do
    {
        printf("\n============ CUSTOMER MENU ============\n");
        printf("1) January bill\n");
        printf("2) February bill\n");
        printf("3) Exit\n");
        printf("Enter your select: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: customerbill01(username);
        break;
        case 2: customerbill02(username);
        break;
        case 3: printf("\nReturn to main menu...\n");
        mainmenu(); //main menu
        default: printf("\nIncorrect select. Please try again.\n");
        break;
        }

    } while (choice != 3);
}

// Customer bill january //
void customerbill01(char *username)
{
    int waterunit = 34;
    int elecunit = 7;

    for (int i=0;i<5;i++)
    {
        if (strcmp(username,Room01[i].username) == 0)
        {
            int water = Room01[i].watercost * waterunit;
            int elec = Room01[i].eleccost * elecunit;
            int total = Room01[i].roomprice + water + elec;

            printf("\n============================================\n");
            printf("             JANUARY BILL DETAILS");
            printf("\n============================================\n");
            printf("Room Number: %d\n", Room01[i].roomnumber);
            printf("Username: %s\n", Room01[i].username);
            printf("Room Price: %d\n", Room01[i].roomprice);
            printf("Water Cost ( Unit: 1/%d ): %d \n", waterunit, water);
            printf("Electricity Cost ( Unit: 1/%d ): %d \n", elecunit, elec);
            printf("----------------------------------------------\n");
            printf("Total: %d\n", total);
            printf("==============================================\n");

            if (Room01[i].pay == 0)
            {
                printf("Please pass enter to continue...");
                while (getchar() != '\n');
                getchar();
                payment(&Room01[i]);
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
} 
   
// Customer bill february //
void customerbill02(char *username)
{
    int waterunit = 34;
    int elecunit = 7;

    for (int i=0;i<5;i++)
    {
        if (strcmp(username,Room02[i].username) == 0)
        {
            int water = Room02[i].watercost * waterunit;
            int elec = Room02[i].eleccost * elecunit;
            int total = Room02[i].roomprice + water + elec;

            printf("\n============================================\n");
            printf("            FEBRUARY BILL DETAILS");
            printf("\n============================================\n");
            printf("Room Number: %d\n", Room02[i].roomnumber);
            printf("Username: %s\n", Room02[i].username);
            printf("Room Price: %d\n", Room02[i].roomprice);
            printf("Water Cost ( Unit: 1/%d ): %d \n", waterunit, water);
            printf("Electricity Cost ( Unit: 1/%d ): %d \n", elecunit, elec);
            printf("----------------------------------------------\n");
            printf("Total: %d\n", total);
            printf("==============================================\n");

            if (Room02[i].pay == 0)
            {
                printf("Please pass enter to continue...");
                while (getchar() != '\n');
                getchar();
                payment(&Room02[i]);
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
        savedataroom01(); // บันทึกข้อมูลที่อัปเดตลงไฟล์//
        savedataroom02(); // บันทึกข้อมูลที่อัปเดตลงไฟล์สำหรับระบบประเภทที่ 2//
        printf("Payment confirmed. Thank you!\n");
    }
    else if (choice == 'N' || choice == 'n')
    {
        printf("Payment cancelled.\n");
    }

    while (getchar() != '\n');
    getchar();
    mainmenu(); // กลับไปยังเมนูหลักหลังจากการชำระเงิน//
} 