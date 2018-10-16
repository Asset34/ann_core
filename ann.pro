TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    src/neuron.cpp \
    src/synapse.cpp \
    src/inputneuron.cpp \
    src/layer.cpp \
    src/inputlayer.cpp \
    src/main.cpp

HEADERS += \
    src/neuron.hpp \
    src/inputneuron.hpp \
    src/layer.hpp \
    src/inputlayer.hpp \
    src/entities.hpp
