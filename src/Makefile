CC = g++
CFLAGS = -O2 -Wall --std=c++11
PYTHON = python2
TESTS_CORRECTITUD = 100
MUESTRAS = 30


problema1: kaioken1.cpp
	$(CC) $(CFLAGS) kaioken1.cpp -o problema1

problema2: genkidama2.cpp
	$(CC) $(CFLAGS) genkidama2.cpp -o problema2

problema3: kamehameha3.cpp Tablero.h
	$(CC) $(CFLAGS) kamehameha3.cpp -o problema3

test1: problema1
	./test-correctitud.sh KaioKenTester.jar ./problema1 $(TESTS_CORRECTITUD)

test2: problema2
	./test-correctitud.sh GenkidamaTester.jar ./problema2 $(TESTS_CORRECTITUD)

test3: problema3
	./test-correctitud.sh KamehamehaTester.jar ./problema3 $(TESTS_CORRECTITUD)
	
test: test1 test2 test3

tiempos1: CFLAGS += -DTOMAR_TIEMPO
tiempos1: problema1 tiempos.py
	$(PYTHON) tiempos.py 1 500 10000 $(MUESTRAS)

tiempos2: CFLAGS += -DTOMAR_TIEMPO
tiempos2: problema2 tiempos.py
	$(PYTHON) tiempos.py 2 400 5000 $(MUESTRAS)

tiempos3: CFLAGS += -DTOMAR_TIEMPO
tiempos3: problema3 tiempos.py
	$(PYTHON) tiempos.py 3 1 10 $(MUESTRAS)


clean:
	rm -rf problema1 problema2 problema3


	
