# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build"

# Include any dependencies generated for this target.
include lib/mbedtls/library/CMakeFiles/mbedtls.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/mbedtls/library/CMakeFiles/mbedtls.dir/compiler_depend.make

# Include the compile flags for this target's objects.
include lib/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make

lib/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
lib/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/includes_C.rsp
lib/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.obj: C:/VSARM/sdk/pico/pico-sdk/lib/mbedtls/library/debug.c
lib/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/compiler_depend.ts
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.obj -MF CMakeFiles\mbedtls.dir\debug.c.obj.d -o CMakeFiles\mbedtls.dir\debug.c.obj -c C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\debug.c

lib/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/debug.c.i"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\debug.c > CMakeFiles\mbedtls.dir\debug.c.i

lib/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/debug.c.s"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\debug.c -o CMakeFiles\mbedtls.dir\debug.c.s

lib/mbedtls/library/CMakeFiles/mbedtls.dir/net_sockets.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
lib/mbedtls/library/CMakeFiles/mbedtls.dir/net_sockets.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/includes_C.rsp
lib/mbedtls/library/CMakeFiles/mbedtls.dir/net_sockets.c.obj: C:/VSARM/sdk/pico/pico-sdk/lib/mbedtls/library/net_sockets.c
lib/mbedtls/library/CMakeFiles/mbedtls.dir/net_sockets.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/compiler_depend.ts
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/mbedtls/library/CMakeFiles/mbedtls.dir/net_sockets.c.obj -MF CMakeFiles\mbedtls.dir\net_sockets.c.obj.d -o CMakeFiles\mbedtls.dir\net_sockets.c.obj -c C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\net_sockets.c

lib/mbedtls/library/CMakeFiles/mbedtls.dir/net_sockets.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/net_sockets.c.i"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\net_sockets.c > CMakeFiles\mbedtls.dir\net_sockets.c.i

lib/mbedtls/library/CMakeFiles/mbedtls.dir/net_sockets.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/net_sockets.c.s"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\net_sockets.c -o CMakeFiles\mbedtls.dir\net_sockets.c.s

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/includes_C.rsp
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.obj: C:/VSARM/sdk/pico/pico-sdk/lib/mbedtls/library/ssl_cache.c
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/compiler_depend.ts
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.obj -MF CMakeFiles\mbedtls.dir\ssl_cache.c.obj.d -o CMakeFiles\mbedtls.dir\ssl_cache.c.obj -c C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_cache.c

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_cache.c.i"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_cache.c > CMakeFiles\mbedtls.dir\ssl_cache.c.i

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_cache.c.s"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_cache.c -o CMakeFiles\mbedtls.dir\ssl_cache.c.s

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/includes_C.rsp
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj: C:/VSARM/sdk/pico/pico-sdk/lib/mbedtls/library/ssl_ciphersuites.c
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/compiler_depend.ts
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj -MF CMakeFiles\mbedtls.dir\ssl_ciphersuites.c.obj.d -o CMakeFiles\mbedtls.dir\ssl_ciphersuites.c.obj -c C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_ciphersuites.c

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.i"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_ciphersuites.c > CMakeFiles\mbedtls.dir\ssl_ciphersuites.c.i

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.s"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_ciphersuites.c -o CMakeFiles\mbedtls.dir\ssl_ciphersuites.c.s

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/includes_C.rsp
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.obj: C:/VSARM/sdk/pico/pico-sdk/lib/mbedtls/library/ssl_cli.c
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/compiler_depend.ts
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.obj -MF CMakeFiles\mbedtls.dir\ssl_cli.c.obj.d -o CMakeFiles\mbedtls.dir\ssl_cli.c.obj -c C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_cli.c

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_cli.c.i"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_cli.c > CMakeFiles\mbedtls.dir\ssl_cli.c.i

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_cli.c.s"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_cli.c -o CMakeFiles\mbedtls.dir\ssl_cli.c.s

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/includes_C.rsp
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.obj: C:/VSARM/sdk/pico/pico-sdk/lib/mbedtls/library/ssl_cookie.c
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/compiler_depend.ts
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.obj -MF CMakeFiles\mbedtls.dir\ssl_cookie.c.obj.d -o CMakeFiles\mbedtls.dir\ssl_cookie.c.obj -c C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_cookie.c

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_cookie.c.i"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_cookie.c > CMakeFiles\mbedtls.dir\ssl_cookie.c.i

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_cookie.c.s"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_cookie.c -o CMakeFiles\mbedtls.dir\ssl_cookie.c.s

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_msg.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_msg.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/includes_C.rsp
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_msg.c.obj: C:/VSARM/sdk/pico/pico-sdk/lib/mbedtls/library/ssl_msg.c
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_msg.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/compiler_depend.ts
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_msg.c.obj -MF CMakeFiles\mbedtls.dir\ssl_msg.c.obj.d -o CMakeFiles\mbedtls.dir\ssl_msg.c.obj -c C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_msg.c

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_msg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_msg.c.i"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_msg.c > CMakeFiles\mbedtls.dir\ssl_msg.c.i

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_msg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_msg.c.s"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_msg.c -o CMakeFiles\mbedtls.dir\ssl_msg.c.s

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/includes_C.rsp
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.obj: C:/VSARM/sdk/pico/pico-sdk/lib/mbedtls/library/ssl_srv.c
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/compiler_depend.ts
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.obj -MF CMakeFiles\mbedtls.dir\ssl_srv.c.obj.d -o CMakeFiles\mbedtls.dir\ssl_srv.c.obj -c C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_srv.c

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_srv.c.i"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_srv.c > CMakeFiles\mbedtls.dir\ssl_srv.c.i

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_srv.c.s"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_srv.c -o CMakeFiles\mbedtls.dir\ssl_srv.c.s

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/includes_C.rsp
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.obj: C:/VSARM/sdk/pico/pico-sdk/lib/mbedtls/library/ssl_ticket.c
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/compiler_depend.ts
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.obj -MF CMakeFiles\mbedtls.dir\ssl_ticket.c.obj.d -o CMakeFiles\mbedtls.dir\ssl_ticket.c.obj -c C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_ticket.c

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_ticket.c.i"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_ticket.c > CMakeFiles\mbedtls.dir\ssl_ticket.c.i

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_ticket.c.s"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_ticket.c -o CMakeFiles\mbedtls.dir\ssl_ticket.c.s

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/includes_C.rsp
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.obj: C:/VSARM/sdk/pico/pico-sdk/lib/mbedtls/library/ssl_tls.c
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/compiler_depend.ts
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.obj -MF CMakeFiles\mbedtls.dir\ssl_tls.c.obj.d -o CMakeFiles\mbedtls.dir\ssl_tls.c.obj -c C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_tls.c

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_tls.c.i"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_tls.c > CMakeFiles\mbedtls.dir\ssl_tls.c.i

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_tls.c.s"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_tls.c -o CMakeFiles\mbedtls.dir\ssl_tls.c.s

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls13_keys.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls13_keys.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/includes_C.rsp
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls13_keys.c.obj: C:/VSARM/sdk/pico/pico-sdk/lib/mbedtls/library/ssl_tls13_keys.c
lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls13_keys.c.obj: lib/mbedtls/library/CMakeFiles/mbedtls.dir/compiler_depend.ts
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls13_keys.c.obj -MF CMakeFiles\mbedtls.dir\ssl_tls13_keys.c.obj.d -o CMakeFiles\mbedtls.dir\ssl_tls13_keys.c.obj -c C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_tls13_keys.c

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls13_keys.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_tls13_keys.c.i"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_tls13_keys.c > CMakeFiles\mbedtls.dir\ssl_tls13_keys.c.i

lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls13_keys.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_tls13_keys.c.s"
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && C:\VSARM\mingw\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library\ssl_tls13_keys.c -o CMakeFiles\mbedtls.dir\ssl_tls13_keys.c.s

# Object files for target mbedtls
mbedtls_OBJECTS = \
"CMakeFiles/mbedtls.dir/debug.c.obj" \
"CMakeFiles/mbedtls.dir/net_sockets.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_cache.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_cli.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_cookie.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_msg.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_srv.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_ticket.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_tls.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_tls13_keys.c.obj"

# External object files for target mbedtls
mbedtls_EXTERNAL_OBJECTS =

lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.obj
lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/net_sockets.c.obj
lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.obj
lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj
lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.obj
lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.obj
lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_msg.c.obj
lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.obj
lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.obj
lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.obj
lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls13_keys.c.obj
lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/build.make
lib/mbedtls/library/libmbedtls.a: lib/mbedtls/library/CMakeFiles/mbedtls.dir/link.txt
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && $(CMAKE_COMMAND) -P CMakeFiles\mbedtls.dir\cmake_clean_target.cmake
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mbedtls.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/mbedtls/library/CMakeFiles/mbedtls.dir/build: lib/mbedtls/library/libmbedtls.a
.PHONY : lib/mbedtls/library/CMakeFiles/mbedtls.dir/build

lib/mbedtls/library/CMakeFiles/mbedtls.dir/clean:
	cd /d "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" && $(CMAKE_COMMAND) -P CMakeFiles\mbedtls.dir\cmake_clean.cmake
.PHONY : lib/mbedtls/library/CMakeFiles/mbedtls.dir/clean

lib/mbedtls/library/CMakeFiles/mbedtls.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-src" C:\VSARM\sdk\pico\pico-sdk\lib\mbedtls\library "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build" "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library" "C:\Users\Youssef\Desktop\Uni\sem 7\Embedded Systems\Project\Milestone 0 & 1\blink\build\_deps\picotool-build\lib\mbedtls\library\CMakeFiles\mbedtls.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : lib/mbedtls/library/CMakeFiles/mbedtls.dir/depend

