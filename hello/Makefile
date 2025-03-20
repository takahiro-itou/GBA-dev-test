
.SUFFIXES:

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

ARCH        :=  -mthumb -mthumb-interwork

CFLAGS      :=  -g -Wall -O3\
                -mcpu=arm7tdmi -mtune=arm7tdmi\
                -fomit-frame-pointer\
                -ffast-math \
                $(ARCH)

CFLAGS      +=  $(INCLUDE)
CXXFLAGS    :=  $(CFLAGS) -fno-rtti -fno-exceptions

ASFLAGS     :=  -g $(ARCH)
LDFLAGS     =   -g $(ARCH) -Wl,-Map,$(notdir $*.map)

LIBS        :=  -lmm -lgba
LIBDIRS     :=  $(LIBGBA)


ifneq ($(BUILDDIR), $(CURDIR))

##========================================================================
##
##    変数定義
##

export  OUTPUT      :=  $(CURDIR)/$(target)

export  VPATH       :=  $(foreach dir,$(sources_dir),$(CURDIR)/$(dir)) \
                        $(foreach dir,$(DATA),$(CURDIR)/$(dir)) \
                        $(foreach dir,$(GRAPHICS),$(CURDIR)/$(dir))

export  DEPSDIR     :=  $(CURDIR)/$(build_dir)


CFILES      :=  $(foreach dir,$(sources_dir),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES    :=  $(foreach dir,$(sources_dir),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES      :=  $(foreach dir,$(sources_dir),$(notdir $(wildcard $(dir)/*.s)))
BINFILES    :=  $(foreach dir,$(data_dir),$(notdir $(wildcard $(dir)/*.*)))

ifeq ($(strip $(CPPFILES)),)
    export  LD  :=  $(CC)
else
    export  LD  :=  $(CXX)
endif

export  OFILES_BIN      :=  $(addsuffix .o,$(BINFILES))
export  OFILES_SOURCES  :=  $(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)
export  OFILES          :=  $(OFILES_BIN) $(OFILES_SOURCES)
export  HFILES          :=  $(addsuffix .h,$(subst .,_,$(BINFILES)))
export  INCLUDE         :=  $(foreach dir,$(INCLUDES),-iquote $(CURDIR)/$(dir)) \
                            $(foreach dir,$(LIBDIRS),-I$(dir)/include) \
                            -I$(CURDIR)/$(build_dir)
export  LIBPATHS        :=  $(foreach dir,$(LIBDIRS),-L$(dir)/lib)

.PHONY: all $(build_dir) clean

$(build_dir):
	[ -d $@ ] || mkdir -p $@
	$(MAKE) BUILDDIR=`cd $(build_dir) && pwd` -C $(build_dir) -f $(CURDIR)/Makefile

clean   :
	@echo clean ...
	rm -rf $(build_dir) $(target).elf $(target).gba

else

##========================================================================
##
##    メインターゲット
##


$(OUTPUT).gba       :   $(OUTPUT).elf

$(OUTPUT).elf       :   $(OFILES)

$(OFILES_SOURCES)   :   $(HFILES)

-include $(DEPSDIR)/*.d

endif
