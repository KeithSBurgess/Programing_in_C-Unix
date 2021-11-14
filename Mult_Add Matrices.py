"""
Keith Burgess

Last modified 10/6/20

This program will prompt the user to enter the number of rows and 
columns in two matrices and then the program will multiply and add the matrices.
"""


def inputValues(matrix,r,c): #Gets a matrix, its corresponding rows and columns, then proceeds to prompt the user to fill out the matrix
 
   print("Enter the matrix by rows")

   for i in range(r):
       a = []
       for j in range(c):
           a.append(int(input() ))
       matrix.append(a)
   return (matrix)    

  
   
def addMatrices(matrix1,r1,c1,matrix2,r2,c2): #Adds two matrices together and returns the result
   if r1 != r2 or c1 != c2:
      return "UNDEFINED(Matrices aren't the same dimensions)"
   else:
      matrix3 = [ [0] * c1 for i in range(r1) ]
      i = 0
      j = 0
   
      while i < r1:
         j = 0
         while j < c1:
            matrix3[i][j] = matrix1[i][j] +matrix2[i][j]
            j += 1
               
         i += 1
   return (matrix3)      

def multMatrices(matrix1,r1,c1,matrix2,r2,c2): #Multiplies two matrices together and returns the result
   if c1 != r2:
      return "UNDEFINED(Columns in Matrix[1] aren't equal to rows in Matrix[2]"
   else:
      matrix3 = [ [0] * c2 for i in range(r1) ]

            
      for i in range(len(matrix1)):
         
         for j in range(len(matrix2[0])):
             
             for k in range(len(matrix2)):
                 matrix3[i][j] += matrix1[i][k] * matrix2[k][j]

   return (matrix3)            


#-----------------------PROGRAM STARTS HERE-----------------------

#Creates matrix 1
r1 = int(input("Enter the number of rows for Matrix[1]: "))
c1 = int(input("Enter the number of columns for Matrix[1]: "))


matrix1 = []

matrix1 = (inputValues(matrix1,r1,c1)) #User fills out matrix


#Creates matrix 2
r2 = int(input("Enter the number of rows for Matrix[2]: "))
c2 = int(input("Enter the number of columns for Matrix[2]: "))


matrix2 = []

matrix2 = (inputValues(matrix2,r2,c2)) #User fills out matrix


#Prints results
print("Result after adding:",addMatrices(matrix1,r1,c1,matrix2,r2,c2),"\n") #Calls to add the matrices

print("Result after multiplying:",multMatrices(matrix1,r1,c1,matrix2,r2,c2)) #Calls to multiply the matrices