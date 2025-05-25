add_executable(stoat main.cpp)

include_directories(
    ../lib/stapplication
)

target_link_libraries(stoat PRIVATE Qt${QT_VERSION}::Widgets StoatPrivate)
