
##========================================================================
##
##    ツールキットの設定
##

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment")
endif

include $(DEVKITARM)/gba_rules

##========================================================================
##
##    ターゲット
##

target          := $(notdir $(CURDIR))
build_dir       := build
sources_dir     := source
include_dir     := include
data_dir        :=


##========================================================================
##
##    コンパイルオプション
##

ARCH        :=      -mthumb -mthumb-interwork

CFLAGS      :=      -g -Wall -O3\
                    -mcpu=arm7tdmi -mtune=arm7tdmi\
                    -fomit-frame-pointer\
                    -ffast-math \
                    $(ARCH)

CFLAGS      +=      $(INCLUDE)
CXXFLAGS    :=      $(CFLAGS) -fno-rtti -fno-exceptions

ASFLAGS     :=      -g $(ARCH)
LDFLAGS     =       -g $(ARCH) -Wl,-Map,$(notdir $*.map)
