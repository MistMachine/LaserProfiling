import sqlite3
import numpy as np
database = 'optical_sensor_database'
table = 'detector_data'
conn = sqlite3.connect(database+'.db')
curs = conn.cursor()

data = curs.execute(""" SELECT * FROM {};""".format(table))

data_table = []

for line in data:
    data_table.append(line)

data = np.array(data_table)
