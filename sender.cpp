#include <bits/stdc++.h>
#include <crafter.h>
#include <time.h>

#define NO_PACKETS 5

/* Collapse namespaces */
using namespace std;
using namespace Crafter;

int main() {

	/* Set the interface */
	string iface = "eth0";

	/* Get the IP address associated to the interface */
	string MyIP = GetMyIP(iface);

	/* Create an IP header */
	IP ip_header;

	/* Set the Source and Destination IP address */
	ip_header.SetSourceIP(MyIP);                      // <-- Set a source IP address.
	ip_header.SetDestinationIP("192.168.0.118");  // <-- Set a destination IP address as a domain name

	/* Create an ICMP header */
	ICMP icmp_header;

	icmp_header.SetType(ICMP::EchoRequest);        // <-- Echo request (a ping)
	icmp_header.SetIdentifier(RNG16());            // <-- Set a random ID for the ICMP packet

	/* Create a payload */
	RawLayer raw_header("HelloPing!\n");

	struct timespec buf;
	int r = clock_gettime(0, &buf);
	printf("Before sending: %ld.%4ld", buf.tv_sec, buf.tv_nsec/100000);

	for (int i = 0; i < NO_PACKETS; i++) {
		/* Create a packet... */
		Packet packet;

		/* ... and push each layer */
		packet.PushLayer(ip_header);
		packet.PushLayer(icmp_header);
		packet.PushLayer(raw_header);


		/* Send the packet, this would fill the missing fields (like checksum, lengths, etc) */
		packet.Send(iface);
	}

	return 0;

}