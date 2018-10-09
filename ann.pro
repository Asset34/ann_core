TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    src/neuron.cpp \
    src/akson.cpp \
    src/synapse.cpp \
    src/inputneuron.cpp \
    src/vector.cpp \
    src/matrix.cpp

HEADERS += \
    src/activationfunction.hpp \
    src/neuron.hpp \
    src/inputneuron.hpp \
    src/vector.hpp \
    src/matrix.hpp
