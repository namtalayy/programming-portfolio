# =============================================================================
# DEMO 2: Interactive Calculator
# =============================================================================

print("=" * 50)
print("DEMO 2: Interactive Calculator")
print("=" * 50)

# รับ input จากผู้ใช้
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))

print(f"\nCalculations with {num1} and {num2}:")
print(f"{num1} + {num2} = {num1 + num2}")
print(f"{num1} - {num2} = {num1 - num2}")
print(f"{num1} * {num2} = {num1 * num2}")

# ตรวจสอบการหารด้วยศูนย์
if num2 != 0:
    print(f"{num1} / {num2} = {num1 / num2}")
    print(f"{num1} // {num2} = {num1 // num2}")
    print(f"{num1} % {num2} = {num1 % num2}")
else:
    print("Cannot divide by zero!")

print(f"{num1} ** {num2} = {num1 ** num2}")

print()