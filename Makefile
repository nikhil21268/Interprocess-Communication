all: P1FIFO P2FIFO P1socket P2socket P1sharedMem P2sharedMem

P1FIFO: P1FIFO.c
	gcc P1FIFO.c -o P1FIFO

P2FIFO: P2FIFO.c
	gcc P2FIFO.c -o P2FIFO

P1socket: P1socket.c
	gcc P1socket.c -o P1socket

P2socket: P2socket.c
	gcc P2socket.c -o P2socket

P1sharedMem: P1sharedMem.c
	gcc P1sharedMem.c -o P1sharedMem

P2sharedMem: P2sharedMem.c
	gcc P2sharedMem.c -o P2sharedMem

clean: 
	rm P1FIFO P2FIFO P1socket P2socket P1sharedMem P2sharedMem