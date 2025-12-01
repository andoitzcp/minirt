FROM ubuntu:latest
WORKDIR /app
#RUN find /app -mindepth 1 -delete
RUN apt-get update && apt-get install -y \
    gcc \
    make \
    git \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    x11proto-dev
COPY . .
RUN make getmlx
RUN cd ../minilibx-linux && make
RUN make
RUN chmod a+rwx /app/minirt
