## \author Hans J. Johnson
cmake_minimum_required(VERSION 3.5.2 FATAL_ERROR)
## Configure the AVR toolchain
include( ${CMAKE_CURRENT_LIST_DIR}/generic-gcc-avr.cmake)

## on mac "https://github.com/osx-cross/homebrew-avr"
## brew tap osx-cross/avr
## brew install avr-gcc
## brew install avrdude
## git clone https://github.com/pololu/libpololu-avr.git
## cd libpololu-avr/
## make
## make install

find_program(AVR_GCC NAMES avr-gcc)
find_program(AVR_GXX NAMES avr-g++)
find_program(AVR_DUDE NAMES avrdude)
find_program(AVR_OBJCOPY NAMES avr-objcopy)

if(NOT EXISTS ${AVR_GCC} )
  message(FATAL_ERROR "avr-gcc is missing")
endif()
if(NOT EXISTS ${AVR_GXX})
  message(FATAL_ERROR "avr-g++ is missing")
endif()
if(NOT EXISTS ${AVR_DUDE})
  message(FATAL_ERROR "avrdude is missing")
endif()
if( NOT EXISTS ${AVR_OBJCOPY})
  message(FATAL_ERROR "avr-objcopy is missing")
endif()

message(STATUS "USING: ${AVR_GCC}, ${AVR_GXX}, ${AVR_DUDE}, and ${AVR_OBJCOPY}")
set(CMAKE_C_COMPILER ${AVR_GCC})
set(CMAKE_CXX_COMPILER ${AVR_GXX})
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(HW2 CXX C)

set(DEVICE atmega328p)
set(MCU atmega328p)
set(AVRDUDE_DEVICE m328p)
#set(DEVICE atmega168)
#set(MCU atmega168)
#set(AVRDUDE_DEVICE m168)

set(CMAKE_C_FLAGS "-g -Wall -mcall-prologues -mmcu=${MCU} ${DEVICE_SPECIFIC_CFLAGS} -Os -std=c99")
set(CMAKE_CXX_FLAGS "-g -Wall -mcall-prologues -mmcu=${MCU} ${DEVICE_SPECIFIC_CFLAGS} -fno-exceptions -Os -std=c++11")
set(CMAKE_LDFLAGS "-Wl,-gc-sections  -Wl,-relax")


file(GLOB POTENTIAL_PORT_NAMES /dev/tty.usbmodem4725 /dev/ttyACM0 /dev/tty.usbmodem*)
message(STATUS "Found candiate ports: ${POTENTIAL_PORT_NAMES}")
list(LENGTH POTENTIAL_PORT_NAMES POTENTIAL_PORT_NAMES_SIZE)
if(POTENTIAL_PORT_NAMES_SIZE GREATER 0)
  list(GET POTENTIAL_PORT_NAMES 0 PORT) #Take first location as PORT setting
  set(PORT "${PORT}" CACHE PATH "A guess for the port to use" FORCE)
else()
  message(STATUS "\nWARNING:\nWARNING:\nSERIAL PORT FOR DOWNLOADING TO ROBOT CAN NOT BE IDENTIFIED AUTOMATICALLY\n\n")
  message(STATUS "   The robot must be connected and turned on for automatic port identification")
  message(STATUS "   to work properly\n\n")
  message(STATUS "   You will need to re-run cmake configuration after the robot is connected to check again")
  message(STATUS "\n\nSet PORT to \"UNKNOWN\" if you just want to compile, but do not want to program the robot")
  message(STATUS "See: https://www.pololu.com/docs/0J36/5.b for identifying the port on a mac computer")
  message(STATUS "\nWARNING:\nWARNING:\nSERIAL PORT FOR DOWNLOADING TO ROBOT IS NOT SET\n\n")
  ## ls /dev/tty.usbmodem* , and choose one with smallest number
  set(PORT "/dev/ttyACM0" CACHE PATH "A guess for the port to use" FORCE)
  ## NOTE THIS IS A GUESS! That usually works for linux
endif()




message(STATUS "Using port ${PORT}")


set(COMMON_SRCS
        utilityFunctions.h utilityFunctions.cpp
        GameConsole.cpp GameConsole.h
        SingleCard.cpp SingleCard.h
        DeckOfCards.cpp DeckOfCards.h
        HandOfCards.cpp HandOfCards.h
        GameLogic.cpp
        )

add_library(LowestCardLib ${COMMON_SRCS})
target_link_libraries(LowestCardLib pololu_${DEVICE} )
        #================================
#== Step 1 Make GameConsole class & test display
#==
set(PROGNAME Step1_testPrinting)

add_executable(${PROGNAME}.obj Step1_testPrinting.cpp )
target_link_libraries(${PROGNAME}.obj LowestCardLib)

#add_custom_command(TARGET ${PROGNAME}.obj
#                   POST_BUILD
#                   COMMENT "OBJ2HEX conversion")

