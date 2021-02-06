// We use header files for including below forward declarations
void doSomething(); // forward declarations

#define PRINT

int main()
{
    doSomething(); // Not printing
    // Scope of object like macros are only in respective files
    return 0;
}