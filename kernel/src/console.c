#include <console.h>
#include <string.h>
#include <types.h>
#include <vga.h>

static uint16 *g_vga_buffer;
static uint32 g_vga_index;

static uint8 cursor_pos_x = 0, cursor_pos_y = 0;

uint8 g_fore_color = COLOR_WHITE, g_back_color = COLOR_BLACK;
static uint16 g_temp_pages[MAXIMUM_PAGES][VGA_TOTAL_ITEMS];
uint32 g_current_temp_page = 0;

void console_clear(VGA_COLOR_TYPE fore_color, VGA_COLOR_TYPE back_color)
{
    uint32 i;

    for (i = 0; i < VGA_TOTAL_ITEMS; i++) {
        g_vga_buffer[i] = vga_item_entry(NULL, fore_color, back_color);
    }

    g_vga_index = 0;
    cursor_pos_x = 0;
    cursor_pos_y = 0;

    vga_set_cursor_pos(cursor_pos_x, cursor_pos_y);
}

//initialize console
void console_init(VGA_COLOR_TYPE fore_color, VGA_COLOR_TYPE back_color) {
    g_vga_buffer = (uint16 *)VGA_ADDRESS;
    g_fore_color = fore_color;
    g_back_color = back_color;
    cursor_pos_x = 0;
    cursor_pos_y = 0;
    console_clear(fore_color, back_color);
}

void console_scroll(int type) {
    uint32 i;
    if (type == SCROLL_UP) {
        // scroll up
        if (g_current_temp_page > 0)
            g_current_temp_page--;
        g_current_temp_page %= MAXIMUM_PAGES;
        for (i = 0; i < VGA_TOTAL_ITEMS; i++) {
            g_vga_buffer[i] = g_temp_pages[g_current_temp_page][i];
        }
    } else {
        // scroll down
        g_current_temp_page++;
        g_current_temp_page %= MAXIMUM_PAGES;
        for (i = 0; i < VGA_TOTAL_ITEMS; i++) {
            g_vga_buffer[i] = g_temp_pages[g_current_temp_page][i];
        }
    }
}

/*
increase vga_index by width of vga width
*/
static void console_newline(void) {
    uint32 i;

    if (cursor_pos_y >= VGA_HEIGHT) {
        for (i = 0; i < VGA_TOTAL_ITEMS; i++)
            g_temp_pages[g_current_temp_page][i] = g_vga_buffer[i];
        g_current_temp_page++;
        cursor_pos_x = 0;
        cursor_pos_y = 0;
        console_clear(g_fore_color, g_back_color);
    } else {
        for (i = 0; i < VGA_TOTAL_ITEMS; i++)
            g_temp_pages[g_current_temp_page][i] = g_vga_buffer[i];

        g_vga_index += VGA_WIDTH - (g_vga_index % VGA_WIDTH);
        cursor_pos_x = 0;
        ++cursor_pos_y;
        vga_set_cursor_pos(cursor_pos_x, cursor_pos_y);
    }
}


//assign ascii character to video buffer
void console_putchar(char ch) {
    if (ch == ' ') {
        g_vga_buffer[g_vga_index++] = vga_item_entry(' ', g_fore_color, g_back_color);
        vga_set_cursor_pos(cursor_pos_x++, cursor_pos_y);
    }
    if (ch == '\t') {
        for(int i = 0; i < 4; i++) {
            g_vga_buffer[g_vga_index++] = vga_item_entry(' ', g_fore_color, g_back_color);
            vga_set_cursor_pos(cursor_pos_x++, cursor_pos_y);
        }
    } else if (ch == '\n') {
        console_newline();
    } else {
        if (ch > 0) {
            g_vga_buffer[g_vga_index++] = vga_item_entry(ch, g_fore_color, g_back_color);
            vga_set_cursor_pos(++cursor_pos_x, cursor_pos_y);
        }
    }
}

void pixel(VGA_COLOR_TYPE pc) {

    g_vga_buffer[g_vga_index++] = vga_item_entry(' ', pc, pc);

}

void rectangle(VGA_COLOR_TYPE rc, int start_x_pos,  int start_y_pos) {

    int ba = start_y_pos++;
    int nah = start_x_pos++;

    console_gotoxy(start_x_pos, start_y_pos);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    console_gotoxy(start_x_pos, ba);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    console_gotoxy(start_x_pos, ba);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
    pixel(rc);
}

void Russia(int x, int y) {

    //russia

    console_gotoxy(x, y++);

    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);

    int yplus = y++;
    int yplusagain = yplus++;

    console_gotoxy(x, yplusagain);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);

    console_gotoxy(x, yplus);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
}

void MiniRussia(int x, int y) {

    //russia

    console_gotoxy(x, y++);

    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);

    int yplusa = y++;
    int yplusagaina = yplusa++;

    console_gotoxy(x, yplusagaina);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);
    pixel(COLOR_BLUE);

    console_gotoxy(x, yplusa);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
}

