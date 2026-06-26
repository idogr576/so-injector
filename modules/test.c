#include "receive.h"
#include "protocol.h"
#include "utils.h"
#include "test.h"
#include "receive.h"

uint64_t g_test_time;

int test_init()
{
    LOG_DEBUG("init test\n");
    g_test_time = get_absolute_nanoseconds();
    return 0;
}
int test_iterate()
{
    if (g_last_time > g_test_time)
    {
        PRINT("[TEST] received %ld bytes: %s\n", g_last_size, (char *)g_last_data);
        g_test_time = g_last_time;
    }
    return 0;
}
int test_destroy()
{
    LOG_DEBUG("destroy test\n");
    return 0;
}