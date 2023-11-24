CC	= g++

all : zuul.exe
	./zuul.exe

zuul.exe : zuul.cpp
	$(CC) -o $@ $<

clean:
	rm -f *.exe *~
