
#include "kernel.h"
#include "console.h"
#include "string.h"
#include "vga.h"

void display_sections() {

    printf("ZecelOS Code Red 2023 \n");

    MiniRussia(74, 22);

    programballs();

//     square(COLOR_MAGENTA, 5, 8);
//
//     rectangle(COLOR_BLUE, 19, 10);

}

void programballs()
{
    Window(COLOR_BLUE, 0, 4);

    console_gotoxy(1, 4);
    balls();
}

void kmain() {
    console_init(COLOR_WHITE, COLOR_GREEN);
    display_sections();
}
