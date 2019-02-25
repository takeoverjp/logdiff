# logdiff
Compare log files.

`logdiff` ignores number characters, not to be fooled by volatile log messages (timestamp, id, ... etc), 

For example, the following two messages are treated as same.

```log1
2019/01/21 18:13 process start
2019/01/21 18:13 process finish
```

```log2
2019/02/13 07:18 process start
2019/02/13 07:23 process finish
```

## Howto build

```shell-session
git submodule update --init
mkdir build
cd build
cmake ..
make
[option] make install
```

## Howto use

```shell-session
logdiff FILE1 FILE2
```

## Howto test

```shell-session
cd build
ctest
```
