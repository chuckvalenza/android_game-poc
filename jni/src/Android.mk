LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := main

#SDK_ROOT points to folder with SDL and oxygine-framework
SDK_ROOT := /home/cvalenza/code/libraries

LOCAL_SRC_FILES := /home/cvalenza/code/libraries/SDL/src/main/android/SDL_android_main.c
LOCAL_SRC_FILES += main.cpp example.cpp Game.cpp Joystick.cpp Player.cpp res.cpp Unit.cpp


LOCAL_STATIC_LIBRARIES := oxygine-framework_static
LOCAL_SHARED_LIBRARIES := SDL2

include $(BUILD_SHARED_LIBRARY)

#import from NDK_MODULE_PATH defined in build.cmd
$(call import-add-path, /home/cvalenza/code/libraries)
$(call import-module, oxygine-framework)
