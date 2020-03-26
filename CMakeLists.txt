#AUTHOR: Julian Andres Guarin Reyes. 
#This is an advanced build of OpenCV
#The Software built here is for AlephZero special library purposes. 
#Please Do Not Distribute Or Use It. 


cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(OpenCVSample)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

if (APPLE)
    message(STATUS "-- APPLE DETECTED --")
    find_package(OpenCV REQUIRED)
endif()
add_executable(sample sample.cpp)

get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

if(APPLE)
    include_directories(
        ${OpenCV_INCLUDE_DIRS}
        )
    target_link_libraries(sample PRIVATE ${OpenCV_LIBRARIES})
else()
    message(STATUS " ON A LINUX")
    target_link_libraries(sample PRIVATE 
        -ltbb
        -lopencv_shape 
        -lopencv_stitching 
        -lopencv_superres 
        -lopencv_videostab 
        -lopencv_aruco 
        -lopencv_bgsegm 
        -lopencv_bioinspired 
        -lopencv_ccalib 
        -lopencv_datasets 
        -lopencv_dpm 
        -lopencv_face 
        -lopencv_freetype 
        -lopencv_fuzzy 
        -lopencv_hdf 
        -lopencv_line_descriptor 
        -lopencv_optflow 
        -lopencv_video 
        -lopencv_plot 
        -lopencv_reg 
        -lopencv_saliency 
        -lopencv_stereo 
        -lopencv_structured_light 
        -lopencv_phase_unwrapping 
        -lopencv_rgbd 
        -lopencv_viz 
        -lopencv_surface_matching 
        -lopencv_text 
        -lopencv_ximgproc 
        -lopencv_calib3d 
        -lopencv_features2d 
        -lopencv_flann 
        -lopencv_xobjdetect 
        -lopencv_objdetect 
        -lopencv_ml 
        -lopencv_xphoto 
        -lopencv_highgui 
        -lopencv_videoio 
        -lopencv_imgcodecs 
        -lopencv_photo 
        -lopencv_imgproc 
        -lopencv_core
        -lpthread
        -ldl
        -lz
        -ljpeg
        -ltiff
        -lpng
        -ldc1394
        -lavcodec
        -lavutil
        -lavformat
        -lwebp
        -lcairo
        -lswscale
        -lX11
        -lIlmImf
        -lgtk-3
        -lgdk-3
        -lgdk_pixbuf-2.0
        -lglib-2.0 
        -lgobject-2.0)
endif()

#include_directories(/usr/local/Cellar/opencv/4.2.0_3/include/opencv4)
#    "-framework AVFoundation"
#    "-framework CoreMedia"
#    "-framework CoreFoundation"
#    "-framework CoreGraphics"
#    "-framework CoreVideo"
#    "-framework Foundation"
    
#)