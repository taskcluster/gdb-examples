SUBDIRS := $(wildcard */.)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -B -C $@

.PHONY: all $(SUBDIRS)
