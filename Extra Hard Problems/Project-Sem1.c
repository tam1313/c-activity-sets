#include <stdio.h>
#include <stdbool.h>
// Define our global pool of memory (10,000 bytes)
unsigned char memory[10000];
// Metadata Structure representing a block header
typedef struct Block {
    int size;           // Size of the data payload (in bytes)
    bool is_free;       // true if available, false if currently in use
    struct Block *next; // Pointer to the next block in memory
} Block;
// Global pointer to the start of our heap metadata list
Block *free_list = NULL;
// Initialization function to set up the very first block covering the whole array
void init_heap() {
    free_list = (Block *)memory;
    free_list->size = sizeof(memory) - sizeof(Block);
    free_list->is_free = true;
    free_list->next = NULL;
}
// Custom my_malloc using First-Fit with Block Splitting
void *my_malloc(int no_of_bytes) {
    // Initialize heap if it hasn't been yet
    if (free_list == NULL) {
        init_heap();
    }
    Block *current = free_list;
    // Traverse the memory blocks to find the first free block that is big enough
    while (current != NULL) {
        if (current->is_free && current->size >= no_of_bytes) {
            // Check if the block is big enough to split into two:
            // (Requested bytes + space needed for a new Block header)
            if (current->size > no_of_bytes + (int)sizeof(Block)) {
                // Calculate the address for the new remaining block
                Block *next_block = (Block *)((unsigned char *)(current + 1) + no_of_bytes);
                // Configure the new remaining block
                next_block->size = current->size - no_of_bytes - (int)sizeof(Block);
                next_block->is_free = true;
                next_block->next = current->next;
                // Shrink the current block to fit only the requested bytes
                current->size = no_of_bytes;
                current->next = next_block;
            }
            // Mark the chosen block as used
            current->is_free = false;
            // Return the memory address *after* the Block metadata structure
            return (void *)(current + 1);
        }
        current = current->next;
    }
    // If no suitable block was found
    printf("Out of memory!\n");
    return NULL;
}
// Helper function to merge adjacent free blocks (Coalescing)
void coalesce() {
    Block *current = free_list;
    while (current != NULL && current->next != NULL) {
        // If both the current block and the next block are free, merge them
        if (current->is_free && current->next->is_free) {
            current->size += sizeof(Block) + current->next->size;
            current->next = current->next->next; // Skip over the absorbed block
        } else {
            current = current->next;
        }
    }
}
// Custom my_free function
void my_free(void *ptr) {
    if (ptr == NULL) return;
    // The user pointer points right after the Block metadata. 
    // Subtract 1 (pointer arithmetic based on Block size) to get the metadata header.
    Block *block_to_free = (Block *)ptr - 1;
    // Mark it as free
    block_to_free->is_free = true;
    // Merge adjacent free blocks to keep the heap clean
    coalesce();
}
int main() {
    char choice;
    int bytes;
    int index;
    // Track up to 100 pointers for easy testing in the console
    void *allocated_ptrs[100] = {NULL}; 
    printf("=== Custom Memory Allocator Interactive Console ===\n");
    printf("Memory Pool Size: 10,000 bytes\n\n");
    while (1) {
        printf("\nChoose an option:\n");
        printf("  [m] Allocate memory (malloc)\n");
        printf("  [f] Free memory\n");
        printf("  [q] Quit\n");
        printf("Enter choice: ");
        if (scanf(" %c", &choice) != 1) break;
        if (choice == 'm' || choice == 'M') {
            printf("Enter number of bytes to allocate: ");
            if (scanf("%d", &bytes) != 1 || bytes <= 0) {
                printf("Invalid byte size.\n");
                continue;
            }
            void *ptr = my_malloc(bytes);
            if (ptr != NULL) {
                // Calculate offset from the start of the memory array for easy reading
                int offset = (int)((unsigned char *)ptr - memory);
                printf("SUCCESS: Allocated %d bytes at offset index: %d\n", bytes, offset);
                // Save it in our tracking array so the user can free it later by slot number
                for (int i = 0; i < 100; i++) {
                    if (allocated_ptrs[i] == NULL) {
                        allocated_ptrs[i] = ptr;
                        printf("Stored in slot [%d]\n", i);
                        break;
                    }
                }
            }
        } 
        else if (choice == 'f' || choice == 'F') {
            printf("Enter the slot index (0 to 99) of the memory to free: ");
            if (scanf("%d", &index) != 1 || index < 0 || index >= 100) {
                printf("Invalid slot index. Choose between 0 and 99.\n");
                continue;
            }
            if (allocated_ptrs[index] != NULL) {
                my_free(allocated_ptrs[index]);
                printf("SUCCESS: Freed memory at slot [%d]\n", index);
                allocated_ptrs[index] = NULL; // Clear slot reference
            } else {
                printf("Slot [%d] is already empty or was never allocated.\n", index);
            }
        } 
        else if (choice == 'q' || choice == 'Q') {
            printf("Exiting allocator console.\n");
            break;
        } 
        else {
            printf("Unknown option. Please try again.\n");
        }
    }
    return 0;
}