



def binary(n):

   print(n%2,' ', end='')
   if n == 1:
      return
   n = n//2
   binary(n)
   
def steps(n):
   print(n,'/ 2 = ',n/2)
   print('R:',n%2)
   if n == 1:
      return
   n = n//2
   steps(n)   


n = int(input("Enter Number: "))

binary(n)
print()
print("reverse for Binary Number")
print("\nSteps:\n")
steps(n)
