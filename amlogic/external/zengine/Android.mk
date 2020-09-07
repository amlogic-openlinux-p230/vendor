LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := zproxy
LOCAL_STRIP_MODULE := keep_symbols
LOCAL_SRC_FILES := zgadget.c trace.c zproxy.c reishi.c zpio.c
LOCAL_MODULE_PATH=$(TARGET_OUT_VENDOR_EXECUTABLES)

LOCAL_CFLAGS := \
	-Wall -Wextra -Werror \
	-Wno-unused-parameter \
	-Wno-deprecated-declarations

LOCAL_SHARED_LIBRARIES := liblog

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_MODULE := zapp
LOCAL_STRIP_MODULE := keep_symbols
LOCAL_SRC_FILES := zapp.c reishi.c trace.c zpio.c
LOCAL_MODULE_PATH=$(TARGET_OUT_VENDOR_EXECUTABLES)

LOCAL_CFLAGS := \
	-Wall -Wextra -Werror \
	-Wno-unused-parameter \
	-Wno-deprecated-declarations

LOCAL_SHARED_LIBRARIES := liblog

include $(BUILD_EXECUTABLE)
