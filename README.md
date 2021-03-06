The main objective of this package is to provide a template to

 - use `PyTorch` C++ API from an R package
 - with `Rcpp`
 - with test in both R and C++ using `testthat` and the wrapper in
   `testthat` of the C++ `Catch` library
 - and which is easy to use (e.g. can use `R CMD INSTALL`,
   `R CMD build`, and `devtools::test()`).


## Installation

This is instructions for Linux.
Download and unzip LibTorch (https://pytorch.org/)

```bash
https://download.pytorch.org/libtorch/cu101/libtorch-cxx11-abi-shared-with-deps-1.4.0.zip
```

Set the following enviroment variable

```bash
export TORCH_INSTALL_PREFIX=/your/path/to/libtorch
```

Install the package

```bash
git clone https://github.com/boennecd/Rtorchcpp
R CMD build Rtorchcpp  && R CMD INSTALL Rtorchcpp_0.1.0.tar.gz
# or
R CMD INSTALL Rtorchcpp
```

The first build may fail but gives instruction on what to do.

## Testing

```bash
R CMD build Rtorchcpp && R CMD check --as-cran Rtorchcpp_0.1.0.tar.gz
```

Or

```r
# assuming that you are in the package directory
devtools::test()
```

## TODOs

 - What about the GPU version?
 - Ask the user to create a symlink to `libtorch.so` instead. Otherwise,
   consider some other alternative (e.g. what is done in `rJava` package).
 - Support more platforms.
