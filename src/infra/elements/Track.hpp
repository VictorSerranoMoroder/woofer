#pragma once

namespace infra::elements 
{
    /// @brief
    ///
    /// @details
    class Track
    {
        public:
        Track() = default;
    
        // Copyable
        Track(const Track&) = default;
        Track& operator=(const Track&) = default;
    
        // Movable
        Track(Track&&) = default;
        Track& operator=(Track&&) = default;
    
    };
}