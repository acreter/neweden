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

CFLAGS += -g -fPIC -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os -D_POSIX_C_SOURCE=200809L
CPPFLAGS += -I../include/
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

SRCS = $(wildcard *.c)
DEPFILES := $(SRCS:%.c=%.d)
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c

SONAME := $(BUILD)/lib$(LIBNAME).so
SOMJR := $(SONAME).$(MAJOR)
REALNAME := $(SOMJR).$(MINOR).$(RELEASE)

all: $(SONAME) $(BUILD)/lib$(LIBNAME).a

$(SONAME): $(SOMJR)
	ln -sf $(notdir $<) $@

$(SOMJR): $(REALNAME)
	ln -sf $(notdir $<) $@

$(REALNAME): $(patsubst %.c,%.o,$(SRCS))
	mkdir -p $(BUILD)/
	$(CC) -shared -Wl,-soname,$(notdir $(SONAME)) -o $@ $^ $(LDFLAGS)

$(BUILD)/lib$(LIBNAME).a: $(patsubst %.c,%.o,$(SRCS))
	$(AR) rcs $@ $^

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
	$(INSTALL) -m 644 -D -t $(PREFIX)/include/neweden/$(LIBNAME) $(wildcard ../include/neweden/$(DEF_LIBNAME)/*.h)

.PHONY: all clean install
