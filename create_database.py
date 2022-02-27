import sqlite3

database = 'optical_sensor_database'
table = 'detector_data'

conn = sqlite3.connect(database+'.db')
curs = conn.cursor()

curs.execute("""CREATE TABLE {} (tdate DATE, ttime TIME, sen_val NUMERIC, s_count NUMERIC);""".format(table))
