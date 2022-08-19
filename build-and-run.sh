#!/bin/bash
set -e

cd ~/Documents/Github/moose
echo "▶︎▶︎▶︎▶ 𝐁 𝐔 𝐈 𝐋 𝐃 𝐈 𝐍 𝐆 ︎◀︎◀︎◀︎◀︎"
bazel build ...
echo "▶︎▶︎▶︎▶  𝐑 𝐔 𝐍 𝐍 𝐈 𝐍 𝐆  ︎◀︎◀︎◀︎◀︎"
bazel-out/darwin_arm64-fastbuild/bin/src/moose
