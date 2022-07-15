#include "socket.hpp"
#include "mrlog.hpp"
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
	mrlog::info("closing: [{}]", fd);
	if (close(fd) == -1) {
		mrlog::error("error closing fd: [{}]", fd);
	}
	fd = -1;
}

Socket::~Socket() {
	close_socket();
}

std::ostream& operator<<(std::ostream& out, const Socket& rhs) {
	out << rhs.fd;
	return out;
}

}
