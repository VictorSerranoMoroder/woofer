#pragma once 

#include <QGuiApplication>
#include <app/ui/Controller.hpp>

namespace app 
{
    /// @brief
    ///
    /// @details
    class MainApplication : public QGuiApplication
    {
        public:
        MainApplication(int &argc, char **argv);
    
        // Non Copyable
        MainApplication(const MainApplication&) = delete;
        MainApplication& operator=(const MainApplication&) = delete;
    
        // Non Movable
        MainApplication(MainApplication&&) = delete;
        MainApplication& operator=(MainApplication&&) = delete;
    

        private:

        ui::Controller controller_;
    };
}