#include "Application.h"
#include "Log/Logger.h"

#include <iostream>
namespace GME {
    Application::Application() {

    }

    Application::~Application() {

    }

    void Application::run() {
        std::cout << "Running!" << std::endl;
        GME_ENGINE_INFO("RUNING!!!! from logger");
    }
}