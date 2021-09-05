# import sys
# from datetime import datetime

# class InputValueError(Exception):
# 	"""入力値の異常を投げるクラス"""
# 	pass

# class InitialValueError(Exception):
# 	"""初期値の異常を投げるクラス"""
# 	pass

# class DataSequenceError(Exception):
# 	""""入力データの序列の異常を投げるクラス """
# 	pass


# # 入力値1行の正しさ、データを保持するクラス
# class InputData:
# 	def __init__(self, line: str):
# 		time, dist = line.split(' ')
# 		hours_str, minutes_str, seconds_str = time.split(':')
# 		self.days, self.hours = self.__validate_hours(hours_str) # 日付は1日から~ 
# 		self.minutes = self.__validate_minutes(minutes_str)
# 		self.seconds, self.milliseconds = self.__validate_seconds(seconds_str)
# 		self.meters, self.ten_cms = self.__validate_dist(dist)

# 	# getter function
# 	def get_milliseconds(self) -> int:
# 		return self.milliseconds + self.seconds * 1000 + self.minutes * 1000 * 60 + self.hours * 1000 * 60 * 60 + self.days * 24 * 1000* 60 * 60

# 	def get_as_date_time(self) -> datetime:
# 		return datetime(2021, 6, self.days, self.hours, self.minutes, self.seconds, self.milliseconds * 1000)

# 	def get_distance(self) -> float:
# 		return self.meters + self.ten_cms * 0.1

# 	def is_midnight(self) -> bool:
# 		datetime = self.get_as_date_time
# 		if self.hours >= 22 and self.minutes >= 0 and self.seconds >= 0 and self.milliseconds >= 0 and self.hours <= 23 and self.minutes <= 59 and self.seconds <= 59 and self.milliseconds <= 999:
# 			return True
# 		elif self.hours >= 0 and self.minutes >= 0 and self.seconds >= 0 and self.milliseconds >= 0 and self.hours <= 4 and self.minutes <= 59 and self.seconds <= 59 and self.milliseconds <= 999:
# 			return True
# 		else:
# 			return False
# 	# End of getter function

# 	def calc_speed_with_millisec_from_last_data(self, last_data) -> (bool,float):
# 		dist = self.get_distance()
# 		time_diff_with_millisec = self.get_milliseconds() - last_data.get_milliseconds()
# 		run_with_slow_speed = (dist / time_diff_with_millisec) > (1000000 / (60 * 60 * 1000))
# 		return (run_with_slow_speed, time_diff_with_millisec)


# 	# validation function

# 	def __validate_hours(self, hours: str) -> int:
# 		hour_num = int(hours)
# 		if hour_num > 99 or hour_num < 0:
# 			raise InputValueError('時間の入力値が異常です')
# 		day_num = hour_num // 24
# 		hour_num %= 24
# 		return day_num+1, hour_num

# 	def __validate_minutes(self, minutes: str) -> int:
# 		minutes_num = int(minutes)
# 		if minutes_num > 59 or minutes_num < 0:
# 			raise InputValueError('分数の入力値が異常です')
# 		return minutes_num

# 	def __validate_seconds(self, seconds: str) -> (int, int):
# 		seconds_num, milliseconds_num = map(int, seconds.split('.'))
# 		if seconds_num > 59 or seconds_num < 0:
# 			raise InputValueError('秒数の入力値が異常です')
# 		if milliseconds_num > 999 or milliseconds_num < 0:
# 			raise InputValueError('ミリ秒の入力値が異常です')
# 		return seconds_num, milliseconds_num

# 	def __validate_dist(self, dist: str) -> (int, int):
# 		meters, ten_cms = map(int, dist.split('.'))
# 		if meters < 0:
# 			raise InputValueError('距離の入力値が異常です[m]')
# 		if ten_cms < 0 or ten_cms > 10:
# 			raise InputValueError('距離の入力値が異常です[cm]')	
# 		return meters, ten_cms

# 	def is_initial_data(self):
# 		if self.meters == 0 and self.ten_cms == 0:
# 			return True
# 		else:
# 			return False
# 	# End of validation function

# class InputService:
# 	def __init__(self, lines: [str]) -> None:
# 		self.initial_data = self.__validate_first_line(lines[0])
# 		self.datas = self.__validate_other_lines(lines[1:])

		
# 	def __validate_first_line(self, line: str) -> InputData:
# 		data = InputData(line)
# 		if not data.is_initial_data:
# 			raise InitialValueError('初期値データが異常です')
# 		return data

# 	def __validate_other_lines(self, lines: [str]) -> [InputData]:
# 		datas = [InputData(lines[index]) for index in range(len(lines))]
# 		#TODO ここで序列のvalidationを加える
# 		return datas
		


# 	# def validate_other_line:
		
# class Calculator:
# 	def __init__(self, init_datas: InputData, datas: [InputData]) -> None:
# 		self.init_datas = init_datas
# 		self.datas = datas

# 	# 低速運賃を計算する
# 	def calc_low_speed_price(self) -> int:
# 		price = 0
# 		last_data_time = self.init_datas.get_as_date_time()
# 		run_with_slow_speed, time_diff_with_millisec = self.datas[0].calc_speed_with_millisec_from_last_data(self.init_datas)
# 		if run_with_slow_speed:
# 			price += self.__calc_price_from_slow_speed_time(milliseconds)

# 		for index in range(1, len(self.datas)):
# 			cur_data = self.datas[index]
# 			run_with_slow_speed, time_diff_with_millisec = cur_data.calc_speed_with_millisec_from_last_data(self.datas[index-1])
# 			if run_with_slow_speed:
# 				price += self.__calc_price_from_slow_speed_time(milliseconds)
# 		return price	
		
# 	# 走行距離による運賃を計算する。
# 	def calc_run_dist_price(self) -> int:
# 		price = 0
# 		last_data_is_night = self.init_datas.is_midnight()
# 		for index in range(len(self.datas)):
# 			dist = self.datas[index].get_distance()
# 			if last_data_is_night and data[index].is_midnight():
# 				dist = data[index].dist * 1.25
# 			price += self.__calc_price_from_distance(dist)
# 		return price

# 	def __calc_price_from_slow_speed_time(self, milliseconds: int) -> int:
# 		if time < 90000:
# 			return 0
# 		elif 90000 <= time < 180000:
# 			return 80
# 		elif 180000 <= time < 270000:
# 			return 160
# 		else:
# 			return 0
		
# 	def __calc_price_from_distance(self, dist: float) -> int:
# 		if 0.0 < dist <= 1052:
# 			return 410
# 		elif 1052 < dist <= 1289:
# 			return 490
# 		elif 1289 < dist <= 1526:
# 			return 570
# 		else:
# 			return 1000

from sample01.sample import InputValueError 
import sys

def main(argv):
	print(argv)
	
	# a = []
	# for i in range(4):
	# 	a.append(input())
	# input_service = InputService(a)
	# calculator = Calculator(input_service.initial_data, input_service.datas)
	# ans = calculator.calc_low_speed_price() + calculator.calc_run_dist_price()
	# print(ans)

if __name__ == '__main__':
	main(sys.argv[1:])