void Ireland() {

    //ireland
    console_gotoxy(0, 5);

    pixel(COLOR_GREEN);
    console_gotoxy(0, 6);
    pixel(COLOR_GREEN);
    console_gotoxy(0, 7);
    pixel(COLOR_GREEN);
    console_gotoxy(0, 8);
    pixel(COLOR_GREEN);
    console_gotoxy(0, 9);
    pixel(COLOR_GREEN);
    console_gotoxy(0, 10);
    pixel(COLOR_GREEN);
    console_gotoxy(0, 11);
    pixel(COLOR_GREEN);

    console_gotoxy(1, 5);
    pixel(COLOR_WHITE);
    console_gotoxy(1, 6);
    pixel(COLOR_WHITE);
    console_gotoxy(1, 7);
    pixel(COLOR_WHITE);
    console_gotoxy(1, 8);
    pixel(COLOR_WHITE);
    console_gotoxy(1, 9);
    pixel(COLOR_WHITE);
    console_gotoxy(1, 10);
    pixel(COLOR_WHITE);
    console_gotoxy(1, 11);
    pixel(COLOR_WHITE);

    console_gotoxy(2, 5);
    pixel(COLOR_YELLOW);
    console_gotoxy(2, 6);
    pixel(COLOR_YELLOW);
    console_gotoxy(2, 7);
    pixel(COLOR_YELLOW);
    console_gotoxy(2, 8);
    pixel(COLOR_YELLOW);
    console_gotoxy(2, 9);
    pixel(COLOR_YELLOW);
    console_gotoxy(2, 10);
    pixel(COLOR_YELLOW);
    console_gotoxy(2, 11);
    pixel(COLOR_YELLOW);
}

void England() {

    // ENGLANDDDDDDDDDDDDDD

    console_gotoxy(0, 15);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_RED);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    console_gotoxy(0, 16);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_RED);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    console_gotoxy(0, 17);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED); // center
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    pixel(COLOR_RED);
    console_gotoxy(0, 18);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_RED);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    console_gotoxy(0, 19);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_RED);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);
    pixel(COLOR_WHITE);

}

void square(VGA_COLOR_TYPE sc, int start_x_pos, int start_y_pos)
{
    int nh = start_y_pos += 1;
    int nhh = nh += 1;
    int nhhh = nhh += 1;

    int bh = start_x_pos += 1;
    int bhh = bh += 1;
    int bhhh = bhh += 1;

    console_gotoxy(start_x_pos, start_y_pos);

    pixel(sc);
    pixel(sc);
    pixel(sc);
    pixel(sc);
    pixel(sc);

    console_gotoxy(start_x_pos, nh);

    pixel(sc);
    pixel(sc);
    pixel(sc);
    pixel(sc);
    pixel(sc);

    console_gotoxy(start_x_pos, nhh);

    pixel(sc);
    pixel(sc);
    pixel(sc);
    pixel(sc);
    pixel(sc);

    console_gotoxy(start_x_pos, nhhh);

    pixel(sc);
    pixel(sc);
    pixel(sc);
    pixel(sc);
    pixel(sc);
}

void HalfWindow(VGA_COLOR_TYPE color, int x, int y)
{
    // a rectangle is 16 pixels wide

    rectangle(color, x, y);

    int windowx = x+= 16;

    console_gotoxy(windowx, y);

    rectangle(color, windowx, y);

//     int windowsx = windowx += 16;
//
//     rectangle(color, windowsx, y);
}

void Box(VGA_COLOR_TYPE color, int x, int y)
{
    HalfWindow(color, x, y);

    int windowsy = y += 2;

    console_gotoxy(x, windowsy);

    HalfWindow(color, x, windowsy);

    int windowsyy = windowsy += 2;

    console_gotoxy(x, windowsyy);

    HalfWindow(color, x, windowsyy);

    int windowsyyy = windowsyy += 2;

    console_gotoxy(x, windowsyyy);

    HalfWindow(color, x, windowsyyy);
}

void Window(VGA_COLOR_TYPE color, int x, int y)
{
    Box(color, x, y);

    int winy = y += 2;

    console_gotoxy(x, winy);

    Box(color, x, winy);

    int winyy = winy += 2;

    console_gotoxy(x, winyy);

    Box(color, x, winyy);

    int winyyy = winyy += 2;

    console_gotoxy(x, winyyy);

    Box(color, x, winyyy);

    int winyyyy = winyyy += 2;

    console_gotoxy(x, winyyyy);

    Box(color, x, winyyyy);

    int winyyyyy = winyyyy += 2;

    console_gotoxy(x, winyyyyy);

    Box(color, x, winyyyyy);

    console_gotoxy(x+=32, y-=2);
    pixel(COLOR_RED);   // close button
}

