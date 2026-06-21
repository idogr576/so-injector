#pragma once
#include <stdint.h>
#include <stddef.h>
#include <wait.h>

typedef unsigned long long int reg_t;

typedef struct
{
    pid_t pid;
    uint8_t patched_bytes[BUFSIZ];
    size_t n; // number of patched bytes
    struct user_regs_struct regs;
    uintptr_t libc_addr;
    uintptr_t argv_addr;
} state_t;

extern const size_t g_shellcode_bin_len;
extern char *g_so_path;

int construct_shellcode(state_t *tracee);

size_t remote_write_mem(int pid, void *addr, uint8_t *buff, size_t n);
int remote_attach_process(state_t *tracee);
int remote_state_preserve(state_t *tracee);
int remote_alloc_args_on_stack(state_t *tracee);
int remote_write_shellcode(state_t *tracee);
int remote_run_shellcode(state_t *tracee);
uintptr_t remote_libc_start_address(state_t *tracee);