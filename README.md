# Interprocess-Communication

## Interprocess Communication (IPC) Programs

This repository contains three programs showcasing different Interprocess Communication mechanisms in C:

1. **Unix Domain Sockets**
2. **FIFO (First In, First Out)**
3. **Shared Memory**

### 1. Unix Domain Sockets

#### Files:
- **P2socket.c (P2)**
- **P1socket.c (P1)**

#### Usage:
To run, use the following commands in separate terminals:

```bash
./P2socket &
./P1socket
```

- The programs demonstrate IPC using Unix domain sockets.
- P1socket.c generates 50 random strings and sends them to P2socket.c using a socket.
- P2socket.c receives the strings, prints them, and sends back the string with the highest index.
- The process repeats until 50 strings are sent, and the programs close connections and unlink sockets.

### 2. FIFO (First In, First Out)

#### Files:
- **P2FIFO.c (P2)**
- **P1FIFO.c (P1)**

#### Usage:
To run, use the following commands in separate terminals:

```bash
./P2FIFO &
./P1FIFO
```

- This program uses FIFOs for communication.
- P1FIFO.c creates two FIFOs for bidirectional communication between client and server.
- Strings are sent in batches of 5, and sleep() is used to prevent misreading.
- Two FIFOs are used - one for client to server communication and one for server to client.

### 3. Shared Memory

#### Files:
- **LMsender.c**
- **LMreceiver.c**

#### Usage:
To run, use the following commands in separate terminals:

```bash
./LMreceiver &
./LMsender
```

- This program uses shared memory for communication.
- LMsender.c opens shared memory in read-write mode and writes the first 5 strings.
- LMreceiver.c receives the data, sends a confirmation to LMsender.c, and repeats until all strings are sent.
- Slight synchronization issues are noted, which can be addressed with semaphores, mutexes, or strategic use of sleep().

### Note:

- For Unix Domain Sockets, run P2socket first and then P1socket.
- For FIFO, run P1FIFO first and then P2FIFO.
- For Shared Memory, run LMreceiver first and then LMsender.

**Enjoy exploring interprocess communication mechanisms!**
