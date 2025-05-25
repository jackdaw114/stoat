add_definitions(-DSTOAT_SHAREDLIBRARY)
set(SRCS
    app/stapplication.cpp
    app/mainwindow.cpp
    menubar/menubar.cpp
    viewport/openglwindow.cpp
)

add_library(StoatPrivate SHARED ${SRCS})

target_include_directories(StoatPrivate PUBLIC app "." vendor/entt components)

target_compile_options(StoatPrivate PRIVATE -Wno-unknown-warning-option)

target_link_libraries(StoatPrivate
    PRIVATE
    Qt${QT_VERSION}::Widgets
    Qt${QT_VERSION}::Core
    Qt${QT_VERSION}::Network
    Qt${QT_VERSION}::Gui
    Qt${QT_VERSION}::OpenGL
)
