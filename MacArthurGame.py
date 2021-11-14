"""
Keith Burgess

Last modified 10/29/20

This program will prompt the user to enter their 2-Digit Birth Month and Age.
The program will then proceed to calculate their Birth Month and Age using MacArthor's Algorithm.
"""
def run(n,a):
   #print("Double it:",n*2)
   n=n*2
   #print("Add 5:", n+5)
   n=n+5
   #print("Multiply by 50:",n*50)
   n=n*50
   #print("Add your age:",n+a)
   n=n+a
   #print("Subtract 365:",n-365)
   n=n-365
   
   print("\nThe Special Number is:",n,"\n")
   
   #print("Add The Magic Number(115):",n+115)
   n=n+115
   
   return n
   

#=============================================================================================================

Months = {1: 'January',2: 'February',3:'March',4:'April',5:'May',6:'June',7:'July',8:'August',9:'June',10:'October',11:'November',12:'December'}   

print("This is the MacArthur Game.The rules are simple:\n")
print("Write down your 2-Digit Month then perform the following steps:")

print("\t1.)Double it\n\t2.)Add 5\n\t3.)Multiply by 50\n\t4.)Add your age\n\t5.)Subtract 365\n")  





month = int(input("Enter Your 2-Digit Birth Month: "))
age = int(input("Enter Your Age: "))

num = run(month,age)


calculatedAge=num%100
num = num//100
calculatedMonth=Months[num]

print("You were born in:",calculatedMonth)
print("You are:",calculatedAge,"years old")