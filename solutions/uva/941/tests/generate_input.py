def main():
	n = 10000
	print n

	word = 'a'

	char_num = ord('a')

	counter = 0

	def fact(n):
		if n < 2:
			return 1
		else:
			return n * fact(n-1)

	while True:
		char_num += 1
		if chr(char_num) == 'z':
			word = 'a'
			char_num = ord('a')
			continue

		word += chr(char_num)
		for x in xrange(0, fact(len(word))):
			print word
			print x
			counter += 1
			if counter == n:
				return 0

if __name__ == '__main__':
	main()