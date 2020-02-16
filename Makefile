CC=g++
LIBS=-lm

DB: database.o dbdriver.o DbHeader.h
	$(CC) *.o DbHeader.h -o DB $(LIBS)

database.o: Database.cpp
	$(CC) Database.cpp -c

dbdriver.o: DbDriver.cpp
	$(CC) DbDriver.cpp -c
