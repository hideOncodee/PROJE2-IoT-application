idf_component_register(SRCS "dht.c" "http_server.c" "devices.c" "wifi_app.c" "main.c" "rgb_led.c"
                    INCLUDE_DIRS "."
                    EMBED_FILES webpage/app.css webpage/app.js webpage/favicon.ico webpage/index.html webpage/jquery-3.3.1.min.js)