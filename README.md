[//]: # (To preview markdown file in Emacs type C-c C-c p)

# Assignment 0: Development Environment and basic programming
The goal of this pre-assignment is to practice the basic use of the terminal environment and make.

## Dependencies

### [FLINT](http://www.flintlib.org/index.html)
C library for doing number theory.

### [Arb](http://arblib.org)
C library for rigorous real and complex arithmetic with arbitrary precision

## Testing installation of Arb on MacOS
On MacOS Mojave, verify that Arb has been successfully installed by compiling and
running the [test program](http://arblib.org/setup.html#running-code) with
additional `-lflint -lmpfr -lgmp -lpthread` linking flags:

`make test`

`./test`

## Library check
On Linux and Mac OS X, to check if library `lib_name` is already installed run:

`find <path/to/search/in> -name \*lib_name\*`

## FLINT configuration
In order to use the CPU capabilities to the fullest, FLINT should be built 
using native processor architecture. To this end, additional option should
be specified in `CFLAGS="-march=native"` of `./configure`.
