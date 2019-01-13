TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lSDL2 -lSDL2_image -lSDL2_ttf

HEADERS += \
    src/Renderers/Sprite.h \
    src/Renderers/Window.h \
    src/Intefaces/NonCopyable.h \
    src/Intefaces/Drawable.h \
    src/Utils/Log.h \
    src/Objects/GameObject.h \
    src/Objects/AbstractObject.h \
    src/Managers/FontManager.h \
    src/Managers/TextureManager.h \
    src/Renderers/ElasticSprite.h \
    src/Renderers/Text.h \
    src/Entities/Camera.h \
    src/Widgets/Label.h \
    src/Widgets/Widget.h \
    src/Entities/InputHandler.h \
    src/Entities/Handler.h \
    src/Widgets/Button.h

SOURCES += \
    src/Renderers/Sprite.cpp \
    src/main.cpp \
    src/Renderers/Window.cpp \
    src/Intefaces/NonCopyable.cpp \
    src/Intefaces/Drawable.cpp \
    src/Utils/Log.cpp \
    src/Objects/GameObject.cpp \
    src/Objects/AbstractObject.cpp \
    src/Managers/FontManager.cpp \
    src/Managers/TextureManager.cpp \
    src/Renderers/ElasticSprite.cpp \
    src/Renderers/Text.cpp \
    src/Examples/Example1.cpp \
    src/Entities/Camera.cpp \
    src/Widgets/Label.cpp \
    src/Widgets/Widget.cpp \
    src/Entities/InputHandler.cpp \
    src/Entities/Handler.cpp \
    src/Widgets/Button.cpp
