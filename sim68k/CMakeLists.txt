#project(add-something)
#include_directories(${add_SOURCE_DIR})

link_directories(${GTK_INCLUDE_DIRS},
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(${GTK_LIBRARY_DIRS}, 
    ${GTKMM_INCLUDE_DIRS}  )


# Include the extension module.
list(APPEND CMAKE_MODULE_PATH  ../GCR_CMake/macros)

include(GlibCompileResourcesSupport)

# Set the resources to bundle.
set(RESOURCE_LIST
    resources/mainWindow.glade
    resources/pushbutton.bmp
    resources/pushbutton2.bmp
    resources/pushbutton3.bmp
    )

# Compile the resources.
compile_gresources(RESOURCE_FILE
                   XML_OUT
                   TYPE EMBED_C
                   RESOURCES ${RESOURCE_LIST})

# Add a custom target to the makefile. Now make builds our resource file.
# It depends on the output RESOURCE_FILE.
#add_custom_target(resource ALL DEPENDS ${RESOURCE_FILE})

add_custom_command(OUTPUT resource ALL DEPENDS ${RESOURCE_FILE})


# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
#include_directories(${GTK_INCLUDE_DIRS})
#link_directories(${GTK_LIBRARY_DIRS})

add_executable(sim68k src/sim68k.cpp resources.c)

target_link_libraries(sim68k ${GTK3_LIBRARIES} ${GTKMM_LIBRARIES} )