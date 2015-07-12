import matplotlib.pyplot as plt

m = [0] * 361

for attempted in range(0, 91):
    for correct in range(0, attempted+1):
        marks = correct*4 - (attempted-correct)
        if marks >= 0:
            m[marks] += 1

plt.xkcd()
plt.plot(m)
plt.title('JEE Mains')
plt.ylabel('No. of ways')
plt.xlabel('Marks')
plt.show()

