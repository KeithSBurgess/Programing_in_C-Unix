"""
Keith Burgess

Last Modified 4/25/21

Programming Assignment #5

This Program uses the Brute Force technique to crack a Caesar Ciphered Code

"""
ABC = [65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90]
#     ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
#       1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26



def Check(cipher,char,List):       #Checks to see if Character is already in List
   for i in range(len(List)):
      if char == List[i][0]:
         return False
   return True
 
   
      
         
def Count(cipher,char,List):      #Counts the Occurence of Each Character in List
   count = 0
   for i in range(len(cipher)):
      if cipher[i] == char:
         count += 1        
   temp = [char,count]         
   List.append(temp)
   return List



def MostCommon(List,char,char2,char3,max):      #Finds Most Common Character
   for i in range(len(List)):
      if List[i][1] > max:
         temp = char
         temp2 = char2
         
         max = List[i][1]
         char = List[i][0]
         
         char2 = temp  
         char3 = temp2
                  
   return char,char2,char3   

"""
def Shift(char,char2,char3):        #Finds the Shift (NEEDS WORK)
   shift = ord('E') - ord(char)
   shift2 = ord('T') - ord(char2)
   shift3 = ord('A') - ord(char3)
   print(shift,shift2,shift3)
   if shift == 3 or shift == -3:
      return shift
   elif shift2 == 3 or shift2 == -3:
      return shift2
   elif shift3 == 3 or shift3 == -3:
      return shift3
"""


def Decode(cipher,ABC):#,shift):       #Decodes and Prints the Cipher
   for j in range(26):
      shift = -j
      print()
      print()
      for i in range(len(cipher)):
         num = ord(cipher[i])
         index = ABC.index(num) + shift
         num2 = ABC[index]
         print(chr(num2),end='')
      
   
   
#----------Code Execution Starts Here----------
         
txt =    'the quick brown fox jumps over the lazy dog'
cipher = "OCDNN CDAOX DKCZM DNVGD OOGZH JMZYD AADXP GOOCV IVXVZ NVMXD KCZMW POIJO CVMY"
#'WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ'
#Plaintext:  the quick brown fox jumps over the lazy dog
#Ciphertext: WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ
print(txt)
print(cipher)
cipher = cipher.replace(' ','')
cipher = cipher.upper()

List = []



for i in range(len(cipher)):
   char = cipher[i]
   if Check(cipher,char,List):
      List = Count(cipher,char,List)
       
"""
max = 0
char = ''
char2 = ''
char3 = ''
     
char,char2,char3 = MostCommon(List,char,char2,char3,max)



shift = Shift(char,char2,char3)
"""
print()
Decode(cipher,ABC)



