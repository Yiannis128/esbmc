#include "common.h"
unsigned char poptab[256] =
{
  0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
};
unsigned long src[1024] =
{
  0x00005678, 0x12340000, 0x02040608, 0x00000001,
  0x12345678, 0x12345678, 0x12345678, 0x12345678,
  0x00005678, 0x12340000, 0x02040608, 0x00000001,
  0x12345678, 0x12345678, 0x12345678, 0x12345678,
  0x00005678, 0x12340000, 0x02040608, 0x00000001,
  0x12345678, 0x12345678, 0x12345678, 0x12345678,
  0x00005678, 0x12340000, 0x02040608, 0x00000001,
  0x12345678, 0x12345678, 0x12345678, 0x12345678,
  0x00005678, 0x12340000, 0x02040608, 0x00000001,
  0x12345678, 0x12345678, 0x12345678, 0x12345678,
  0x00005678, 0x12340000, 0x02040608, 0x00000001,
  0x10101010, 0x12345678, 0x10101010, 0x12345678,
  0x00005678, 0x12340000, 0x02040608, 0x00000001,
  0x10101010, 0x12345678, 0x10101010, 0x12345678,
  0x00005678, 0x12340000, 0x02040608, 0x00000001,
  0x10101010, 0x12345678, 0x10101010, 0x12345678,
  0
};
unsigned long dst[1024];
int main()
{
  unsigned long *s, *d;
  unsigned long x;
  int k, t = 0;
  for (s = src, d = dst, t = 0; *s; s += 4, d += 4)
    {
      x = s[0] ^ d[0];
      k = poptab[x & 0xff];
      k += poptab[(x >> 8) & 0xff];
      k += poptab[(x >> 16) & 0xff];
      k += poptab[x >> 24];
      t += k;
      x = s[1] ^ d[1];
      k = poptab[x & 0xff];
      k += poptab[(x >> 8) & 0xff];
      k += poptab[(x >> 16) & 0xff];
      k += poptab[x >> 24];
      t += k;
      x = s[2] ^ d[2];
      k = poptab[x & 0xff];
      k += poptab[(x >> 8) & 0xff];
      k += poptab[(x >> 16) & 0xff];
      k += poptab[x >> 24];
      t += k;
      x = s[3] ^ d[3];
      k = poptab[x & 0xff];
      k += poptab[(x >> 8) & 0xff];
      k += poptab[(x >> 16) & 0xff];
      k += poptab[x >> 24];
      t += k;
    }
#if 1
  if (t != 0x202)
    {
      puts("bcnt: failed\n");
    } 
  else
    {
      puts("bcnt: success\n");
    }
#endif
  return 0;
}
