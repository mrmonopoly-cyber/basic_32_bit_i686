# Setup
To compile the kernel you need the i686 toolchain, to get it run the following script
Run:
```sh
 setup.sh
```

# Build
The building process will create the following objects:
 
 - Grub image : isodir/boot/damos.bin
 - kernel object: kernel.o
 - boot object: boot.o

```sh
  make build
```

# Run
To run the OS in an emulated environement run:
```sh
 make run
```

# Clean
```sh
make clean
```
