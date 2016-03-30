"""
parametros:
    problema
    granularidad
    ultimo
    cantidad_muestras
"""
import random
import sys
import os
import subprocess

import matplotlib.pyplot as plt
import numpy as np
import math

archivo = "data.in"

problema = int(sys.argv[1])
granularidad = int(sys.argv[2])
ultimo = int(sys.argv[3])
cantidad_muestras = int(sys.argv[4])


def generar1(tamanio_muestra):
    f = open(archivo, "w")
    f.write(str(tamanio_muestra))

def generar2(tamanio_muestra):
    f = open(archivo, "w")
    n = tamanio_muestra
    MAXIMO_T = n
    MAXIMA_COORD = n*n
    f.write(str(n) + " " + str(random.randint(1, MAXIMO_T)) + "\n")
    xs = random.sample(range(MAXIMA_COORD), n)
    ys = random.sample(range(MAXIMA_COORD), n)
    xs.sort(reverse = True)
    ys.sort()
    for x, y in zip(xs, ys):
        f.write(str(x) + " " + str(y) + "\n")


def generar3(tamanio_muestra):
    f = open(archivo, "w")
    n = tamanio_muestra
    MAXIMO_T = n
    MAXIMA_COORD = 2 * n
    f.write(str(n) + "\n")
    xs = random.sample(range(MAXIMA_COORD), n)
    ys = random.sample(range(MAXIMA_COORD), n)
    for x, y in zip(xs, ys):
        f.write(str(x) + " " + str(y) + "\n")

def correr_programa(binario):
    p = subprocess.Popen("cat " + archivo + " | " + binario,
                         shell = True,
                         stderr=subprocess.PIPE, stdout=subprocess.PIPE)
    out, err = p.communicate()
    return 1000 * float(err)

def mean(xs):
    if len(xs) == 0:
        return 0.0
    else:
        suma = 0.0
        for x in xs:
            suma += x
        return suma / len(xs)

def median(xs):
    xs.sort()
    return xs[len(xs) / 2]

binarios = ["", "./problema1", "./problema2", "./problema3"]

def encontrar_k(problema, puntos):
    ks = []
    puntos = puntos[1:]

    for n, tiempo in puntos:
        if problema == 1:
            ks.append(tiempo / (n * math.log(n)))
        elif problema == 2:
            ks.append(tiempo / n)
        elif problema == 3:
            ks.append(tiempo / n**(n+2))
    return mean(ks)


def main():
    datos = []
    posiciones = []
    for tamanio_muestra in range(0, ultimo, granularidad):
        if tamanio_muestra == 0: tamanio_muestra = 1
        posiciones.append(float(tamanio_muestra))
        tiempos = []
        for seed in range(cantidad_muestras):
            random.seed(seed)
            if problema == 1:
                generar1(tamanio_muestra)
                tiempos.append(correr_programa(binarios[problema]))
            elif problema == 2:
                generar2(tamanio_muestra)
                tiempos.append(correr_programa(binarios[problema]))
            elif problema == 3:
                generar3(tamanio_muestra)
                tiempos.append(correr_programa(binarios[problema]))
        datos.append(tiempos)
    plt.figure()
    puntos = zip(map(float, posiciones), map(median, datos))
    k = encontrar_k(problema, puntos)
    fit = []
    if problema == 1:
        fit = map(lambda n: k * n * math.log(n), posiciones)
    elif problema == 2:
        fit = map(lambda n: k * n, posiciones)
    elif problema == 3:
        fit = map(lambda n: k * n**(n+2), posiciones)
    print [x[1] for x in puntos]
    print fit
    plt.plot(posiciones, fit)
    plt.boxplot(datos, positions=posiciones, widths=granularidad/2.0,
                showfliers=False)
    plt.show()


main()
os.remove(archivo)


