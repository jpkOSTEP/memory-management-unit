#ifndef VM_H_INCLUDED
#define VM_H_INCLUDED
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <pthread.h>

//Assume the address space is 32 bits, so the max memory size is 4GB
//Page size is 4KB

#define PGSIZE 4096

// Maximum size of virtual memory
#define MAX_MEMSIZE 4ULL*1024*1024*1024

// Size of "physcial memory"
#define MEMSIZE 1024*1024*1024

// Represents a page table entry
typedef unsigned long pte_t;

// Represents a page directory entry
typedef unsigned long pde_t;

#define TLB_ENTRIES 512

typedef struct PartialNode
{
    unsigned long space_taken;
    unsigned long base_va;
    struct PartialNode* next;
}partial_node;

typedef struct AllocNode
{
    unsigned long offset_start;
    unsigned long offset_end;
    int free_status;
    struct AllocNode* next;
}alloc_node;

typedef struct TLB_Node{
	void *va;
    pte_t pa;
    struct TLB_Node* next;
} tlb_node;

//Structure to represents TLB
struct tlb {
    /*Assume your TLB is a direct mapped TLB with number of entries as TLB_ENTRIES
    * Think about the size of each TLB entry that performs virtual to physical
    * address translation.
    */
    struct TLB_Node* head;
	struct TLB_Node* tail;
    int length;
};
// struct tlb tlb_store;

struct alloc_list{
    struct AllocNode* head;
    struct AllocNode* tail;
};

struct partial_list{
    struct PartialNode* head;
    struct PartialNode* tail;
};


void set_physical_mem();
pte_t* translate(pde_t *pgdir, void *va);
int page_map(pde_t *pgdir, void *va, void* pa);
bool check_in_tlb(void *va);
void put_in_tlb(void *va, void *pa);
void *t_malloc(unsigned int num_bytes);
void t_free(void *va, int size);
void put_value(void *va, void *val, int size);
void get_value(void *va, void *val, int size);
void mat_mult(void *mat1, void *mat2, int size, void *answer);
void print_TLB_missrate();

#endif
