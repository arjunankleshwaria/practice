#include <stdio.h>
#include <stdlib.h>

#define REV1(a)		(((a & 0xaaaaaaaa) >> 1) | ((a & 0x55555555) << 1))
#define REV2(a)		(((REV1(a) & 0xcccccccc) >> 2) | ((REV1(a) & 0x33333333) << 2))
#define REV4(a)		(((REV2(a) & 0xf0f0f0f0) >> 4) | ((REV2(a) & 0x0f0f0f0f) << 4))
#define REV8(a)		(((REV4(a) & 0xff00ff00) >> 8) | ((REV4(a) & 0x00ff00ff) << 8))
#define REV(a)		((REV8(a) >> 16) | (REV8(a) << 16))

int main()
{
	int a = 0xdeadbeef;
	int i = 31;
	for(; i >= 0; i--)
		printf("%d", ((a >> i) & 0x1));
	printf("\n");
	a = REV(a);
	for(i = 31; i >= 0; i--)
		printf("%d", ((a >> i) & 0x1));
	printf("\n");
	return 0;
}
