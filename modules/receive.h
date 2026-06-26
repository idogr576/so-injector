#pragma once
#include "protocol.h"

/* ----------------------- DECLARED GLOBALS ----------------------- */
/* data of last packet received by the module */
extern uint8_t g_last_data[MAX_DATA_SIZE];
extern size_t g_last_size;
extern uint64_t g_last_time;


int receive_init();
int receive_iterate();
int receive_destroy();