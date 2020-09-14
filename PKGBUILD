_pkgname=minitraycal
pkgname=$_pkgname-git
pkgver=1.0.2a3d118
pkgrel=1
pkgdesc="A small tray launcher for gsimplecal"
arch=('i686' 'x86_64')
url="https://github.com/karabaja4/minitraycal"
license=('GPL')
depends=('qt5-base' 'gsimplecal')
provides=('minitraycal')
conflicts=('minitraycal')
source=('git+https://github.com/karabaja4/minitraycal.git')
md5sums=('SKIP')

pkgver() {
  cd "$_pkgname"
  echo "1.0.$(git rev-parse --short HEAD)"
}

build() {
  cd "$_pkgname"
  [[ -d build ]] || mkdir build
  cd build
  qmake ..
  make
}

package() {
  cd $_pkgname/build
  make INSTALL_ROOT="$pkgdir" install
}
