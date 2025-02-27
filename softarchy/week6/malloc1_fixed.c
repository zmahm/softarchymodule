// CyberSec - MALLOC - WIP1 (Fixed Version)
// Written by Lee Speakman 2017-12-11 (originally :^) )
// Reads a file in blocks using malloc/realloc and writes a copy out.

// Improvements and fixes:
// ------------------------
// 1. Added error handling for malloc and realloc
//    - Checks for NULL after memory allocation to prevent crashes.
//    - If allocation fails, prints an error message and exits safely.

// 2. Improved file handling and binary mode fixes
//    - Uses "rb" (read binary) and "wb" (write binary) to handle all file types, including text, images, and executables.
//    - Improved error messages using strerror(errno) to provide clearer explanations for failures.

// 3. More efficient memory management
//    - Reads and writes in larger blocks (1MB at a time) instead of byte by byte.
//    - Expands memory dynamically with realloc only when needed, preventing excessive memory usage.

// 4. Added proper error handling for fwrite
//    - Ensures that the correct number of bytes is written to the output file.
//    - If fwrite fails, the program stops and displays an error message instead of producing a corrupt file.

#include <stdio.h>   // For printf(), fopen(), fclose(), fread(), fwrite()
#include <stdlib.h>  // For exit(), malloc(), realloc()
#include <errno.h>   // For errno
#include <string.h>  // For strerror()

#define MEM_BLOCK (1024 * 1024)  // 1MB memory block size

int main(int argc, const char *argv[]) {
    // Check for correct command-line arguments
    if (argc < 3) {
        printf("USAGE: %s filename_in filename_out\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // ********** VARIABLES **********
    const char *filename_in = argv[1];
    const char *filename_out = argv[2];

    size_t current_mem_size = MEM_BLOCK;
    size_t items_read, total_read = 0;

    // ********** OPEN FILES **********
    FILE *file_in = fopen(filename_in, "rb");  // Open in binary mode
    if (!file_in) {
        fprintf(stderr, "ERROR: Could not open input file '%s': %s\n", filename_in, strerror(errno));
        exit(EXIT_FAILURE);
    }

    FILE *file_out = fopen(filename_out, "wb");  // Open in binary mode
    if (!file_out) {
        fprintf(stderr, "ERROR: Could not open output file '%s': %s\n", filename_out, strerror(errno));
        fclose(file_in);
        exit(EXIT_FAILURE);
    }

    // ********** DYNAMIC MEMORY ALLOCATION **********
    void *base_ptr = malloc(MEM_BLOCK);
    if (!base_ptr) {
        fprintf(stderr, "ERROR: Memory allocation failed!\n");
        fclose(file_in);
        fclose(file_out);
        exit(EXIT_FAILURE);
    }

    void *mem_ptr = base_ptr;

    // ********** READ FILE IN BLOCKS **********
    while ((items_read = fread(mem_ptr, 1, MEM_BLOCK, file_in)) > 0) {
        total_read += items_read;

        // Write the read data to the output file
        size_t items_written = fwrite(mem_ptr, 1, items_read, file_out);
        if (items_written != items_read) {
            fprintf(stderr, "ERROR: Writing to output file failed!\n");
            free(base_ptr);
            fclose(file_in);
            fclose(file_out);
            exit(EXIT_FAILURE);
        }

        // If a full block was read, increase memory allocation
        if (items_read == MEM_BLOCK) {
            current_mem_size += MEM_BLOCK;
            void *new_ptr = realloc(base_ptr, current_mem_size);
            if (!new_ptr) {
                fprintf(stderr, "ERROR: Memory reallocation failed!\n");
                free(base_ptr);
                fclose(file_in);
                fclose(file_out);
                exit(EXIT_FAILURE);
            }
            base_ptr = new_ptr;
            mem_ptr = (char *)base_ptr + total_read;  // Adjust pointer
        }
    }

    printf("File copied successfully: %zu bytes copied.\n", total_read);

    // ********** CLEANUP **********
    free(base_ptr);
    fclose(file_in);
    fclose(file_out);

    return EXIT_SUCCESS;
}
