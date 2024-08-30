#!/bin/sh

od -Ax -tx1z -v ./build/switchblade.sna > /tmp/current.hex
diff -C 0 src/raw/reference.hex /tmp/current.hex
