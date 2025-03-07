import socket

target = input("Enter target IP: ")
ports = [21, 22, 25, 53, 80, 443, 3389, 8080, 3306]

for port in ports:
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.settimeout(1)  # Set timeout for connection attempt
    result = sock.connect_ex((target, port))
    
    if result == 0:
        print(f"✅ Port {port} is OPEN on {target}")
    else:
        print(f"❌ Port {port} is CLOSED on {target}")
    
    sock.close()
