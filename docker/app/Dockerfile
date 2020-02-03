FROM debian:bullseye

# Install packages and tools
RUN \
    apt update && \
    apt -y install \
        gcc \
        make \
        git \
        binutils \
        libc6-dev && \

    # clean repository
    apt clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Swithing working directory
WORKDIR /workspace
