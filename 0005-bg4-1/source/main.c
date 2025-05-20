
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
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i]   = RGB5(i, i, i);
    }
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i +  32] = RGB5(i, i, i);
    }
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i +  64] = RGB5(i, i, i);
    }
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i +  96] = RGB5(i, i, i);
    }
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i + 128] = RGB5(i, i, i);
    }
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i + 160] = RGB5(i, i, i);
    }
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i + 192] = RGB5(i, i, i);
    }
    for (u32 i = 0; i < 32; ++ i ) {
        BG_PALETTE[i + 224] = RGB5(i, i, i);
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

int main()
{
    SetMode(MODE_4 | BG2_ENABLE);
    initPalette();
    screen  = VRAM_FRAME_0;

    for (;;) { }
}
