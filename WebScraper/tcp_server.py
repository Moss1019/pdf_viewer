
import socket
import threading


class TcpServer(object):
    def __init__(self, ip_address, port, on_connection):
        self._ip_address = ip_address
        self._port = port
        self._on_connection = on_connection
        self._server = socket.socket(socket.AF_INET, socket.SOCK_STREAM, socket.IPPROTO_TCP)
        self._is_running = False
        self._worker = None
        address = (ip_address, port)
        self._server.bind(address)

    def start(self):
        self._is_running = True
        self._worker = threading.Thread(target=self._do_work)
        self._worker.start()

    def stop(self):
        self._is_running = False
        self._worker = None

    def _do_work(self):
        self._server.listen(3)
        while self._is_running:
            try:
                connection = self._server.accept()
                self._on_connection(connection[0], connection[1])
            except Exception as ex:
                print(ex)
        self._server.close()



