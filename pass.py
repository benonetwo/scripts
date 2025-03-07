import hashlib

password = input("Enter password: ")
hashed_password = hashlib.sha256(password.encode()).hexdigest()

print(f"SHA-256 Hashed Password: {hashed_password}")
