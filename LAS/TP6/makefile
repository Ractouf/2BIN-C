CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all: radar dashboard

radar: radar.o utils_v2.o
	cc $(CFLAGS) -o radar radar.o utils_v2.o

radar.o: radar.c utils_v2.h
	cc $(CFLAGS) -c radar.c


dashboard: dashboard.o utils_v2.o
	cc $(CFLAGS) -o dashboard dashboard.o utils_v2.o

dashboard.o: dashboard.c utils_v2.h
	cc $(CFLAGS) -c dashboard.c


utils_v2.o: utils_v2.c utils_v2.h
	cc $(CFLAGS) -c utils_v2.c

clean:
	rm *.o
	rm dashboard
	rm radar
