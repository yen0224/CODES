firstday=[0,0,0,0]
jumpLine=[0,0,0,0]
frameStart=[0,0,0,0]
def canlenderTitle(startMonth, year, time):
	monthName = ["January", "February", "March", "April", "May", "June",
                 "July", "August", "September", "October", "November", "December"]
	for i in range(startMonth, startMonth+time):
		print("                ", "%9s" %
              monthName[i], "%4d" % year,"                ", sep='', end='')
	print()


def separate(tms):
	for i in range(0, tms):
		print("-----------------------------------------------", sep='', end='')
		i
	print()


def weekName(tms):
	for i in range(0, tms):
		print("     S     M     T     W     T     F     S     ",sep='', end='')
		i
	print()


def get_MonthFirstDay(month, year):
	month += 1
	d = 1
	m = month+10
	if m > 12:
		m = m % 12
	if(month < 3):
		year -= 1
	a = year//100
	b = year % 100
	w = d+int(2.6*m-0.2)-2*a+b+a//4+b//4
	while(w < 7):
		w += 7
	w = w % 7
	return w

#FIXME #6 月份天數錯誤 結束點錯誤
def CanlenderBody(month, year, mode):
	monthdayLeap = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
	monthday = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
	#FIXME #3 閏年判斷錯誤
	if ((year % 4)==0):
		if((year % 100)==0):
			if((year % 400)==0):
				isLeap = 1
			else: isLeap = 0
		else :isLeap=1
	else: isLeap=0

	if (mode==0):
		firstday[0]=get_MonthFirstDay(month,year)
		jumpLine[0]=6-firstday[0]
		#print("|",end='')
		for i in range(6*firstday[0]):
			print(" ",sep='',end='')
		for i in range(monthdayLeap[month] if isLeap else monthday[month]):
			print("%6d"%(i+1),end='')
			if (jumpLine[0]==0):
				print("%4s"%"|","\n",end='',sep='')
				jumpLine[0]=7
			jumpLine[0]=jumpLine[0]-1
		print()
	elif(mode==1):
		monthInFunc=month
		# 取得每個月的第一天
		for i in range(0,3):
			firstday[i]=get_MonthFirstDay(monthInFunc,year)
			jumpLine[i]=6-firstday[i]
			monthInFunc=monthInFunc+1
		
		for i in range(0,3):
			#輸出空格使其對齊
			for j in range(6*firstday[i]):
				print(" ",end='')
			#輸出數字
			k=0
			while(k!=jumpLine[i]+1):
				print("%6d"%(k+1),end='')
				if(jumpLine[i]==k):
					frameStart[i]=k+2
				k=k+1
			print("%5s"%"|",end='')
		print()
		for t in range(0,5):
			for i in range(0,3):
				for j in range(0,7):
					#fell in here
					if(frameStart[i]-1==(monthdayLeap[month+i] if isLeap else monthday[month+i])):
						print("%6s"%" ",end='')
					else:
						print("%6d"%(frameStart[i]),end='')
						frameStart[i]=frameStart[i]+1
				print("%5s"%"|",end='')
			print()

	elif(mode==2):
		monthInFunc=month
		# 取得每個月的第一天
		for i in range(0,4):
			firstday[i]=get_MonthFirstDay(monthInFunc,year)
			jumpLine[i]=6-firstday[i]
			monthInFunc=monthInFunc+1
		#輸出空格使其對齊
		for i in range(0,4):
			for j in range(6*firstday[i]):
				print(" ",end='')
			k=0
			while(k!=jumpLine[i]+1):
				print("%6d"%(k+1),end='')
				if(jumpLine[i]==k):
					frameStart[i]=k+2
				k=k+1
			print("%5s"%"|",end='')
		print()
		for t in range(5):
			for i in range(0,4):
				for j in range(0,7):
					if(frameStart[i]-1==(monthdayLeap[month+i] if isLeap else monthday[month+i])):
						print("%6s"%" ",end='')
					else:
						print("%6d"%(frameStart[i]),end='')
						frameStart[i]=frameStart[i]+1
				print("%5s"%"|",end='')
			print()

#year=int(input("Enter the year of the canlender which you want to see:"))
#format=int(input("[OPTION] please select the format :\n[0]12x1\n[1] 3x4\n[2] 4x3"))
year=2021
format=2
if format==1:
	for i in range(4):
		canlenderTitle(i*3,year,3)
		weekName(3)
		separate(3)
		CanlenderBody(i*3,year,1)
		separate(3)
		print()
elif format==2:
	for i in range(3):
		canlenderTitle(i*4,year,4)
		weekName(4)
		separate(4)
		CanlenderBody(i*4,year,2)
		separate(4)
		print()
elif format==0:
	for i in range(12):
		canlenderTitle(i,year,1)
		weekName(1)
		separate(1)
		CanlenderBody(i,year,0)
		separate(1)
		print()