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

export
include VERSION
include config.mk
BUILD = build
INSTALL := install
RM += -r

all: src/essence src/everyshore

src/essence: VERSION
	$(MAKE) -C $@ all

src/everyshore: VERSION src/essence
	$(MAKE) -C $@ all

clean:
	$(MAKE) -C src/essence clean
	$(MAKE) -C src/everyshore clean
	$(RM) $(BUILD) $(wildcard *.a)

config.mk:
	cp config.def.mk $@

install: all
	$(MAKE) -C src/essence install
	$(MAKE) -C src/everyshore install

.PHONY: all src/essence src/everyshore clean install
