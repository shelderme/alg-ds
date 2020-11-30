#pragma once

#define ALL_IS_OK 0
#define KEY 777
#define NULL_MEM 2
#define TOO_SMALL_SIZE 3


typedef struct NodeHeader {
    int size;
    int num; // for checking validness of pointer
    struct NodeHeader* next;
} nodeHeader_t;

typedef struct NodeEnder {
    int size;
} nodeEnder_t;

nodeHeader_t* theFirst;
    // Init memory system with memory block pMemory.
    int meminit(void* pMemory, int size);

    // You can implement memory leak checks here
    void memdone();

    // Allocate memory block of size 'size'.
    // Returns pointer to memory block is success, 0 otherwise
    void* memalloc(int size);

    // Free memory previously allocated by memalloc
    void memfree(void* p);

    // Return minimum size in bytes of the memory pool to allocate 0-bytes block
    // use case:
    // void *p   = 0;
    // void *ptr = malloc(memgetminimumsize() + 1);
    // meminit(ptr, memgetminimumsize() + 1)
    // p = memalloc(1); // Success!
    // memfree(p);
    // memdone();
    // free(ptr);
    int memgetminimumsize();


    // Returns size in bytes of additional information per allocation
    // use case:
    // void *p1 = 0, *p2 = 0;
    // int  memsize = memgetminimumsize() + memgetblocksize() + 2;
    // void *ptr = malloc(memsize);
    // meminit(ptr, memsize())
    // p1 = memalloc(1); // Success!
    // p2 = memalloc(1); // Success!
    // memfree(p2);
    // memfree(p1);
    // memdone();
    // free(ptr);
    int memgetblocksize();


