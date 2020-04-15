#!/usr/bin/python3

import matplotlib.pyplot as plt
import numpy as np
import math

def cost_n(x):
    return x

def cost_logn(x):
    return math.log10(x)/math.log10(2)

x, y, e = np.loadtxt('data.csv', delimiter=';', unpack=True)
plt.errorbar(x, y, e, linestyle='None', marker='None', label='Error')
plt.plot(x,y, label='Media linked')

#x, y, e = np.loadtxt('data_skip.csv', delimiter=';', unpack=True)
#plt.errorbar(x, y, e, linestyle='None', marker='None', label='Error')
#plt.plot(x,y, label='Media skip')

y_log = x.copy()
i=0

for items in x:
    y_log[i] = cost_n(x[i])
    i=i+1

plt.plot(x, y_log, label='Log')

plt.xlabel('Cantidad de numeros')
plt.xticks(np.arange(0, 50001, 5000))
plt.ylabel('Coste de busqueda')
plt.title('Grafico de costes de lista skip')
plt.legend(loc='upper left')
plt.show()
