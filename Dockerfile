FROM debian:10.12

ENV DEBIAN_FRONTEND noninteractive
ENV PATH="${PATH}:/opt/KasperskyOS-Community-Edition-1.1.1.40/toolchain/bin"

COPY KasperskyOS-Community-Edition_1.1.1.40_en.deb /kos/

RUN apt-get update && \
    apt install -y --fix-broken /kos/KasperskyOS-Community-Edition_1.1.1.40_en.deb && \
    apt install -y curl vim

RUN mkdir -p /tmp/firefighter-drone/civetweb && \
    cd /tmp/firefighter-drone/civetweb && \
    curl -L -s -o v1.15.tar.gz https://github.com/civetweb/civetweb/archive/refs/tags/v1.15.tar.gz && \
    tar xzf v1.15.tar.gz && \
    cd civetweb-1.15 && \
    mkdir .build && \
    cd .build && \
    cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=None -DCMAKE_INSTALL_SYSCONFDIR=/etc -DCMAKE_INSTALL_LOCALSTATEDIR=/var -DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON -DCMAKE_FIND_USE_PACKAGE_REGISTRY=OFF -DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON -DFETCHCONTENT_FULLY_DISCONNECTED=ON -DCMAKE_INSTALL_RUNSTATEDIR=/run -DCMAKE_SKIP_INSTALL_ALL_DEPENDENCY=ON "-GUnix Makefiles" -DCMAKE_VERBOSE_MAKEFILE=ON -DCMAKE_INSTALL_LIBDIR=lib/x86_64-linux-gnu -DCMAKE_BUILD_TYPE=None -DCIVETWEB_BUILD_TESTING=OFF -DCIVETWEB_SOVERSION=1 -DCIVETWEB_ENABLE_CXX=ON -DBUILD_SHARED_LIBS=ON -DCIVETWEB_ENABLE_WEBSOCKETS=ON .. && \
    make -j4 "INSTALL=install --strip-program=true" VERBOSE=1 && \
    make install && \
    rm -rf /tmp/firefighter-drone


CMD ["bash"]
