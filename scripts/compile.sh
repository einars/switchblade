#!/bin/sh

set -o pipefail -o errexit -o nounset

cd "$(dirname "$0")/.."

sjasmplus \
  --syntax=ab \
  --outprefix=build/ \
  --nologo \
  --sym=build/switchblade.sym \
  -Wno-sna48 \
  src/main.asm

./scripts/verify.sh
