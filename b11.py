"""a) Write a pythonprogram to store roll numbers of student in array who attended
training program in random order. Write function for searching whether particular
student attended training program or not, using Linear search and Sentinel search.
b) Write a python program to store roll numbers of student array who attended training
program in sorted order. Write function for searching whether particular student
attended training program or not, using Binary search and Fibonacci search"""
n=int(input("Enter the number of students who attended the program"))
s=[]

print("Enter their rol number")
for i in range(n):
    roll=int(input())
    s.append(roll)
print("List of students",s)

key=int(input("Enter the roll number to be seached"))

def linear_search():
    flag=0
    for i in range(n):
        if key==s[i]:
            flag=1
            break
    
    if(flag==1):
        print("Student is found at index ",i)
    else:
        print("The student is not present")

def sentinel_search():
    last=s[n-1]
    s[n-1]=key
    for i in range(n):
        if key==s[i]:
            break
    if(i<n-1 and last!=key):
        print("Student is found at index ",i)
    elif(last==key):
        print("Student is found at index ",i)
    else:
        print("The student is not present")

a=s.copy()
def sort():
    for i in range(n):
        for j in range(n):
            if(a[i]<a[j]):
                a[i],a[j]=a[j],a[i]
    print("Sorted list=",a)

sort()
lst=a.copy()

low=0
high=n-1
def binary_search(lst,low,high,key):
    if(high>low):
        mid=(low+high)//2
        if(key==lst[mid]):
            return mid
        elif(key>lst[mid]):
            binary_search(lst,mid+1,high,key)
        else:
            binary_search(lst,low,mid-1,key)
    else:
        return -1

        
c=a.copy()
def fibo(c,key,n):
    b=0
    a=1
    f=a+b

    while(f<n):
        b=a
        a=f
        f=a+b
    
    offset=-1
    while True:
        i=min(offset+b,n-1)
        if(key>c[i]):
            f=a
            a=b
            b=f-a
            offset=i
        elif(key<c[i]):
            f=b
            a=a-b
            b=b-a
        else:
            return i
    if(a and c[offset+1]==key):
        return offset+1
    else:
        return -1
    

a=1
while (a==1):
    print("\nMENU")
    print("1.Search using binary search")
    print("2.Search using fibonacci search")
    print("3.Search using linear search")
    print("4.Search using sentinel search")
    print("Exit")
    ch=int(input("Enter your choice"))

    if ch==1:
        result=binary_search(lst,low,high,key)
        
        if(result==-1):
            print("Student not found")
        else:
            print("The student is present at the index ",result)
            
    elif ch==2:
        result2=fibo(c,key,n)
        if(result2==-1):
            print("Student not found")
        else:
            print("The student is present at the index ",result2)

    elif ch==3:
        linear_search()

    elif ch==4:
        sentinel_search()

    elif ch==5:
        print("Thankyou")
        a=0
    else:
        print("Invalid choice")

    







    