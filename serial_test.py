import serial

ser = serial.Serial("/dev/ttyACM0", 9600)

line = ser.readline()
line = line.decode().rstrip('\n').split(',')


