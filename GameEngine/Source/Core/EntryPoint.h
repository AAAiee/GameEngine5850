// The entry point of the program.
#pragma once

extern GME::Application* GME::createApplication();

int main(/*int argc, char** argv*/) {
    GME::Application* app = GME::createApplication();
    app->run();

    delete app;
    return 0;
}