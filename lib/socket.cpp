#include "socket.hpp"
#include <unistd.h>

namespace net {

Socket::Socket(): fd(-1) {}
Socket::Socket(int fd): fd(fd) {}

Socket::Socket(Socket&& other): fd(other.fd) {
	other.fd = -1;
}

Socket& Socket::operator=(Socket&& other) {
	if (this == &other) {
		return *this;
	}
	close_socket();
	fd = other.fd;
	other.fd = -1;
	return *this;
}

/*
FIXME: some discussion on retrying the closing of a fd on EINTR error
*/
void Socket::close_socket() {
	if (fd < 0) {
		// fail quietly
		return;
	}
	if (close(fd) == -1) {
		// TODO: log error
	}
	fd = -1;

}

Socket::~Socket() {
	close_socket();
}

}
