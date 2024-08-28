#!/bin/sh

od -Ax -tx1z -v ./build/switchblade.sna > /tmp/current.hex
diff -u src/raw/reference.hex /tmp/current.hex
