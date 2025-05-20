
#include    <gba.h>

#define     VRAM_FRAME_0    (u8 *)(0x06000000)
#define     VRAM_FRAME_1    (u8 *)(0x0600A000)

u8 *    screen;

void toggleFrame()
{
    REG_DISPCNT ^= BACKBUFFER;
    screen  = (REG_DISPCNT & BACKBUFFER) ? VRAM_FRAME_0 : VRAM_FRAME_1;
}

void initPalette()
{
    //  (31, 0, 0) -> (31, 31, 31)  //
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i]   = RGB5(31, i, i);
    }
    //  (31, 31, 31) -> (0, 0, 31)  //
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i +  32] = RGB5(31 - i, 31 - i, 31);
    }
    //  (0, 0, 31) -> (0, 31, 0)    //
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i +  64] = RGB5(0, i, 31 - i);
    }
    //  (0, 31, 0) -> (31, 31, 0)   //
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i +  96] = RGB5(i, 31, 0);
    }
    //  (31, 31, 0) -> (0, 31, 31)  //
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i + 128] = RGB5(31 - i, 31, i);
    }
    //  (0, 31, 31) -> (0, 0, 0)  //
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i + 160] = RGB5(0, 31 - i, 31 - i);
    }
    //  (0, 0, 0) -> (31, 0, 31)    //
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i + 192] = RGB5(i, 0, i);
    }
    //  (31, 0, 31) -> (31, 0, 0)     //
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i + 224] = RGB5(31, 0, 31 - i);
    }
}

void drawLine(u32 y, u8 color)
{
    u32 cv  = (color) | (color << 8) | (color << 16) | (color <<24);
    u32 * s = (u32 *)(screen + y * color);
    for (u32 i = 0; i < 60; ++ i ) {
        *(s ++) = cv;
    }
}

void waitVsync()
{
    while ( REG_VCOUNT >= 160 ) { }
    while ( REG_VCOUNT <  160 ) { }
    toggleFrame();
}

void drawScreen()
{
    static  u32 i = 0;
    for (u32 y = 0; y < 160; ++ y ) {
        drawLine(y, (i + y) & 0xFF);
    }
    ++  i;
}

int main()
{
    SetMode(MODE_4 | BG2_ENABLE);
    initPalette();
    screen  = VRAM_FRAME_0;

    for (;;) {
        drawScreen();
        waitVsync();
    }
}
