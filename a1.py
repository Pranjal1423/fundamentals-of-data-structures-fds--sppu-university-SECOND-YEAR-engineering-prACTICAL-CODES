"""In second year computer engineering class, group A student’s play cricket, group B
students play badminton and group C students play football.
Write a Python program using functions to compute following: -
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton.
(Note- While realizing the group, duplicate entries should be avoided, Do not use SET
built-in functions) """

def rem_dup(d):
    lst=[]
    for i in d:
        if i not in lst:
            lst.append(i)
    return lst

n=int(input("Enter the number of students who play cricket"))
cric=[]
print("Enter their names")
for i in range(n):
    name=input()
    cric.append(name)
print("List of students who play cricket=",cric)
cric=rem_dup(cric)

m=int(input("Enter the number of students who play cbadminton"))
bmin=[]
print("Enter their names")
for i in range(m):
    name=input()
    bmin.append(name)
print("List of students who play cricket=",bmin)
bmin=rem_dup(bmin)

p=int(input("Enter the number of students who play cricket"))
fball=[]
print("Enter their names")
for i in range(p):
    name=input()
    fball.append(name)
print("List of students who play cricket=",fball)
fball=rem_dup(fball)

def inter(a,b):
    lst=[]
    for i in a:
        if i in b:
            lst.append(i)
    return lst

def diff(c,d):
    lst=[]
    for i in c:
        if i not in d:
            lst.append(i)
    return lst

def union(e,f):
    lst=e.copy()
    for i in f:
        if i not in lst:
            lst.append(i)
    return lst

def symm(a,b):
    lst1=diff(a,b)
    lst2=diff(b,a)
    lst3=union(lst1,lst2)
    return lst3

#list of students who play both cricket and badminton
def c_b():
    print("list of students who play both cricket and badminton :",inter(cric,bmin))

#List of students who play either cricket or badminton but not both
def cb_bnb():
    print("List of students who play either cricket or badminton but not both:",symm(cric,bmin))

#Number of students who play neither cricket nor badminton
def nc_nb():
    lst3=union(cric,bmin)
    lst4=diff(fball,lst3)
    print("Number of students who play neither cricket nor badminton:",lst4)

#Number of students who play cricket and football but not badminton.
def cf_nb():
    lst5=inter(cric,fball)
    lst6=diff(lst5,bmin)
    print("Number of students who play cricket and football but not badminton" ,lst6)

print("***********************MENU******************************")
print("\n1.list of students who play both cricket and badminton")
print("\n2.List of students who play either cricket or badminton but not both")
print("\n3.Number of students who play neither cricket nor badminton")
print("\n4.Number of students who play cricket and football but not badminton.")
print("\n5.EXIT")
flag=1
while (flag==1):
    ch=int(input("enter the choice"))

    if(ch==1):
        c_b()
    elif ch==2:
        cb_bnb()
    elif ch==3:
        nc_nb()
    elif ch==4:
        cf_nb()
    elif ch==5:
        print("Thankyou")
        flag=0
    else:
        print("Invalid choice")


