#include <iostream>
#include <string>

using namespace std;

// Global variable
int globalVar = 42;

// Function prototype
void demonstrateFunctions(int a, int b);

int main() {
    int num = 10;

    // 1. Operators
    int sum = num + 5;
    int product = num * 2;
    int bitwiseAnd = num & 6;
    cout << "Sum: " << sum << " | Product: " << product << " | Bitwise AND: " << bitwiseAnd << endl;

    // 2. Conditional Statements
    if (num > 5) {
        cout << "Num is greater than 5" << endl;
    } else {
        cout << "Num is 5 or less" << endl;
    }

    // 3. Loops
    cout << "For loop: ";
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    cout << "While loop: ";
    int counter = 0;
    while (counter < 5) {
        cout << counter << " ";
        counter++;
    }
    cout << endl;

    // 4. Functions
    demonstrateFunctions(3, 7);

    // 5. Arrays
    int numbers[] = {1, 2, 3, 4, 5};
    cout << "Array element at index 2: " << numbers[2] << endl;

    // 6. Pointers
    int* ptr = &num;
    cout << "Pointer address: " << ptr << " | Value: " << *ptr << endl;// implicit casting so we dont have to worry about that  
// ⣿⣿⣿⣿⣿⣿⡿⠛⢉⣿⣿⠿⠋⠄⢴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⠄⠄
// ⣿⣿⣿⣿⣿⠏⣠⣶⣿⠟⠁⣠⣶⣶⣤⣄⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠄
// ⣿⣿⣿⠟⠁⣴⡿⠛⠁⢠⣾⣯⣉⡉⠛⢿⣿⣿⣿⣿⣯⣍⡉⠙⢿⣿⣿⣿⣿⡇
// ⣿⡟⠁⠄⣾⠋⠄⠄⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠿⣷⣤⣽⣿⣿⣿⠄
// ⠟⠄⠄⣠⣴⠋⣰⣿⣿⣿⣿⣿⣯⣹⣟⡉⢻⣿⣿⣿⣿⣷⣤⣈⠻⣿⣿⣿⣿⡀
// ⠄⠄⣴⡟⠁⣰⣿⣿⣿⣿⣤⣤⣌⡙⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿
// ⠄⢰⣿⠁⣰⣿⣿⣿⡟⢁⣤⣤⣭⡙⠳⢦⣄⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟
// ⠄⣾⡇⢸⣿⣿⣿⣿⡇⢻⡏⠉⠻⠿⣷⣆⠹⡆⢸⣿⣿⣿⣿⣿⣿⣿⠋⠁⠄⠄
// ⠄⡿⠄⣡⣬⠉⣻⣿⣷⣄⣀⠄⠄⠄⠈⠛⠂⠿⢿⣿⣿⣿⣿⣿⡿⠃⠄⠄⢠⣾
// ⠄⣡⣾⡿⢇⣼⣿⠿⠿⠟⢉⣉⣠⣶⣾⣿⣿⣿⠈⣿⣿⣿⣿⡿⠁⠄⠄⣴⣿⠏
// ⣾⣿⣟⣁⣈⣩⣴⣶⣾⣿⣿⣿⠿⠟⠛⠛⠋⠡⣾⣿⣿⣿⣿⠇⠄⢀⣾⡟⠁⠄
// ⣿⣿⣿⠿⠿⠿⠛⣛⣉⣁⣀⣤⣤⣤⣤⣤⣀⣀⠘⠻⣿⣿⠟⠄⠄⣾⠟⠄⠄⠄
// ⣿⣿⣿⣷⣶⣿⣿⣿⣿⣿⡿⠿⠿⠿⠿⣿⣿⣿⣿⡆⢸⡿⠄⠄⣼⡏⠄⠄⠄⠄
// ⣿⣿⣿⣿⠿⠛⣉⣁⣤⣤⣴⣶⣶⣶⣦⣤⣌⣙⠛⢀⣈⠃⠄⠰⣿⠁⠄⠄⠄⢠
// ⣿⣿⣿⣿⣶⣿⣿⣿⣿⠿⠟⠛⣋⣉⣩⣭⠉⢋⣴⣿⣿⣿⣿⣷⣶⣦⣤⣤⣴⣿

//A special case exists for char* (C-style strings). If you pass a char* to cout, it prints the string, not the memory address.

    // 7. References
    int& ref = num;
    ref += 5;
    cout << "Referenced value: " << ref << " (num is now: " << num << ")" << endl;

    // 8. Scope Resolution Operator ::
    cout << "Global variable: " << ::globalVar << endl;

    return 0;
}

// Function definition
void demonstrateFunctions(int a, int b) {
    cout << "Function call: Sum of " << a << " and " << b << " is " << (a + b) << endl;
} 