void balls()
{
    g_vga_buffer[g_vga_index++] = vga_item_entry('b', COLOR_WHITE, COLOR_BLUE);
    g_vga_buffer[g_vga_index++] = vga_item_entry('a', COLOR_WHITE, COLOR_BLUE);
    g_vga_buffer[g_vga_index++] = vga_item_entry('l', COLOR_WHITE, COLOR_BLUE);
    g_vga_buffer[g_vga_index++] = vga_item_entry('l', COLOR_WHITE, COLOR_BLUE);
    g_vga_buffer[g_vga_index++] = vga_item_entry('s', COLOR_WHITE, COLOR_BLUE);
}

void ni()
{
    g_vga_buffer[g_vga_index++] = vga_item_entry('n', COLOR_WHITE, COLOR_MAGENTA);
    g_vga_buffer[g_vga_index++] = vga_item_entry('i', COLOR_WHITE, COLOR_MAGENTA);
}

void empty()
{
    g_vga_buffer[g_vga_index++] = vga_item_entry('E', COLOR_WHITE, COLOR_BLUE);
    g_vga_buffer[g_vga_index++] = vga_item_entry('m', COLOR_WHITE, COLOR_BLUE);
    g_vga_buffer[g_vga_index++] = vga_item_entry('p', COLOR_WHITE, COLOR_BLUE);
    g_vga_buffer[g_vga_index++] = vga_item_entry('t', COLOR_WHITE, COLOR_BLUE);
    g_vga_buffer[g_vga_index++] = vga_item_entry('y', COLOR_WHITE, COLOR_BLUE);
}

// revert back the printed character and add 0 to it
void console_ungetchar() {
    if(g_vga_index > 0) {
        g_vga_buffer[g_vga_index--] = vga_item_entry(0, g_fore_color, g_back_color);
        if(cursor_pos_x > 0) {
            vga_set_cursor_pos(cursor_pos_x--, cursor_pos_y);
        } else {
            cursor_pos_x = VGA_WIDTH;
            if (cursor_pos_y > 0)
                vga_set_cursor_pos(cursor_pos_x--, --cursor_pos_y);
            else
                cursor_pos_y = 0;
        }
    }

    // set last printed character to 0
    g_vga_buffer[g_vga_index] = vga_item_entry(0, g_fore_color, g_back_color);
}

// revert back the printed character until n characters
void console_ungetchar_bound(uint8 n) {
    if(((g_vga_index % VGA_WIDTH) > n) && (n > 0)) {
        g_vga_buffer[g_vga_index--] = vga_item_entry(0, g_fore_color, g_back_color);
        if(cursor_pos_x >= n) {
            vga_set_cursor_pos(cursor_pos_x--, cursor_pos_y);
        } else {
            cursor_pos_x = VGA_WIDTH;
            if (cursor_pos_y > 0)
                vga_set_cursor_pos(cursor_pos_x--, --cursor_pos_y);
            else
                cursor_pos_y = 0;
        }
    }

    // set last printed character to 0
    g_vga_buffer[g_vga_index] = vga_item_entry(0, g_fore_color, g_back_color);
}

void console_gotoxy(uint16 x, uint16 y) {
    g_vga_index = (80 * y) + x;
    cursor_pos_x = x;
    cursor_pos_y = y;
    vga_set_cursor_pos(cursor_pos_x, cursor_pos_y);
}

//print string by calling print_char
void console_putstr(const char *str) {
    uint32 index = 0;
    while (str[index]) {
        if (str[index] == '\n')
            console_newline();
        else
            console_putchar(str[index]);
        index++;
    }
}

void printf(const char *format, ...) {
    char **arg = (char **)&format;
    int c;
    char buf[32];

    arg++;

    memset(buf, 0, sizeof(buf));
    while ((c = *format++) != 0) {
        if (c != '%')
            console_putchar(c);
        else {
            char *p, *p2;
            int pad0 = 0, pad = 0;

            c = *format++;
            if (c == '0') {
                pad0 = 1;
                c = *format++;
            }

            if (c >= '0' && c <= '9') {
                pad = c - '0';
                c = *format++;
            }

            switch (c) {
                case 'd':
                case 'u':
                case 'x':
                    itoa(buf, c, *((int *)arg++));
                    p = buf;
                    goto string;
                    break;

                case 's':
                    p = *arg++;
                    if (!p)
                        p = "(null)";

                string:
                    for (p2 = p; *p2; p2++)
                        ;
                    for (; p2 < p + pad; p2++)
                        console_putchar(pad0 ? '0' : ' ');
                    while (*p)
                        console_putchar(*p++);
                    break;

                default:
                    console_putchar(*((int *)arg++));
                    break;
            }
        }
    }
}
