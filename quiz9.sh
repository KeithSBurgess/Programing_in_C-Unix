#!/bin/bash
#Usage: quiz9.sh 3 4 4 5 /etc/passwd	3-4 GroupID	4-5 RealName
#Programmer: Keith Burgess

#This program takes 4 int arguments (3 4 4 5) direct path (/etc/passwd)
#and sorts by GroupID. If the same GroupID sorts by RealName in Reverse Order
echo sort -t: +$1n -$2 -r +$3n -$4 $5 
echo
sort -t: +$1n -$2 -r +$3n -$4 $5
