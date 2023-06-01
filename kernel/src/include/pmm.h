/*
 * pmm.h - A simple Physical Memory Manager
 * Author(s) - KapPetrov
 */

#ifndef PMM_H
#define PMM_H

#include <stdint.h>

typedef uint32_t PMM_PHYSICAL_ADDRESS;

#define PMM_BLOCK_SIZE      4096
#define NULL                0

typedef struct {

    uint32_t memorySize;
    uint32_t maxBlocks;
    uint32_t *memoryMapArray;
    uint32_t memoryMapEnd;
    uint32_t usedBlocks;

} PmmInfo;

uint32_t PmmMaxBlocks();
uint32_t PmmGetUsedBlocks();

/**
 * returns index of bitmap array if no of bits(size) are free
 */

int PmmNextFreeFrame(int size);

/**
 * initialize memory bitmap array by making blocks from total memory size
 * 
 */

void PmmInit(PMM_PHYSICAL_ADDRESS bitmap, uint32_t totalMemorySize);
/**
 * initialize/request for a free region of region_size from pmm
 */
void PmmInitRegion(PMM_PHYSICAL_ADDRESS base, uint32_t regionSize);

/**
 * de-initialize/free allocated region of region_size from pmm
 */

void PmmDeInitRegion(PMM_PHYSICAL_ADDRESS base, uint32_t regionSize);

/**
 * request to allocate a single block of memory from pmm
 */

void* PmmAllocBlock();

/**
 * free given requested single block of memory from pmm
 */

void PmmFreeBlock(void* p);

/**
 * request to allocate no of blocks of memory from pmm
 */

void* PmmAllocBlocks(uint32_t size);

/**
 * free given requested no of blocks of memory from pmm
 */

void PmmFreeBlocks(void* p, uint32_t size);

#endif