#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "pcb.h" // For struct PCB

int lastPID;

int findLoadUpdate(struct PCB *pcb, int pageNumber, int PID);
int launcher(char *filename);

#endif
