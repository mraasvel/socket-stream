#include "tcp_listener.hpp"
#include "tcp_stream.hpp"
#include "mrlog.hpp"

int main() {
	net::TcpListener listener;
	const std::string address = "127.0.0.1";
	const short port = 3000;
	listener.init(address, port);
	while (true) {
		mrlog::info("accepting connections on {}:{}", address, port);
		net::TcpStream connection = listener.accept();
	}
	return 0;
}
