#include <stdio.h>
#include <ockam/log/log.h>
#include <ockam/memory/stdlib/memory_stdlib.h>

void custom_log(const char* str) {
    printf("CUSTOM PRINT: %s\n", str);
}

int main(void) {
    ockam_set_log_function(custom_log);
    ockam_memory_stdlib_t *memory;
    ockam_memory_stdlib_new(&memory);

    return 0;
}
