CC = g++
CFLAGS = -O2 -Wall --std=c++11
TESTS = 100


problema1: kaioken1.cpp
	$(CC) $(CFLAGS) kaioken1.cpp -o problema1

problema2: genkidama2.cpp
	$(CC) $(CFLAGS) genkidama2.cpp -o problema2

problema3: kamehameha3.cpp Tablero.h
	$(CC) $(CFLAGS) kamehameha3.cpp -o problema3

test1: problema1
	./test-correctitud.sh KaioKenTester.jar ./problema1 $(TESTS)

test2: problema2
	./test-correctitud.sh GenkidamaTester.jar ./problema2 $(TESTS)

test3: problema3
	./test-correctitud.sh KamehamehaTester.jar ./problema3 $(TESTS)
	
test: test1 test2 test3

clean:
	rm -rf problema1 problema2 problema3

	
