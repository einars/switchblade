#!/bin/sh

set -o pipefail -o errexit -o nounset

cd "$(dirname "$0")/.."

compiler='/proj/zx/0-sjasmplus/build/sjasmplus'

$compiler \
  --syntax=ab \
  --outprefix=build/ \
  --nologo \
  src/main.asm

./scripts/verify.sh
