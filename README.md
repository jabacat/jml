![JML](./resources/jml-logo-long.png#gh-light-mode-only)
![JML](./resources/jml-logo-long-dark-mode.png#gh-dark-mode-only)
JABACAT-created machine learning library from scratch.

![GitHub Workflow Status (with event)](https://img.shields.io/github/actions/workflow/status/jabacat/jml/build-test.yml?style=for-the-badge)

## Build
> [!IMPORTANT]
> This project uses [The Meson Build system](https://mesonbuild.com/index.html). Follow instructions posted on the website to [install meson](https://mesonbuild.com/SimpleStart.html). On Windows, there is a winget package available.

To build, setup the build directory. Any configuration steps should be done now (specifying compiler or linker, etc.).
```bash
meson setup build   # replace `build` with any arbitrary output build directory
```
Then, compile it.
```bash
meson compile -C build  # replace `build` with the directory specified in the previous step
```
The outputs are in `build/` (or whatever directory specified). Install the outputs:
```bash
meson install -C build  # again, replace `build`
```

## Test
This project uses [Catch2](https://github.com/catchorg/Catch2) as its testing framework.

Run `meson test` to test the project.
```bash
meson test -C build     # replace `build`
```

Unfortunately, meson doesn't provide good output when a test fails. Running the test executable manually is often more helpful. Look under `build/tests/` to find the right executable. The executable for testing the core library is `core_tests`.
