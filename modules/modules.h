#pragma once
#include <stdio.h>
#include <stdbool.h>

#include "receive.h"
#include "test.h"

typedef struct
{
    int (*init)(void);
    int (*iterate)(void);
    int (*destroy)(void);
} module_operations_t;

typedef struct
{
    __id_t id;
    bool is_loaded;
    module_operations_t ops;
} module_t;

/* ----------------------- DECLARED MODULES ----------------------- */
module_t modrecv = {
    .ops = {.init = receive_init, .iterate = receive_iterate, .destroy = receive_destroy}
};

module_t modtest = {
    .ops = {.init = test_init, .iterate = test_iterate, .destroy = test_destroy}
};
/* ----------------------- DECLARED GLOBALS ----------------------- */
module_t *g_modules[] = {&modrecv, &modtest};
int g_num = sizeof(g_modules) / sizeof(*g_modules);