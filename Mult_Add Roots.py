"""
Keith Burgess

Last Modified 9/20/20

This program takes an integer given by the user and returns the additive persistence, additive root, multiplicative persistence, and the multiplicative root.
The program continues until a negative number is entered.
"""

def addDigits(n): #Adds the digits together and returns sum
   x = 0
   z = 0
   
      
   while n > 0:
      x = n%10         
      n = n//10                     
      
      z = z + x
      
   return z   

#-------------------------------------------------------
def multDigits(n): #multiplies the digits together and returns value
   x = 0
   z = 1
   
      
   while n > 0:
      x = n%10         
      n = n//10                     
      
      z = z * x
      
   return z      
#-------------------------------------------------------- 
#--------------------------------------------------------  

def add(n):          #Uses addDigits to find Additive Persistence/Root
   addPersistence = 0
   addRoot = 0
   n1 = n

   while True:                        
      n1 = addDigits(n1)
#      print(n1)                          Test statement 
  
      addPersistence = addPersistence + 1
      

      if n1 < 10:
       addRoot = n1
       break

   
   return(addPersistence,addRoot) #returns the persistence and root
     
#----------------------------------------

def mult(n):          #Uses multDigits to find Multiplicative Persistence/Root
   multPersistence = 0
   multRoot = 0
   n1 = n

   while True:                        
      n1 = multDigits(n1)
#      print(n1)                          Test statement   
 
      multPersistence = multPersistence + 1
      

      if n1 < 10:
       multRoot = n1
       break

   
   return(multPersistence,multRoot) #returns the persistence and root
     
#-----------------------------------------



num = int(input("Enter an Integer(negative to quit) "))
while num > 0:                            #Makes so when a negative number is entered the program ends  

   if num < 10:
      addPersistence = 0
      multPersistence = 0
      addRoot = num
      multRoot = num
      print("\nAdditive properties:")
      print("\nThe additive persistence is",addPersistence)
      print("The additive root is",addRoot,)
      
      print("\nMultiplicative properties:")
      print("\nThe multiplicative persistence is",multPersistence)
      print("The multiplicative root is",multRoot, "\n")
      
      num = int(input("Enter an Integer(negative to quit) "))


   else:
 
   
         addPersistence, addRoot = add(num)
         multPersistence, multRoot = mult(num)
         
         print("\nAdditive properties:")
         print("\nThe additive persistence is",addPersistence)
         print("The additive root is",addRoot,)
         
         print("\nMultiplicative properties:")
         print("\nThe multiplicative persistence is",multPersistence)
         print("The multiplicative root is",multRoot, "\n")
         
         num = int(input("Enter an Integer(negative to quit) "))
      
      
      




