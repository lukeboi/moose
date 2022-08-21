#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
  echo "platform: linux"
  os=linux
elif [[ "$OSTYPE" == "darwin"* ]]; then
  echo "platform: macos"
  os=macos
  set -e
fi

#cd ~/Documents/Github/moose
echo ">>>>> 𝐁 𝐔 𝐈 𝐋 𝐃 𝐈 𝐍 𝐆 <<<<<"
bazel build ... --symlink_prefix=bazel-$os-
echo ">>>>> 𝐑 𝐔 𝐍 𝐍 𝐈 𝐍 𝐆 <<<<<"

if [ "$os" == "macos" ]; then
  bazel-macos-out/darwin_arm64-fastbuild/bin/src/moose
elif [ "$os" == "linux" ]; then
  bazel-linux-out/k8-fastbuild/bin/src/moose
fi