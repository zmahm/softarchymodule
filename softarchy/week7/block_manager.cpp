#include <iostream>
#include <fstream>
#include <cstdlib>  // For malloc(), realloc(), free()
#include <cstring>  // For memcpy()
#include <stdexcept> // For std::bad_alloc

#define BLOCK_SIZE 4096  // Define block size (4KB)

class BlockManager {
public:
    // Constructor: Allocate initial block
    BlockManager() : data_ptr(nullptr), allocated_size(0), data_size(0) {
        allocate(BLOCK_SIZE);  // Start with 1 block
    }

    // Destructor: Free allocated memory
    ~BlockManager() {
        free(data_ptr);
        data_ptr = nullptr;
        data_size = 0;
        allocated_size = 0;
    }

    // Function to read data from a file
    void readFromFile(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Error: Cannot open file " + filename);
        }

        char buffer[BLOCK_SIZE];
        while (file) {
            file.read(buffer, BLOCK_SIZE);
            std::streamsize bytesRead = file.gcount();

            if (bytesRead > 0) {
                appendData(buffer, bytesRead);
            }
        }

        std::cout << "File read successfully. Total bytes stored: " << data_size << std::endl;
    }

    // Function to print stored data (for debugging)
    void printData() const {
        std::cout.write(data_ptr, data_size);
        std::cout << std::endl;
    }

private:
    char* data_ptr;       // Pointer to allocated memory block
    size_t allocated_size; // Total allocated size
    size_t data_size;      // Current size of stored data

    // Function to allocate memory
    void allocate(size_t size) {
        data_ptr = (char*)malloc(size);
        if (!data_ptr) {
            throw std::bad_alloc();
        }
        allocated_size = size;
    }

    // Function to append data, resizing memory if needed
    void appendData(const char* new_data, size_t new_size) {
        if (data_size + new_size > allocated_size) {
            resizeMemory(data_size + new_size);
        }
        memcpy(data_ptr + data_size, new_data, new_size);
        data_size += new_size;
    }

    // Function to resize memory block
    void resizeMemory(size_t new_size) {
        size_t new_alloc_size = ((new_size / BLOCK_SIZE) + 1) * BLOCK_SIZE;
        char* new_ptr = (char*)realloc(data_ptr, new_alloc_size);
        if (!new_ptr) {
            throw std::bad_alloc();
        }
        data_ptr = new_ptr;
        allocated_size = new_alloc_size;
        std::cout << "Resized memory to: " << allocated_size << " bytes." << std::endl;
    }
};

// Main function for testing
int main() {
    try {
        BlockManager manager;
        manager.readFromFile("example.txt");  // Change filename as needed
        manager.printData();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
