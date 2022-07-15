# Todo
- TcpListener:
	- Options struct/flags for binding and accepting
- TcpStream:
	- Static connect function
- Socket:
	- make reference counted fd using fd table for cloning/copying, splitting into r/w halves, etc

# Socket
Streaming interface for socket connections

- binding and listening on a given address
- accepting connections
- making connections
- get the underlying fd

## TcpListener
- Class for binding to a socket and accepting connections from it
- Accept will return the TcpStream class

## TcpStream
- Static function for making a connection
- Stream class for socket connection
