# logdiff
Compare log files.
`logdiff` ignores number characters, not to be fooled by volatile log messages (timestamp, id, ... etc), 

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
