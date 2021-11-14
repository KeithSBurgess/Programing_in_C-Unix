"""
Keith Burgess

Last Modified 4/7/21

Programming Assignment #4

"""

def computeN(p,q):
   return(p*q)
   
def computeM(p,q):
   return (p-1)*(q-1)

def encrypt(m,e,n):
#   print("m =",m,"e =",e,"n =",n)
#   print(m**e)
#   print(m**e%n)
   c = m**e % n
   return c
      
def decrypt(c,d,n):
   r = c**d % n
   return r

p = 83
q = 103

n = computeN(p,q)
m = computeM(p,q)
print(n)

e = 35 
d = 239 

print("Public Key (n,e)")
print("public key(",n,",",e,")")
print()
print("Private Key(n,d)")
print("private key(",n,",",d,")")

message = int(input("\nEnter your message (e.g. 14): "))
"""
while message > 8548:
   print("Number Too Large")
   message = int(input("Enter your message (e.g. 14): "))
"""   
   
print("\nThe message is",message)

cipher = encrypt(message,e,n)
print("The cipher is:",cipher)

decryption = decrypt(cipher,d,n)
print("The decryption is:",decryption)


