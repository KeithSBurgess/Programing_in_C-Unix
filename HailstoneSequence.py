"""
   Keith Burgess
   
   Last updated 9/8/20
   
   This program recieves an integer from the user and 
   implements the Hailstone Algorithm.


"""

def HailstoneSequence(n):
   k = 0
   print()
   while n != 1:
      if n % 2 == 1:
         print(n," is odd, so I make 3n+1 ", 3*n+1)
         n = 3*n+1
         k = k + 1
         
      if n % 2 == 0:
         print(n," is even, so I take half ", n//2)
         n = n//2
         k = k + 1
            

   return k    #How many steps it took to reach 1
   
   


n = int(input("Enter a Positive Integer ")) #Gets user input 


#Checks if input is a valid integer

while n <= 0:
   print(n," is not a Valid Integer")
   n = int(input("Enter a Positive Integer "))
   

#Prints outcome
   
print("\nIt took",HailstoneSequence(n),"steps to reach 1")    

