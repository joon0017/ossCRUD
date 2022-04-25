CC = gcc
CFLAGS = -c -Wall
LFLAGS = -Wall
market: manager.o product.o market.c
	$(CC) $(LFLAGS) -o market market.c manager.c product.c
product.o: product.c product.h
	$(CC) $(CFLAGS) product.c
manager.o: manager.c manager.h
	$(CC) $(CFLAGS) manager.c
clean:
	rm -f *.o market
