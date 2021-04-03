# written by Chiayen,HSU,S0951037
# DO NOT COPY
firstday = [0, 0, 0, 0]
jumpLine = [0, 0, 0, 0]
frameStart = [0, 0, 0, 0]
year1582jump = 15


def canlenderTitle(startMonth, year, time):
    monthName = ["January", "February", "March", "April", "May", "June",
                 "July", "August", "September", "October", "November", "December"]
    for i in range(startMonth, startMonth+time):
        print("                {0:<9s} {1:>4d}                  ".format(
            monthName[i], year), sep='', end='')
    print()


def separate(tms):
    for i in range(0, tms):
        print("-----------------------------------------------", sep='', end='')
        i
    print()


def weekName(tms):
    for i in range(0, tms):
        print("     S     M     T     W     T     F     S     ", sep='', end='')
        i
    print()


def get_MonthFirstDay(month, year):
    month += 1
    d = 1
    if(month == 1 or month == 2):
        m = month+12
        c = (year-1)//100
        y = (year-1) % 100
    else:
        m = month
        c = year//100
        y = year % 100
    if (year < 1583):
        if(month > 10):
            w = y+y//4+c//4-2*c+2*m+(3*(m+1))//5+d+1
        else:
            w = y+y//4-c+2*m+(3*(m+1))//5+d-1
    else:
        w = y + y // 4 + c // 4 - 2 * c + 2 * m + (3 * (m + 1)) // 5 + d + 1
    while w < 7:
        w = w+7
    w = w % 7
    return w


def CanlenderBody(month, year, mode):
    monthdayLeap = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    monthday = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    global year1582jump
    # FIXME #3 閏年判斷錯誤
    if ((year % 4) == 0):
        if((year % 100) == 0):
            if((year % 400) == 0):
                isLeap = 1
            else:
                isLeap = 0
        else:
            isLeap = 1
    else:
        isLeap = 0

    if (mode == 0):
        firstday[0] = get_MonthFirstDay(month, year)
        jumpLine[0] = 6-firstday[0]
        # print("|",end='')
        for i in range(6*firstday[0]):
            print(" ", sep='', end='')
        for i in range(monthdayLeap[month] if isLeap else monthday[month]):
            if year == 1582 and month == 9:
                if i+1 > 4 and i+1 < 15:
                    continue
                else:
                    print("%6d" % (i+1), end='')
            else:
                print("%6d" % (i+1), end='')
            #print("%6d" % (i+1), end='')
            if (jumpLine[0] == 0):
                #print("%4s" % "|", "\n", end='', sep='')
                print()
                jumpLine[0] = 7
            jumpLine[0] = jumpLine[0]-1
        print()
    elif(mode == 1):
        monthInFunc = month
        # 取得每個月的第一天
        for i in range(0, 3):
            firstday[i] = get_MonthFirstDay(monthInFunc, year)
            jumpLine[i] = 6-firstday[i]
            monthInFunc = monthInFunc+1

        for i in range(0, 3):
            # 輸出空格使其對齊
            for j in range(6*firstday[i]):
                print(" ", end='')
            # 輸出數字
            k = 0

            while(k != jumpLine[i]+1):
                if(year != 1582):
                    print("%6d" % (k+1), end='')
                    if(jumpLine[i] == k):
                        frameStart[i] = k+2
                else:
                    if(month+i == 9):
                        if k < 4:
                            print("%6d" % (k+1), end='')
                        else:
                            print("%6d" % year1582jump, end='')
                            year1582jump = year1582jump+1
                            if(year1582jump == 17):
                                frameStart[i] = year1582jump
                                pass
                    else:
                        print("%6d" % (k+1), end='')
                        if(jumpLine[i] == k):
                            frameStart[i] = k+2
                k = k+1

            if(i < 2):
                print("%5s" % "|", end='')
        print()
        # 以下不需更動
        for t in range(0, 5):
            for i in range(0, 3):
                for j in range(0, 7):
                    #fell in here
                    if(frameStart[i]-1 == (monthdayLeap[month+i] if isLeap else monthday[month+i])):
                        print("%6s" % " ", end='')
                    else:
                        print("%6d" % (frameStart[i]), end='')
                        frameStart[i] = frameStart[i]+1
                if(i < 2):
                    print("%5s" % "|", end='')
            print()

    elif(mode == 2):
        monthInFunc = month
        # 取得每個月的第一天
        for i in range(0, 4):
            firstday[i] = get_MonthFirstDay(monthInFunc, year)
            jumpLine[i] = 6-firstday[i]
            monthInFunc = monthInFunc+1
        # 輸出空格使其對齊
        for i in range(0, 4):
            for j in range(6*firstday[i]):
                print(" ", end='')
            k = 0
            while(k != jumpLine[i]+1):
                if(year != 1582):
                    print("%6d" % (k+1), end='')
                    if(jumpLine[i] == k):
                        frameStart[i] = k+2
                else:
                    if(month+i == 9):
                        if k < 4:
                            print("%6d" % (k+1), end='')
                        else:
                            print("%6d" % year1582jump, end='')
                            year1582jump = year1582jump+1
                            if(year1582jump == 17):
                                frameStart[i] = year1582jump
                                pass
                    else:
                        print("%6d" % (k+1), end='')
                        if(jumpLine[i] == k):
                            frameStart[i] = k+2
                k = k+1

            if(i < 3):
                print("%5s" % "|", end='')
        print()
        for t in range(5):
            for i in range(0, 4):
                for j in range(0, 7):
                    if(frameStart[i]-1 == (monthdayLeap[month+i] if isLeap else monthday[month+i])):
                        print("%6s" % " ", end='')
                    else:
                        print("%6d" % (frameStart[i]), end='')
                        frameStart[i] = frameStart[i]+1
                if(i < 3):
                    print("%5s" % "|", end='')
            print()


functionSelect = int(input(
    "PLEASE SELECT: which functionality would you like to use\n[0] print the canlendar of selected month\n[1] print the canlendar of the year\n->"))

if functionSelect:
    year = int(input("Enter the year of the canlender which you want to see:"))
    format = int(
        input("[OPTION] please select the format :\n[0]12x1\n[1] 3x4\n[2] 4x3\n->"))
    if format == 1:
        for i in range(4):
            canlenderTitle(i*3, year, 3)
            weekName(3)
            separate(3)
            CanlenderBody(i*3, year, 1)
            separate(3)
            print()
    elif format == 2:
        for i in range(3):
            canlenderTitle(i*4, year, 4)
            weekName(4)
            separate(4)
            CanlenderBody(i*4, year, 2)
            separate(4)
            print()
    elif format == 0:
        for i in range(12):
            canlenderTitle(i, year, 1)
            weekName(1)
            separate(1)
            CanlenderBody(i, year, 0)
            separate(1)
            print()
else:
    year = int(input("Enter the year:"))
    month = int(input("Enter the month:"))
    canlenderTitle(month-1, year, 1)
    weekName(1)
    separate(1)
    CanlenderBody(month-1, year, 0)
    separate(1)
    print()
print("written by Chiayen,HSU,S0951037\nDO NOT COPY")
