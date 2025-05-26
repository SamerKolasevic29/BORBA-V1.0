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

# Exponuj ttyd port
EXPOSE 7681

# Pokreni aplikaciju kroz ttyd (u writable režimu)
CMD ["ttyd", "--writable", "-p", "7681", "./borba"]
