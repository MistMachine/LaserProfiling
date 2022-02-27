import serial
import sqlite3
import matplotlib.pyplot as plt

database = 'optical_sensor_database'
table = 'detector_data1'
conn = sqlite3.connect(database+'.db')
curs = conn.cursor()
curs.execute("""CREATE TABLE {} (tdate DATE, ttime TIME, sen_val NUMERIC, s_count NUMERIC);""".format(table))

ser = serial.Serial("/dev/ttyACM0", 9600)
i = 0
while i < 2000:
    i += 1
    if i  <5:
        continue
    else:
        line = ser.readline()
        line = line.decode().rstrip('\n').split(',')
        print('line = ', line)
        sen_val = line[0]
        c_step = line[1]
        curs.execute("""INSERT INTO {} values(date('now'), time('now'), (?),(?))""".format(table), (sen_val,c_step))
        conn.commit()

data = curs.execute(""" SELECT * FROM {};""".format(table))

data_table = []

for line in data:
    data_table.append(line)

data = np.array(data_table)

plt.plot(s_count, sen_vals)
plt.show()
## red white green blue
