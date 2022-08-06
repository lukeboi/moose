cd ~/Documents/Github/moose
echo "......Building......"
bazel build ...
echo "......Running......."
bazel-out/darwin_arm64-fastbuild/bin/src/moose
