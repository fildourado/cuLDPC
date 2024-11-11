FROM nvidia/cuda:12.6.1-devel-ubuntu24.04

SHELL ["/bin/bash", "-c"]

# Set environment variables for non-interactive installation
ENV DEBIAN_FRONTEND=noninteractive

ARG USERNAME=ubuntu
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create the user
#RUN groupadd --gid $USER_GID $USERNAME \
#    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    #
    # [Optional] Add sudo support. Omit if you don't need to install software after connecting.
RUN apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME


# Update and install system dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    libgtest-dev \
    libeigen3-dev \
    python3 \
    python3-pip \
    python3-venv \
    python3-numpy \
    git \
    curl \
    wget \
    zip \
    unzip \
    libssl-dev \
    pkg-config


WORKDIR /tmp
RUN git clone https://github.com/gabime/spdlog.git
RUN mkdir spdlog/build
WORKDIR /tmp/spdlog/build
RUN cmake .. && make -j
RUN make install

RUN apt-get install -y python3-full

USER ${USERNAME}

# Generate a python venv
RUN python3 -m venv ~/venv
RUN echo 'source ~/venv/bin/activate' >> ~/.bashrc

RUN . ~/venv/bin/activate && \
    pip install numpy && \
    pip install pytest && \
    pip install pybind11 && \
    pip install setuptools && \
    pip install --no-build-isolation pyldpc

#RUN rm -rf /var/lib/apt/lists/*

