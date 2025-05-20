
#include    <gba.h>

#define     VRAM_FRAME_0    (u8 *)(0x06000000)
#define     VRAM_FRAME_1    (u8 *)(0x0600A000)

u8 *    screen;

void toggleFrame()
{
    REG_DISPCNT ^= BACKBUFFER;
    screen  = (REG_DISPCNT & BACKBUFFER) ? VRAM_FRAME_0 : VRAM_FRAME_1;
}

int main()
{
    SetMode(MODE_4 | BG2_ENABLE);
    screen  = VRAM_FRAME_0;

    for (;;) { }
}
