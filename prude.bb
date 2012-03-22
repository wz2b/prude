DESCRIPTION="PRU Debugger (ncurses)"
HOMEPAGE="https://github.com/wz2b/prude"

LICENSE="GPLv2"
LIC_FILES_CHKSUM="file://LICENSE.TXT;md5=b234ee4d69f5fce4486a80fdaf4a4263"

DEPENDS="ncurses panel"

# SRCREV="7c860c58162f7119763988c1f241fe64a47f486e"
SRCREV="${AUTOREV}"
SRC_URI="git://github.com/wz2b/prude.git;branch=master"

S="${WORKDIR}/git"

do_compile() {
        oe_runmake
}

do_install() {
        install -d ${D}${bindir}
        install -m 0755 prude ${D}${bindir}
}
