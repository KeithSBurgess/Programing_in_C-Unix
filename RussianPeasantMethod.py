"""
Keith Burgess

Last modified 11/24/20

This program will prompt the user to enter 2 numbers seperated by a space.
The program will then proceed to calculate their product using the Russian Peasant Algorithm.
"""
x = True
while x == True:
   a,b = input("Enter in two integers that you want multiplied seperated by a space: ").split()
  
   a = int(a)
   ob = int(b)
   b = abs(int(b))
   c = 0
   
   while b > 0:
      print("A =",a,"B =",b)
      if b % 2 == 1:
         c += a
         print("B is odd, add A to make the product:",c)
         a = a*2
         b = b//2
         
      else: 
         a = a*2
         b = b//2
   if (a > 0 and ob > 0) or (a < 0 and ob < 0):
      print("Product is positive")
      c = abs(c)
   else:
      print("The product is negative")
      if c > 0:
         c = c*-1
               
   print("The product of the two numbers is:",c)
         
   x = input("Do you want to continue? (y/n) ")
   x = x.upper()
   if x == 'Y':
      x = True
      print("====================================================\n")
   elif x == 'N':
      x = False
   else:
      print("Bad input, quitting")
      break   