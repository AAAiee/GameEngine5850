#include "Engine.h"

class ExampleApp : public GME::Application {
public:
    ExampleApp() {

    }

    ~ExampleApp() {

    }
};

GME::Application* GME::createApplication() {
    return new ExampleApp();
}