import matplotlib.pyplot as plt
import numpy as np

n = int(input())
ns = np.zeros(n)
times = np.zeros(n)

# read file
for i in range(n):
	temp = input().split()
	ns[i] = float(temp[0])
	times[i] = float(temp[1])
	
# plot
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
ax.plot(ns, times, label="experiment result")
ax.set_title('Time to calclate matrix product')
ax.set_xlabel("N (size of matrix)")
ax.set_ylabel("Time [s]")
plt.legend()
fig.savefig("hw1.png")

# add fitting 
fitting = np.polyfit(ns,times,3)
print(fitting)
fittime = fitting[0]*ns**3 +  fitting[1]*ns**2 + fitting[2]*ns + + fitting[3]
ax.plot(ns,fittime, label = "fitting result (3rd order)")
plt.legend()
plt.show()
fig.savefig("hw1_fit.png")