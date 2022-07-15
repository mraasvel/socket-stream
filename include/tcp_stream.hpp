#pragma once

#include "socket_buffer.hpp"
#include <iostream>

namespace net {

class TcpStream: public std::iostream {
	public:
		TcpStream() = delete;
		TcpStream(const TcpStream& other) = delete;
		TcpStream& operator=(const TcpStream& other) = delete;

		TcpStream(Socket&& socket);
		TcpStream(TcpStream&& other);
		TcpStream& operator=(TcpStream&& other);
		~TcpStream();

	private:
		SocketBuffer buffer;
};

}
