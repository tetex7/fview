# Maintainer: tete <tetex7@outlook.com>
pkgname=fview
pkgver=1.0.5
pkgrel=1
pkgdesc='Cat with line numbers'
url='www.github.com/tetex7/fview'
provides=('fview')
arch=('x86_64')
PACKAGER="TRS"
license=('GPL3')
makedepends=()
depends=('gcc-libs' 'glibc')
options=('!strip' 'docs' 'libtool' 'staticlibs' 'emptydirs' 'zipman' '!purge' '!debug' '!lto')

prepare() {
cd ..
echo $PWD
make clean
}

build () {
    cd ..
    make DEBUG=0 VER=${pkgver}
}

package() {
    cd ..
    if [ "$OS" == "Windows_NT" ]; then
        echo "Windows detected"
        install -Dm755 ./fview.exe "${pkgdir}/usr/bin/fview.exe"
    else
        install -Dm755 ./fview "${pkgdir}/usr/bin/fview"
    fi
    rm -rf ./src
}