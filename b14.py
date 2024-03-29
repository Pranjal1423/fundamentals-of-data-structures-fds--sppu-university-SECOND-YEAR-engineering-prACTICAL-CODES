"""Write a pythonprogram to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores"""


m=[]
n=int(input("Enter the number of students in class:"))
for i in range(n):
    marks=float(input("Enter the percentage of students :"))
    m.append(marks)
print("List of percentage of students:",m)

lst=m.copy()
def bubblesort():
    for i in range(0,n):
        for j in range(0,n-i-1):
            if(lst[j]>lst[j+1]):
                lst[j],lst[j+1]=lst[j+1],lst[j]
    print("Sorted list using bubble sort=",lst)

s=m.copy()
def selectionsort():
    for i in range(0,n-1):
        min=i
        for j in range(i+1,n):
            if(s[j]<s[min]):
                min=j
        s[i],s[min]=s[min],s[i]
    print("Sorted list using selection sort=",s)


def topfive():
    print("Top five scores=",s[-1:-6:-1])

print("\n\n...................MENU.....................\n\n")	
print("Enter which operation  you want to perform")
print(" 1)Sorting using Bubble sort")
print(" 2)Sorting using selection sort")
print(" 3)To display the top five scores")
print(" 4)EXIT")
a=1
while (a==1):
    ch=int(input("Enter your choice:"))

    if ch==1:
        bubblesort()
    elif ch==2:
        selectionsort()
    elif ch==3:
        topfive()
    elif ch==4:
        print("Thank you")
        a=0
    else:
        print("Wrong choice")
    
