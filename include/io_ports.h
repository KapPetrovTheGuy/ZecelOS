#ifndef IO_PORTS_H
#define IO_PORTS_H

#include "types.h" //quick obvious note, you need to include this whenever you're using uint stuff. Its defined there obviously.

uint8 inportb(uint16 port);

void outportb(uint16 port, uint8 val);

uint16 inports(uint16 port);

void outports(uint16 port, uint16 data);

uint32 inportl(uint16 port);

void outportl(uint16 port, uint32 data);

#endif
