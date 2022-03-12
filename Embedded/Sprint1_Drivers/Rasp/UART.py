import serial

ser = serial.Serial()
ser.port = '/dev/ttyAMA0'
ser.baudrate = 115200
ser.timeout = 60
ser.open()

msg = ''
while True:
        ser.write("A".encode())
        char = ser.read(1)
        try:
                char = char.decode()
                msg = msg + char
                print (msg)
        except (UnicodeDecodeError, AttributeError):
                pass
        if char == b'\r':
                break
