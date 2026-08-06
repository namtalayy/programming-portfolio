#progressive tax calculator

def print_save(text, file): #บันทึกข้อความลงไฟล์
    print(text) 
    file.write(text + "\n") #ข้อความ + "\n" เพื่อขึ้นบรรทัดใหม่

def calculate_tax(income):
    #ภาษีแต่ละขั้น
    tax0 = 0   #0 - 150,000 (0%)
 
    #ขั้นที่ 2: 150,001 - 300,000 (5%)
    if income > 150000:
        if income > 300000:
            tax05 = (300000 - 150000) * 0.05   #เกินขั้นนี้แล้วคิดเต็มขั้น
        else:
            tax05 = (income - 150000) * 0.05   #ยังไม่เกินคิดแค่ส่วนที่เหลือ
    else:
        tax05 = 0
 
    #ขั้นที่ 3: 300,001 - 500,000 (10%)
    if income > 300000:
        if income > 500000:
            tax10 = (500000 - 300000) * 0.10
        else:
            tax10 = (income - 300000) * 0.10
    else:
        tax10 = 0
 
    #ขั้นที่ 4: 500,001 - 750,000 (15%)
    if income > 500000:
        if income > 750000:
            tax15 = (750000 - 500000) * 0.15
        else:
            tax15 = (income - 500000) * 0.15
    else:
        tax15 = 0
 
    #ขั้นที่ 5: 750,001 - 1,000,000 (20%)
    if income > 750000:
        if income > 1000000:
            tax20 = (1000000 - 750000) * 0.20
        else:
            tax20 = (income - 750000) * 0.20
    else:
        tax20 = 0
 
    #ขั้นที่ 6: 1,000,001 - 2,000,000 (25%)
    if income > 1000000:
        if income > 2000000:
            tax25 = (2000000 - 1000000) * 0.25
        else:
            tax25 = (income - 1000000) * 0.25
    else:
        tax25 = 0
 
    #ขั้นที่ 7: 2,000,001 - 5,000,000 (30%)
    if income > 2000000:
        if income > 5000000:
            tax30 = (5000000 - 2000000) * 0.30
        else:
            tax30 = (income - 2000000) * 0.30
    else:
        tax30 = 0
 
    #ขั้นที่ 8: มากกว่า 5,000,000 (35%)
    if income > 5000000:
        tax35 = (income - 5000000) * 0.35
    else:
        tax35 = 0
 
    total_tax = tax05 + tax10 + tax15 + tax20 + tax25 + tax30 + tax35
    
    with open("tax_save.txt", "a") as file: 
        
        print_save("=" * 50,file)
        print_save("PROGRESSIVE TAX RATES".center(50),file)
        print_save("=" * 50,file)
        
        print_save(f"{'0 - 150,000':<25}{tax0:>12,.0f} THB",file)

        if income > 150000:
            print_save(f"{'150,001 - 300,000':<25}{tax05:>12,.0f} THB",file)

        if income > 300000:
            print_save(f"{'300,001 - 500,000':<25}{tax10:>12,.0f} THB",file)

        if income > 500000:
            print_save(f"{'500,001 - 750,000':<25}{tax15:>12,.0f} THB",file)

        if income > 750000:
            print_save(f"{'750,001 - 1,000,000':<25}{tax20:>12,.0f} THB",file)

        if income > 1000000:
            print_save(f"{'1,000,001 - 2,000,000':<25}{tax25:>12,.0f} THB",file)

        if income > 2000000:
            print_save(f"{'2,000,001 - 5,000,000':<25}{tax30:>12,.0f} THB",file)

        if income > 5000000:
            print_save(f"{'More than 5,000,000':<25}{tax35:>12,.0f} THB",file)
        
        print_save("-" * 50,file)
        print_save(f"{'Total Tax':<25}{total_tax:>12,.0f} THB",file)
        
        disposable_income = income - total_tax
        print_save(f"{'Disposable income':<25}{disposable_income:>12,.0f} THB",file)
    
        if income > 0:
            tax_rate = (total_tax / income) * 100
        else:
            tax_rate = 0
        
        print_save(f"{'Effective Tax Rate':<25}{tax_rate:>12.2f} %",file)
        print_save("=" * 50,file)
    
def one_person():
    income = float(input("Enter income : "))
    
    if income < 0:
        print("Sorry income invalid.")
        return
        
    calculate_tax(income)

def multiple_people():
    people = int(input("Enter number of people : "))
    
    for i in range(people):
        
        with open("tax_save.txt", "a") as file:
            print_save(f" Person {i+1} ".center(50,'='),file)
            
        income = float(input("Enter income : "))
        
        if income < 0:
            print("Sorry income invalid.")
            continue
            
        calculate_tax(income)
    
def menu():
    while True:
        print("=" * 50)
        print("Tax Calculator".center(50))
        print("=" * 50)
        print("1) Calculate tax for 1 person")
        print("2) Calculate tax for multiple people")
        print("3) Exit")
 
        choice = input("Enter your choice : ")

        if choice == "1":
            one_person()
 
        elif choice == "2":
            multiple_people()
 
        elif choice == "3":
            print("Exiting the program...")
            break
 
        else:
            print("Invalid choice. Please try again.") 

menu()