s=input("Enter a string\n")
l=s.split()

def longest():
    maxc=0
    for i in l:
        c=0
        for j in i:
            c=c+1
        if(c>maxc):
            maxc=c
            word=i
    print("The longest word is ",word," and its frequency is ",maxc)


def f_o_c():# frequency of a character
    ch=input("Enter the character whose frequency is to be determined")
    c=0
    for i in s:
        if(ch==i):
            c=c+1
    print("The frequency of the character is ",c)


def palindrome():
    rev=""
    for i in range(len(s)-1,-1,-1):
        rev=rev+s[i]
    print(rev)
    if(rev==s):
        print("Entered string is a palindrome")
    else:
        print("Entered string is not a palindrome")

def substring():
    s2=input("enter the substring whose index is to be found:")
    l2=len(s2)
    for i in range(len(s)):
        if(s[i]==s2[0]):
            end=i+l2
            str2=s[i:end]
            if(str2==s2):
                print("The substring is found at position ",i)
                break
            else:
                print("The substring is not present")

def w_count():
    for i in l:
        c=0
        for j in l:
            if i==j:
                c=c+1
        print("the word ",i,"is reapeated ",c,"times")

flag = 1
while flag == 1:
    print("1. Display word with longest word: \n")
    print("2. The occurence of character in the string is: \n")
    print("3. Check whether is string is palindrome or not: \n")
    print("4. Display index of first appearance of the substring: \n")
    print("5. Occurrence of each word in the given string: \n")
    print("6. Exit")
    ch = int(input("Enter your choice: "))
    if(ch == 1):
        longest()
    elif(ch == 2):
        f_o_c()
    elif(ch == 3):
        palindrome()
    elif(ch == 4):
        substring()
    elif(ch == 5):
        w_count()
    elif(ch == 6):
        flag=0
    else:
        print("Enter valid choice")