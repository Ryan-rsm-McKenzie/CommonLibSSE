cmake_minimum_required(VERSION 3.18)

# ---- Project ----

project(
	CommonLibSSE
	VERSION 1.0.0
	LANGUAGES CXX
)

# ---- Include guards ----

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
	message(
		FATAL_ERROR
			"In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
)
endif()

# ---- Dependencies ----

find_package(span-lite REQUIRED CONFIG)
find_package(spdlog REQUIRED CONFIG)

# ---- Add source files ----

include(cmake/headerlist.cmake)
include(cmake/sourcelist.cmake)

source_group(
	TREE ${CMAKE_CURRENT_SOURCE_DIR}
	FILES ${headers} ${sources}
)

# ---- Create library ----

set(MSVC_OPTIONS
	/TP	# Specify Source File Type (C++)
	
	/experimental:external
	/external:anglebrackets
	/external:W0
	
	# warnings -> errors
	/we4715	# 'function' : not all control paths return a value
	
	# disable warnings
	/wd4061 # enumerator 'identifier' in switch of enum 'enumeration' is not explicitly handled by a case label
	/wd4200 # nonstandard extension used : zero-sized array in struct/union
	/wd4265 # 'type': class has virtual functions, but its non-trivial destructor is not virtual; instances of this class may not be destructed correctly
	/wd4266 # 'function' : no override available for virtual member function from base 'type'; function is hidden
	/wd4371 # 'classname': layout of class may have changed from a previous version of the compiler due to better packing of member 'member'
	/wd4514 # 'function' : unreferenced inline function has been removed
	/wd4582 # 'type': constructor is not implicitly called
	/wd4583 # 'type': destructor is not implicitly called
	/wd4623 # 'derived class' : default constructor was implicitly defined as deleted because a base class default constructor is inaccessible or deleted
	/wd4625 # 'derived class' : copy constructor was implicitly defined as deleted because a base class copy constructor is inaccessible or deleted
	/wd4626 # 'derived class' : assignment operator was implicitly defined as deleted because a base class assignment operator is inaccessible or deleted
	/wd4710 # 'function' : function not inlined
	/wd4711 # function 'function' selected for inline expansion
	/wd4820 # 'bytes' bytes padding added after construct 'member_name'
	/wd5026 # 'type': move constructor was implicitly defined as deleted
	/wd5027 # 'type': move assignment operator was implicitly defined as deleted
	/wd5045 # Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
	/wd5053 # support for 'explicit(<expr>)' in C++17 and earlier is a vendor extension
	/wd5204 # 'type-name': class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly
	/wd5220 # 'member': a non-static data member with a volatile qualified type no longer implies that compiler generated copy / move constructors and copy / move assignment operators are not trivial
)

add_library(CommonLibSSE STATIC
	${headers}
	${sources}
	.clang-format
	CommonLibSSE.natvis
)

target_compile_definitions(CommonLibSSE
	PUBLIC
		WINVER=0x0601	# windows 7, minimum supported version by skyrim special edition
		_WIN32_WINNT=0x0601
		SPDLOG_COMPILED_LIB
)

target_compile_features(CommonLibSSE
	PUBLIC
		cxx_std_17
)

target_compile_options(CommonLibSSE
	PRIVATE
		"$<$<BOOL:${MSVC}>:${MSVC_OPTIONS}>"
)

target_include_directories(CommonLibSSE
	PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(CommonLibSSE
	PUBLIC
		nonstd::span-lite
		spdlog::spdlog
		Version.lib
)

target_precompile_headers(CommonLibSSE
	PRIVATE
		include/SKSE/Impl/PCH.h
)

# ---- Create an installable target ----

include(GNUInstallDirs)

install(
	TARGETS CommonLibSSE
	EXPORT CommonLibSSE-targets
)

install(
	DIRECTORY include/
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

configure_file(
	cmake/config.cmake.in
	CommonLibSSEConfig.cmake
	@ONLY
)

install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/CommonLibSSEConfig.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CommonLibSSE
)

install(
	EXPORT CommonLibSSE-targets
	NAMESPACE CommonLibSSE::
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CommonLibSSE
)
