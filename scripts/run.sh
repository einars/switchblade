#!/bin/sh

set -o pipefail -o errexit -o nounset

cd "$(dirname "$0")/.."

(scripts/compile.sh || true) && fuse build/switchblade.sna
