MAKEFLAGS += -s

MOD_MAKEFILES = $(wildcard ./*/Makefile)
MOD_DIRS := $(dir $(MOD_MAKEFILES))

.PHONY: all clean $(MOD_DIRS)

all: $(MOD_DIRS)

$(MOD_DIRS):
	@echo Build $(patsubst %/,%,$@) ...
	$(MAKE) -C $@

clean: $(addsuffix .clean,$(MOD_DIRS))

%.clean:
	@echo Clean $(patsubst %/.clean,%,$@) ...
	$(MAKE) -C $* clean