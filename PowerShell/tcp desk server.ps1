function Wait-OnPort ($port) {
$endpoint = new-object System.Net.IPEndPoint ([ipaddress]::any,$port)
$listener = new-object System.Net.Sockets.TcpListener $endpoint
$listener.start()
$listener.AcceptTcpClient() # wait until somebody connect
#$listener.stop()
}