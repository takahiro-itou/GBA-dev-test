
#include    <gba.h>

void waitVsync()
{
    while ( REG_VCOUNT >= 160 ) { }
    while ( REG_VCOUNT <  160 ) { }
}

int main()
{
    for (;;) {
        waitVsync();
    }
}
