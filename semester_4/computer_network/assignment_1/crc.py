def xor(a, b):
	result = []
	for i in range(1, len(b)):
		if a[i] == b[i]:
			result.append('0')
		else:
			result.append('1')

	return ''.join(result)


def mod2div(dividend, divisor):
	pick = len(divisor)
	tmp = dividend[0: pick]
	while pick < len(dividend):
		if tmp[0] == '1':
			tmp = xor(divisor, tmp) + dividend[pick]
		else:
			tmp = xor('0'*pick, tmp) + dividend[pick]
		pick += 1
	if tmp[0] == '1':
		tmp = xor(divisor, tmp)
	else:
		tmp = xor('0'*pick, tmp)
	checkword = tmp
	return checkword



def encodeData(data, key):
	l_key = len(key)
	appended_data = data + '0'*(l_key-1)
	remainder = mod2div(appended_data, key)
	codeword = data + remainder
	return codeword,remainder

def decodeData(data,key):
	remainder = mod2div(data, key)
	int_remainder = int(remainder)
	if int_remainder == 0:
		print("message recieved, no errors")
	else:
		print("remainder not equal to 0, some error during transmission")

data = "100100"
key = "1101"
codeword,remainder = encodeData(data, key)
print("the remainder added to the end is: ",remainder)
print("The encoded data is: ",codeword)
decodeData(codeword,key)