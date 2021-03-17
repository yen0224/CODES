# coding=UTF-8
import time
def print_month(year, month):
	print()
	print_month_title(year, month)
	print_month_body(year%400 + 2000, month)
	print('\n')


def print_month_title(year, month):

	print('          ', get_month_name(month), ' ', year)
	print('---------------------------------------')
	print('   日   一   二   三   四    五   六')

def print_month_body(year, month):
	start_day = get_start_day(year, month)
	number_of_days_in_month = get_number_of_days_in_month(year, month)
	# print('\033[35;1m %s \033[m' % (30))
	today = list(time.localtime(time.time()))
	for i in range(start_day):
		print('     ', end = '')
	for j in range(1, number_of_days_in_month+1):
        #這個地方的作用就是如果你查看的是當年的日曆，那麼這個判斷語句就會
        #把當天的日曆用紫紅色標出
		if today[0] == year and today[1] == month and today[2] == j:
			print('\033[35;1m   %s \033[m' % (j), end = "")
		else:
			print(format(j, '4d'), end = ' ')
		if(j + start_day) % 7 ==0:
			print()

def get_month_name(month):
	n_month = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
	month_name = n_month[month-1]
	return month_name
def get_start_day(year, month):
	START_DAY_FOR_JAN_1_1800 = 3
	total_number_of_days = get_total_number_of_days(year, month)
	return((total_number_of_days + START_DAY_FOR_JAN_1_1800) % 7)
def get_number_of_days_in_month(year, month):
	if month in [1,3,5,7,8,10,12]:
		return 31
	elif month in [4,6,9,11]:
		return 30
	elif is_leapyear(year):
		return 29
	else:
		return 28
def get_total_number_of_days(year, month):
	total = 0
	for i in range(1800, year):
		if is_leapyear(i):
			total += 366
		else:
			total += 365
	for j in range(1, month):
		total += get_number_of_days_in_month(year, j)
	return total
def is_leapyear(year):
	if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0):
		return True
	else:
		return False

year = eval(input('Which year would you want to see? Enter full year (e.g., 2001): '))
for month_n in range(1,12+1):
	# year = year%400 + 2000
	print_month(year, month_n)
