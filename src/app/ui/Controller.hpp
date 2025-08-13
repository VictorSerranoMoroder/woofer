#pragma once

#include <app/ui/ViewModel.hpp>

namespace app::ui
{
    /// @brief
    ///
    /// @details
    class Controller
    {
        public:
        Controller() = default;
    
        // Copyable
        Controller(const Controller&) = default;
        Controller& operator=(const Controller&) = default;
    
        // Movable
        Controller(Controller&&) = default;
        Controller& operator=(Controller&&) = default;
    
        private:

        ViewModel viewmodel_;
    };
}