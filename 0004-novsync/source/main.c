
#include    <gba.h>

void waitVsync()
{
    while ( REG_VCOUNT >= 160 ) { }
    while ( REG_VCOUNT <  160 ) { }
}

void drawLine(u32 x, u16 color)
{
    static u16 * const  screen = (u16 *)VRAM;
    for ( u32 y = 0; y < 160; ++ y ) {
        screen[x + y * SCREEN_WIDTH] = color;
    }
}

int main()
{
    u32 x = 0;
    SetMode(MODE_3 | BG2_ENABLE);

    for (;;) {
        drawLine(x++, 0x0000);
        drawLine(x++, 0x0000);
        x %= 238;
        drawLine(x + 0, 0x001f);
        drawLine(x + 1, 0x001f);
    }
}
