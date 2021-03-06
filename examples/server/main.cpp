#include "tcp_listener.hpp"
#include "tcp_stream.hpp"
#include "mrlog.hpp"

// just echo data back
int handle_connection(net::TcpStream connection) {
	mrlog::info("new connection");
	while (connection.good()) {
		int n = connection.get();
		connection.put(n);
		connection.flush();
	}
	mrlog::info("client hung up");
	return 0;
}

int main() {
	const std::string address = "127.0.0.1";
	const short port = 3000;

	net::TcpListener listener;
	if (listener.init(address, port) == net::NetResult::Error) {
		return 1;
	}
	while (true) {
		mrlog::info("accepting connections on {}:{}", address, port);
		net::TcpStream connection = listener.accept();
		if (handle_connection(std::move(connection)) == -1) {
			return 1;
		}
	}
	return 0;
}
