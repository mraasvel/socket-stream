#pragma once

#include "net.hpp"
#include "socket.hpp"
#include "tcp_stream.hpp"

namespace net {

class TcpListener {
	public:
		TcpListener(const string& address);
		// simple blocking accept
		TcpStream accept() const;

	private:
		Socket listen;
};

}
