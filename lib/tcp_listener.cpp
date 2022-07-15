#include "tcp_listener.hpp"
#include "socket.hpp"
#include "mrlog.hpp"
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <cstring>
#include <cassert>

namespace net {

NetResult TcpListener::init(const string& ip, short port) {
	assert(listener.fd == -1);
	Socket sock { socket(AF_INET, SOCK_STREAM, 0) };
	if (sock.fd == -1) {
		mrlog::error("failed to create socket");
		return NetResult::Error;
	}
	sockaddr_in addr;
	std::memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip.c_str());
	if (bind(sock.fd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) < 0) {
		mrlog::error("failed to bind on interface {}:{}", ip, port);
		return NetResult::Error;
	}
	if (listen(sock.fd, 10) < 0) {
		mrlog::error("listen failed on interface {}:{}", ip, port);
		return NetResult::Error;
	}
	listener = std::move(sock);
	mrlog::info("new listening socket [{}] on {}:{}", listener.fd, ip, port);
	return NetResult::Ok;
}

// simple blocking accept
TcpStream TcpListener::accept() const {
	assert(listener.fd != -1);
	static constexpr int MAX_RETRIES = 3;

	int retries = 0;
	while (retries < MAX_RETRIES) {
		Socket connection = { ::accept(listener.fd, NULL, NULL) };
		if (connection.fd < 0) {
			retries += 1;
			mrlog::error("failed to accept connection, retrying...");
			continue;
		}
		return TcpStream { std::move(connection) };
	}
	throw NetException { "failed to accept connection" };
}

}
