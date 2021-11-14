from numpy.random import randint
from statistics import mode


def bubbleSort(n):               #Function Sorts list
    for i in range(len(n)-1, 0, -1):
        for j in range(i):
            if n[j] > n[j+1]:
                temp = n[j]
                n[j] = n[j+1]
                n[j+1] = temp
    return n
    
def printNumbers(n,i):    #Function prints list 
   if i < len(n):
      print(n[i]," ",end='')
      printNumbers(n,i+1)
   else:
      print("")

def mostOccuring(n): #Function uses mode from statistics to find mode, if none exsist returns "No Unique Mode"
   try:
      m = mode(n)
      return m
   except:
      m = "No Unique Mode"
      return m
      
      
      
def average(n,i,sum):    #Function gets the sum of list then returns the average 
   if i >= len(n):
      return (sum/len(n))
   else:
      sum += n[i]
      return average(n,i+1,sum)      
      
def inputValues(matrix,r): #Gets a matrix, its corresponding rows and columns, then proceeds to prompt the user to fill out the matrix
 
   print("Enter the List")

   for i in range(r):
       matrix.append(int(input()))
   return (matrix)          
#===============================================
num = int(input("How many numbers? "))

list = []

numbers = (inputValues(list,num)) #User fills out list      
      
print(numbers)
#printNumbers(list,0) #Prints the List

sortedNumbers = bubbleSort(numbers) #Sorts the List

print("The Mean of List:,",average(list,0,0))
print("The Median Element in List:",sortedNumbers[len(sortedNumbers)//2]) #Prints Median Element
print("The Most Occuring Element in List:",mostOccuring(numbers)) #Prints Most Occuring Element