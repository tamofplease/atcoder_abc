import datetime
li = [[] for _ in range()]
li = [[[[[]] * 3] *4] * 3][0]

# print((datetime.datetime(2021, 5, 18) - datetime.datetime(2021, 6, 18)).days)

# 1 31 3 1 4
# submit
# taro
# 1
# 02/01 10:00-12:00
# check
# taro
# submit
# jiro
# 3
# 01/31 09:00-12:00 02/01 10:00-12:00 02/02 08:00-10:00
# check
# jiro

print(li)
li[0][2][1] = 'some'
print(li)
