#pragma once
#include "Typedefs.h"
#include "Memory.h"

struct MemorySegmentHeader{
    uint64 MemoryLength;
    MemorySegmentHeader* NextSegment;
    MemorySegmentHeader* PreviousSegment;
    MemorySegmentHeader* NextFreeSegment;
    MemorySegmentHeader* PreviousFreeSegment;
    bool Free;
};

struct AlignedMemorySegmentHeader{
    uint64 MemorySegmentHeader : 63;
    bool IsAligned : 1;
};

/**
 * @brief 
 * 
 * @param heapAddress 
 * @param heapLength 
 */
void InitializeHeap(uint64 heapAddress, uint64 heapLength);

/**
 * @brief 
 * 
 * @param size 
 * @return void* 
 */
void* calloc(uint64 size);

/**
 * @brief 
 * 
 * @param size 
 * @return void* 
 */
void* malloc(uint64 size);

/**
 * @brief 
 * 
 * @param address 
 * @param newSize 
 * @return void* 
 */
void* realloc(void* address, uint64 newSize);

/**
 * @brief 
 * 
 * @param alignment 
 * @param size 
 * @return void* 
 */
void* aligned_alloc(uint64 alignment, uint64 size);

/**
 * @brief 
 * 
 * @param address 
 */
void free(void* address);