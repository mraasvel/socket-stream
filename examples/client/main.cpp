#include "net.hpp"
#include "mrlog.hpp"

int main() {
	net::TcpStream stream = net::connect("127.0.0.1", 3000);
	std::string expected { "abcde" };
	mrlog::info("sending: {}", expected);
	stream.write(expected.c_str(), expected.size());
	stream.flush();
	char buffer[10];
	// have to read exact size because otherwise it will wait for more input or EOF since it's blocking
	stream.read(buffer, expected.size());
	buffer[stream.gcount()] = '\0';
	mrlog::info("received: {}", buffer);
	return 0;
}
