#include <bits/stdc++.h>
#include <time.h>

int main() {

	struct timespec buf;
	system("tcpdump -i eth0 icmp src 192.168.0.115 dst 192.168.0.118");
	int r = clock_gettime(0, &buf);
	printf("After capturing: %ld.%4ld", buf.tv_sec, buf.tv_nsec/100000);

	return 0;
}