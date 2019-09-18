#include <hello.h>

int main()
{

	HelloFunc();

#ifdef ENABLE_DEBUG
	printf("enable-debug\n");
#endif

#ifdef ABC
	printf("enable-abc\n");
#endif

	return 0;

}
