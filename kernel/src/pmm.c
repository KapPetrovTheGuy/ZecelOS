/*
 * pmm.c - A simple Physical Memory Manager
 * Author(s) - KapPetrov
 */

#include <pmm.h>
#include <c/string.h>
#include <console.h>

static PmmInfo g_pmm_info;

// set bit in memory map array

static inline void PmmMMapSet(int bit)
{
    g_pmm_info.memoryMapArray[bit / 32] |= (1 << (bit % 32));
}

// unset bit in memory map array

static inline void PmmMMapUnset(int bit)
{
    g_pmm_info.memoryMapArray[bit / 32] &= ~(1 << (bit % 32));
}

// test if given nth is set

// static inline char PmmMMapTest(int bit) {
//     return g_pmm_info.memoryMapArray[bit / 32] & (1 << (bit % 32));
// }

uint32_t PmmGetMaxBlocks() {
    return g_pmm_info.maxBlocks;
}

uint32_t PmmGetUsedBlocks() {
    return g_pmm_info.usedBlocks;
}

// find first free frame in bitmap array and return its index
int PmmMMapFirstFree() {
    uint32_t i, j;

    // find the first free bit
    for(i = 0; i < g_pmm_info.maxBlocks; i++)
    {
        if(g_pmm_info.memoryMapArray[i] != 0xffffffff) {
            // check each bit, if not set
            for (j = 0; j < 32; j++) {
                int bit = 1 << j;
                if (!(g_pmm_info.memoryMapArray[i] & bit))
                    return i * 32 + j;
            }
        }
    }
    return -1;
}

int PmmMMapFirstFreeBySize(uint32_t size)
{
    uint32_t i, j, k, free = 0;
    int bit;

    if (size == 0)
        return -1;

    // if size is 1, return first free
    if (size == 1)
        return PmmMMapFirstFree();

    for (i = 0; i < g_pmm_info.maxBlocks; i++) {
        if (g_pmm_info.memoryMapArray[i] != 0xffffffff) {
            // check each bit, if not set
            for (j = 0; j < 32; j++) {
                bit = 1 << j;
                if (!(g_pmm_info.memoryMapArray[i] & bit)) {
                    // check no of bits(size) are free or not?
                    for (k = j; k < 32; k++) {
                        bit = 1 << k;
                        if (!(g_pmm_info.memoryMapArray[i] & bit))
                            free++;
                        
                        if (free == size)
                            return i * 32 + j;
                    }
                }
            }
        }
    }
    return -1;
}

int PmmNextFreeFrane(int size) {
    return PmmMMapFirstFreeBySize(size);
}

void PmmInit(PMM_PHYSICAL_ADDRESS bitmap, uint32_t totalMemorySize)
{
    g_pmm_info.memorySize = totalMemorySize;
    g_pmm_info.memoryMapArray = (uint32_t *)bitmap;
    // Remember - memory_size is in bytes
    g_pmm_info.maxBlocks = totalMemorySize / PMM_BLOCK_SIZE;
    g_pmm_info.usedBlocks = g_pmm_info.maxBlocks;
    // set all of memory is in use
    MemSet(g_pmm_info.memoryMapArray, 0xff, g_pmm_info.maxBlocks * sizeof(uint32_t));
    // ending address of map array for staring point of regions
    g_pmm_info.memoryMapArray = (uint32_t *)&g_pmm_info.memoryMapArray[g_pmm_info.maxBlocks];
}

void PmmInitRegion(PMM_PHYSICAL_ADDRESS base, uint32_t regionSize)
{
    int align = base / PMM_BLOCK_SIZE;
    int blocks = regionSize / PMM_BLOCK_SIZE;

    // make free the blocks associated with given address base to mark that region as free
    while (blocks >= 0) {
        // unset bit to make it free
        PmmMMapUnset(align++);
        // reduce used blocks count
        g_pmm_info.usedBlocks--;
        blocks--;
    }
}

void PmmDeInitRegion(PMM_PHYSICAL_ADDRESS base, uint32_t regionSize)
{
    int align = base / PMM_BLOCK_SIZE;
    int blocks = regionSize / PMM_BLOCK_SIZE;

    while (blocks >= 0) {
        // set block bit
        PmmMMapSet(align++);
        // increase used blocks count
        g_pmm_info.usedBlocks++;
        blocks--;
    }
}

void* PmmAllocBlock()
{
    // out of memory
    if ((g_pmm_info.maxBlocks - g_pmm_info.usedBlocks) <= 0)
        return NULL;

    int frame = PmmMMapFirstFree();
    if (frame == -1)
        return NULL;

    PmmMMapSet(frame);

    // get actual address by skipping memory map
    PMM_PHYSICAL_ADDRESS addr = *((frame * PMM_BLOCK_SIZE) + g_pmm_info.memoryMapArray);
    g_pmm_info.usedBlocks++;

    return (void *)addr;
}

void PmmFreeBlock(void* p)
{
    PMM_PHYSICAL_ADDRESS addr = (PMM_PHYSICAL_ADDRESS)p;
    // go to the bitmap array address
    addr -= g_pmm_info.memoryMapEnd;
    int frame = addr / PMM_BLOCK_SIZE;
    PmmMMapUnset(frame);
    g_pmm_info.usedBlocks--;
}

void* PmmAllocBlocks(uint32_t size)
{
    uint32_t i;

    // out of memory
    if ((g_pmm_info.maxBlocks - g_pmm_info.usedBlocks) <= size)
        return NULL;

    int frame = PmmMMapFirstFreeBySize(size);
    if (frame == -1)
        return NULL;

    // set bits in memory map
    for (i = 0; i < size; i++)
        PmmMMapSet(frame + i);

    PMM_PHYSICAL_ADDRESS addr = (frame * PMM_BLOCK_SIZE) + g_pmm_info.memoryMapEnd;
    g_pmm_info.usedBlocks += size;

    return (void *)addr;
}

void PmmFreeBlocks(void* p, uint32_t size)
{
    uint32_t i;

    PMM_PHYSICAL_ADDRESS addr = (PMM_PHYSICAL_ADDRESS)p;
    // go to the bitmap array address
    addr -= g_pmm_info.memoryMapEnd;
    int frame = addr / PMM_BLOCK_SIZE;
    for (i = 0; i < size; i++)
        PmmMMapUnset(frame + i);
    g_pmm_info.usedBlocks -= size;
}