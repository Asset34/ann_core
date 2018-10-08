TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
    src/neuron.cpp \
    src/akson.cpp \
    src/synapse.cpp \
    src/inputneuron.cpp \
    src/outputneuron.cpp

HEADERS += \
    src/activationfunction.hpp \
    src/neuron.hpp \
    src/inputneuron.hpp \
    src/outputneuron.hpp
