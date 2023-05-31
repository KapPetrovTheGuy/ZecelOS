#ifndef GDT_H
#define GDT_H

#define i686_GDT_CODE_SEGMENT 0x08
#define i686_GDT_DATA_SEGMENT 0x10

void InstallGdt(void);

#endif
