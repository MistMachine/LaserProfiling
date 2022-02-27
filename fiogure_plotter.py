import matplotlib.pyplot as plt
fig = plt.figure()
ax = fig.add_subplot(111)
laser_plot = ax.plot(s_count, sen_vals, label = 'Laser Profile')
laser_plot.set_title('Laser Profile')
ax.set_xlabel('Step Counts')
ax.set_ylabel('Sensor Value')
ax.set_title('Laser Profile')
plt.show()
