#pragma once

namespace GME {
    class Application {
    public:
        Application();
        virtual ~Application();

        void run();
    };

    Application* createApplication();
}