cmake_minimum_required(VERSION 3.21)  # Qt6 requires at least 3.21
project(woofer VERSION 1.0 LANGUAGES CXX)

# Enable C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

# Find Qt6 packages (Core and Widgets as example)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Qml QuickControls2)

# Find Boost libraries - adjust components as needed
find_package(Boost REQUIRED COMPONENTS filesystem system)

# Create executable from source file
add_executable(woofer src/main.cpp)

# Link Qt6 libraries
target_link_libraries(woofer PRIVATE Qt6::Core Qt6::Widgets Qt6::Qml Qt6::QuickControls2)

# Link Boost libraries
target_link_libraries(woofer PRIVATE Boost::filesystem Boost::system)

# Include directories (optional, Boost usually adds them)
target_include_directories(woofer PRIVATE ${Boost_INCLUDE_DIRS})

# Enable automatic MOC, UIC, RCC processing by Qt6
set_target_properties(woofer PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)
