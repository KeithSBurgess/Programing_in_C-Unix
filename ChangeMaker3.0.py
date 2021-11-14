"""
Keith Burgess

Last modified 11/6/20

This program is a simple change maker vending machine that will get a purchase price from the user and prompt them to enter their deposits.
The program will end once the user enters 'q' and the total of the stock is printed.
"""
class stock:

   def __init__(self):
      self.nickels = 25
      self.dimes = 25
      self.quarters = 25
      self.ones = 0
      self.fives = 0
   
   
   
   def updateStock(self,n,d,q,o,f):
      self.nickels = self.nickels + n
      self.dimes = self.dimes + d
      self.quarters = self.quarters + q
      self.ones = self.ones + o
      self.fives = self.fives + f
 
    
   def changeReturn(self,x):
      print("\nPlease take the change below.")
      if x == 0:
         print("\tNo change due.")
      else:         
         changef = 0
         changeo = 0
         changeq = 0
         changed = 0
         changen = 0
#
#         while self.fives > 0 and  x/500 >= 1:   #If you want to allow Fives and Ones to be deposited uncomment these lines
#            x = x - 500
#            self.fives -= 1
#            changef += 1
#                     
#         while self.ones > 0 and x/100 >= 1:
#            x = x - 100
#            self.ones -= 1
#            changeo += 1
#         
         while self.quarters > 0 and x/25 >= 1:
            x = x - 25
            self.quarters -= 1
            changeq += 1

         
         while self.dimes > 0 and x/10 >= 1:
            x = x - 10
            self.dimes -= 1
            changed += 1

         
         while self.nickels > 0 and x/5 >= 1:
            x = x - 5
            self.nickels -= 1
            changen += 1

         #if changef > 0:                      #If you want to allow Fives and Ones to be deposited uncomment these lines
         #   print("\t",changef,"fives")
         #if changeo > 0:
         #   print("\t",changeo,"ones")
         if changeq > 0:
            print("\t",changeq,"quarters")            
         if changed > 0:
            print("\t",changed,"dimes")            
         if changen > 0:
            print("\t",changen,"nickels") 
            
         if x > 0:
            if x > 100:
               print("Machine is out of change.\nSee store manager for remaining refund.\nAmount due is:",x//100,"dollars and",x%100,"cents") #If value is less than 1 dollar prints only cents 
            else:
               print("Machine is out of change.\nSee store manager for remaining refund.\nAmount due is:",x%100,"cents")             
                                         
   
   def printStock(self):
      print("\nStock contains:")
      print("\t",self.nickels, "nickels")
      print("\t",self.dimes, "dimes")
      print("\t",self.quarters, "quarters")
      print("\t",self.ones, "ones")
      print("\t",self.fives, "fives")
      
   def totalStock(self):
      total = self.nickels*5 + self.dimes*10 + self.quarters*25 + self.ones*100 + self.fives*500
      return total      
      

#=====================================================================        
def checkInput(string): #Returns TRUE if input is Valid else it returns FALSE
   if string == 'q':
      check1 = True
   else:
      check1 = False   
   #
   try:
      float(string)
      check2 = True
   except ValueError:
      check2 = False
   
   if check2 == True:
      num = float(string)
      num = round(num*100)
      if num > 0 and num % 5 == 0:
         check2 = True
      else:
         check2 = False         
          
      
   if check1 or check2:
      return True
       
#----------------------------------------------------------------------------------

f = 0 #Fives to be added
o = 0 #Ones to be added  
q = 0 #Quarters to be added
d = 0 #Dimes to be added
n = 0 #Nickels to be added 

print("Welcome to the vending machine change maker program\nChange maker initialized.")
amount = stock()
amount.printStock()


while True:

   x = input("\nEnter the purchase price (xx.xx) or `q' to quit: ")
   
   while checkInput(x) != True: #If input is Invalid tells the user and prompts them for another input   
      if checkInput(x) != True:   
         print("Illegal price: Must be a non-negative multiple of 5 cents.")
         x = input("\nEnter the purchase price (xx.xx) or `q' to quit: ")
   
   
   if x == 'q':
      total = amount.totalStock()
      print("Total:", total//100,"dollars and",total%100,"cents")
      break     
   else:
      x = float(x)
      x = round(x*100)
      print("\nMenu for deposits:\n\t'n' - deposit a nickel\n\t'd' - deposit a dime\n\t'q' - deposit a quarter\n\t'o' - deposit a one dollar bill\n\t'f' - deposit a five dollar bill\n\t'c' - cancel the purchase\n")

      while x > 0:
         if x > 100:
          print("Payment due:",x//100,"dollars and",x%100,"cents")      #If value is less than 1 dollar prints only cents 
         else:
          print("Payment due:",x%100,"cents")                                                                                      
         dep = str(input("Indicate your deposit: "))
         if dep == 'n':
            x = x-5
            n += 1
         elif dep == 'd':
            x = x-10
            d += 1
         elif dep == 'q':
            x = x-25
            q += 1
         elif dep == 'o':
            x = x-100
            o += 1
         elif dep == 'f':
            x = x-500
            f += 1
         elif dep == 'c':
            x = n*5 + d*10 + q*25 + o*100 + f*500
            #print("Deposit Canceled")
            break
         else:
            print("Illegel selection",dep) 
        
      amount.updateStock(n,d,q,o,f)
      x = abs(x) #Used to make changeReturn works as intended
      amount.changeReturn(x)
      amount.printStock()
      
      
   f = 0 #Resets Fives to be added
   o = 0 #Resets Ones to be added  
   q = 0 #Resets Quarters to be added
   d = 0 #Resets Dimes to be added
   n = 0 #Resets Nickels to be added 
