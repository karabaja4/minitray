SOURCES       = main.cpp
RESOURCES     = minitray.qrc

QT += widgets
requires(qtConfig(combobox))

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/desktop/minitray
INSTALLS += target
