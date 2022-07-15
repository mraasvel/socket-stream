#include "net.hpp"

namespace net {

NetException::NetException(const std::string& reason): reason(reason) {}

const char* NetException::what() const noexcept {
	return reason.c_str();
}

}
