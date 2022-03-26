import serial

ser = serial.Serial()
ser.port = '/dev/ttyAMA0'
ser.baudrate = 115200
ser.timeout = 60
ser.open()

TXSize = 50
RXSize = 50
msgReceived = ''

msgSent = input("Write: ")
for i in range(len(msgSent), TXSize):
        msgSent += '.'
ser.write(msgSent.encode())
while True:
        msgReceived = ser.read(RXSize)
        try:
                msgReceived.decode()
                print (msgReceived)
        except (UnicodeDecodeError, AttributeError):
                print("error")
                pass
        if msgReceived == b'\r':
                break
        msgReceived = ''

