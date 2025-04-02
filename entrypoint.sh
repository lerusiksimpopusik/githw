#!/bin/bash

# Ждем появления файла с результатами
while [ ! -f /usr/share/nginx/html/index.txt ]; do
  sleep 1
done

# Конвертируем в HTML
sed 's/$/<br>/' /usr/share/nginx/html/index.txt > /usr/share/nginx/html/index.html

# Запускаем Nginx
nginx -g "daemon off;"