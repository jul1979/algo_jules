TEMPLATE = app
CONFIG += console # c++11
QMAKE_CXXFLAGS += -std=c++17 -pedantic-errors
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        carremagique.cpp \
        knight.cpp \
        linkedlistiterator.cpp \
        linkedlisttype.cpp \
        main.cpp \
        nQueensPuzzle.cpp \
        position.cpp \
        sudoku.cpp

HEADERS += \
    carremagique.h \
    knight.h \
    linkedlistiterator.h \
    linkedlisttype.h \
    nQueensPuzzle.h \
    position.h \
    sudoku.h
