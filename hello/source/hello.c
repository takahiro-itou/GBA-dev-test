
int main()
{
    *(unsigned int*)0x04000000=0x0403;
    for ( int y = 0; y < 4; ++ y ) {
        for ( int x = 0; x < 8; ++ x ) {
            ((unsigned short*)0x06000000)[(120+x)+(80+y)*240]=0x001f;
            ((unsigned short*)0x06000000)[(136+x)+(80+y)*240]=0x03e0;
            ((unsigned short*)0x06000000)[(120+x)+(96+y)*240]=0x7c00;
        }
    }
    while(1);
}
