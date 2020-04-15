#!/usr/bin/python3

import matplotlib.pyplot as plt
import numpy as np

##x, y, e = np.loadtxt('data.csv', delimiter=';', unpack=True)

##plt.errorbar(x, y, e, linestyle='None', marker='None', label='Error')
#plt.plot(x,y, label='Media')

x, y, e = np.loadtxt('data_skip.csv', delimiter=';', unpack=True)

plt.errorbar(x, y, e, linestyle='None', marker='None', label='Error')
plt.plot(x,y, label='Media')

plt.xlabel('Cantidad de numeros')
plt.xticks(np.arange(0, 50001, 5000))
plt.ylabel('Coste de busqueda')
plt.title('Grafico de costes de lista linkada')
plt.legend(loc='upper left')
plt.show()
