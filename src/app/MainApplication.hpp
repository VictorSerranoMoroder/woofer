#pragma once 

#include <QApplication>
#include <qapplication.h>

namespace app 
{
    /// @brief
    ///
    /// @details
    class MainApplication : public QApplication
    {
        public:
        MainApplication(int &argc, char **argv);
    
        // Non Copyable
        MainApplication(const MainApplication&) = delete;
        MainApplication& operator=(const MainApplication&) = delete;
    
        // Non Movable
        MainApplication(MainApplication&&) = delete;
        MainApplication& operator=(MainApplication&&) = delete;
    
    };
}