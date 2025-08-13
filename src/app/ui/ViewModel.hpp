#pragma once

namespace app::ui 
{
    /// @brief
    ///
    /// @details
    class ViewModel
    {
        public:
        ViewModel() = default;
    
        // Copyable
        ViewModel(const ViewModel&) = default;
        ViewModel& operator=(const ViewModel&) = default;
    
        // Movable
        ViewModel(ViewModel&&) = default;
        ViewModel& operator=(ViewModel&&) = default;
    
    };
}