#include <stdio.h>
#include <dlfcn.h>

typedef void (*print_number_fn)(void);

static void *handle = NULL;
static print_number_fn print_number = NULL;

static void load(const char *lib_n, const char *func_n)
{
    if (handle)
        dlclose(handle);
    
    handle = dlopen(lib_n, RTLD_LAZY);
    print_number = dlsym(handle, func_n);
}

int main(void)
{
    printf("shared library loading test\n");
    printf("---------------------------\n");

    printf("\nusage:\n");
    printf("\tq - quit\n");
    printf("\tt - test function\n");
    printf("\tu - unload library\n");
    printf("\ta - load library a\n");
    printf("\tb - load library b\n");

    char c;
    for (;;) {
        printf("\nloaded: %p\n", handle);

        printf(":: ");
        scanf(" %c", &c);
        
        switch (c) {
        case 'q':
            goto end;
        
        case 'u':
            if (handle) {
                dlclose(handle);
                handle = NULL;
                print_number = NULL;

                printf("shared library unloaded\n");
            } else {
                printf("no library loaded\n");
            }
            break;
        
        case 't':
            if (print_number)
                print_number();
            else
                printf("no function loaded\n");
            break;
        
        case 'a':
            load("lib_a/liba.so", "print_number");
            break;
        
        case 'b':
            load("lib_b/libb.so", "print_number");
            break;
        
        default:
            break;
        }
    }

end:
    printf("\nquit\n");
    return 0;
}
