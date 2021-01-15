# Copyright (C) 2021 Peter Markfelder
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public
# License version 3 as published by the Free Software Foundation.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.

BUILD := ../../$(BUILD)

CFLAGS += -O2 -fPIC
CPPFLAGS += -I../include/
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

SRCS = $(wildcard *.c)
DEPFILES := $(SRCS:%.c=%.d)
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c

SONAME := $(BUILD)/lib$(LIBNAME).so
SOMJR := $(SONAME).$(MAJOR)
REALNAME := $(SOMJR).$(MINOR).$(RELEASE)

all: $(SONAME)

$(SONAME): $(SOMJR)
	ln -sf $(notdir $<) $@

$(SOMJR): $(REALNAME)
	ln -sf $(notdir $<) $@

$(REALNAME): $(patsubst %.c,%.o,$(SRCS))
	mkdir -p $(BUILD)/
	$(CC) -shared -Wl,-soname,$(notdir $(SONAME)) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(COMPILE.c) -o $@ $<

$(DEPFILES):
include $(wildcard $(DEPFILES))

clean:
	$(RM) $(wildcard *.o) $(wildcard *.d) $(REALNAME) $(SONAME) $(SOMJR)

install: all
	$(INSTALL) -m 755 -D $(REALNAME) $(PREFIX)/lib
	ln -sf $(notdir $(SOMJR)) $(PREFIX)/lib/$(notdir $(SONAME))
	ln -sf $(notdir $(REALNAME)) $(PREFIX)/lib/$(notdir $(SOMJR))
	$(INSTALL) -m 644 -D $(wildcard ../include/neweden/$(LIBNAME)/*.h) $(PREFIX)/include/neweden/$(LIBNAME)

.PHONY: all clean install
