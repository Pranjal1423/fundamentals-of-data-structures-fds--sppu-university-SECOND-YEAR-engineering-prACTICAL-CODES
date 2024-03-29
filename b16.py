"""Write a pythonprogram to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores"""


ms=[]
n=int(input("Enter the number of students in class:"))
for i in range(n):
    marks=float(input("Enter the percentage of students :"))
    ms.append(marks)
print("List of percentage of students:",ms)

m=ms.copy()


def part(m,low,high):
    pivot=m[low]
    p=low+1
    q=high
    while True:
        while(p<=q and m[p]<=pivot):
            p=p+1
        while(p<=q and m[q]>=pivot):
            q=q-1
        if(p<=q):
            m[p],m[q]=m[q],m[p]
        else:
            break
    m[low],m[q]=m[q],m[low]
    return q

def quick_sort(m,low,high):
    while(low<high):
        partition=part(m,low,high)
        quick_sort(m,low,partition-1)
        quick_sort(m,partition+1,high)
    return m

def topfive():
    
    print("Top five",m[-1:-6:-1])


print("\n\n...................MENU.....................\n\n")	
print("Enter which operation  you want to perform")
print("\n 1)Sorting using quick sort sort")
print("\n 2)To display the top five scores")
a=1
while (a==1):
    ch=int(input("Enter your choice:"))

    if ch==1:
        print("Sorted array=",quick_sort(ms,0,len(ms)-1))
    
    elif ch==2:
        topfive()
    else:
        print("Wrong choice")
    q=input("Do you want to continue?(yes/no):")
    if q=="yes":
        a=1
    else:
        a=0
print("Thankyou")