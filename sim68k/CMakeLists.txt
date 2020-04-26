

# libraries
link_directories(${GTK_INCLUDE_DIRS},
    ${GTKMM_LIBRARY_DIRS}  )

#includes 
include_directories(${GTK_LIBRARY_DIRS}, wrappers
    ${GTKMM_INCLUDE_DIRS}  )


# Include the extension module to support bundled resources
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

# Add a custom command to the makefile. Now make builds our resource file.
# It depends on the output RESOURCE_FILE.
#add_custom_target(resource ALL DEPENDS ${RESOURCE_FILE})

add_custom_command(OUTPUT resource ALL DEPENDS ${RESOURCE_FILE})


add_executable(sim68k 
	src/sim68k.cpp 
	src/run.cpp 
	src/startsim.cpp 
	src/logU.cpp 
	src/code1.cpp 
	src/code2.cpp 
	src/code3.cpp 
	src/code4.cpp 
	src/code5.cpp 
	src/code6.cpp 
	src/code7.cpp 
	src/code8.cpp 
	src/code9.cpp 
	src/utils.cpp 
	src/BPoint.cpp 
	src/BPointExpr.cpp 
	src/hardwareu.cpp
	resources.c)

target_link_libraries(sim68k ${GTK3_LIBRARIES} ${GTKMM_LIBRARIES} )