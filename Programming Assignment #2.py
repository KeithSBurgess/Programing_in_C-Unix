"""
Keith Burgess

Last Modified 2/11/21

Programing Assignment #2  

"""
from numpy.random import randint
from statistics import mode


def printNumbers(n,i):    #Function prints list 
   if i < len(n):
      print(n[i]," ",end='')
      printNumbers(n,i+1)
   else:
      print("")


def bubbleSort(n):               #Function Sorts list
    for i in range(len(n)-1, 0, -1):
        for j in range(i):
            if n[j] > n[j+1]:
                temp = n[j]
                n[j] = n[j+1]
                n[j+1] = temp
    return n


def mostOccuring(n): #Function uses mode from statistics to find mode, if none exsist returns "No Unique Mode"
   try:
      m = mode(n)
      return m
   except:
      m = "No Unique Mode"
      return m
         
def sumOfSquares(n,i,ssum): #Function gets and returns the sum of squares 
   if i >= len(n):
      return ssum
   else:
      ssum += (n[i])**2
      return sumOfSquares(n,i+1,ssum)
      
  
def average(n,i,sum):    #Function gets the sum of list then returns the average 
   if i >= len(n):
      return (sum/len(n))
   else:
      sum += n[i]
      return average(n,i+1,sum)

 
def closestToZero(n,i,CTZ): #Function compares the absolute values and returns the number closest to Zero 
   if i < len(n):
      if abs(n[i]) < abs(CTZ):
          CTZ = n[i]
      return closestToZero(n,i+1,CTZ)          
   else:
      return CTZ 


def aboveAverage(n,i,average):
   if i < len(n) and n[i] < average:
      return aboveAverage(n,i+1,average)
   else:
      return i              


def randomizeOrder(n,i): #Function randomizes the order in list 
   if i < len(n):
      rand = randint(0,len(n))
      temp = n[i]
      temp2 = n[rand]
      n[i] = temp2
      n[rand] = temp
      return randomizeOrder(n,i+1)   
   else:
      return n
"""=======================Code Starts Here======================="""

numbers = randint(-99,99,20) #Creates a Random List


print("\na.")
print("The List Created:")
printNumbers(numbers,0) #Prints the List


sortedNumbers = bubbleSort(numbers) #Sorts the List
print("\nb.")
print("The Maximum Element in List:",sortedNumbers[-1]) #Prints Maximum Element


print("\nc.")
print("The Maximum Element in List:",sortedNumbers[-1],"\nThe Minimum Element in List:",sortedNumbers[0]) #Prints Maximum and Minumum Elements


print("\nd.")
print("The Median Element in List:",sortedNumbers[len(sortedNumbers)//2]) #Prints Median Element


print("\ne.")
print("The Most Occuring Element in List:",mostOccuring(numbers)) #Prints Most Occuring Element


print("\nf.")
print("The Sum of Squares of Elements in List:",sumOfSquares(numbers,0,0)) #Prints Maximum Element


print("\ng.")
average = average(numbers,0,0) #Stores average of list for later use
print("The Average of Elements in List:", average) #Prints Average of Elements       


print("\nh.")
print("The Element Closes to Zero in List:",closestToZero(numbers,0,abs(numbers[0]))) #Prints Element Closest to Zero


print("\ni.")
index = aboveAverage(sortedNumbers,0,average) #Finds the index of when numbers are higher than average
print("The Elements Greater Than The Average in List:")
printNumbers(sortedNumbers,index) #Prints Elements Greater Than The Average


print("\nj.")
print("The List in Increasing Order:")
printNumbers(sortedNumbers,0) #Prints the List in Increasing Order


print("\nk.")
randOrder = randomizeOrder(numbers,0) #Randomizes List
print("The List in Random Order:")
printNumbers(randOrder,0) #Prints Randomized List