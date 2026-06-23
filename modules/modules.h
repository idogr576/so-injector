#pragma once
#include <stdio.h>
#include <stdbool.h>

#include "socket.h"

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
module_t modsocket = {
    .ops = {.init = socket_init, .iterate = socket_iterate, .destroy = socket_destroy}
};

module_t *g_modules[] = { &modsocket };
int g_num = sizeof(g_modules) / sizeof(*g_modules);