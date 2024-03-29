mark=[]
n=int(input("Enter the number of students in class:"))


# to input data fro the user
def read():
    
    for i in range(n):
        m=float(input("Enter the percentage of students :"))
        mark.append(m)
    print("List of percentage of students:",mark)


read() # calling read function
marks=mark.copy()
def part(marks,low,high):
    pivot = marks[low]
    p =low + 1
    q = high

    while True:
        while p <= q and marks[p] <= pivot:
            p += 1

        while p <= q and marks[q] >= pivot:
            q-=1

        if p <= q:
            marks[p],marks[q]=marks[q],marks[p]

        else:
            break

    marks[low],marks[q]=marks[q],marks[low]
    return q

def Quick_Sort(marks,low,high):
    while low < high:
        partition = part(marks,low,high)
        Quick_Sort(marks,low,partition-1)
        Quick_Sort(marks,partition+1,high)
        return marks

def topfive():
    
    print("Top five",marks[-1:-6:-1])


print("\n\n...................MENU.....................\n\n")	
print("Enter which operation  you want to perform")
print("\n 1)Sorting using quick sort sort")
print("\n 2)To display the top five scores")
a=1
while (a==1):
    ch=int(input("Enter your choice:"))

    if ch==1:
        print("Sorted array=",Quick_Sort(marks,0,len(marks)-1))
    
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