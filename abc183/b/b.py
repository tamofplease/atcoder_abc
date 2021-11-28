x_1, y_1, x_2, y_2 = map(int, input().split())

df = x_2 - x_1
from_left = df * (y_1 / (y_1 + y_2))
print(from_left + x_1)
