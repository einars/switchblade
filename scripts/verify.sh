#!/bin/sh

od -Ax -tx1z -v ./build/switchblade.sna > /tmp/current.hex
diff -u /tmp/current.hex src/raw/reference.hex
