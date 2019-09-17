import matplotlib.pyplot as plt
import csv

x = []
y = []

with open('out.csv', 'r') as csvfile:
    data = csv.reader(csvfile, delimiter=',')
    for row in data:
        x.append(int(row[0]))
        y.append(int(row[1]))

plt.plot(x, y)
plt.show();
