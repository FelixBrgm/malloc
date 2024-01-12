# Use an official lightweight base image
FROM debian:bullseye-slim

# Install necessary tools
RUN apt-get update && apt-get install -y \
	build-essential \
	curl \
	gcc \
	gdb \
	git \
	pkg-config \
	&& rm -rf /var/lib/apt/lists/*

# Install Rust
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
ENV PATH="/root/.cargo/bin:${PATH}"