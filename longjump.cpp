#include <iostream>
#include <csetjmp>
 
jmp_buf jump_buffer;
 
[[noreturn]] void a(int c) {
    std::cout << "a(" << c << ") called\n";
    longjmp(jump_buffer, c);
}
 
int main(){
    volatile int count = 0;
    if (setjmp(jump_buffer) != 9)
        a(count++);
}
