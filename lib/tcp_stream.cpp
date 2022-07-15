#include "tcp_stream.hpp"
#include <utility>

namespace net {

TcpStream::TcpStream(Socket&& socket): socket(std::move(socket)) {}

}
