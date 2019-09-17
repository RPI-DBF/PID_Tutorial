import matplotlib.pyplot as plt
import csv

x = []
y = []

with open('out.csv', 'r') as csvfile:
    data = csv.reader(csvfile, delimiter=',')
    for row in data:
        x.append(float(row[0]))
        y.append(float(row[1]))

plt.plot(x, y)
plt.show();
