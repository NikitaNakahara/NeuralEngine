#include <iostream>

#include <Graphic/Graphic.hpp>

#include <unistd.h>

int main() {
    Graphic::MyWindow window = Graphic::createWindow(800, 600, "Neural Engine");
    window.initGraphicContext();

    window.draw();

    sleep(5);

    return 0;
}