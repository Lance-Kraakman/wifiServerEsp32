# @Caleb

Here is the link to set up the eclipse editor
https://github.com/espressif/idf-eclipse-plugin/blob/master/README.md

If you get a brownout error it just means you need a better usb cable

im going to create a branch so i can try and make a get request to the esp32 and which wil turn it off/on based on a paramater from the request. But the msater version of this currently shows the not set variable. 

The below is why the handshake failed i didnt set it up properly @Caleb. But the program worked it did work it just isnt secure when you try and send it a request :(
It will give the handshake error on the log if you look at the console. There are many guides online to set-up the certificates including the https server example. 

# HTTP server with SSL support using OpenSSL

This example creates a SSL server that returns a simple HTML page when you visit its root URL.

See the `esp_https_server` component documentation for details.

Before using the example, open the project configuration menu (`idf.py menuconfig`) to configure Wi-Fi or Ethernet. See "Establishing Wi-Fi or Ethernet Connection" section in [examples/protocols/README.md](../README.md) for more details.

## Certificates

You will need to approve a security exception in your browser. This is because of a self signed
certificate; this will be always the case, unless you preload the CA root into your browser/system
as trusted.

You can generate a new certificate using the OpenSSL command line tool:

```
openssl req -newkey rsa:2048 -nodes -keyout prvtkey.pem -x509 -days 3650 -out cacert.pem -subj "/CN=ESP32 HTTPS server example"
```

Expiry time and metadata fields can be adjusted in the invocation.

Please see the openssl man pages (man openssl-req) for more details.

It is **strongly recommended** to not reuse the example certificate in your application;
it is included only for demonstration.


