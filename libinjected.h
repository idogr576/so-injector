#pragma once

void __attribute__((constructor)) entrypoint(void);
void __attribute__((destructor)) exitpoint(void);

void tool_init();
void tool_destroy();
void tool_main_loop(int);
