num = int(input("Enter a number: "))
i = 1
factorial = 1
while i <= num:
    factorial *= i
    i += 1
print("Factorial of", num, "is", factorial)