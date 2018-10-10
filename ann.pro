TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    src/neuron.cpp \
    src/synapse.cpp \
    src/inputneuron.cpp \
    src/vector.cpp \
    src/matrix.cpp \
    src/layer.cpp \
    src/inputlayer.cpp \
    src/axon.cpp

HEADERS += \
    src/neuron.hpp \
    src/inputneuron.hpp \
    src/vector.hpp \
    src/matrix.hpp \
    src/layer.hpp \
    src/inputlayer.hpp \
    src/transferfunc.hpp
