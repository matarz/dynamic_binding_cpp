CPPFLAGS=-g

all: main.o n73.o iphone.o hash_table.o droid.o device_ABC.o
	g++ $(CPPFLAGS) -o a.out main.o n73.o iphone.o hash_table.o droid.o device_ABC.o

main.o: main.cpp
	g++ $(CPPFLAGS) -c main.cpp

n73.o: n73.h n73.cpp
	g++ $(CPPFLAGS) -c n73.cpp

iphone.o: iphone.h iphone.cpp
	g++ $(CPPFLAGS) -c iphone.cpp

hash_table.o: hash_table.h hash_table.cpp
	g++ $(CPPFLAGS) -c hash_table.cpp

droid.o: droid.h droid.cpp
	g++ $(CPPFLAGS) -c droid.cpp

device_ABC.o: device_ABC.h device_ABC.cpp
	g++ $(CPPFLAGS) -c device_ABC.cpp

clean:
	rm -f *.o core p

