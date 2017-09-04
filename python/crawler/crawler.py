#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def fetach(url):
    sock = socket.socket()
    sock.connect(('xkcd.com', 80))
    request = 'GET {} HTTP/1.0\r\nHost: xkcd.com\r\n\r\n'.format(url)
    sock.send(request.encode('ascii'))
    respones = b''
    chunk = sock.recv(4096)
    while chunk:
        respones += chunk
        chunk = sock.recv(4096)

    links = parse_links(response)
    q.add(links)
