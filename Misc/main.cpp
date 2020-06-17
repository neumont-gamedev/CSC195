// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include <bitset>

using namespace std;

#ifdef NDEBUG
#define ASSERT_MSG(condition, message) ((void)0)
#else
#define ASSERT_MSG(condition, message) Assert(condition, #condition, __FILE__, __LINE__, __func__, message)
#endif // NDEBUG

void Assert(bool condition, const char* condition_string, const char* filename, int line, const char* function, const char* message)
{
    if (!(condition))
    {
        cout << condition_string << endl;
        cout << "message: " << message << endl;
        cout << "filename: " << filename << endl;
        cout << "line: " << line << endl;
        cout << "function: " << function << endl;
        abort();
    }
}

using u8_t = unsigned char; // (0,0,0,0,0,0,0,0)
using u32_t = unsigned int;

#define BIT(index) (1 << index)

const u8_t kPlayer      = BIT(0); // 0001 (1 << 0)
const u8_t kInvisible   = BIT(1); // 0010 (1 << 1)
const u8_t kFlight      = BIT(2); // 0100 (1 << 2)

#define PI 3.1415f

int main()
{
    float c = PI;
    u8_t bits = BIT(1);

#ifdef NDEBUG
    cout << "debug";
#endif // NDEBUG


    // assert
    int i = 5;
    assert(i == 5); // -> ((void)0);
    int* p{ &i };
    assert(p);
    static_assert(sizeof(int*) == 4, "invalid value");

    // pointer arithmetic
    int int_array[4]{ 23, 54, 6, 7 };
    cout << int_array << endl;
    cout << &int_array[1] << endl;

    int* int_ptr = int_array;  // &int_array[0]
    int_ptr++;
    int_ptr++;
    int_ptr--;
    cout << *int_ptr << endl;

    int_ptr = int_array;
    int_ptr = int_ptr - 2; // int_ptr[2] == *(int_ptr + 2)
    cout << *int_ptr << endl;

    // bitwise operator
    unsigned char stats{ 0 };
    stats |= (kFlight | kPlayer); // turn bits on (0100 | 0001 = 0101)
    cout << bitset<8>{stats} << endl;
    stats = stats & ~kFlight; // turn bits off (0101 & ~1011 = 0001)
    cout << bitset<8>{stats} << endl;
    stats = stats ^ kFlight; // toggle bits (0001 ^ 0100 = 0101)

    //if (5 & 1) cout << "odd\n"; // 0101
    if ((stats & kPlayer) && (stats & kFlight)) cout << "is flying player\n"; // bit test (0101 & 0001 = 0001)

    u32_t color{ (145 << 16) | (212 << 8) | 255 }; // argb (8, 8, 8, 8) -> (255, 255, 255, 255) -> 255 = 11111111 = (11111111)ff
    cout << bitset<32>{color} << endl;
    cout << "blue: " << bitset<32>{ color & 0xff } << endl; // 00001111 & 10111101 = 00001101
    cout << "red: " << bitset<32>{ (color >> 8) & 0xff } << endl; // 00001111 & 10111101 = 00001101


    std::cout << "Hello World!\n";
}

 