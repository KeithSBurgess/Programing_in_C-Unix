"""
Keith Burgess

Last Modified 9/22/20

This program prompts the user to enter the year, month, day, and
then calculates what day of the week it is.
"""

d = {0 : "Saturday", 1 : "Sunday", 2 : "Monday", 3 : "Tuesday", 4 : "Wednesday", 5 : "Thursday", 6 : "Friday"}

def DayOfWeek(k,m,q,j):
   
   h = int((q + ((26*(m+1))/10) + k + (k/4) + (j/4) + (5*j)) % 7)
   
#   print(h) Test function

   return d[h]

k = int(input("Enter year (2012): ")) #year
m = int(input("Enter month (1-12): ")) #month
if m == 1 or m == 2:
   m = m + 12
   k = k - 1
q = int(input("Enter the day of the month(1-31): ")) #day

j = k//100 #century
k = k % 200 #year of century


print("The day of the week is",DayOfWeek(k,m,q,j))
