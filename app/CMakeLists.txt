cmake_minimum_required(VERSION 3.4.1)

set( OpenCV_DIR D:/opencv-3.3.1-android-sdk/OpenCV-android-sdk/sdk/native/jni )
# set(WITH_TBB OFF CACHE BOOL "Include Intel TBB support")

# set(WITH_IPP OFF CACHE BOOL "Include Intel IPP support")

# set(WITH_EIGEN ON CACHE BOOL "Include Eigen2/Eigen3 support")

# set(WITH_CUDA ON CACHE BOOL "Include NVidia Cuda Runtime support")

# set(WITH_OPENNI OFF CACHE BOOL "Include OpenNI support")
find_package(OpenCV REQUIRED )
if(OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    message(STATUS "OpenCV library status:")
    message(STATUS "    version: ${OpenCV_VERSION}")
    message(STATUS "    libraries: ${OpenCV_LIBS}")
    message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
else(OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV library not found")
endif(OpenCV_FOUND)
add_library( native-lib
             SHARED
             src/main/cpp/native-lib.cpp )

target_link_libraries( native-lib
                        ${OpenCV_LIBS}
                       log )