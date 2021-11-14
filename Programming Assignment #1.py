"""
Keith Burgess

Last Modified: 1/26/21

Programing Assignment #1

"""



#1.Boolean and integer variables and Conditionals
"""

def Order(x,y,z):
   return True if (x<y<z) or (x>y>z) else False


numbers = input("Enter 3 numbers: ")

x,y,z = numbers.split()

x = int(x)
y = int(y)
z = int(z)

print("Numbers:",numbers)
print("In order:",Order(x,y,z))

"""

#2.Type conversion
"""

def Conversion(r,g,b):
   w = max(r/255,g/255,b/255)
   if w == 0:
      C = 0
      M = 0
      Y = 0

   else:
      C = ((w-r/255)/w)
      M = ((w-g/255)/w)
      Y = ((w-b/255)/w)
   K = (1-w)
   
   return(C,M,Y,K)
   

red = int(input("Enter an integer for the color Red: "))
green = int(input("Enter an integer for the color Green: "))
blue = int(input("Enter an integer for the color Blue: "))


c,m,y,k = Conversion(red,green,blue)

print("Cyan =",c)
print("Magenta =",m)
print("Yellow =",y)
print("Black =",k)

"""

#3. Checkerboard
"""

n = int(input("Enter an Integer Number: "))
      
for i in range(n):
   print()
   for j in range(n*2):
      if (i+j) % 2 == 0:
         print("*",end='')
      else:   
       print(" ",end='')      
      
"""

#4. A drunkard's walk

"""
import random

def Walk(n,s,l):
   
   if n == 0:
      return print("squared distance:",l[0]**2+l[1]**2)
      
   else:
      l[random.randint(0,1)] += s[random.randint(0,1)] 
      print(l)  
      Walk(n-1,s,l)
   
n = int(input("Enter an integer number: ")) # Number of Steps

location = [0,0] #x,y Location

s = [-1,1]  #List for Step

Walk(n,s,location)

"""




