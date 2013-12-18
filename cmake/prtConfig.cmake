set(PRT_PROJECT prt)
find_path(PRT_INSTALL_PATH NAMES "cmake/${PRT_PROJECT}Config.cmake" PATHS ${CMAKE_CURRENT_LIST_DIR}/..)

set(PRT_INCLUDE_PATH ${PRT_INSTALL_PATH}/include)

if(WIN32)
	set(LIBSUF ${CMAKE_IMPORT_LIBRARY_SUFFIX})
else()
	set(LIBSUF ${CMAKE_SHARED_LIBRARY_SUFFIX})
endif()

find_library(PRT_LIBRARY NAMES ${CMAKE_SHARED_LIBRARY_PREFIX}com.esri.prt.core${LIBSUF} HINTS ${PRT_INSTALL_PATH}/bin)

set(PRT_LIBRARIES)
list(APPEND PRT_LIBRARIES ${PRT_LIBRARY})
list(APPEND PRT_LIBRARIES ${PRT_INSTALL_PATH}/bin/${CMAKE_SHARED_LIBRARY_PREFIX}com.esri.prt.loader${CMAKE_SHARED_LIBRARY_SUFFIX})
if(WIN32)
	list(APPEND PRT_LIBRARIES ${PRT_INSTALL_PATH}/bin/${CMAKE_SHARED_LIBRARY_PREFIX}com.esri.prt.core${CMAKE_SHARED_LIBRARY_SUFFIX})
endif()

set(PRT_EXT_LIBRARIES)
list(APPEND PRT_EXT_LIBRARIES ${PRT_INSTALL_PATH}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}com.esri.prt.codecs${CMAKE_SHARED_LIBRARY_SUFFIX})
list(APPEND PRT_EXT_LIBRARIES ${PRT_INSTALL_PATH}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}com.esri.prt.adaptors${CMAKE_SHARED_LIBRARY_SUFFIX})

set(PRT_PYTHON_PATH ${PRT_INSTALL_PATH}/python)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(${PRT_PROJECT} DEFAULT_MSG PRT_LIBRARY PRT_INCLUDE_PATH)
