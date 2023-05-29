
#include "kernel.h"
#include "console.h"
#include "string.h"
#include "vga.h"

void display_sections() {

    printf("Welcome To ZecelOS! \n");

    //Russia();

    //Ireland();

    //England();

    square(COLOR_RED, 5, 2);

    rectangle(COLOR_GREEN, 10, 10);
//
//     square(COLOR_BLUE, 12);
//
//     rectangle(COLOR_BRIGHT_GREEN, 17);
//
//     square(COLOR_DARK_GREY, 21);
//
//     rectangle(COLOR_BRIGHT_MAGENTA, 27);

//     square(COLOR_RED, 2);
//
//     rectangle(COLOR_GREEN, 10);

}

void kmain() {
    console_init(COLOR_WHITE, COLOR_BLACK);
    display_sections();
}
