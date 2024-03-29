
fds= []


def read_val():
	n=int(input("Enter the number of students in class"))
	for i in range(0,n):
		marks=int(input("Enter the marks of the studends .If the student is absent enter -1"))
		fds.append(marks)
	print("List of Marks entered=",fds)



def avg():
	sum=0
	p=0
	for i in fds:
		if i==-1:
			continue
		else:
			sum=sum+i
			p=p+1
	avg=sum/p
	print("Average of marks entered =",avg)


def high_score():#10,53,65,23,98 
	mx=fds[0]
	for i in fds:
		if i>mx:
			mx=i
	print("Highest marks scored in FDS subject=",mx)

def low_score():#-1,45,23,16
	for i in fds:
		if i!=-1:
			mn=i
			break
	
	for i in fds:
		if i==-1:
			continue
		else:
			if i<mn:
				mn=i
	print("Lowest marks scored in FDS subject=",mn)

def absent():
	ab=0
	for i in fds:
		if i==-1:
			ab=ab+1
	print("Number of students absent =",ab)

def freq():
	maxc=0
	maxf=0
	for i in fds:
		c=0
		if i==-1:
			continue
		for j in fds:
			if j==i:
				c=c+1
		if c>maxc:
			maxc=c
			maxf=i
	print("Marks with highest frequency are ",maxf,"MAXIMUM COUNT= ",maxc)

def retest():
	r=int(input("Enter the number of students who appeared for retest"))
	for i in range(0,r):
		r_n=int(input("Enter the roll no of the student who appeared for the retest"))
		n_marks=int(input("Enter new marks scored"))
		
		if fds[r_n-1]==-1 or fds[r_n-1]<n_marks:
			fds[r_n-1]=n_marks
	print("New list=",fds)
	avg()
	high_score()
	low_score()
	absent()
	freq()
			

read_val()

flag=1
while flag==1:
	print("\n\n........................MENU.....................\n")
	print("1) The average score of the class")
	print("2) Highest score of the class")
	print("3) lowest score of the class")
	print("4) Number of students who are absent.")
	print("5)Marks with highest frequency")
	print("6)Retest calibration")
	
	ch = int(input("Enter your choice from 1 to 6"))

	if ch==1:
		avg()
	elif ch==2:
		high_score()
	elif ch==3:
		low_score()
	elif ch==4:
		absent()
	elif ch==5:
		freq()
	elif ch==6:
		retest()
	else:
		print("Wrong choice")
	
	a=input("Dou want to continue (yes/no)")
	if a=="yes":
		flag=1
	else:
		flag=0


		

