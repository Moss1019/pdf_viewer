
from tcp_server import TcpServer


def on_connection_handler(connection, address):
    data = connection.recv(1024)
    print(data.decode())


server = TcpServer("192.168.1.100", 8080, on_connection_handler)

server.start()

input()

server.stop()
