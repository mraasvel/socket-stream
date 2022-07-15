#pragma once

#include "socket.hpp"

namespace net {

class TcpStream {
	public:
		TcpStream(Socket&& socket);

	private:
		Socket socket;
};

}
