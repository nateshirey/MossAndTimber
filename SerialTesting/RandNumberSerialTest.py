import time
import serial
import random

ser = serial.Serial( port = '/dev/',
                     baudrate = 9600,
                     parity = serial.PARITY_NONE,
                     stopbits = serial.STOPBITS_ONE,
                     bytesize = serial.EIGHTBITS,
                     timeout = 1)

while True:
    n = random.randint(1, 9)
    print("Writing", n)
    ser.write(n)
    time.sleep(1)
    feedback = ser.read()
    print(feedback)
