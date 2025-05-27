FROM gcc:latest

# Instaliraj zavisnosti i ttyd
RUN apt-get update && apt-get install -y \
    cmake \
    git \
    libjson-c-dev \
    libwebsockets-dev \
    build-essential \
 && git clone https://github.com/tsl0922/ttyd.git \
 && cd ttyd && mkdir build && cd build && cmake .. && make && make install \
 && cd / && rm -rf ttyd

# Postavi radni direktorijum
WORKDIR /app

# Kopiraj sve fajlove u kontejner
COPY . .

# Buildaj projekat (koristi make)
RUN make

# Exponuj port koji Render koristi (automatski postavlja $PORT)
EXPOSE 10000

# Pokreni aplikaciju kroz ttyd koristeći $PORT koji Render automatski dodijeli
CMD ["sh", "-c", "ttyd --writable -p $PORT ./borba"]
