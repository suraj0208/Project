#include <bits/stdc++.h>
#include <time.h>

int main() {

	struct timespec buf;
	int r = clock_gettime(0, &buf);
	printf("%ld.%4ld", buf.tv_sec, buf.tv_nsec/100000);

	return 0;
}