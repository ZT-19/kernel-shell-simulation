#ifndef KERNEL_H
#define KERNEL_H

struct PCB *initPCB(int PID, int pages_max);
void scheduler();
int boot();
int kernel();
int shutDown();

#endif