add_custom_target(flash_${PROGNAME}
        COMMAND ${AVR_OBJCOPY} -R .eeprom -O ihex ${PROGNAME}.obj ${PROGNAME}.hex
        COMMAND ${AVR_DUDE} -p  ${AVRDUDE_DEVICE} -c avrisp2 -P ${PORT} -U flash:w:${PROGNAME}.hex
        DEPENDS ${PROGNAME}.obj
        COMMENT "dump program to the robot on port ${PORT}")

#================================
#== Step 2 Update GameConsole class & test button pressing
#==
set(PROGNAME Step2_testButtons)

add_executable(${PROGNAME}.obj Step2_testButtons.cpp )
target_link_libraries(${PROGNAME}.obj LowestCardLib)

#add_custom_command(TARGET ${PROGNAME}.obj
#                   POST_BUILD
#                   COMMENT "OBJ2HEX conversion")

add_custom_target(flash_${PROGNAME}
        COMMAND ${AVR_OBJCOPY} -R .eeprom -O ihex ${PROGNAME}.obj ${PROGNAME}.hex
        COMMAND ${AVR_DUDE} -p  ${AVRDUDE_DEVICE} -c avrisp2 -P ${PORT} -U flash:w:${PROGNAME}.hex
        DEPENDS ${PROGNAME}.obj
        COMMENT "dump program to the robot on port ${PORT}")

#================================
#== Step 3 Update Test DeckOfCards class basic Features
#==
set(PROGNAME Step3_testShowDeckOfCards)

add_executable(${PROGNAME}.obj Step3_testShowDeckOfCards.cpp)
target_link_libraries(${PROGNAME}.obj LowestCardLib)

#add_custom_command(TARGET ${PROGNAME}.obj
#                   POST_BUILD
#                   COMMENT "OBJ2HEX conversion")

add_custom_target(flash_${PROGNAME}
        COMMAND ${AVR_OBJCOPY} -R .eeprom -O ihex ${PROGNAME}.obj ${PROGNAME}.hex
        COMMAND ${AVR_DUDE} -p  ${AVRDUDE_DEVICE} -c avrisp2 -P ${PORT} -U flash:w:${PROGNAME}.hex
        DEPENDS ${PROGNAME}.obj
        COMMENT "dump program to the robot on port ${PORT}")


#================================
#== Step 4 Update Test HandOfCards class basic Features
#==
set(PROGNAME Step4_testHandOfCards)

add_executable(${PROGNAME}.obj Step4_testHandOfCards.cpp )
target_link_libraries(${PROGNAME}.obj LowestCardLib)

#add_custom_command(TARGET ${PROGNAME}.obj
#                   POST_BUILD
#                   COMMENT "OBJ2HEX conversion")

add_custom_target(flash_${PROGNAME}
COMMAND ${AVR_OBJCOPY} -R .eeprom -O ihex ${PROGNAME}.obj ${PROGNAME}.hex
COMMAND ${AVR_DUDE} -p  ${AVRDUDE_DEVICE} -c avrisp2 -P ${PORT} -U flash:w:${PROGNAME}.hex
DEPENDS ${PROGNAME}.obj
COMMENT "dump program to the robot on port ${PORT}")

#================================
#== Step Write Final Program
#==

set(PROGNAME LowestScoreGame)
add_executable(${PROGNAME}.obj LowestScoreGame.cpp)
target_link_libraries(${PROGNAME}.obj LowestCardLib)

#add_custom_command(TARGET ${PROGNAME}.obj
#                   POST_BUILD
#                   COMMENT "OBJ2HEX conversion")

add_custom_target(flash_${PROGNAME}
                  COMMAND ${AVR_OBJCOPY} -R .eeprom -O ihex ${PROGNAME}.obj ${PROGNAME}.hex
                  COMMAND ${AVR_DUDE} -p  ${AVRDUDE_DEVICE} -c avrisp2 -P ${PORT} -U flash:w:${PROGNAME}.hex
                  DEPENDS ${PROGNAME}.obj
                  COMMENT "dump program to the robot on port ${PORT}")


#===========================
# REFERENCE SOLUTIN

add_custom_target(flash_ReferenceSolutionLowestScoreGame
COMMAND ${AVR_OBJCOPY} -R .eeprom -O ihex ${CMAKE_CURRENT_LIST_DIR}/ReferenceSolutionLowestScoreGame.obj ReferenceSolutionLowestScoreGame.hex
COMMAND ${AVR_DUDE} -p  ${AVRDUDE_DEVICE} -c avrisp2 -P ${PORT} -U flash:w:ReferenceSolutionLowestScoreGame.hex
DEPENDS ReferenceSolutionLowestScoreGame.obj
COMMENT "Write a solution program the robot on port ${PORT}")
