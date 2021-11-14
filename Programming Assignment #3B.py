"""
Keith Burgess

Last Modified 3/19/21

Programming Assignment #3B

"""
from math import factorial 

print("--Pascal's Triangle:--")  

n = int(input("Enter the number of rows: "))

for i in range(n): 
    for j in range(n-i+1):
        print(end=" ")   #For left spaces
  
    for j in range(i+1): 
        print(factorial(i)//(factorial(j)*factorial(i-j)), end=" ") 
        
    print() #New line



class Node:

   def __init__(self,data):
      self.data = data
      self.next = None

class LinkedList:

   def __init__(self):
      self.head = None
      
   def printList(self,temp):
      if temp:
         print(temp.data,' ',end='')
         self.printList(temp.next)
      else:
         print()  #New Line
 
   
   def reverseList(self,list):
      if list.next == None:
         self.head = list
         return
      self.reverseList(list.next)
      temp = list.next
      temp.next = list
      list.next = None   

      
   def isPrime(self,temp):
      if temp:
         if temp.data > 1 and ((temp.data % 2 == 1) and (temp.data % 3 == 1)) or (temp.data == 2 or temp.data == 3):
            print(temp.data,' ',end='')    
         self.isPrime(temp.next)
      else:
         print() #New Line  
      
   
   def findLargest(self,curr,largest):
      if not curr:
         print(largest)
      else:
         if curr.data > largest:
            largest = curr.data
         self.findLargest(curr.next,largest)
                                    
   

print("\n--Linked List:--")
#Code Execution Starts Here For Linked List
if __name__ == '__main__':

   llist = LinkedList()
                        
   llist.head = Node(7)
   second = Node(3)
   third = Node(18)
   fourth = Node(12)
   fifth = Node(4)

   llist.head.next = second
   second.next = third
   third.next = fourth
   fourth.next = fifth

print("The LinkedList is:")
llist.printList(llist.head)

print("The Reversed LinkedList is:")
llist.reverseList(llist.head)
llist.printList(llist.head)

print("The Largest Element is:")
llist.findLargest(llist.head,llist.head.data)

print("The Prime Numbers in LinkedList are:")
llist.isPrime(llist.head)

