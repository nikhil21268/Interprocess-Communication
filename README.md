# Interprocess-Communication | Operating Systems Assignment 
Created Processes which communicate with each other using Unix Domain Sockets, FIFOs and Shared Memory. 

## Interprocess Communication (IPC) Programs

This repository contains implementations of the problem statement titled "Interprocess Communication." The goal is to exchange information between two programs, P1 and P2, using three different IPC mechanisms: Unix domain sockets, FIFOs, and shared memory.

### Problem Statement Overview

The problem statement requires the following functionalities:

1. **P1 Program:**
   - Generate an array of 50 random strings.
   - Send groups of five consecutive elements of the array to P2 with corresponding IDs (indices).
   - Receive acknowledgment from P2 containing the highest ID received.
   - Send the next batch of strings, starting from the successor of the acknowledged ID.

2. **P2 Program:**
   - Accept received strings and print their IDs and content.
   - Send back the highest ID received to acknowledge the strings.

This repository contains three programs showcasing different Interprocess Communication mechanisms in C:

1. **Unix Domain Sockets**
2. **FIFO (First In, First Out)**
3. **Shared Memory**

### Implementation Details

#### 1. Unix Domain Sockets

- **P1 Program (P1socket.c):**
  - Generates and sends strings using Unix domain sockets.

- **P2 Program (P2socket.c):**
  - Accepts strings, prints IDs and content.
  - Sends back the highest received ID.

#### 2. FIFOs

- **P1 Program (P1FIFO.c):**
  - Generates and sends strings using FIFOs.

- **P2 Program (P2FIFO.c):**
  - Accepts strings, prints IDs and content.
  - Sends back the highest received ID.

#### 3. Shared Memory

- **P1 Program (LMsender.c):**
  - Generates and sends strings using shared memory.

- **P2 Program (LMreceiver.c):**
  - Accepts strings, prints IDs and content.
  - Sends back the highest received ID.

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

### Compilation

A Makefile is provided to compile all source files:

```bash
make all
```

### Time Measurement

The programs output the time required to finish receiving the acknowledgment of all 50 strings in each case.

**Enjoy exploring interprocess communication mechanisms!**
